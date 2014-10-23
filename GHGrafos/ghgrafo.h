#ifndef GHGrafo_H
#define GHGrafo_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QTableWidget>
#include "ghnode.h"
#include "utils.h"
class GHGrafo : public QObject
{
    Q_OBJECT
public:
    enum GRAFOTYPE{NOT_ORIENTED=0,ORIENTED};
    explicit GHGrafo(QObject *parent = 0);
    explicit GHGrafo(GHGrafo::GRAFOTYPE type, QObject *parent = 0);
    explicit GHGrafo(QString path,GHGrafo::GRAFOTYPE type, QObject *parent = 0);

    void setGrafoType(GHGrafo::GRAFOTYPE grafotype);
    GHGrafo::GRAFOTYPE getGrafoType();

    QList<GHNode*> * getGHNodeList();
    void setGHNodeList( QList<GHNode*> *GHNodelist);
    int getIndexOfNodeSelected(GHNode::SELECTION selection, int from=0);
    QList<GHNode *> getListNodeSelected(GHNode::SELECTION selection);
    int isInsideOfNode(QPoint point);
    int isInsideOfNode(QPoint point, int startindex);
    GHEdge *isInsideOfArrow(QPoint point);
    static void drawNodes(QList<GHNode*> nodelist,QImage *imgview);
    void drawNodes(QImage *imgview);
    QList<GHNode *> getRoots();
    QList<GHEdge *> getAllArrows();
    static void setNodeListSelection(QList<GHNode*> nodelist,GHNode::SELECTION selection);
    void setNodeListSelection(GHNode::SELECTION selection);
    static void setArrowListSelection(QList<GHEdge *> arrowlist, GHEdge::SELECTION selection);
    QList<GHEdge*> getListArrowSelected(GHEdge::SELECTION selection);
    void printMatrizAdjacency(QTableWidget *tablewidget);
    QString printAdjacentList();
    void deepFirstSearch(GHNode *node, int *time);
    QString deepSearch(GHNode *firstNode);
    QString breadthSearch(GHNode *firstnode);
    QString kruskal();
    QString prim(GHNode *firstnode);
    GHNode* findByName(QString name);
    void connectNodes(GHNode *ghnode1, GHNode *ghnode2, int weight);

    bool hasEdge(GHEdge *edge);
    bool hasNode(GHNode *node);

    QString checkConectivity();
    void checkAdjacentsConectivity(QList<GHNode *> *conectedNodes, GHNode *node);
    GHNode *extractMin(QList<GHNode *> *list);
    void initializes(GHNode *node);
    void relax(GHNode *u, GHNode *v, GHEdge *edge);

    QString bellmanford(GHNode *s);
    QString dijsktra(GHNode *node);

    QString deepSearchColor();
    void nodesColor(GHNode *node);
    int searchForColor(GHNode *node, int color);

    GHGrafo *generateTranposedGraph();

    GHEdge *findEdgeWith(GHNode *u, GHNode *v);
    GHEdge *findPrimEdgeWith(GHNode *u, GHNode *v);

    QString getFileContent();

    QStringList getVertexNames();
    QList<GHEdge*> getAllEdgeTimes();
signals:
    
public slots:
private:
    QList<GHNode*> *GHNodelist;
    GHGrafo::GRAFOTYPE grafotype;
    int numvertex;
    QString filecontent;

};

#endif // GHGrafo_H
