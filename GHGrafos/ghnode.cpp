#include "ghnode.h"

GHNode::GHNode(QObject *parent) :
    QObject(parent)
{
    setSelection(NOT_SELECTED);
    arrowlist = new QList <GHEdge*>();
    timeD = timeF = 0;
    nodecolor = GHNode::WHITE;
}
GHNode::GHNode(QString name , QObject * parent) :
    QObject(parent)
{
    setSelection(NOT_SELECTED);
    arrowlist = new QList <GHEdge*>();
    this->name = name;
    timeD = timeF = 0;
    nodecolor = GHNode::WHITE;
}
GHNode::NODETYPE GHNode::nodeType()
{
    return this->nodetype;
}
//---------------Set's;
void GHNode::setCurrentImage(QImage *img)
{
    //this->currentImage = img;
}
void GHNode::setDefaultImage(QImage *img)
{
//    this->defaultImage = img;
//    updateCurrentImage(this);
}
void GHNode::updateCurrentImage(GHNode *node)
{        
//    *(node->getCurrentImage()) = QImage(node->getDefaultImage()->size(),
//                                        QImage::Format_ARGB32_Premultiplied);
//    node->getCurrentImage()->fill(Qt::transparent);
//    QPainter painter;

//    painter.begin(node->getCurrentImage());
//    painter.setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform
//                         ,true);
//    painter.drawImage(node->getDefaultImage()->rect(),*(node->getDefaultImage()));
//    painter.end();
}
void GHNode::drawNode(GHNode *node, QImage *imgview)
{
//    QPainter painter;
//    painter.begin(imgview);
//    painter.setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform
//                         ,true);
//    painter.drawImage(node->getPos(),*(node->getCurrentImage()));
//    QPen pen;
//    pen.setWidth(4);
//    QColor color(255,0,0,50);
//    switch (node->getSelection())
//    {
//    case GHNode::SELECTED:
//        pen.setStyle(Qt::DashLine);
//        pen.setColor(Qt::red);
//        painter.setPen(pen);
//        painter.drawRect(node->getRect());
//    break;
//    case GHNode::SELECTION_IMMINENT:
//        pen.setStyle(Qt::SolidLine);
//        pen.setColor(Qt::red);
//        painter.setPen(pen);
//        painter.drawRect(node->getRect());
//    break;
//    case GHNode::SELECTION_ARROW_IMMINENT:
//        pen.setStyle(Qt::SolidLine);
//        pen.setColor(Qt::red);
//        painter.setPen(pen);
//        painter.drawRect(node->getRect());
//        painter.fillRect(node->getRect(),color);
//    break;
//   }
//    painter.end();
}

void GHNode::setSelection(GHNode::SELECTION selection)
{
    this->selection = selection;
}

void GHNode::setArrowList(QList<GHEdge *> *arrowlist)
{
    this->arrowlist=arrowlist;
}

//---------------Get's;
//QImage *GHNode::getCurrentImage()
//{
//    return currentImage;
//}

//QImage *GHNode::getDefaultImage()
//{
//    return defaultImage;
//}

GHNode::SELECTION GHNode::getSelection()
{
    return selection;
}

QList<GHEdge *> * GHNode::getArrowList()
{
    return this->arrowlist;
}

void GHNode::setDistance(int distance)
{
    this->distance = distance;
}

int GHNode::getDistance()
{
    return distance;
}

void GHNode::setX(int x)
{
    this->x = x;
}

void GHNode::setY(int y)
{
    this->y = y;
}

void GHNode::setPos(QPoint point)
{
    setX(point.x());
    setY(point.y());
}

int GHNode::getX()
{
    return x;
}

int GHNode::getY()
{
    return y;
}
QRect GHNode::getRect()
{
    //return QRect(getPos(),getCurrentImage()->size());
}
QPoint GHNode::getPos()
{
    return QPoint(x,y);
}

QPoint GHNode::getCenter()
{
//    int x = (getX() + (getCurrentImage()->width()/2));
//    int y = (getY() + (getCurrentImage()->height()/2));
    //    return QPoint(x,y);
}

void GHNode::setName(QString name)
{
    this->name = name;
}

QString GHNode::getName()
{
    return name;
}

int GHNode::getTimeD()
{
    return timeD;
}

int GHNode::getTimeF()
{
    return timeF;
}

void GHNode::setTimeD(int time)
{
    timeD = time;
}

void GHNode::setTimeF(int time)
{
    timeF = time;
}

GHNode::COLOR GHNode::getColor()
{
    return nodecolor;
}

void GHNode::setColor(GHNode::COLOR color)
{
    nodecolor = color;
}
QPoint GHNode::getCenterTop()
{
//    int x = (getX() + (getCurrentImage()->width()/2));
//    int y = getY();
//    return QPoint(x,y);
}
QPoint GHNode::getCenterBotton()
{
//    int x = (getX() + (getCurrentImage()->width()/2));
//    int y = (getY() + getCurrentImage()->height());
//    return QPoint(x,y);
}
QList<GHEdge *> GHNode::getArrowsThatStartOnIt()
{
    QList<GHEdge*> listaux;
    foreach (GHEdge *arrow, *(this->getArrowList())){
        if(arrow->getStartNode()==this)
            listaux.append(arrow);
    }
    return listaux;
}
QList<GHEdge *> GHNode::getArrowsThatEndOnIt()
{
    QList<GHEdge*> listaux;
    foreach (GHEdge *arrow, *(this->getArrowList())){
        if(arrow->getEndNode()==this)
            listaux.append(arrow);
    }
    return listaux;
}
QList<GHNode*> GHNode::getFathers()
{
    QList<GHNode*> listaux;
    foreach(GHEdge *arrow,getArrowsThatEndOnIt())
    {
        listaux.append(arrow->getStartNode());
    }
    return listaux;
}
QList<GHNode*> GHNode::getChilds()
{
    QList<GHNode*> listaux;
    foreach(GHEdge *arrow,getArrowsThatStartOnIt())
    {
        listaux.append(arrow->getEndNode());
    }
    return listaux;
}
void GHNode::recalculateArrows()
{
    GHNode::recalculateArrows(this);
}
void GHNode::recalculateArrows(GHNode *node)
{
    foreach (GHEdge *arrow, *(node->getArrowList())){
        if (arrow->getStartNode()== node)
            arrow->getLine()->setPoints(node->getCenterBotton(),arrow->getLine()->p2());
        else
            arrow->getLine()->setPoints(arrow->getLine()->p1(),node->getCenterTop());
    }
}
QList<GHNode*> GHNode::getNodeListByLvl(GHNode *noderoot, int lvl, int i)
{
    QList<GHNode*> listaux;
    if (i == lvl-1)
    {
        return noderoot->getChilds();
    }
    else{
        foreach(GHNode *nodechild,noderoot->getChilds())
        {
            listaux.append(getNodeListByLvl(nodechild,lvl,i+1));
        }
        return listaux;
    }
}

void GHNode::drawNode(QImage *imgview)
{
    GHNode::drawNode(this,imgview);
}

bool GHNode::checkNodeAvailable(GHNode *node)
{
    if (node->getArrowList()->size()>0){
        qDebug()<< "não esta disponivel";
        return false;
    }
    else
    {
        return true;
    }
}
void GHNode::removeAllArrows(GHNode* node)
{
    GHNode::removeArrows(*(node->getArrowList()));
}
void GHNode::removeArrows(QList<GHEdge*> listarrow)
{
    foreach(GHEdge* arrow,listarrow)
        GHNode::removeArrow(arrow);
}
void GHNode::removeArrow(GHEdge* arrow)
{
    arrow->getStartNode()->getArrowList()->removeAll(arrow);
    arrow->getEndNode()->getArrowList()->removeAll(arrow);
    arrow->setStartNode(NULL);
    arrow->setEndNode(NULL);
    delete arrow;
}
bool GHNode::searchCyclicReference(GHNode *nodekey, GHNode *nodeaux)
{
    if (nodekey == nodeaux )
            return true;
    else
    {
        foreach (GHNode *node, nodeaux->getChilds()) {
            if(GHNode::searchCyclicReference (nodekey,node))
                return true;
        }
    }
    return false;
}
bool GHNode::searchCyclicReference(GHNode *nodekey)
{
    foreach(GHNode *nodeaux, nodekey->getChilds()) {
        if (GHNode::searchCyclicReference(nodekey,nodeaux))
            return true;
    }
    return false;
}
bool GHNode::searchCyclicReference()
{
   if(GHNode::searchCyclicReference(this))
       return true;
   else
       return false;
}
bool GHNode::searchStartArrowConnection(GHNode *nodestart, GHNode*nodeend)
{
    QList<GHEdge*> startarrowlist = nodestart->getArrowsThatStartOnIt();
    QList<GHEdge*> endarrowlist = nodeend->getArrowsThatEndOnIt();

    foreach(GHEdge* arrowstart,startarrowlist)
        foreach(GHEdge *arrowend ,endarrowlist)
            if (arrowstart == arrowend)
                return true;
    return false;
}
bool GHNode::searchArrowConnection(GHNode *node1, GHNode*node2)
{
//    foreach(GHEdge* arrow1,*(node1->getArrowList()))
//        foreach(GHEdge *arrow2 ,*(node2->getArrowList()))
//            if (arrow1 == arrow2)
//                return true;
//    return false;
    foreach (GHNode*nodeaux,GHNode::getAdjacentNodes(node1)) {
        if (nodeaux == node2)
            return true;
    }

    return false;


}
QList<GHNode*> GHNode::getAdjacentNodes(GHNode *node)
{
    QList<GHNode*> listaux;
    foreach (GHEdge *edge,*(node->getArrowList())) {
        if(edge->getStartNode()==node)
        {
            listaux.append(edge->getEndNode());
        }
        else
        {
            listaux.append(edge->getStartNode());
        }

    }
    return(listaux);
}
QList<GHNode*> GHNode::getAdjacentOrientedNodes(GHNode *node)
{
    QList<GHNode*> listaux;
    foreach (GHEdge *edge,*(node->getArrowList())) {
        if(edge->getStartNode()==node)
        {
            listaux.append(edge->getEndNode());
        }
    }
    return(listaux);
}
//---------------Slot's
QString GHNode::printNodeState()
{
    QString straux = "Name: "+this->name+" color: "+QString::number(this->nodecolor)+" timeD: "+QString::number(this->timeD)+" timeF: "+QString::number(this->timeF);
    return straux;
}

void GHNode::setParent(GHNode *parentnode)
{
    this->parentnode = parentnode;
}

GHNode *GHNode::getParent()
{
    return parentnode;
}

QString GHNode::getParentName()
{
    if( parentnode==NULL )
        return "null";
    else return parentnode->getName();
}

void GHNode::setKey(int key)
{
    this->key = key;
}

int GHNode::getKey()
{
    return key;
}

void GHNode::setNumberChanged(bool changed)
{
    this->numberchanged = changed;
}

bool GHNode::getNumberChanged()
{
    return numberchanged;
}
