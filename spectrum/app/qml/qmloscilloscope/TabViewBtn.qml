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

import QtQuick 2.7
import QtCharts 2.1

Item {
    id: _tabBtn
    width: 100; height: 40

    property string title: "Click"
    property bool selected: false
    property bool closable: true
    signal clicked;
    signal entered;
    signal exited;
    signal close;

    Item{
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 3
        clip: true
        width: 22
        height: width
        enabled: closable
        visible: closable
        z: 22
        IconBtn{
            url: "qrc:/icons/qml/icons/ic_cancel_white_48px.svg";
            onClick: close();
        }
    }

    TextMetrics {
        id: textMetrics
        font.family: "Arial"
        elide: Text.ElideMiddle
        elideWidth: parent.width
        text: _tabBtn.title;
    }

    Text {
        id: _title
        text: textMetrics.elidedText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
        lineHeight: height
        font.pixelSize: 20
        color: "white"

    }
    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            _title.font.pixelSize = 24;
            _tabBtn.z = 2;
            _tabBtn.entered();
        }
        onExited: {
            _title.font.pixelSize = 20;
            _tabBtn.z = 0;
            _tabBtn.exited();
        }

        onClicked: {
            _tabBtn.clicked();
        }
    }
}
