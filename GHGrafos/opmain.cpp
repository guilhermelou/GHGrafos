#include "opmain.h"
#include <QFileDialog>
OpMain::OpMain(QObject *parent) :
    QObject(parent)
{    
}
void OpMain::startProgram()
{    
    initOBjects();
    viewmain->showMaximized();
   // GHGrafo *ghgrafo = new GHGrafo(GHGrafo::NOT_ORIENTED);
//    QString path  = QFileDialog::getOpenFileName(NULL,"Abrir Arquivo de texto",NULL);
//    ghgrafo= new GHGrafo(path,GHGrafo::ORIENTED);
//    GHNode *node1 = new GHNode("1");
//    GHNode *node2 = new GHNode("2");
//    GHNode *node3 = new GHNode("3");
//    GHNode *node4 = new GHNode("4");
//    GHNode *node5 = new GHNode("5");


//    GHEdge *edge1 = new GHEdge(5);
//    GHEdge *edge2 = new GHEdge(4);
//    GHEdge *edge3 = new GHEdge(3);
//    GHEdge *edge4 = new GHEdge(2);
//    GHEdge *edge5 = new GHEdge(1);

//    edge1->setStartNode(node1);
//    edge1->setEndNode(node2);
//    node1->getArrowList()->append(edge1);
//    node2->getArrowList()->append(edge1);

//    edge2->setStartNode(node2);
//    edge2->setEndNode(node3);
//    node2->getArrowList()->append(edge2);
//    node3->getArrowList()->append(edge2);

//    edge3->setStartNode(node3);
//    edge3->setEndNode(node4);
//    node3->getArrowList()->append(edge3);
//    node4->getArrowList()->append(edge3);

//    edge4->setStartNode(node4);
//    edge4->setEndNode(node5);
//    node4->getArrowList()->append(edge4);
//    node5->getArrowList()->append(edge4);

//    edge5->setStartNode(node5);
//    edge5->setEndNode(node1);
//    node5->getArrowList()->append(edge5);
//    node1->getArrowList()->append(edge5);

//    ghgrafo->getGHNodeList()->append(node1);
//    ghgrafo->getGHNodeList()->append(node2);
//    ghgrafo->getGHNodeList()->append(node3);
//    ghgrafo->getGHNodeList()->append(node4);
//    ghgrafo->getGHNodeList()->append(node5);

    //ghgrafo->deepSearch(node2);
//    ghgrafo->printMatrizAdjacency(viewmain->getTableWidget1());
//    ghgrafo->breadthSearch(node1);
    //ghgrafo->kruskal();
    //qDebug()<<"opa";
    //ghgrafo->prim(ghgrafo->findByName("1"));
    //ghgrafo->printAdjacentList();
}

void OpMain::initOBjects()
{
    viewmain = new ViewMain();
}

void OpMain::settingView()
{
    //opdraw->setViewMain(viewmain);
}
void OpMain::connectingObjects()
{
//    connect(viewmain,SIGNAL(mouseMove(QMouseEvent*)),opdraw,SLOT(mouseMove(QMouseEvent*)));
//    connect(viewmain,SIGNAL(mousePress(QMouseEvent*)),opdraw,SLOT(mousePress(QMouseEvent*)));
//    connect(viewmain,SIGNAL(mouseRelease(QMouseEvent*)),opdraw,SLOT(mouseRelease(QMouseEvent*)));
//    connect(viewmain,SIGNAL(resize(QResizeEvent*)),opdraw,SLOT(resize(QResizeEvent*)));
}

void OpMain::exitProgram()
{   
    exit(1);
}
