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

//![1]
Rectangle {
    id: root
    width: 600
    height: 400
    color: root.screenShot ? "#fff" : "#2c2d37"
    //color:"#2c2d37"
    property int nextId: 0
    property bool screenShot: false
    /*MouseArea{
        z:1
        anchors.fill: parent;
        propagateComposedEvents: true
        onClicked: {
            root.forceActiveFocus();
            mouse.accepted = false
        }
    }*/
    Row{
        id: windowControlPanel
        anchors.top: parent.top
        anchors.right: parent.right
        height: 30
        IconBtn{
            id: screenShot
            url: "qrc:/icons/qml/icons/screen-1.svg"
            onClick: {
                root.screenShot = true;
                function Timer() {
                    return Qt.createQmlObject( "import QtQuick 2.0; Timer {}", root);
                }

                var timer = new Timer();
                timer.interval = 1000;
                timer.repeat = false;
                timer.triggered.connect(function () {
                    mainWindow.getScreenShot();
                    root.screenShot = false;
                })

                timer.start();

            }
        }
        IconBtn{
            id: fullScreenSwitch
            url: "qrc:/icons/qml/icons/ic_open_with_white_48px.svg"
            onClick: {
                mainWindow.switchFullScreen();
                closeBtn.visible = mainWindow.isFullScreen();
            }
        }
        IconBtn{
            id: closeBtn
            url: "qrc:/icons/qml/icons/ic_highlight_off_white_48px.svg"
            visible: mainWindow.isFullScreen();
            onClick: mainWindow.close();
            Connections{
                target: root
                onWidthChanged:{
                    closeBtn.visible = mainWindow.isFullScreen();;
                }
            }
        }
    }

    TabView{
        width: parent.width
        anchors.fill: parent

        anchors.margins: 20
        anchors.bottomMargin: mediaControlPanel.height + 3
        templateName: "Page"
    }
    MediaControlPanel{
        id: mediaControlPanel
        z:2//for MediaControlPanel overlap
        anchors.bottom: parent.bottom
    }
}
