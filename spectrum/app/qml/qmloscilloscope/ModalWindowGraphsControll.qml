import QtQuick 2.0

Item{
    id: container
    signal hideEvent;
    function show()
    {
        _chartSettings.show(_chartSettingsC);
    }

    ModalWindow{
        id: _chartSettings
        onHideEvent: container.hideEvent();
        Item{
            id: _chartSettingsC
            property int index: 0
            width: _chartSettings.width - 60//50px close btn
            height: _chartSettings.height - 60
            function range(min, max){
                var array = [];
                for(var i = min; i <= max; i++)
                    array.push(i);
                return array;
            }
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
                            text: "Імя графіку: "
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
            Column{
                anchors.fill: parent
                anchors.topMargin: addComponent.height + 10
                spacing: 10
                Repeater{
                    id: rows
                    model: mainWindow.getPraphIds(chartView.viewId).length
                    Row{
                        id: graph
                        property var graphId
                        property var graphObj
                        width: parent.width
                        height: childrenRect.height
                        spacing: 5
                        z: 1000 - index

                        Text {
                            id: name
                            text: qsTr("text")
                            color: "white"
                            width: 200
                            y: filter.height/4
                            font.pixelSize: filter.height/2
                        }
                        ComboBox{
                            id: filter
                            items: mainWindow.getTemplatesQML();
                            titleLink: null
                            onComboClicked: {
                                graph.graphObj.setTemplateName(filter.selectedValue());
                            }
                        }
                        //chanels
                        ComboBox{
                            id:chanel
                            items: _chartSettingsC.range(0,3);
                            titleLink: null
                            onComboClicked: {
                                graph.graphObj.setChanel(chanel.selectedValue());
                            }
                        }
                        //chanels
                        ComboBox{
                            id:type
                            items: [{title:"Форма", value: 1},{title:"Спектр", value: 2}]
                            titleLink: 'title'
                            onComboClicked: {
                                console.log(type.selectedValue().value);
                                graph.graphObj.setType(type.selectedValue().value);

                            }
                        }
                        Component.onCompleted: {
                            graph.graphId = mainWindow.getPraphIds(chartView.viewId)[index];
                            graph.graphObj = mainWindow.getPraphById(graphId, chartView.viewId)

                            filter.setCurrent(filter.items.indexOf(graph.graphObj.getTemplateName()));
                            chanel.setCurrent(chanel.items.indexOf(graph.graphObj.getChanel()));
                            console.log(graph.graphObj.getType());
                            if(graph.graphObj.getType() == 1)
                                type.setCurrent(0);
                            else
                                type.setCurrent(1);

                            name.text = graph.graphObj.getName();
                        }
                    }
                }
                Component.onCompleted: {
                    rows.model = mainWindow.getPraphIds(chartView.viewId).length;
                }
            }
        }
    }
}
