#include "beziercurveeditor.h"

#include <QPainter>
#include <QMouseEvent>

BezierCurveEditor::BezierCurveEditor(QWidget *parent)
    : QWidget(parent)
    , m_curvePen(Qt::black)
    , m_dragging(false)
{
    m_curvePen.setWidth(2);

    m_colors[0] = Qt::yellow;
    m_colors[1] = Qt::red;
    m_colors[2] = Qt::blue;
    m_colors[3] = Qt::yellow;

    for (int i = 0; i < NUM_POINTS; i++) {
        m_pens[i]    = QPen(m_colors[i]);
        m_brushes[i] = QBrush(m_colors[i]);
    }
}

BezierCurveEditor::~BezierCurveEditor()
{

}

void BezierCurveEditor::mousePressEvent(QMouseEvent *event)
{
    for(int i = 0; i < NUM_POINTS; i++) {
        if(distance(m_points[i], event->pos()) <= POINT_RADIUS) {
            m_selectedPoint = i;
            m_dragging = true;
            break;
        }
    }
}

void BezierCurveEditor::mouseMoveEvent(QMouseEvent *event)
{
    if(m_dragging) {
        m_points[m_selectedPoint] = event->pos();
    }
    update();
}

void BezierCurveEditor::mouseReleaseEvent(QMouseEvent *)
{
    m_dragging = false;
}

void BezierCurveEditor::resizeEvent(QResizeEvent *)
{
    m_points[StartPoint]    = QPointF(20, height() - 20);
    m_points[ControlPoint1] = QPointF(width() - 20, height() - 20);
    m_points[ControlPoint2] = QPointF(20, 20);
    m_points[EndPoint]      = QPointF(width() - 20, 20);
}

void BezierCurveEditor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(m_curvePen);
    QPainterPath path;
    path.moveTo(m_points[StartPoint]);
    path.cubicTo(m_points[ControlPoint1], m_points[ControlPoint2], m_points[EndPoint]);
    painter.drawPath(path);

    for (int i = 0; i < NUM_POINTS; i++) {
        painter.setPen(m_pens[i]);
        painter.setBrush(m_brushes[i]);
        painter.drawEllipse(m_points[i], POINT_RADIUS, POINT_RADIUS);
    }
}

