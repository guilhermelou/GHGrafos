#include "ghedge.h"

GHEdge::GHEdge(QObject *parent) :
    QObject(parent)
{
    this->color = new QColor(Qt::black);
    this->arrowwidth = 8;
    this->line = new QLine();
}

GHEdge::GHEdge(int weight, QObject *parent)
{
    this->color = new QColor(Qt::black);
    this->arrowwidth = 8;
    this->line = new QLine();
    this->weight = weight;
}


GHNode *GHEdge::getStartNode()
{
    return this->startnode;
}

GHNode *GHEdge::getEndNode()
{
    return this->endnode;
}

QLine *GHEdge::getLine()
{
    return this->line;
}

QColor *GHEdge::getColor()
{
    return this->color;
}

int GHEdge::getArrowWidth()
{
    return this->arrowwidth;
}

void GHEdge::setSelection(GHEdge::SELECTION selection)
{
    this->selection = selection;
}

GHEdge::SELECTION GHEdge::getSelection()
{
    return selection;
}


void GHEdge::setStartNode(GHNode *startnode)
{
    this->startnode = startnode;
}

void GHEdge::setEndNode(GHNode *endnode)
{
    this->endnode = endnode;
}

void GHEdge::setLine(QLine *line)
{
    this->line = line;
}

void GHEdge::setColor(QColor *color)
{
    this->color = color;
}

void GHEdge::setArrowWidth(int width)
{
    this->arrowwidth = width;
}

void GHEdge::setWeight(int weight)
{
    this->weight = weight;
}

int GHEdge::getWeight()
{
    return weight;
}
void GHEdge::drawArrow(QImage *imgview)
{
    GHEdge::drawArrow(this,imgview);
}


void GHEdge::drawArrow(GHEdge *arrow, QImage *imgview)
{
    QPainter painter;
    QPen pen;
    pen.setWidth(arrow->getArrowWidth());
    painter.begin(imgview);
    painter.setPen(pen);

    painter.setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform,true);
    painter.drawLine(arrow->getLine()->p1(),arrow->getLine()->p2());
    QPoint triangle[3];
    GHEdge::calculateArrow(arrow,triangle);
    painter.drawPolygon(triangle,3,Qt::WindingFill);
    switch (arrow->getSelection())
    {
    case GHEdge::SELECTED:
        pen.setStyle(Qt::DashLine);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.drawLine(arrow->getLine()->p1(),arrow->getLine()->p2());
        painter.drawPolygon(triangle,3,Qt::WindingFill);
    break;
    case GHEdge::SELECTION_IMMINENT:
        pen.setStyle(Qt::SolidLine);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.drawLine(arrow->getLine()->p1(),arrow->getLine()->p2());
        painter.drawPolygon(triangle,3,Qt::WindingFill);
    break;
    case GHEdge::SELECTION_NODE_IMMINENT:
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.setPen(pen);
        painter.drawLine(arrow->getLine()->p1(),arrow->getLine()->p2());
        painter.drawPolygon(triangle,3,Qt::WindingFill);
    break;
    }
    painter.end();
}
void GHEdge::calculateArrow(GHEdge *arrow, QPoint *points)
{
    int x = arrow->getLine()->p2().x();
    int y = arrow->getLine()->p2().y();
    int YStart = arrow->getLine()->p1().y();
    int XStart = arrow->getLine()->p1().x();
    int arrowwidth = arrow->getArrowWidth();
    qreal angulo = qAtan2(y-YStart, x-XStart);
    qreal PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
    QPoint leftpoint, rightpoint, midpoint;
    leftpoint.setX((int)(x - qCos(PI/2-angulo)*arrowwidth*2));
    leftpoint.setY((int)(y + qSin(PI/2-angulo)*arrowwidth*2));
    rightpoint.setX((int)(x + qCos(PI/2-angulo)*arrowwidth*2));
    rightpoint.setY((int)(y - qSin(PI/2+angulo)*arrowwidth*2));
    midpoint.setX((int)(x + qCos(angulo)*arrowwidth*4));
    midpoint.setY((int)(y + qSin(angulo)*arrowwidth*4));
    points[0] = rightpoint;
    points[1] = leftpoint;
    points[2] = midpoint;
}
