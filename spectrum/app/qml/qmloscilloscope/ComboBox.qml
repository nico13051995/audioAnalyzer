import QtQuick 2.3
Item {
    id:comboBox
    property variant items: [{title:"Item 1"}, {title:"Item 2"}, {title:"Item 3"}]
    function selectedIndex(){
        return listView.currentIndex;
    }
    function setCurrent(index){
        listView.currentIndex = index;
    }
    property var titleLink: "title"
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
            text:titleLink == null ? comboBox.items[0] : comboBox.items[0][comboBox.titleLink];
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
                    id: text
                    text: titleLink == null ? modelData : modelData[comboBox.titleLink];
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.margins: 5;

                }
                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        comboBox.state = ""
                        var prevSelection = chosenItemText.text
                        chosenItemText.text = text.text;
                        listView.currentIndex = index;
                        if(chosenItemText.text != prevSelection){
                            comboBox.comboClicked();
                        }
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

