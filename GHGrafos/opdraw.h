#ifndef OPDRAW_H
#define OPDRAW_H

#include <QObject>
#include <QMouseEvent>
#include "viewmain.h"

#include "egarrow.h"
#include "eglogicstruct.h"
#include "egnode.h"
#include "egnodequestion.h"
#include <qmath.h>
#include <QResizeEvent>
#include <modelegnodelist.h>
class OpDraw : public QObject
{
    Q_OBJECT
public:
    explicit OpDraw(QObject *parent = 0);
    enum MODE{NODE=0,ARROW};    
    OpDraw::MODE getMode();
    void setMode(OpDraw::MODE mode);

    void drawNode(EGNode *node, QImage *imgview);
    void drawNodes();// function to draw the list of arrows connected to nodes
    void drawArrow(EGArrow *arrow,QImage *imgview);
    void drawArrows();
    void drawScene();

    void setViewMain(ViewMain *viewmain);

    int isInsideOfNode(QPoint point);
    int isInsideOfNode(QPoint point, int startindex);
    void drawCurrentNode();
    void drawCurrentArrow();
    void calculateArrow(EGArrow *arrow, QPoint *points);
    static QImage *resizeImage(QSize size, QImage *img);
    //QList<EGArrow *> getExercArrowList();
    //void recalculateArrow(EGArrow *arrow, QPoint p1, QPoint p2);
    //void recalculateArrows(EGNode *node);
signals:
    //mouseMoving
    //mousePressing
    //mousePress
    //mouseRelease

    //arrowMode
    //nodeMode
    //currentArrow
    //currentNode

    //moving    
    void mouseMovingNodeMode();
    void mouseMovingCurrentArrow();
    void mouseMovingCurrentNode();
    void mouseMovingOverNode(int nodeindex);
    void mouseMovingNodeModeOverFreeSpace();
    void mouseMovingOverArrow(EGArrow*);
    void mouseMovingArrowModeOverFreeSpace();
    void mouseMovingArrowMode();
    //pressing
    void mousePressingArrowMode();
    void mousePressingNodeMode();
    void mousePressingCurrentArrow();
    void mousePressingCurrentNode(QMouseEvent *);
    void mousePressingArrowOverNode(QMouseEvent *, int );
    void mousePressingArrowOverFreeSpace(QMouseEvent *);
    void mousePressingNodeOverArrow(EGArrow*);
    void mousePressingNodeOverNode(QMouseEvent *, int );
    void mousePressingNodeOverFreeSpace(QMouseEvent *);
    //press
    void mousePressArrowModeOverNode(QMouseEvent *, int );
    void mousePressNodeModeOverNode(QMouseEvent *, int );
    void mousePressNodeModeOverFreeSpace();
    void mousePressArrowMode();
    void mousePressNodeMode();
    void mousePressCurrentArrow();
    void mousePressCurrentNode();
    void mousePressArrowModeOverArrow(EGArrow*);
    void mousePressArrowModeOverFreeSpace();
    //release
//    void mouseReleaseArrowMode();
//    void mouseReleaseNodeMode();
//    void mouseReleaseCurrentArrow();
//    void mouseReleaseCurrentNode();
//    void mouseReleaseArrowOverNode();
//    void mouseReleaseNodeOverArrow();
//    void mouseReleaseNodeOverNode();

    void mouseReleaseArrowOverStartNode();
    void mouseReleaseArrowOverEndNode(int);
    void mouseReleaseArrowOverNode();
    void mouseReleaseArrowOverFreeSpace();
    void mouseReleaseNodeOverNode(int);
    void mouseReleaseNodeOverArrow(EGArrow*);
    void mouseReleaseNodeOverFreeSpace();
    void mouseReleaseCurrentNode();
    void mouseReleaseNodeMode();

public slots:
    void mousePress(QMouseEvent *event);
    void mouseMove(QMouseEvent *event);
    void mouseRelease(QMouseEvent *event);
    void resize(QResizeEvent *event);

    void pressingCurrentArrow();
    void pressingArrowOverFreeSpace(QMouseEvent *event);
    void pressingArrowOverNode(QMouseEvent *, int );
    //-------------------------------
    void pressingCurrentNode(QMouseEvent *event);
    void pressingNodeOverNode(QMouseEvent *event, int index);
    void pressingNodeOverFreeSpace(QMouseEvent *event);
    void pressingNodeOverArrow(EGArrow*);
    //-----------------------------
    void movingOverNode(int);
    void movingNodeModeOverFreeSpace();
    void movingNodeMode();
    void movingOverArrow(EGArrow *);
    void movingArrowModeOverFreeSpace();
    //void movingNodeModeOverFreeSpace();
    void movingArrowMode();
    //---------------------
    void pressArrowModeOverNode(QMouseEvent *event, int nodeindex);
    void pressNodeModeOverNode(QMouseEvent *event, int nodeindex);
    void pressNodeModeOverFreeSpace();
    void pressArrowModeOverArrow(EGArrow*);
    void pressArrowModeOverFreeSpace();
    //------------------------------
    void releaseArrowOverNode();
    void releaseArrowOverStartNode();
    void releaseArrowOverEndNode(int nodeindex);
    void releaseArrowOverFreeSpace();
    void releaseNodeOverNode(int nodeindex);
    void releaseNodeOverArrow(EGArrow *arrowaux);
    void releaseNodeOverFreeSpace();
    void releaseCurrentNode();
    void releaseNodeMode();
private:
    bool drag;
    ViewMain *viewmain;
    //QList<EGNode*> listnode;
    ModelEGNodeList *modelegnodelist;
    EGArrow *currentarrow;
    EGNode *currentnode;
    QPoint mousepresspos;
    OpDraw::MODE mode;
    
};

#endif // OPDRAW_H
