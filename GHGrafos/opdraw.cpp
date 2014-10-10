#include "opdraw.h"

OpDraw::OpDraw(QObject *parent) :
    QObject(parent)
{    
    connect(this,SIGNAL(mousePressingArrowOverNode(QMouseEvent*,int)),
            this,SLOT(pressingArrowOverNode(QMouseEvent*,int)));
    connect(this,SIGNAL(mousePressingArrowOverFreeSpace(QMouseEvent*)),
            this,SLOT(pressingArrowOverFreeSpace(QMouseEvent*)));
    connect(this,SIGNAL(mousePressingCurrentArrow()),
            this,SLOT(pressingCurrentArrow()));
    //---------------------------------
    connect(this,SIGNAL(mousePressingNodeOverNode(QMouseEvent*,int)),
            this,SLOT(pressingNodeOverNode(QMouseEvent*,int)));
    connect(this,SIGNAL(mousePressingNodeOverFreeSpace(QMouseEvent*)),
            this,SLOT(pressingNodeOverFreeSpace(QMouseEvent*)));
    connect(this,SIGNAL(mousePressingCurrentNode(QMouseEvent*)),
            this,SLOT(pressingCurrentNode(QMouseEvent*)));
    connect(this,SIGNAL(mousePressingNodeOverArrow(EGArrow*)),
            this,SLOT(pressingNodeOverArrow(EGArrow*)));
    //-------------------------------
    connect(this,SIGNAL(mouseMovingOverNode(int)),this,SLOT(movingOverNode(int)));
    connect(this,SIGNAL(mouseMovingNodeModeOverFreeSpace()),
            this,SLOT(movingNodeModeOverFreeSpace()));
    connect(this,SIGNAL(mouseMovingNodeMode()),this,SLOT(movingNodeMode()));
    connect(this,SIGNAL(mouseMovingOverArrow(EGArrow*)),this,SLOT(movingOverArrow(EGArrow *)));
    connect(this,SIGNAL(mouseMovingArrowModeOverFreeSpace()),
            this,SLOT(movingArrowModeOverFreeSpace()));
    connect(this, SIGNAL(mouseMovingArrowMode()),this,SLOT(movingArrowMode()));
    //-------------------------
    connect(this,SIGNAL(mousePressArrowModeOverNode(QMouseEvent*,int)),
            this,SLOT(pressArrowModeOverNode(QMouseEvent*,int)));
    connect(this,SIGNAL(mousePressNodeModeOverNode(QMouseEvent *, int )),
            this,SLOT(pressNodeModeOverNode(QMouseEvent*,int)));
    connect(this,SIGNAL(mousePressNodeModeOverFreeSpace()),this,SLOT(pressNodeModeOverFreeSpace()));
    connect(this,SIGNAL(mousePressArrowModeOverArrow(EGArrow*)),
            this,SLOT(pressArrowModeOverArrow(EGArrow *)));
    connect(this,SIGNAL(mousePressArrowModeOverFreeSpace()),
            this,SLOT(pressArrowModeOverFreeSpace()));
    //--------------------------------
    connect(this,SIGNAL(mouseReleaseArrowOverStartNode()),this,SLOT(releaseArrowOverStartNode()));
    connect(this,SIGNAL(mouseReleaseArrowOverEndNode(int)),this,SLOT(releaseArrowOverEndNode(int)));
    connect(this,SIGNAL(mouseReleaseArrowOverNode()),this,SLOT(releaseArrowOverNode()));
    connect(this,SIGNAL(mouseReleaseArrowOverFreeSpace()),this,SLOT(releaseArrowOverFreeSpace()));
    connect(this,SIGNAL(mouseReleaseNodeOverNode(int)),this,SLOT(releaseNodeOverNode(int)));
    connect(this,SIGNAL(mouseReleaseNodeOverArrow(EGArrow*)),
            this,SLOT(releaseNodeOverArrow(EGArrow*)));
    connect(this,SIGNAL(mouseReleaseNodeOverFreeSpace()),this,SLOT(releaseNodeOverFreeSpace()));
    connect(this,SIGNAL(mouseReleaseCurrentNode()),this,SLOT(releaseCurrentNode()));
    connect(this,SIGNAL(mouseReleaseNodeMode()),this,SLOT(releaseNodeMode()));

    setMode(OpDraw::NODE);
    currentarrow = NULL;
    currentnode = NULL;
    modelegnodelist = new ModelEGNodeList();
    modelegnodelist->getEGNodeList()->append(new EGNode());
    modelegnodelist->getEGNodeList()->append(new EGNode());
    modelegnodelist->getEGNodeList()->append(new EGNode());
    modelegnodelist->getEGNodeList()->append(new EGNode());
    int i = 0;
    foreach(EGNode *node, *(modelegnodelist->getEGNodeList()))
    {
        node->setDefaultImage(new QImage(QString("image"+QString::number(i)+".png")));
        node->setPos(QPoint(0,0));
        i++;
    }
    modelegnodelist->getEGNodeList()->at(1)->setPos(QPoint(600,800));

}
void OpDraw::drawNodes()
{
    viewmain->getImgPolygonList()->fill(Qt::transparent);
    foreach(EGNode *node, *(modelegnodelist->getEGNodeList()))
    {        
        node->drawNode(node,viewmain->getImgPolygonList());
    }
}
void OpDraw::drawArrows()
{    
    viewmain->getImgArrowList()->fill(Qt::transparent);
    foreach(EGArrow *arrow,modelegnodelist->getAllArrows())
    {                
        EGArrow::drawArrow(arrow, viewmain->getImgArrowList());
    }
}
void OpDraw::drawScene()
{
    drawArrows();
    drawNodes();
    viewmain->update();
}
void OpDraw::drawCurrentArrow()
{
    viewmain->getImgCurrentArrow()->fill(Qt::transparent);
    if (currentarrow !=NULL)
        currentarrow->drawArrow(currentarrow,viewmain->getImgCurrentArrow());    
}
void OpDraw::drawCurrentNode()
{
    viewmain->getImgCurrentNode()->fill(Qt::transparent);
    if (currentnode !=NULL){
        currentnode->drawNode(currentnode,viewmain->getImgCurrentNode());
        foreach (EGArrow *arrow, *(currentnode->getArrowList())) {
            if(arrow->getStartNode()==currentnode)
                arrow->drawArrow(arrow,viewmain->getImgArrowList());
        }
    }    
}
void OpDraw::setViewMain(ViewMain *viewmain)
{
    this->viewmain = viewmain;
    drawScene();
}
void OpDraw::pressingArrowOverNode(QMouseEvent *event, int nodeindex)
{
    EGNode *nodeaux =modelegnodelist->getEGNodeList()->at(nodeindex);
    nodeaux->setSelection(EGNode::SELECTION_ARROW_IMMINENT);
    currentarrow->getLine()->setPoints(currentarrow->getLine()->p1(),
                                       QPoint(event->pos().x(),
                                              event->pos().y()));
    QList<EGNode*> nodelist = modelegnodelist->getListNodeSelected(
                EGNode::SELECTION_ARROW_IMMINENT);
    nodelist.removeAll(currentarrow->getStartNode());
    nodelist.removeAll(nodeaux);
    modelegnodelist->setNodeListSelection(nodelist,EGNode::NOT_SELECTED);    
    //pintando todos os nós
    drawNodes();
}
void OpDraw::pressingArrowOverFreeSpace(QMouseEvent *event)
{
    //capturando lista de nós que estavam selecionados
    QList<EGNode*> nodelist=modelegnodelist->getListNodeSelected(EGNode::SELECTION_ARROW_IMMINENT);
    //removendo o nó inicial que tem o começo da seta da lista
    nodelist.removeAll(currentarrow->getStartNode());
    //limpando os que ja não estão mais sendo selecionados
    ModelEGNodeList::setNodeListSelection(nodelist,EGNode::NOT_SELECTED);
    ModelEGNodeList::drawNodes(nodelist,viewmain->getImgPolygonList());
    currentarrow->getLine()->setPoints(currentarrow->getLine()->p1(),
                                       QPoint(event->pos().x(),
                                              event->pos().y()));
    //pintando todos os nós
    drawNodes();
}
void OpDraw::pressingCurrentArrow()
{
    drawCurrentArrow();
    viewmain->update();
}
void OpDraw::pressingNodeOverNode(QMouseEvent *event,int index)
{
    EGNode *nodeaux = modelegnodelist->getEGNodeList()->at(index);
    nodeaux->setSelection(EGNode::SELECTION_ANCHOR_IMMINENT);
    QList<EGNode*> nodelist = modelegnodelist->getListNodeSelected(
                EGNode::SELECTION_ANCHOR_IMMINENT);
    nodelist.removeAll(nodeaux);
    ModelEGNodeList::setNodeListSelection(nodelist,EGNode::NOT_SELECTED);
    currentnode->setSelection(EGNode::SELECTION_ANCHOR_IMMINENT);
    drawNodes();
}
void OpDraw::pressingNodeOverFreeSpace(QMouseEvent *event)
{
    QList<EGNode*> listaux = modelegnodelist->getListNodeSelected(
                EGNode::SELECTION_ANCHOR_IMMINENT);
    ModelEGNodeList::setNodeListSelection(listaux,EGNode::NOT_SELECTED);
    currentnode->setSelection(EGNode::SELECTION_IMMINENT);
    modelegnodelist->setArrowListSelection(
                modelegnodelist->getListArrowSelected(
                    EGArrow::SELECTION_SUBTITLE_IMMINENT),EGArrow::NOT_SELECTED);
    drawArrows();
}
void OpDraw::pressingNodeOverArrow(EGArrow *arrow)
{
    modelegnodelist->setArrowListSelection(
                modelegnodelist->getListArrowSelected(
                    EGArrow::SELECTION_SUBTITLE_IMMINENT),EGArrow::NOT_SELECTED);
    arrow->setSelection(EGArrow::SELECTION_SUBTITLE_IMMINENT);

}
void OpDraw::pressingCurrentNode(QMouseEvent *event)
{
    //alterando posição do nó
    currentnode->setPos((event->pos()- mousepresspos));
    //alterando posição das setas ligadas ao nó
    currentnode->recalculateArrows(currentnode);
    drawArrows();
    drawNodes();
    drawCurrentNode();
    viewmain->update();
}
void OpDraw::movingOverNode(int nodeindex)
{
    EGNode *nodeaux = modelegnodelist->getEGNodeList()->at(nodeindex);
    movingNodeModeOverFreeSpace();
    if (nodeaux->getSelection()!=EGNode::SELECTED)
        nodeaux->setSelection(EGNode::SELECTION_IMMINENT);
}
void OpDraw::movingNodeModeOverFreeSpace()
{
    QList<EGNode*> nodelist = modelegnodelist->getListNodeSelected(EGNode::SELECTION_IMMINENT);
    ModelEGNodeList::setNodeListSelection(nodelist,EGNode::NOT_SELECTED);
}
void OpDraw::movingNodeMode()
{
    drawNodes();
    viewmain->update();
}
void OpDraw::movingOverArrow(EGArrow *arrow)
{
    modelegnodelist->setArrowListSelection(
                modelegnodelist->getListArrowSelected(EGArrow::SELECTION_IMMINENT),
                EGArrow::NOT_SELECTED);
    arrow->setSelection(EGArrow::SELECTION_IMMINENT);
}
void OpDraw::movingArrowModeOverFreeSpace()
{
    modelegnodelist->setArrowListSelection(
                modelegnodelist->getListArrowSelected(EGArrow::SELECTION_IMMINENT),
                EGArrow::NOT_SELECTED);
}
void OpDraw::movingArrowMode()
{
    drawArrows();
    viewmain->update();
}
void OpDraw::pressArrowModeOverNode(QMouseEvent *event,int nodeindex)
{
    currentarrow = new EGArrow();
    currentarrow->setStartNode(modelegnodelist->getEGNodeList()->at(nodeindex));
    currentarrow->getStartNode()->getArrowList()->append(currentarrow);
    currentarrow->getLine()->setPoints(event->pos(),event->pos());
}
void OpDraw::pressNodeModeOverNode(QMouseEvent *event,int nodeindex)
{
    currentnode = modelegnodelist->getEGNodeList()->at(nodeindex);
    modelegnodelist->getEGNodeList()->removeAll(currentnode);
    ModelEGNodeList::setNodeListSelection(*(modelegnodelist->getEGNodeList()),EGNode::NOT_SELECTED);
    mousepresspos = event->pos() - currentnode->getPos();
    drawNodes();
    drawCurrentNode();
    viewmain->update();

}
void OpDraw::pressNodeModeOverFreeSpace()
{
    ModelEGNodeList::setNodeListSelection(*(modelegnodelist->getEGNodeList()),EGNode::NOT_SELECTED);
    drawNodes();
    viewmain->update();
}

void OpDraw::pressArrowModeOverArrow(EGArrow *)
{
}

void OpDraw::pressArrowModeOverFreeSpace()
{
}
void OpDraw::releaseArrowOverStartNode()
{
    currentarrow->getStartNode()->getArrowList()->removeAll(currentarrow);
    currentarrow->getStartNode()->setSelection(EGNode::NOT_SELECTED);
    delete currentarrow;
    currentarrow = NULL;
    drawNodes();
    drawCurrentArrow();
}
void OpDraw::releaseArrowOverEndNode(int nodeindex)
{
    currentarrow->setEndNode(modelegnodelist->getEGNodeList()->at(nodeindex));
    currentarrow->getStartNode()->setSelection(EGNode::NOT_SELECTED);
    currentarrow->getEndNode()->setSelection(EGNode::NOT_SELECTED);
    currentarrow->getLine()->setPoints(currentarrow->getStartNode()->getCenterBotton(),
                                       currentarrow->getEndNode()->getCenterTop());
    if (!(EGNode::searchArrowConnection(currentarrow->getStartNode(),
                                               currentarrow->getEndNode()))){
        currentarrow->getEndNode()->getArrowList()->append(currentarrow);
        if (currentarrow->getEndNode()->searchCyclicReference()){
            qDebug()<<"referencia ciclica";
            currentarrow->getEndNode()->getArrowList()->removeAll(currentarrow);
            currentarrow->getStartNode()->getArrowList()->removeAll(currentarrow);
            currentarrow->setEndNode(NULL);
            currentarrow->setStartNode(NULL);
            delete currentarrow;
        }
    }
    else{
        qDebug()<<"2 setas e mesmo objetivo ou, referência ciclica";
        currentarrow->getStartNode()->getArrowList()->removeAll(currentarrow);
        currentarrow->setEndNode(NULL);
        currentarrow->setStartNode(NULL);
        delete currentarrow;
    }
    currentarrow = NULL;
    drawCurrentArrow();
    drawNodes();
    drawArrows();
}
void OpDraw::releaseArrowOverNode()
{
    viewmain->update();
}
void OpDraw::releaseArrowOverFreeSpace()
{
//    if (currentarrow->getStartNode()!=NULL){
//        currentarrow->getStartNode()->getArrowList()->removeAll(currentarrow);
    currentarrow->getStartNode()->setSelection(EGNode::NOT_SELECTED);
    currentarrow->getStartNode()->getArrowList()->removeAll(currentarrow);
    delete currentarrow;
    currentarrow = NULL;
    drawCurrentArrow();
    drawNodes();
    viewmain->update();
}
void OpDraw::releaseNodeOverNode(int nodeindex)
{
    //showDialogChangeToAnchor
    EGNode *nodeaux = modelegnodelist->getEGNodeList()->at(nodeindex);
    if (EGNode::addAnchor(nodeaux,currentnode )){
        nodeaux->setSelection(EGNode::SELECTED);
        delete currentnode;
    }
    else
    {
        nodeaux->setSelection(EGNode::NOT_SELECTED);
        currentnode->setSelection(EGNode::SELECTED);
        modelegnodelist->getEGNodeList()->append(currentnode);
    }
    currentnode = NULL;
}
void OpDraw::releaseNodeOverArrow(EGArrow *arrowaux)
{
    //showDialogChangeToSubtittle
    if(EGNode::addSubtitle(arrowaux,currentnode)){
        delete currentnode;
        currentnode = NULL;
    }
    else
    {
        arrowaux->setSelection(EGArrow::NOT_SELECTED);
        drawArrows();
        releaseNodeOverFreeSpace();
    }
}
void OpDraw::releaseNodeOverFreeSpace()
{
    currentnode->setSelection(EGNode::SELECTED);
    modelegnodelist->getEGNodeList()->append(currentnode);
    currentnode = NULL;    
}
void OpDraw::releaseCurrentNode()
{
    viewmain->update();
    drawCurrentNode();
    drawNodes();
}
void OpDraw::releaseNodeMode()
{
}
void OpDraw::mouseMove(QMouseEvent *event)
{    
    switch (getMode())
    {
    case OpDraw::ARROW:
        if(event->buttons() == Qt::LeftButton && currentarrow != NULL)
        {                        
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());
            if (nodeindex!=-1)
            {
                //movendo seta em cima de um objeto(iminência de seta sobre objeto)(move + botão
                emit mousePressingArrowOverNode(event,nodeindex);            //esquerdo pressionado)
            }
            else{
                //movendo seta sem esbarrar em objetos(move + botão esquerdo pressionado)
                emit mousePressingArrowOverFreeSpace(event);
            }
            //movendo seta(move + botão esquerdo pressionado)
            emit mousePressingCurrentArrow();
        }
        else
        {
            EGArrow* arrowaux = modelegnodelist->isInsideOfArrow(event->pos());
            if (arrowaux!=NULL)
            {
                //movendo mouse sobre seta (iminência de seleção)
                emit mouseMovingOverArrow(arrowaux);
            }
            else
            {
                //movendo mouse sobre espaço livre
                emit mouseMovingArrowModeOverFreeSpace();
            }
            //movendo mouse com a opção de seta selecionada
            emit mouseMovingArrowMode();
        }
    break;
    case OpDraw::NODE:
        if(event->buttons() == Qt::LeftButton && currentnode != NULL)
        {                        
            int index = modelegnodelist->isInsideOfNode(event->pos());
            EGArrow* arrowaux = modelegnodelist->isInsideOfArrow(event->pos());
            if (index!=-1)
            {
                //pressionando objeto sobre outro objeto(Iminência de ancora)
                emit mousePressingNodeOverNode(event,index);
            }
            else if (arrowaux!=NULL)
            {
                //pressionando objeto sobre uma seta(Iminência de legenda)
                emit mousePressingNodeOverArrow(arrowaux);
            }
            else
            {
                //pressionando objeto sobre espaço livre
                emit mousePressingNodeOverFreeSpace(event);
            }
            //pressionando objeto
            emit mousePressingCurrentNode(event);
        }
        else
        {
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());
            if (nodeindex!=-1)
            {
                //movendo mouse sobre objeto (iminência de seleção)
                emit mouseMovingOverNode(nodeindex);
            }
            else
            {
                //movendo mouse sobre espaço livre
                emit mouseMovingNodeModeOverFreeSpace();
            }
            //movendo mouse com a opção de nó selecionada
            emit mouseMovingNodeMode();
        }
    break;
    defaul:
    break;
    }
}
void OpDraw::mousePress(QMouseEvent *event)
{    
    switch (getMode()){
    case OpDraw::ARROW:
        if (event->buttons() == Qt::LeftButton)
        {
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());
            EGArrow* arrowaux = modelegnodelist->isInsideOfArrow(event->pos());
            if (nodeindex!=-1)
            {
                //clicando com o mouse sobre objeto no modo arrow (iminência de arrow )
                emit mousePressArrowModeOverNode(event, nodeindex);
            }
            else if (arrowaux!=NULL)
            {
                emit mousePressArrowModeOverArrow(arrowaux);
            }
            else
            {
                emit mousePressArrowModeOverFreeSpace();
            }
        }
    break;
    case OpDraw::NODE:
        if (event->buttons() == Qt::LeftButton)
        {
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());
            if (nodeindex!=-1)
            {
                //clicando com o mouse sobre objeto no modo Node (seleção )
                emit mousePressNodeModeOverNode(event,nodeindex);
            }
            else
            {
                //clicando com o mouse sobre espaço livre com Modo objeto (nada selecionado )
                emit mousePressNodeModeOverFreeSpace();
            }
        }
    break;
    defaul:
    break;
    }
    if(event->buttons() == Qt::MidButton)
    {        
        if (getMode()== OpDraw::ARROW)
            setMode(OpDraw::NODE);
        else
            setMode(OpDraw::ARROW);
    }
}

void OpDraw::mouseRelease(QMouseEvent *event)
{
    switch (getMode()){
    case OpDraw::ARROW:
        if(event->button() == Qt::LeftButton && currentarrow !=NULL)
        {
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());            
            if (nodeindex!=-1)
            {                
                if (modelegnodelist->getEGNodeList()->at(nodeindex) == currentarrow->getStartNode())
                {
                    //release do mouse com a seta atual ligada a um nó igual ao inicial
                    emit mouseReleaseArrowOverStartNode();
                }                
                else
                {
                    //release do mouse com a seta atual ligada a um nó diferente do inicial
                    emit mouseReleaseArrowOverEndNode(nodeindex);

                }
                // release do mouse com a seta formada sobre algum nó
                emit mouseReleaseArrowOverNode();
            }
            else
            {
                // release do mouse com a seta formada sobre espaço livre
                emit mouseReleaseArrowOverFreeSpace();
            }
        }
    break;
    case OpDraw::NODE:
        if(event->button() == Qt::LeftButton && currentnode !=NULL)
        {
            int nodeindex = modelegnodelist->isInsideOfNode(event->pos());
            EGArrow *arrowaux = modelegnodelist->isInsideOfArrow(event->pos());
            if (nodeindex!=-1)
            {
                //release do mouse com a nó atual sobre outro nó (ancora)
                emit mouseReleaseNodeOverNode(nodeindex);
            }
            else if (arrowaux!=NULL)
            {
                //release do mouse com a nó atual sobre arrow (legenda)
                emit mouseReleaseNodeOverArrow(arrowaux);
            }
            else
            {
                //release do mouse com a nó atual sobre espaço livre
                emit mouseReleaseNodeOverFreeSpace();
            }
            //release do mouse com o nó atual
            emit mouseReleaseCurrentNode();
        }
        else
        {
            //release do mouse com o modo nó selecionado
            emit mouseReleaseNodeMode();
        }
    break;
    default:
    break;
    }
}
OpDraw::MODE OpDraw::getMode()
{
    return this->mode;
}
void OpDraw::setMode(OpDraw::MODE mode)
{
    this->mode = mode;
}
void OpDraw::resize(QResizeEvent *event)
{
    this->viewmain->setImgCurrentArrow(resizeImage(event->size(),viewmain->getImgCurrentArrow()));
    this->viewmain->setImgCurrentNode(resizeImage(event->size(),viewmain->getImgCurrentNode()));
    this->viewmain->setImgArrowList(resizeImage(event->size(),viewmain->getImgArrowList()));
    this->viewmain->setImgPolygonList(resizeImage(event->size(),viewmain->getImgPolygonList()));
    drawScene();
}
QImage* OpDraw::resizeImage(QSize size, QImage *img)
{
    QImage *imgaux = new QImage(size,QImage::Format_ARGB32_Premultiplied);
    imgaux->fill(Qt::transparent);
    QPainter painter;
    painter.begin(imgaux);
    painter.drawImage(0,0,*img);
    painter.end();
    delete img;
    return imgaux;
}
