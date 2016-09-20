/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Item {
    id: _progressBar
    property color color: "#3fb8f1"
    property color backColor: "#333"
    property double min: 0
    property double max: 100
    property double value: 0
    property double virtualValue: 0
    signal userChangeValue;
    signal startChangeValue;

    function updateValue(){
        if(_progressBar.value > _progressBar.max)
            _progressBar.value = _progressBar.max;
        if(_progressBar.value < _progressBar.min)
            _progressBar.value = _progressBar.min;
        valueRect.width = _progressBar.width*((_progressBar.value - _progressBar.min)/(_progressBar.max - _progressBar.min));
        _progressBar.virtualValue = _progressBar.value;
    }

    onValueChanged: {
        updateValue();
    }
    onMinChanged: {
        updateValue();
    }
    onMaxChanged: {
        updateValue();
    }
    onBackColorChanged: background.calcColor();

    Rectangle{
        id: background
        width: parent.width - x*2
        height: 6
        radius: 255
        color: backColor
        anchors.verticalCenter: parent.verticalCenter
        x: 50
        function calcColor() {
            var t_color = _progressBar.backColor;
            t_color.a = 0.3;
            return t_color;
        }
        Rectangle{
            id: valueRect
            height: parent.height
            radius: background.radius
            color: _progressBar.color
        }
        Rectangle{
            id: control
            height: parent.height*3.0
            width: height
            radius: 255
            x: valueRect.width  - control.width/2
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                id: controlMouseArea
                anchors.fill: parent
                property double lastX
                property double savedWidth : -1
                hoverEnabled: true
                onEntered: {
                    cursorShape: Qt.IBeamCursor;
                }
                onExited: {
                    cursorShape: Qt.ArrowCursor;
                }

                onMouseXChanged: {
                    if(pressed)
                    {
                        var delta = lastX - mouseX;
                        lastX = mouseX;
                        /*var deltaForValue = (delta*(_progressBar.max - _progressBar.min))/control.width + _progressBar.min;
                        _progressBar.value -= deltaForValue*0.001;*/

                        valueRect.width = controlMouseArea.mapToItem(valueRect, mouseX, 0).x;
                        if(valueRect.width > background.width)
                            valueRect.width = background.width;
                        if(valueRect.width < 0)
                            valueRect.width = 0;

                        _progressBar.virtualValue = ((valueRect.width*(_progressBar.max - _progressBar.min))/_progressBar.width) + _progressBar.min;
                       // control.x = valueRect.width - control.width/2;
                    }
                }
                onPressed: {
                    controlMouseArea.savedWidth = valueRect.width;
                    _progressBar.startChangeValue();
                }

                onReleased: {
                    if(controlMouseArea.savedWidth != -1/* && valueRect.width != controlMouseArea.savedWidth*/)
                    {
                        var value = ((valueRect.width*(_progressBar.max - _progressBar.min))/_progressBar.width) + _progressBar.min;
                        _progressBar.value = value;
                        _progressBar.userChangeValue();
                        controlMouseArea.savedWidth = -1;
                    }
                }
            }
        }
    }
    Component.onCompleted: {
        controlMouseArea.lastX = controlMouseArea.mouseX;
        updateValue();
    }

}
