import QtQuick 2.0

Item {
    id: _iconBtn
    y: (parent.height - height)/2
    height: parent.height*0.8
    width: height
    property string title: "title"
    property string url: "qrc:/icons/qml/icons/ic_build_white_48px.svg"
    property string urlChecked: "qrc:/icons/qml/icons/ic_build_white_48px.svg"
    property bool checked: false
    property bool checkable: false
    signal click;
    Image {
        id: icon
        source: _iconBtn.checked ? urlChecked : url
        scale: 0.8
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        Behavior on scale {
            NumberAnimation {
                id: bouncebehavior
                easing {
                    type: Easing.OutElastic
                    amplitude: 1.0
                    period: 1.0
                }
            }
        }
    }
    MouseArea{
        anchors.fill: parent;
        hoverEnabled: true;
        onClicked: {
            if(_iconBtn.checkable)
            {
                _iconBtn.checked = !_iconBtn.checked;
            }
            _iconBtn.click();
        }
        onEntered: {
            icon.scale = 1.0;
        }
        onExited: {
            icon.scale = 0.8;
        }
    }
}

