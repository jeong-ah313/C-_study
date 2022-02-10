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

#include "chartview.h"
#include <QtGui/QMouseEvent>

ChartView::ChartView(QChart *chart, QWidget *parent) :
    QChartView(chart, parent),
    m_isTouching(false) // 멤버변수
{
    // 러벌밴드 설정
    __super::setRubberBand(QChartView::RectangleRubberBand);
}

bool ChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

// 마우스 누를떄 이벤트
void ChartView::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mousePressEvent(event);
}

// 마우스 움직임 이벤트
void ChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mouseMoveEvent(event);
}

// 마우스 뗼 ㄸㅐ 이벤트
void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);

    QChartView::mouseReleaseEvent(event);
}

// 키 누를 ㄸㅐ 이벤트
void ChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn(); // 플러스 키를 누를 ㄸㅐ, 차트 줌인
        break;
    case Qt::Key_Minus:
        chart()->zoomOut(); // 마이너스 ㅋㅣ를 누를 ㄸㅐ. 차트 줌아웃
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0); // 왼ㅉㅗㄱ키를 누를ㄸㅐ, 스크롤의 x값이 왼ㅉㅗㄱ으로 10만큼 이동
        // 차트 왼ㅉㅗㄱ으로 10만큼
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0); // 오른ㅉㅗㄱ 키를 누를ㄸㅐ, 차트 오른ㅉㅗㄱ으로 10만큼 이동
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10); // 위ㅉㅗㄱ 키를 누를 ㄸㅐ, 차트 위ㅉㅗㄱ으로 10만큼 이동
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10); // 아래ㅉㅗㄱ 키를 누를 ㄸㅐ, 차크 아래ㅉㅗㅅ으로 10만큼 이동
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}
