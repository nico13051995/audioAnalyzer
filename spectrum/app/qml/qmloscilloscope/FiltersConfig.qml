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
Item{
    id: _filtersConfig
    function show(){
        _filtersConfigW.show(_filtersConfigC);
    }

    ModalWindow{
        id: _filtersConfigW
        Item{
            id: _filtersConfigC
            width: _filtersConfigW.width - 60//50px close btn
            height: _filtersConfigW.height - 60
            Item{
                id: addComponent
                width: parent.width
                height: childrenRect.height
                Row{
                    width: parent.width
                    height: graphNameContainer.height
                    Rectangle{
                        id: graphNameContainer
                        width: parent.width - icon.width
                        height: 40
                        color: "transparent"
                        property int botomBorder: 3
                        Text{
                            id: lable
                            color: "white"
                            y: parent.height/4 - graphNameContainer.botomBorder*2
                            font.pointSize: parent.height/2
                            text: "Імя торби: "
                        }
                        TextInput{
                            id: graphName
                            anchors.fill: parent
                            anchors.bottomMargin: graphNameContainer.botomBorder
                            anchors.topMargin: parent.height/4
                            anchors.leftMargin: lable.width
                            color: "white"
                            font.pointSize: parent.height/2
                        }
                        Rectangle{
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
                            color: "white"
                            height: graphNameContainer.botomBorder - 1
                            opacity: 0.5
                        }
                    }
                    IconBtn{
                        id: icon
                        url: "qrc:/icons/qml/icons/ic_add_white_48px.svg"
                        onClick: {

                            console.log("OK = " + mainWindow.addPraph(graphName.text, chartView.viewId).getName());
                            console.log("OK = " + mainWindow.getPraphIds(chartView.viewId).length);
                            rows.model = mainWindow.getPraphIds(chartView.viewId).length;
                            graphName.text = "";
                        }
                    }
                }
            }
            ListView{
                id: list
                anchors.fill: parent
                anchors.topMargin: addComponent.height
                Repeater{
                    id:filtesRep
                    model: mainWindow.getTemplatesQML()
                    Row{
                        width: parent.width
                        height: childrenRect.height
                        Text {
                            id: name
                            text: modelData
                            onTextChanged: console.log("TEXT: " + modelData)
                        }
                    }
                }

            }
        }
    }
}
