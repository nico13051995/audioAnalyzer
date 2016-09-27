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

import QtQuick 2.7
import QtCharts 2.1

//![1]
ChartView {
    id: chartView
    animationOptions: ChartView.NoAnimation
    theme: ChartView.ChartThemeDark
    property bool openGL: true
    antialiasing: false;
    title: "TEST"
    function realResetZoom()
    {
        chartView.zoomReset();
        chartView.scrollUp(0);
        chartView.scrollLeft(0);
        selectArea.reset();
    }

    ModalWindow{
        id: chartSettings
        Item{
            id: chartSettingsC
            property int index: 0
            width: chartSettings.width - 60//50px close btn
            height: chartSettings.height - 60
            function range(min, max){
                var array = [];
                for(var i = min; i <= max; i++)
                    array.push(i);
                return array;
            }
            Row{
                width: parent.width
                height: childrenRect.height
                //filter map
                ComboBox{
                    id: filter
                    items: mainWindow.getTemplatesQML();
                    titleLink: null
                }
                //chanels
                ComboBox{
                    id:chanel
                    items: chartSettingsC.range(0,4);
                    titleLink: null
                }
            }
        }
    }
    Item{
        id: controllPanel
        width: childrenRect.width
        height: parent.height < 48 ? parent.height*0.3 : 48
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        Row{
            width: childrenRect.width
            height: parent.height
            IconBtn{
                url: "qrc:/icons/qml/icons/ic_settings_applications_white_48px.svg"
                onClick: {chartSettings.show(chartSettingsC)}

            }
            IconBtn{
                url: "qrc:/icons/qml/icons/ic_delete_forever_white_48px.svg"
                onClick: {_tabView.addTab();}
            }
        }
    }
    ValueAxis {
        id: axisY1
        property int digitNum: 16
        min: -1 * (Math.pow(2, digitNum - 1))
        max: (Math.pow(2, digitNum - 1))

    }

    ValueAxis {
        id: axisY2
        min: 0
        max: 1
    }

    ValueAxis {
        id: axisX
        min: 0
        max: 22600
    }
    ValueAxis {
        id: axisX2
        min: -1
        max: dataSpectr.getBarNumber()
    }

    LineSeries {
        id: lineSeries1
        name: "signal 1"
        axisX: axisX
        axisY: axisY1
        pointsVisible: true
        useOpenGL: chartView.openGL
        onHovered: function(point){ console.log("onClicked: " + point.x + ", " + point.y)};

    }
    LineSeries {
        id: lineSeries2
        name: "signal 2"
        axisX: axisX
        axisYRight: axisY1
        useOpenGL: chartView.openGL
    }
    ScatterSeries {
        id: myBarSeries
        axisX: axisX2
        axisYRight: axisY2
        useOpenGL: true
        borderColor: "white"
        borderWidth: 20
        markerSize: 16
    }
    //![1]

    //![2]
    /* Timer {
        id: refreshTimer
        interval: 1 / 60 * 1000 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            dataSource.update(chartView.series(0));
            dataSource.update(chartView.series(1));
        }
    }*/
    //![2]

    //![3]
    function changeSeriesType(type) {
        /* chartView.removeAllSeries();

        // Create two new series of the correct type. Axis x is the same for both of the series,
        // but the series have their own y-axes to make it possible to control the y-offset
        // of the "signal sources".
        if (type == "line") {
            var series1 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 1",
                                                 axisX, axisY1);
            series1.useOpenGL = chartView.openGL

            var series2 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 2",
                                                 axisX, axisY2);
            series2.useOpenGL = chartView.openGL
        } else {
            var series1 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 1",
                                                 axisX, axisY1);
            series1.markerSize = 2;
            series1.borderColor = "transparent";
            series1.useOpenGL = chartView.openGL

            var series2 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 2",
                                                 axisX, axisY2);
            series2.markerSize = 2;
            series2.borderColor = "transparent";
            series2.useOpenGL = chartView.openGL
        }*/
    }

    function createAxis(min, max) {
        // The following creates a ValueAxis object that can be then set as a x or y axis for a series
        return Qt.createQmlObject("import QtQuick 2.0; import QtCharts 2.0; ValueAxis { min: "
                                  + min + "; max: " + max + " }", chartView);
    }
    MouseArea {
        id: selectArea;
        anchors.fill: parent;
        acceptedButtons: Qt.AllButtons
        propagateComposedEvents: true
        property point previous: Qt.point(mouseX, mouseY)
        property point scrollPoint
        property double scale: -0.5
        function reset(){
            scrollPoint = Qt.point(0,0);
        }

        onWheel: {
            if (wheel.modifiers & Qt.ControlModifier) {
                chartView.zoom(wheel.angleDelta.y / 1200 + 1)
            }
            wheel.accepted = false;

        }
        onClicked: {
            if(mouse.button == Qt.MiddleButton)
                chartView.realResetZoom();
            mouse.accepted = false;

        }
        onDoubleClicked: {
            if(mouse.button == Qt.LeftButton)
                chartView.realResetZoom();
            mouse.accepted = false;
        }

        onPressed: {
            if(mouse.button == Qt.LeftButton && mouse.modifiers & Qt.ControlModifier)
            {
                if (highlightItem !== null) {
                    // if there is already a selection, delete it
                    highlightItem.destroy ();
                }
                // create a new rectangle at the wanted position
                highlightItem = highlightComponent.createObject (selectArea, {
                                                                     x : mouse.x,  y : mouse.y
                                                                 });
                // here you can add you zooming stuff if you want
            }
            previous = Qt.point(mouseX, mouseY);
            mouse.accepted = true;
        }
        onPositionChanged: {
            // on move, update the width of rectangle
            if (highlightItem !== null) {
                highlightItem.width = (Math.abs (mouse.x - highlightItem.x));
                highlightItem.height = (Math.abs (mouse.y - highlightItem.y));
                if(mouse.x - highlightItem.x > 0)
                {
                    highlightItem.invertX = 1;
                    highlightItem.invertY = 1;
                }
                else
                {
                    highlightItem.invertX = -1;
                    if(mouse.y - highlightItem.y > 0)
                        highlightItem.invertY = 1;
                    else
                        highlightItem.invertY = -1;
                }
            }
            else if(pressedButtons & Qt.LeftButton)
            {
                if(chartView.isZoomed())
                {
                    scrollPoint.x = (previous.x - mouse.x)*scale;
                    scrollPoint.y = (previous.y - mouse.y)*scale;
                    console.log(scrollPoint)
                    if(scrollPoint.y > 0)
                    {
                        chartView.scrollUp(scrollPoint.y);
                        chartView.scrollDown(0);
                    }
                    else{
                        chartView.scrollDown(-scrollPoint.y);
                        chartView.scrollUp(0);
                    }
                    if(scrollPoint.x > 0)
                    {
                        chartView.scrollLeft(scrollPoint.x);
                        chartView.scrollRight(0);
                    }
                    else{
                        chartView.scrollLeft(0);
                        chartView.scrollRight(-scrollPoint.x);
                    }
                }
                previous = Qt.point(mouse.x, mouse.y);
            }

        }
        onReleased: {
            if (mouse.button == Qt.LeftButton && highlightItem !== null) {
                var rect = Qt.rect(highlightItem.x, highlightItem.y, highlightItem.invertX*highlightItem.width, highlightItem.invertY*highlightItem.height);
                //normalization
                if(rect.width < 0)
                {
                    rect.x += rect.width;
                    rect.width *= -1;
                }
                if(rect.height < 0)
                {
                    rect.y += rect.height;
                    rect.height *= -1;
                }
                console.log(rect)
                chartView.zoomIn(rect);
                highlightItem.destroy ();
            }
            mouse.accepted = false;
            // here you can add you zooming stuff if you want
        }

        property Rectangle highlightItem : null;

        Component {
            id: highlightComponent;

            Rectangle {
                property int invertX: 1
                property int invertY: 1
                color: "yellow";
                opacity: 0.35;
                transform : Scale {origin.x: 0; origin.y: 0; xScale: invertX; yScale: invertY}
            }
        }
    }


    Component.onCompleted:{
        dataSource.subscribeSeries(chartView.series(0), 0);
        dataSource.subscribeSeries(chartView.series(1), 1);
        dataSpectr.subsctibeChart(myBarSeries);
    }
}
