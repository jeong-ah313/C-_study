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

#include "chart.h"
#include "chartview.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QtMath>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // line 시리즈 객체를 생성한다.
    QLineSeries *series = new QLineSeries(); // heap
//    QLineSeries series2; // stack
//    *series == QLineSeries

    // 500개의 랜덤 포인트를 시리즈 객체에 삽입한다.
    for (int i = 0; i < 500; i++) {
        //
        QPointF point((qreal) i, qSin(M_PI / 50 * i) * 100);
        point.ry() += QRandomGenerator::global()->bounded(20);
        *series << point; // operator
//        series->append(p); // method, function
    }

    // 차트 객체를 생성
    Chart *chart = new Chart(); // c++
//    Chart chart = new Chart(); // java
//    chart = Chart() // python
//    let chart = new Chart(); // javascript

    // 차트에 시리즈를 추가
    chart->addSeries(series);
    ((QLineSeries*)chart->series()[0])->append(QPointF(0, 0));
    series->append(QPointF(0, 0));

    // 차트에 제목 설정
    chart->setTitle("Zoom in/out example");
    // 차트에 애니메이션 옵션 설정
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 차트의 범례를 숨긴다.
    chart->legend()->hide();

    // 차트의 기본 축들을 생성
    chart->createDefaultAxes();

    // 차트뷰 객체 생성
    ChartView *chartView = new ChartView(chart);
    // 차트뷰에 render힌트 설정
    chartView->setRenderHint(QPainter::Antialiasing);

    //
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.grabGesture(Qt::PanGesture);
    window.grabGesture(Qt::PinchGesture);
    window.show();

    return a.exec();
}
