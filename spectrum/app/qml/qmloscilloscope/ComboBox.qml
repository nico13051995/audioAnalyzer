import QtQuick 2.3

Item {
    width:comboBox.width;
    height: comboBox.height;


    Item {
            id:comboBox
            property variant items: ["Item 1", "Item 2", "Item 3"]
            property alias selectedItem: chosenItemText.text;
            property alias selectedIndex: listView.currentIndex;
            signal comboClicked;
            width: 100;
            height: 30;
            smooth:true;
            focus: true
            onFocusChanged: {
                if(focus == false)
                    comboBox.state = "";
            }

            Rectangle {
                id:chosenItem
                radius:4;
                width:parent.width;
                height:comboBox.height;
                color: "lightsteelblue"
                smooth:true;
                Text {
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.margins: 8;
                    id:chosenItemText
                    text:comboBox.items[0];
                    font.family: "Arial"
                    font.pointSize: 14;
                    smooth:true
                }

                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        comboBox.state = comboBox.state==="dropDown"?"":"dropDown"
                        comboBox.forceActiveFocus();
                    }
                }
            }

            Rectangle {
                id:dropDown
                width:comboBox.width;
                height:0;
                clip:true;
                radius:4;
                anchors.top: chosenItem.bottom;
                anchors.margins: 2;
                color: "lightgray"

                ListView {
                    id:listView
                    height:parent.height;
                    model: comboBox.items
                    currentIndex: 0
                    delegate: Item{
                        width:comboBox.width;
                        height: comboBox.height;

                        Text {
                            text: modelData
                            anchors.top: parent.top;
                            anchors.left: parent.left;
                            anchors.margins: 5;

                        }
                        MouseArea {
                            anchors.fill: parent;
                            onClicked: {
                                comboBox.state = ""
                                var prevSelection = chosenItemText.text
                                chosenItemText.text = modelData
                                if(chosenItemText.text != prevSelection){
                                    comboBox.comboClicked();
                                }
                                listView.currentIndex = index;
                            }
                        }
                    }
                }
            }

            Component {
                id: highlight
                Rectangle {
                    width:comboBox.width;
                    height:comboBox.height;
                    color: "red";
                    radius: 4
                }
            }

            states: State {
                name: "dropDown";
                PropertyChanges { target: dropDown; height:comboBox.height*comboBox.items.length }
            }

            transitions: Transition {
                NumberAnimation { target: dropDown; properties: "height"; easing.type: Easing.OutExpo; duration: 1000 }
            }
        }
    }
