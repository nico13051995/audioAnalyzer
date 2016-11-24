import QtQuick 2.0
import QtGraphicalEffects 1.0

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
        visible: false
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }
    ColorOverlay {
        id: colorVersion
        anchors.fill: icon
        source: icon
        color: "#fff"
        scale: 0.8
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
            colorVersion.scale = 1.0;
        }
        onExited: {
            colorVersion.scale = 0.8;
        }
    }
}

