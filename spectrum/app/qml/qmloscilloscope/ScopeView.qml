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

import QtQuick 2.0
import QtCharts 2.1

//![1]
ChartView {
    id: chartView
    animationOptions: ChartView.NoAnimation
    theme: ChartView.ChartThemeDark
    property bool openGL: true
    antialiasing: false;
    ModalWindow{
        id: chartSettings
        Item{
            id: chartSettingsC
            property int index: 0
            width: chartSettings.width - 60//50px close btn
            height: chartSettings.height - 60

            ComboBox{

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

    Component.onCompleted:{
        dataSource.subscribeSeries(chartView.series(0), 0);
        dataSource.subscribeSeries(chartView.series(1), 1);
        dataSpectr.subsctibeChart(myBarSeries);
    }
}
