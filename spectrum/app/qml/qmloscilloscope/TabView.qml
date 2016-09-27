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
import QtQuick.Controls 1.4
import QtCharts 2.1


Item{
    id: _tabView
    property string templateName: null

    function addTab()
    {
        var object = privateComponent.componentTemp.createObject(content, privateComponent.componentTemp);
        /*var test = JSON.stringify(object);
        object = JSON.parse(test);*/
        privateComponent.childrens.push(object);
        // console.log(privateComponent.childrens.length);
        menu_rep.model = privateComponent.childrens.length;
        selectTab(privateComponent.childrens.length - 1);
    }
    ModalWindowConfirm{
        id: removeSure
        property int index: 0
        text: "Ви точно бажаєте закрити вкладку?"
        callBack: function(){
            privateComponent.childrens[removeSure.index].destroy();
            privateComponent.childrens.splice(removeSure.index, 1);
            menu_rep.model = privateComponent.childrens.length;
            selectTab(removeSure.index - 1);
        }
    }

    FiltersConfig{
        id: filtersConfig
    }


    function removeTab(index)
    {
        removeSure.index = index;
        removeSure.show();

    }
    function selectTab(indexS){
        if(privateComponent.childrens.length > privateComponent.selectedTab && privateComponent.selectedTab > 0)
            privateComponent.childrens[privateComponent.selectedTab].visible = false;
        privateComponent.selectedTab = indexS;
        if(privateComponent.childrens.length > privateComponent.selectedTab  && privateComponent.selectedTab > 0)
            privateComponent.childrens[privateComponent.selectedTab].visible = true;
        selector.atach = menu_rep.itemAt(privateComponent.selectedTab);
    }

    onTemplateNameChanged: {
        privateComponent.componentTemp = Qt.createComponent(templateName + ".qml");
    }

    Item{
        id: privateComponent
        property var childrens: []
        property var componentTemp: null
        property int selectedTab: 0
    }

    Column{
        anchors.fill: parent
        Item{
            id: tabsCool
            width: parent.width
            height: menu.height
            Flickable {
                id: scroll
                width: parent.width - configPanel.width - configPanel.anchors.rightMargin
                height: parent.height
                contentWidth: menu.width
                z: 1
                clip: true
                MouseArea
                {
                    anchors.fill: parent
                    //
                    onWheel: {
                        scroll.flick(wheel.angleDelta.y*1.7, 0);
                    }
                }
                Row {
                    id: menu
                    width: childrenRect.width
                    height: childrenRect.height
                    clip: false
                    x: 10
                    Repeater {
                        id: menu_rep
                        model: privateComponent.childrens.length
                        TabViewBtn{
                            id: btn
                            title: index + 1
                            selected: index == privateComponent.selectedTab
                            onClicked: {
                                selectTab(index);
                                //   selector.atach = this;
                                //  console.log("fdfd");
                            }
                            onClose: {
                                removeTab(index);
                            }

                            onXChanged: {
                                if(selected)
                                    selector.x = x + menu.x;
                            }

                        }
                    }
                    TabViewBtn{
                        id: addBtn
                        title: ""
                        closable: false
                        IconBtn{
                            url: "qrc:/icons/qml/icons/ic_create_new_folder_white_48px.svg"
                            onClick: {_tabView.addTab();}
                        }
                    }
                }
                Rectangle{
                    id: selector
                    property Item atach: null
                    Behavior on x {
                        NumberAnimation {
                            id: bouncebehavior
                            easing {
                                type: Easing.OutElastic
                                amplitude: 1.0
                                period: 0.5
                            }
                        }
                    }
                    width: addBtn.width
                    height: 3
                    visible: atach == null ? false : true
                    onAtachChanged: {
                        if(selector.atach != null)
                        {
                            //var new_coord = selector.atach.mapToItem(tabsCool, 0, selector.atach.height);
                            x = selector.atach.x + menu.x;
                            y = selector.atach.y + selector.atach.height - height;
                        }
                    }
                }
            }
            Item{
                id: configPanel
                width: childrenRect.width
                height: parent.height
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.rightMargin: 10
                Row{
                    width: childrenRect.width
                    height: parent.height
                    spacing: 3
                    Rectangle{
                        width: 2
                        height: parent.height
                        color: "white"
                    }
                    IconBtn{
                        url: "qrc:/icons/qml/icons/ic_add_white_48px.svg"
                        onClick: {
                            privateComponent.childrens[privateComponent.selectedTab].createNewView();
                        }
                    }
                    IconBtn{
                        url: "qrc:/icons/qml/icons/ic_assessment_white_48px.svg"
                        onClick: {
                            filtersConfig.show();
                        }
                    }
                    IconBtn{
                        url: "qrc:/icons/qml/icons/ic_build_white_48px.svg"
                        onClick: {mainWindow.showSettingsDialog();}
                    }
                }
            }
        }
        Rectangle{
            id: content
            height: parent.height - menu.height
            width: parent.width
            color: "transparent"
        }
    }
    Component.onCompleted: {
        addTab();
    }
}
