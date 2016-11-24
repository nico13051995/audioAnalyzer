import QtQuick 2.7

Rectangle
{
    id: _modalWindow
    parent: root
    color: "#bb000000"
    anchors.fill: parent
    visible: hide.content == null ? false : true
    z:12
    property bool closable: true
    function close(){
        hide.content = null;
        _modalWindow.hideEvent();
    }
    function show(item)
    {
        hide.content = item;
    }
    signal showEvent;
    signal hideEvent;

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            _modalWindow.forceActiveFocus();
            mouse.accepted = false
        }
    }

    Item{
        id : hide
        property Item content: null
        onContentChanged: {
            if(content != null)
                content.parent = realContent;
        }
    }

    Item {
        id: realContent
        width: hide.content == null ? 0 : hide.content.width
        height: hide.content == null ? 0 : hide.content.height
        y: parent.height/2 - height/2
        x: parent.width/2 - width/2
        function close(){
            _modalWindow.close();
            _modalWindow.hideEvent();
        }

        Item{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: -height*0.7
            clip: true
            width: 50
            height: width
            enabled: closable
            visible: closable
            z: 22
            IconBtn{
                url: "qrc:/icons/qml/icons/ic_cancel_white_48px.svg"
                onClick: {close();}
            }
        }

    }

}
