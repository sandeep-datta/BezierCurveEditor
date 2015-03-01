#ifndef BEZIERCURVEEDITOR_H
#define BEZIERCURVEEDITOR_H

#include <QPen>
#include <QBrush>
#include <QWidget>

class BezierCurveEditor : public QWidget
{
    Q_OBJECT
public:
    explicit BezierCurveEditor(QWidget *parent = 0);
    ~BezierCurveEditor();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
signals:

public slots:

private:
    QPointF     m_controlPoint1;
    QPointF     m_controlPoint2;
    QPointF     m_startPoint;
    QPointF     m_endPoint;

    QPen        m_blackPen;
    QPen        m_redPen;
    QPen        m_yellowPen;

    QBrush      m_blackBrush;
    QBrush      m_redBrush;
    QBrush      m_yellowBrush;

};

#endif // BEZIERCURVEEDITOR_H
