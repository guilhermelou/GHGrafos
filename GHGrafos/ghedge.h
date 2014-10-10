#ifndef GHEdge_H
#define GHEdge_H

#include <QObject>
#include <QColor>
#include <QLine>
#include <QPainter>
#include <QPen>
#include <qmath.h>
class GHNode;

class GHEdge : public QObject
{
    Q_OBJECT
public:
    explicit GHEdge(QObject *parent = 0);
    explicit GHEdge(int weight, QObject *parent = 0);

    enum SELECTION{NOT_SELECTED = 0,SELECTION_IMMINENT,SELECTED,
                   SELECTION_NODE_IMMINENT};
    GHNode* getStartNode();
    GHNode* getEndNode();
    QLine* getLine();
    QColor* getColor();
    int getArrowWidth();
    void setSelection(GHEdge::SELECTION selection);
    GHEdge::SELECTION getSelection();
    void setStartNode(GHNode* startnode);
    void setEndNode(GHNode* endnode);
    void setLine(QLine* line);
    void setColor(QColor* color);
    void setArrowWidth(int);
    void setWeight(int weight);
    int getWeight();


    void drawArrow(QImage *imgview);
    static void drawArrow(GHEdge *arrow, QImage *imgview);
    static void calculateArrow(GHEdge *arrow, QPoint *points);
signals:
    
public slots:
private:
    GHNode *startnode;
    GHNode *endnode;
    QLine *line;
    QColor *color;
    int arrowwidth;
    GHEdge::SELECTION selection;
    int weight;
};

#endif // GHEdge_H
