#ifndef VIEWMAIN_H
#define VIEWMAIN_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintDevice>
#include <QPaintEvent>
#include <QTableWidget>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QFileDialog>
#include "groupboxoption.h"
#include "ghgrafo.h"
class ViewMain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ViewMain(QWidget *parent = 0);    
    ~ViewMain();
    void resizeEvent(QResizeEvent *);
    void updatePresentations();
//    void paintEvent(QPaintEvent *);
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    QImage* getImgCurrentArrow();
//    void setImgCurrentArrow(QImage*currentarrow);
//    QImage *getImgPolygonList();
//    void setImgPolygonList(QImage *polygonlist);
//    void setImgArrowList(QImage *imgarrowlist);
//    QImage *getImgArrowList();
//    void setImgCurrentNode(QImage *currentnode);
//    QImage *getImgCurrentNode();
    void createTabWidget();
    QTableWidget *getTableWidget1();
    // QTableWidget *getTableWidget2();
public slots:
    void checkBarrier();
    void openNewFile();

    void deepsearch();

    void deepsearchcolor();

    void breadhsearch();

    void conectivity();

    void prim();

    void kruskal();

    void djkstra();

    void bellmanford();

    void generateTransposed();

    void startNodeChanged(const QString &arg1);

    void finalNodeChanged(const QString &arg1);
signals:
    void mouseMove(QMouseEvent *event);
    void mousePress(QMouseEvent *event);
    void mouseRelease(QMouseEvent *event);
    void resize(QResizeEvent *event);
private:
    QImage *imgcurrentarrow, *imgpolygonlist, *imgarrowlist, *imgcurrentnode;
    QTabWidget *tabwidget;
    QTableWidget *tablewidget1;//, *tablewidget2;
    QPushButton *btnloadfile;/*,*btndeepsearch, *btnbreadthsearch, *btnconectivity,*/
//                *btnprim,*btnkruskal,*btndijkstra,*btnbellmanford;
//    QComboBox *cbxstartnode,cbxfinalnode;
//    QLabel *lblobsfinalnode;
    GroupBoxOption *grboption;
    QLabel *lblresult;
    QLabel *lblfile;
    QLabel *lbladjacentlist;
    GHGrafo* ghgrafo;
};

#endif // VIEWMAIN_H
