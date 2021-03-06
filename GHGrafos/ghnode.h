#ifndef GHNode_H
#define GHNode_H



#include <QObject>
#include <QImage>
#include "ghedge.h"
#include "eglogicstruct.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>
//class GHEdge;

class GHNode : public QObject
{
    Q_OBJECT
public:
    enum NODETYPE{NODE=0};
    enum SELECTION{NOT_SELECTED=0,SELECTION_IMMINENT,SELECTED,
                   SELECTION_ARROW_IMMINENT};
    enum COLOR{WHITE=0,GRAY,BLACK};


    explicit GHNode(QObject *parent = 0);
    explicit GHNode(QString name,QObject *parent = 0);
    //GHNode(QImage *imgCurrent);
    //GHNode(QImage *imgCurrent, QImage *imgDefault, EGLogicStruct *logicStruct, bool isQuestion, QImage *imgAnchor);


    NODETYPE nodeType();


    //sets
    void setCurrentImage(QImage *img);
    void setDefaultImage(QImage *img);
    void setSelection(GHNode::SELECTION selection);
    void setNodeType(GHNode::NODETYPE node);
    void setArrowList(QList<GHEdge *> *arrowlist);
    //~sets

    //gets
//    QImage *getCurrentImage();
//    QImage *getDefaultImage();
    GHNode::SELECTION getSelection();
    QList <GHEdge*> *getArrowList();

   void  setDistance(int distance);
   int getDistance();

    void setX(int x);
    void setY(int y);
    void setPos(QPoint point);
    int  getX();
    int  getY();
    QPoint getPos();
    QPoint getCenter();
    void setName(QString name);
    QString getName();

    int getTimeD();
    int getTimeF();
    void setTimeD(int time);
    void setTimeF(int time);

    GHNode::COLOR getColor();
    void setColor(GHNode::COLOR color);
    QPoint getCenterBotton();
    QPoint getCenterTop();
    QRect getRect();
    QList<GHEdge *> getArrowsThatEndOnIt();
    QList<GHEdge *> getArrowsThatStartOnIt();
    QList<GHNode *> getChilds();
    QList<GHNode *> getFathers();
    QList<GHNode *> getNodeListByLvl(GHNode *noderoot, int lvl, int i);

    static void drawNode(GHNode *node, QImage *imgview);
    void drawNode(QImage *imgview);
    static void recalculateArrows(GHNode *node);
    void recalculateArrows();
    static void updateCurrentImage(GHNode *node);
    static void removeArrows(QList<GHEdge *> listarrow);
    static void removeArrow(GHEdge *arrow);
    static bool checkNodeAvailable(GHNode *node);
    static void removeAllArrows(GHNode *node);
    static bool searchCyclicReference(GHNode *nodekey, GHNode *nodeaux);
    static bool searchCyclicReference(GHNode *nodekey);
    bool searchCyclicReference();
    static bool searchArrowConnection(GHNode *node1, GHNode *node2);
    static bool searchStartArrowConnection(GHNode *nodestart, GHNode *nodeend);
    static QList<GHNode*> getAdjacentNodes(GHNode *node);
    static QList<GHNode*> getAdjacentOrientedNodes(GHNode *node);

    QString printNodeState();

    void setParent(GHNode *parentnode);
    GHNode* getParent();
    QString getParentName();
    void setKey(int key);
    int getKey();
    void setNumberChanged(bool changed);
    bool getNumberChanged();

    void setColorIndex(int colorindex);
    int getColorIndex();
    bool isBarrier();
    bool isOpen();
    void setIsBarrier(bool isbarrier);
    void setIsOpen(bool isopen);
signals:
    
public slots:

private:
    //QImage *currentImage, *defaultImage;
    GHNode::SELECTION selection;
    GHNode::NODETYPE nodetype;
    GHNode::COLOR nodecolor;
    GHNode *parentnode;
    int x,y;
    QList <GHEdge*> *arrowlist;
    QString name,value;
    int timeD,timeF, distance,key, colorindex;
    bool numberchanged;
    bool barrier;
    bool open;

};

#endif // GHNode_H
