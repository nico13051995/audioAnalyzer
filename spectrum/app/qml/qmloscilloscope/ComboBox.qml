import QtQuick 2.3
import QtGraphicalEffects 1.0

Item {
    id:comboBox
    property variant items: [{title:"Item 1"}, {title:"Item 2"}, {title:"Item 3"}]
    function selectedIndex(){
        return listView.currentIndex;
    }
    function selectedValue(){
        return comboBox.items[listView.currentIndex];
    }
    function setCurrent(index){
        listView.currentIndex = index;
        if(index == -1)
            return;
        chosenItemText.text = titleLink == null ? comboBox.items[index] : comboBox.items[index][comboBox.titleLink];
    }
    property var titleLink: "title"
    property bool popUp: false
    property var nextState: comboBox.popUp ?  "popUp" : "dropDown"
    property color color: "#1eb98f";
    property color text_color: "#fff";
    signal comboClicked;
    width: 100;
    height: 30;
    smooth:true;
    focus: true

    onPopUpChanged: {

    }

    onStateChanged: {
        if(popUp === true)
        {
            triangle.popUpConfig();
        }
        else
        {
            triangle.popDownConfig();
        }
    }

    onFocusChanged: {
        if(focus == false)
            comboBox.state = "";
    }

    Rectangle {
        id:chosenItem
        radius:4;
        width:parent.width;
        height:comboBox.height;
        color: comboBox.color
        smooth:true;
        clip: true
        Text {
            id:chosenItemText
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.margins: 8;
            text:titleLink == null ? comboBox.items[0] : comboBox.items[0][comboBox.titleLink];
            font.family: "Arial"
           // onTextChanged: font.pointSize = 14/chosenItemText.paintedWidth/chosenItemText.width;
            fontSizeMode: Text.Fit;
             minimumPixelSize: 5;
             font.pixelSize: 24
            color: comboBox.text_color
        }

        MouseArea {
            anchors.fill: parent;
            onClicked: {
                comboBox.state = comboBox.state === comboBox.nextState ?"": comboBox.nextState
                comboBox.forceActiveFocus();
            }
        }
    }

    Item {
        id:dropDownWraper
        width:comboBox.width;
        height:0;
        z:-1
        anchors.top: chosenItem.bottom;
        anchors.margins: -5;
        Rectangle{
            id:dropDown
            clip:true;
            radius:5;
            anchors.fill: parent
            color: comboBox.color
            ListView {
                id:listView
                anchors.fill: parent
                model: comboBox.items
                currentIndex: 0
                clip: true
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: dropDown
                }
                delegate: Rectangle{
                    id: elm
                    width:(comboBox.width - text.paintedWidth < 0) ? text.paintedWidth : comboBox.width;

                    height: comboBox.height;
                    color: comboBox.color
                    SequentialAnimation {
                        id: animation
                        loops: Animation.Infinite
                        NumberAnimation {target:elm; property: "x"; from: 0; to: (comboBox.width - text.paintedWidth < 0) ? (comboBox.width - text.paintedWidth) : 0 ; duration: 1000;}
                        PauseAnimation { duration: 1000 }
                        NumberAnimation {target:elm; property: "x"; to: 0; from: (comboBox.width - text.paintedWidth < 0) ? (comboBox.width - text.paintedWidth) : 0 ; duration: 1000;}
                        PauseAnimation { duration: 1000 }
                    }

                    Text {
                        id: text
                        text: titleLink == null ? modelData : modelData[comboBox.titleLink];


                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: comboBox.text_color
                    }
                    MouseArea {
                        id: mouse
                        anchors.fill: parent;
                        hoverEnabled: true
                        onClicked: {
                            comboBox.state = ""
                            var prevSelection = chosenItemText.text
                            chosenItemText.text = text.text;
                            listView.currentIndex = index;
                            if(chosenItemText.text != prevSelection){
                                comboBox.comboClicked();
                            }
                        }
                        onEntered: {
                            parent.color.g = comboBox.color.g*0.8;
                            parent.color.r = comboBox.color.r*0.8;
                            parent.color.b = comboBox.color.b*0.8;
                            animation.start();
                        }
                        onExited: {
                            animation.stop();
                            parent.color = comboBox.color;
                        }
                    }
                }
            }
        }

        Item {
            id : triangle
            width: 10
            height: 10
            clip : true


            function popUpConfig(){
                anchors.centerIn = undefined;
                state = "moved";
                triangle.anchors.top = undefined;
                triangle.anchors.bottom = parent.bottom;
                triangle.anchors.right = parent.right;
                triangle.anchors.rightMargin =  10;
                triangle.anchors.bottomMargin = -4;
                triangle.rotation = -135;
            }
            function popDownConfig(){
                anchors.centerIn = undefined;
                state = "moved";
                triangle.anchors.top = parent.top;
                triangle.anchors.right = parent.right;
                triangle.anchors.topMargin = -4;
                triangle.anchors.rightMargin =  10;
                triangle.rotation =45;
            }
            // The index of corner for the triangle to be attached
            property int corner : 0;
            property alias color : rect.color

            Rectangle {
                x : triangle.width * ((triangle.corner+1) % 4 < 2 ? 0 : 1) - width / 2
                y : triangle.height * (triangle.corner    % 4 < 2 ? 0 : 1) - height / 2
                id : rect
                color : comboBox.color
                antialiasing: true
                width : Math.min(triangle.width,triangle.height)
                height : width
                transformOrigin: Item.Center
                rotation : 45
                scale : 1.414
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

    Component.onCompleted: {
        triangle.popDownConfig();
    }

    states: [State {
            name: "dropDown";
            PropertyChanges { target: dropDownWraper; height:comboBox.height*comboBox.items.length}
            PropertyChanges { target: dropDownWraper; anchors.topMargin: 8}
        },
        State {
            name: "popUp"
            PropertyChanges { target: dropDownWraper; height:comboBox.height*comboBox.items.length }
            PropertyChanges { target: dropDownWraper; anchors.topMargin:-dropDown.height - chosenItem.height - 10}
        }]

    transitions: Transition {
        NumberAnimation { target: dropDownWraper; properties: "height"; easing.type: Easing.OutExpo; duration: 1000 }
        NumberAnimation { target: dropDownWraper; properties: "anchors.topMargin"; easing.type: Easing.OutExpo; duration: 1000 }
    }
}

