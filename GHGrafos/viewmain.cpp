#include "viewmain.h"

ViewMain::ViewMain(QWidget *parent) :
    QMainWindow(parent)
{   
    createTabWidget();
}

ViewMain::~ViewMain()
{
}

QTableWidget *ViewMain::getTableWidget1()
{
    return tablewidget1;
}

void ViewMain::createTabWidget()
{
    btnloadfile = new QPushButton("Abrir Arquivo",this);
    btnloadfile->setGeometry(0,10,this->width(),80);
    connect(btnloadfile,SIGNAL(clicked()),this,SLOT(openNewFile()));

    grboption = new GroupBoxOption(this);
    grboption->setGeometry(0,100,this->width(),this->height()/2 - 100);
    tabwidget = new QTabWidget(this);
    tabwidget->setGeometry(0,(this->height()/2),this->width(),this->height()/2);
    tabwidget->setMovable(true);
    tabwidget->setTabShape(QTabWidget::Triangular);
    tabwidget->setStyleSheet("font: bold 17px; font: Calibri;");

    tablewidget1 = new QTableWidget();
    tabwidget->addTab(tablewidget1,"Matriz de Adjacencia");

    lbladjacentlist = new QLabel();
    tabwidget->addTab(lbladjacentlist,"Lista de Adjacencia");

    //filewidget;
    lblfile = new QLabel();
    tabwidget->addTab(lblfile,"Conteúdo do arquivo");

    lblresult = new QLabel();
    tabwidget->addTab(lblresult,"Resultado");
    //resultwidget;
    //tabwidget->addTab()
    connect(grboption,SIGNAL(btndeepsearch_clicked()),this,SLOT(deepsearch()));
    connect(grboption,SIGNAL(btnbreadhsearch_clicked()),this,SLOT(breadhsearch()));
    connect(grboption,SIGNAL(btnconectivity_clicked()),this,SLOT(conectivity()));
    connect(grboption,SIGNAL(btnkruskal_clicked()),this,SLOT(kruskal()));
    connect(grboption,SIGNAL(btnprim_clicked()),this,SLOT(prim()));
    connect(grboption,SIGNAL(btndjkstra_clicked()),this,SLOT(djkstra()));
    connect(grboption,SIGNAL(btnbellmanford_clicked()),this,SLOT(bellmanford()));
}

//QTableWidget *ViewMain::getTableWidget2()
//{
//    return tablewidget2;
//}

void ViewMain::openNewFile()
{
    QString path  = QFileDialog::getOpenFileName(this,"Abrir Arquivo de texto",NULL);
    if (path != "")
    {
        ghgrafo= new GHGrafo(path,GHGrafo::ORIENTED);
        updatePresentations();
        tabwidget->setCurrentIndex(2);
    }

}

void ViewMain::ViewMain::deepsearch()
{
    qDebug()<<ghgrafo->deepSearch(ghgrafo->findByName(
                                      grboption->getCbxStartNodeContent()));
    lblresult->setText(ghgrafo->deepSearch(ghgrafo->findByName(
                                               grboption->getCbxStartNodeContent())));
    tabwidget->setCurrentIndex(3);
}
void ViewMain::ViewMain::breadhsearch()
{
    lblresult->setText(ghgrafo->breadthSearch(ghgrafo->findByName(
                                               grboption->getCbxStartNodeContent())));
    tabwidget->setCurrentIndex(3);
}
void ViewMain::ViewMain::conectivity()
{
    lblresult->setText(ghgrafo->checkConectivity());
    tabwidget->setCurrentIndex(3);
}

void ViewMain::ViewMain::prim()
{
    lblresult->setText(ghgrafo->prim(ghgrafo->findByName(
                                               grboption->getCbxStartNodeContent())));
    tabwidget->setCurrentIndex(3);
}

void ViewMain::ViewMain::kruskal()
{
    lblresult->setText(ghgrafo->kruskal());
    tabwidget->setCurrentIndex(3);
}

void ViewMain::ViewMain::djkstra()
{
    lblresult->setText(ghgrafo->dijsktra(ghgrafo->findByName(
                                               grboption->getCbxStartNodeContent())));
    tabwidget->setCurrentIndex(3);
}

void ViewMain::ViewMain::bellmanford()
{
    lblresult->setText(ghgrafo->bellmanford(ghgrafo->findByName(
                                               grboption->getCbxStartNodeContent())));
    tabwidget->setCurrentIndex(3);
}

void ViewMain::ViewMain::startNodeChanged(const QString &arg1)
{

}

void ViewMain::ViewMain::finalNodeChanged(const QString &arg1)
{

}

//void ViewMain::paintEvent(QPaintEvent *)
//{
////    QPainter painter;
////    painter.begin(this);
////    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
////        //painter.drawImage(0, 0, *backgroundview);
////        painter.drawImage(0, 0, *imgarrowlist);
////        painter.drawImage(0, 0, *imgcurrentarrow);
////        painter.drawImage(0, 0, *imgpolygonlist);
////        painter.drawImage(0, 0, *imgcurrentnode);
////    painter.end();

//}

//void ViewMain::mouseMoveEvent(QMouseEvent *event)
//{
//    emit mouseMove(event);
//}

//void ViewMain::mousePressEvent(QMouseEvent *event)
//{
//    emit mousePress(event);
//}

//void ViewMain::mouseReleaseEvent(QMouseEvent *event)
//{
//    emit mouseRelease(event);
//}

//QImage *ViewMain::getImgCurrentArrow()
//{
//    return imgcurrentarrow;
//}

//void ViewMain::setImgCurrentArrow(QImage *currentarrow)
//{
//   this->imgcurrentarrow = currentarrow;
//}
//QImage *ViewMain::getImgPolygonList()
//{
//    return imgpolygonlist;
//}
//void ViewMain::setImgArrowList(QImage *imgarrowlist)
//{
//    this->imgarrowlist = imgarrowlist;
//}
//QImage *ViewMain::getImgArrowList()
//{
//    return imgarrowlist;
//}
//QImage *ViewMain::getImgCurrentNode()
//{
//    return imgcurrentnode;
//}
//void ViewMain::setImgCurrentNode(QImage *currentnode)
//{
//   this->imgcurrentnode = currentnode;
//}
//void ViewMain::setImgPolygonList(QImage *polygonlist)
//{
//    this->imgpolygonlist=polygonlist;
//}
void ViewMain::resizeEvent(QResizeEvent *event)
{
    btnloadfile->setGeometry(0,10,this->width(),80);
    grboption->setGeometry(0,100,this->width(),this->height()/2 - 100);
    tabwidget->setGeometry(0,(this->height()/2),this->width(),this->height()/2);
    emit resize(event);
}

void ViewMain::updatePresentations()
{
    lblfile->setText(ghgrafo->getFileContent());

   // lblfile->setGeometry(0,0,this->width(),this->height()/2 - 200);
    //tabwidget->insertTab(2,lblfile,"Conteúdo do arquivo");

    lbladjacentlist->setText(ghgrafo->printAdjacentList());
    ghgrafo->printMatrizAdjacency(tablewidget1);

    grboption->setNameNodes(ghgrafo->getVertexNames());
}
