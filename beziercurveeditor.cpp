#include "beziercurveeditor.h"

#include <QPainter>

BezierCurveEditor::BezierCurveEditor(QWidget *parent)
    : QWidget(parent)
    , m_blackPen(Qt::black)
    , m_redPen(Qt::red)
    , m_yellowPen(Qt::yellow)
    , m_blackBrush(Qt::black)
    , m_redBrush(Qt::red)
    , m_yellowBrush(Qt::yellow)
{
    m_blackPen.setWidth(2);
    m_redPen.setWidth(2);
}

BezierCurveEditor::~BezierCurveEditor()
{

}

void BezierCurveEditor::resizeEvent(QResizeEvent *)
{
    m_startPoint = QPointF(20, height() - 20);
    m_endPoint   = QPointF(width() - 20, 20);

    m_controlPoint2 = QPointF(20, 20);
    m_controlPoint1 = QPointF(width() - 20, height() - 20);
}

void BezierCurveEditor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(m_blackPen);
    QPainterPath path;
    path.moveTo(m_startPoint);
    path.cubicTo(m_controlPoint1, m_controlPoint2, m_endPoint);
    painter.drawPath(path);

    painter.setPen(m_yellowPen);
    painter.setBrush(m_yellowBrush);
    painter.drawEllipse(m_startPoint, 6, 6);
    painter.drawEllipse(m_endPoint, 6, 6);

    painter.setPen(m_redPen);
    painter.setBrush(m_redBrush);
    painter.drawEllipse(m_controlPoint1, 6, 6);
    painter.drawEllipse(m_controlPoint2, 6, 6);

}

