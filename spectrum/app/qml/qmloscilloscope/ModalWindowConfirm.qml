import QtQuick 2.7
Item{
    id: _modalWindowsConfirm
    property string text: "!!!"
    property var callBack: null
    function show(){
        _modalWindowsConfirmW.show(_modalWindowsConfirmC);
    }
    ModalWindow{
        id: _modalWindowsConfirmW
        closable: false
        Item{
            id: _modalWindowsConfirmC
            width: name.width
            height: childrenRect.height
            Column{
                width: parent.width
                height: childrenRect.height
                spacing: 10
                Text {
                    id: name
                    text: _modalWindowsConfirm.text
                    font.pixelSize: 24
                    height: 24
                    color: "white"
                }
                Row{
                    width: parent.width
                    height: childrenRect.height
                    Rectangle{
                        width: parent.width/2
                        height: 40
                        color: "red"
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                _modalWindowsConfirmC.parent.close();
                            }
                        }
                    }
                    Rectangle{
                        width: parent.width/2
                        height: 40
                        color: "blue"
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                _modalWindowsConfirm.callBack();
                                _modalWindowsConfirmC.parent.close();
                            }
                        }
                    }
                }
            }
        }
    }
}

