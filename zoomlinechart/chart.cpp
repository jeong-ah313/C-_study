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

#include "chart.h" // 차트
#include <QtWidgets/QGesture> // Qt위젯/Q제스처
#include <QtWidgets/QGraphicsScene> // 그래프장면?
#include <QtWidgets/QGraphicsView> // 그래프보기?

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags) // :: 는 클래스를 의미
    : QChart(QChart::ChartTypeCartesian, parent, wFlags) // :(콜론)은 멤버변수를 의미
{
    // Seems that QGraphicsView (QChartView) does not grab gestures.
    // They can only be grabbed here in the QGraphicsWidget (QChart).
    grabGesture(Qt::PanGesture); // QT의 제스처 처리 기능
    // 핀치제스처: 사용자가 화면의 +, -를 통해 화면 확대/축소를 할 수 있는 기능
    grabGesture(Qt::PinchGesture);
}

Chart::~Chart() // 소멸자
{

}

//![1]
bool Chart::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent *>(event)); // gestureEvent의 event발생
    return QChart::event(event);
}

bool Chart::gestureEvent(QGestureEvent *event) //
{
    // -> 포인터로 요소 선택(화살표 앞에 포인터가 있을 경우 사용)
    if (QGesture *gesture = event->gesture(Qt::PanGesture)) { // 이벤트가 발생 gesture라는..
        QPanGesture *pan = static_cast<QPanGesture *>(gesture); //
        QChart::scroll(-(pan->delta().x()), pan->delta().y()); // 스크롤하면 dx, dy로 지정된 거리만큼 차트의 가시 영역을 스크롤
    }

    if (QGesture *gesture = event->gesture(Qt::PinchGesture)) { //
        QPinchGesture *pinch = static_cast<QPinchGesture *>(gesture);
        if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged) // ScaleFactorChanged가 보유한 스케일팩터가 변경
            QChart::zoom(pinch->scaleFactor()); // 제스처가 발생한 위치에서 zoom 기능 발생
    }

    return true;
}
//![1]
