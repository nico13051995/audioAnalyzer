import QtQuick 2.0

Item{
    width: parent.width;
    height: 60;
    id: _mediaControlPanel
    property int mode: 0

    function getDate(value){
        var date = new Date();
        date.setFullYear(0);
        date.setMonth(0);
        date.setHours(0);
        date.setMinutes(0);
        date.setSeconds(0);
        date.setMilliseconds(Math.floor(value / (1000) - date.getSeconds()*1000 - date.getMinutes()*60 - date.getHours()*60))
        return date;
    }
    function toMicroseconds(time){
        return time.getHours()*1000*1000*60*60 + time.getMinutes()*1000*1000*60 + time.getSeconds()*1000*1000 + time.getMilliseconds()*1000;
    }
    Connections{
        target: mainWindow
        onModeChanged:{
            console.log("QQQQQQQQQQQQQQQQQQQQ:" + mode);
            _mediaControlPanel.mode = mode;
        }
    }

    Row {
        anchors.fill: parent;
        anchors.margins: 10
        anchors.leftMargin: 10
        Item{
            id :btnContainer
            height: parent.height
            width: childrenRect.width
            Row {
                height: parent.height
                width: childrenRect.width
                spacing: 5
                IconBtn{
                    title: "Open"
                    url: "qrc:/icons/qml/icons/ic_perm_camera_mic_white_48px.svg"
                    onClick: mainWindow.showFileDialog();
                }
                IconBtn{
                    id :playState
                    title: "Play/resume"
                    url: "qrc:/icons/qml/icons/ic_play_arrow_white_48px.svg"
                    urlChecked: "qrc:/icons/qml/icons/ic_pause_circle_outline_white_48px.svg"
                    checkable: true
                    checked: false
                    visible:  _mediaControlPanel.mode == 2
                    onClick: function(){
                        mainWindow.play_pause();
                    }
                }
                IconBtn{
                    id :stopState
                    title: "Play/resume"
                    url: "qrc:/icons/qml/icons/ic_stop_circle_outline_white_48px.svg"
                    checkable: false
                    visible: playState.checked
                    onClick: function(){
                        playState.checked = false;
                        mainWindow.stop();
                    }
                }
                Rectangle{
                    visible:  _mediaControlPanel.mode == 2
                    height: parent.height*.8
                    y: parent.height*.1
                    width: 2
                    color: "white"
                }
                ComboBox{
                    id: filter
                    //height: parent.height
                    items: mainWindow.getTemplatesQML();
                    visible:  _mediaControlPanel.mode == 2
                    titleLink: null
                    popUp: true
                    onComboClicked: {
                        mainWindow.changePlayTemplate(filter.selectedValue());
                    }
                    Text{
                        text: "Поточний фільтр"
                        color: "white"
                        anchors.top: parent.bottom
                        font.pointSize: btnContainer.height - parent.height
                        x: (parent.width - paintedWidth)/2
                    }
                }
                IconBtn{
                    id :saveDump
                    title: "Save dump"
                    url: "qrc:/icons/qml/icons/ic_save_white_48px.svg"
                    checkable: false
                    visible:  _mediaControlPanel.mode == 2
                    onClick: function(){
                        mainWindow.saveDump();
                    }
                }

            }
        }
        Item{
            id :playPositionContainer
            height: parent.height
            width: parent.width - btnContainer.width
            visible:  _mediaControlPanel.mode == 2
            Row{
                id: timeLine
                anchors.fill: parent
                ProgressBar{
                    id: playPosition
                    height: parent.height
                    width: parent.width - timeEditor.width - fullTime.width - 20
                    min:0
                    max: mainWindow.getDuration()
                    value: mainWindow.getTimePosition()
                    property date timeContainer: getDate(0)
                    onStartChangeValue: {
                        playPositionTimer.running = false;
                        if(playState.checked)
                            mainWindow.play_pause();
                    }
                    onUserChangeValue: {
                        mainWindow.setTimePosition(value);
                        if(playState.checked)
                            mainWindow.play_pause();
                        playPositionTimer.running = true;
                    }
                    onVirtualValueChanged: {
                        playPosition.timeContainer = getDate(playPosition.virtualValue);//????
                    }

                    Timer{
                        id: playPositionTimer
                        interval: 20
                        repeat: true
                        running: true
                        onTriggered: {
                            playPosition.max = mainWindow.getDuration();
                            playPosition.value = mainWindow.getTimePosition()

                        }
                    }
                }
                /*************************
                  * 1000000
                *************************/
                // playPosition.value

                TimeEdit{
                    id: timeEditor
                    time: playPosition.timeContainer
                    textFont.pixelSize: 18 //parse problem NOT WARNING!!!
                }
                Text{
                    anchors.verticalCenter: parent.verticalCenter
                    color: timeEditor.textColor
                    font: timeEditor.textFont
                    text: " / "
                }
                TimeEdit{
                    id: fullTime
                    textColor: timeEditor.textColor
                    textFont: timeEditor.textFont
                    time: getDate(playPosition.max);
                }
            }


        }
    }
}

