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
Column{
    id: _tabPage
    anchors.fill: parent
    Item{
        id: privateComponent
        property var childrens: []
        property var componentTemp: null
    }

    function createNewView()
    {
        var object = privateComponent.componentTemp.createObject(_tabPage, privateComponent.componentTemp);
        privateComponent.childrens.push(object);
        object.width = Qt.binding(function() { return _tabPage.width});
        object.height = Qt.binding(function() { return _tabPage.height/(_tabPage.children.length-1);});
        _tabPage.update();
    }
    Component.onCompleted: {
        privateComponent.componentTemp = Qt.createComponent("ScopeView.qml");
        createNewView();
    }
}
