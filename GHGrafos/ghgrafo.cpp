#include "ghgrafo.h"

GHGrafo::GHGrafo(QObject *parent) :
    QObject(parent)
{
    GHNodelist = new QList<GHNode*>();
}
GHGrafo::GHGrafo(GHGrafo::GRAFOTYPE type, QObject *parent) :
    QObject(parent)
{
    GHNodelist = new QList<GHNode*>();
    grafotype = type;
}

GHGrafo::GHGrafo(QString path, GHGrafo::GRAFOTYPE type, QObject *parent)
{
    GHNodelist = new QList<GHNode*>();
    grafotype = type;
    QFileInfo fileinfo(path);

        //qDebug() << path;

        if( path==NULL )
            return;

        else
        {
            QFile file(path);
            if( !file.open(QIODevice::ReadOnly) )
            {
                QMessageBox::about(NULL,"Erro!","Erro ao ler o arquivo");
                return;
            }
            QTextStream stream (&file);
            int i = 0;
            while(!stream.atEnd()){
                QString line = stream.readLine();
                filecontent.append(line);
                filecontent.append('\n');
                if( !line.isEmpty() )
                {
                    if( i==0 )
                    {
                        //qDebug() << "grafo type:  " << line;
                        grafotype = (GHGrafo::GRAFOTYPE)line.toInt();
                    }
                    else if( i==1 )
                    {
                        //qDebug() << "vertices: " << line;
                         numvertex = line.toInt();
                    }
                    else{
                        QStringList list = line.split(" ");
                        //qDebug() << "elem: " << list.at(0)  << "->: " << list.at(1) << " ,valor: " << list.at(2);

                        GHNode *ghnode1 =  findByName(list.at(0));
                        //qDebug() << "1";
                        if( ghnode1==NULL )
                        {
                         //   qDebug() << "2";
                            ghnode1 = new GHNode(list.at(0));
                         //   qDebug() << "3";
                            this->GHNodelist->append(ghnode1);
                        //    qDebug() << "4";
                        }

                        GHNode *ghnode2 =  findByName(list.at(1));
                        if( ghnode2==NULL )
                        {
                          //  qDebug() << "5";
                             ghnode2 = new GHNode(list.at(1));
                          //   qDebug() << "6";
                             this->GHNodelist->append(ghnode2);
                         //    qDebug() << "7";
                        }
                        connectNodes(ghnode1,ghnode2,list.at(2).toInt());
                    }
                    i++;
                }
            }            
            file.flush();
            file.close();
        }
}

void GHGrafo::setGrafoType(GHGrafo::GRAFOTYPE grafotype)
{
    this->grafotype = grafotype;
}

GHGrafo::GRAFOTYPE GHGrafo::getGrafoType()
{
    return grafotype;
}

QList<GHNode *> *GHGrafo::getGHNodeList()
{
    return GHNodelist;
}

void GHGrafo::setGHNodeList(QList<GHNode *> *GHNodelist)
{
    this->GHNodelist = GHNodelist;
}
QList<GHNode*> GHGrafo::getListNodeSelected(GHNode::SELECTION selection)
{    
    QList <GHNode*> listaux;
    int length = GHNodelist->length();
    for(int i=0;i<length;i++)
    {
        int index = getIndexOfNodeSelected(selection,i);
        if (index==-1)
            return listaux;
        else{
            listaux.append(GHNodelist->at(index));
            i = index;
        }
    }
    return listaux;
}
QList<GHEdge *> GHGrafo::getListArrowSelected(GHEdge::SELECTION selection)
{
    QList<GHEdge *> listaux;
    foreach (GHEdge*arrow, getAllArrows()) {
        if (arrow->getSelection()==selection)
            listaux.append(arrow);
    }
    return listaux;
}
int GHGrafo::getIndexOfNodeSelected(GHNode::SELECTION selection,int from)
{
    int length = GHNodelist->length();
    for(;from<length;from++)
    {        
        if (GHNodelist->at(from)->getSelection() == selection)
            return from;        
    }
    return -1;
}
int GHGrafo::isInsideOfNode(QPoint point)
{
    return isInsideOfNode(point,0);
}
int GHGrafo::isInsideOfNode(QPoint point, int startindex)
{
    int length = GHNodelist->length();
    for(int i = startindex;i<length;i++)
    {
        if (GHNodelist->at(i)->getRect().contains(point))
        {
            return (i);
        }
    }
    return -1;
}
GHEdge* GHGrafo::isInsideOfArrow(QPoint point)
{
    foreach(GHEdge *arrow,getAllArrows())
    {
        QPointF pointf;
        QLineF linef1(point.x()-10, point.y()-10, point.x()+10, point.y()+10);
        QLineF linef2(point.x()-10, point.y()+10, point.x()+10, point.y()-10);
        if ((QLineF(*(arrow->getLine())).intersect(linef1,&pointf)== QLineF::BoundedIntersection)||
                (QLineF(*(arrow->getLine())).intersect(linef2,&pointf)
                 ==QLineF::BoundedIntersection)){
            return(arrow);
        }
    }
    return NULL;
}
void GHGrafo::drawNodes(QList<GHNode*> nodelist,QImage *imgview)
{
    foreach(GHNode *node, nodelist)
    {
        node->drawNode(node,imgview);
    }
}
void GHGrafo::setArrowListSelection(QList<GHEdge*>arrowlist,GHEdge::SELECTION selection)
{
    foreach (GHEdge *arrow, arrowlist) {
        arrow->setSelection(selection);
    }
}

void GHGrafo::setNodeListSelection(QList<GHNode*> nodelist,GHNode::SELECTION selection)
{
    foreach (GHNode*node, nodelist) {
        node->setSelection(selection);
    }
}
void GHGrafo::setNodeListSelection(GHNode::SELECTION selection)
{
    GHGrafo::setNodeListSelection(*GHNodelist,selection);
}
void GHGrafo::drawNodes(QImage *imgview)
{
    GHGrafo::drawNodes(*GHNodelist,imgview);
}
QList<GHNode*> GHGrafo::getRoots()
{
    QList<GHNode*> listaux;
    int lenght = GHNodelist->length();
    for(int i=0;i<lenght;i++)
    {
        if (GHNodelist->at(i)->getFathers().size()==0)
            listaux.append(GHNodelist->at(i));
    }
    return listaux;
}
QList<GHEdge*> GHGrafo::getAllArrows()
{
    QList<GHEdge*> listaux;
    foreach(GHNode *node, *(GHNodelist))
    {

        foreach(GHEdge *arrow,*(node->getArrowList()))
        {
            if (arrow->getStartNode()==node)
            {
                listaux.append(arrow);
            }
        }
    }
    return listaux;
}
void GHGrafo::printMatrizAdjacency(QTableWidget *tablewidget)
{
    tablewidget->setRowCount(GHNodelist->size());
    tablewidget->setColumnCount(GHNodelist->size());

    for( int i=0; i<GHNodelist->size(); i++ )
    {
        tablewidget->setVerticalHeaderItem(i,new QTableWidgetItem(QString::number(i)));
        tablewidget->setHorizontalHeaderItem(i,new QTableWidgetItem(QString::number(i)));
    }

    int i=0;
    int j = 0;

    switch( grafotype ){
    case GHGrafo::NOT_ORIENTED:
        //qDebug() << "oriented: " << "not_oriented";
        foreach (GHNode* nodeH, *GHNodelist) {


            j = 0;
            foreach (GHNode *nodeV, *GHNodelist) {

                if(GHNode::searchStartArrowConnection(nodeH,nodeV))
                {

                    tablewidget->setItem(i,j,new QTableWidgetItem("1"));
                }
                else
                {

                    tablewidget->setItem(i,j,new QTableWidgetItem("0"));
                }

                j++;
            }
            i++;
        }
    break;
    case GHGrafo::ORIENTED:
        //qDebug() << "oriented: " << "oriented";
        foreach (GHNode* nodeH, *GHNodelist) {


            j = 0;
            foreach (GHNode *nodeV, *GHNodelist) {

                if(GHNode::searchStartArrowConnection(nodeH,nodeV))
                {

                    tablewidget->setItem(i,j,new QTableWidgetItem("1"));
                }
                else
                {

                    tablewidget->setItem(i,j,new QTableWidgetItem("0"));
                }
                j++;
            }
            i++;
        }
    break;
    }
}
QString GHGrafo::printAdjacentList()
{
    QString straux;
    switch(grafotype){//if
    case GHGrafo::NOT_ORIENTED:

        foreach (GHNode* node, *GHNodelist) {
            straux.append("|"+node->getName()+"|-> ");
            foreach (GHNode*nodeL,GHNode::getAdjacentNodes(node)) {
                straux.append(nodeL->getName());
                straux.append(" -> ");
            }
            straux.append("_");
            straux.append('\n');
        }
    break;
    case GHGrafo::ORIENTED:
        qDebug()<<"oriented";
        foreach (GHNode* node, *GHNodelist) {
            straux.append("|"+node->getName()+"|-> ");
            foreach (GHNode*nodeL,GHNode::getAdjacentOrientedNodes(node)) {
                straux.append(nodeL->getName());
                straux.append(" -> ");
            }
            straux.append("_");
            straux.append('\n');
        }
    break;
    default:
    break;
    }
    return(straux);
}
QString GHGrafo::deepSearch(GHNode*firstNode)
{
    int time = 0;
    foreach (GHNode *node, *GHNodelist) {
        node->setColor(GHNode::WHITE);
    }
    QList<GHNode*> listaux = *GHNodelist;
    if (listaux.removeAll(firstNode)==0)        

    deepFirstSearch(firstNode,&time);

    foreach (GHNode *node, listaux) {
        if (node->getColor()==GHNode::WHITE){
            deepFirstSearch(node,&time);
        }
    }
    QString result;
    foreach (GHNode*nodeaux,listaux) {
        result.append(nodeaux->printNodeState());
        result.append('\n');
    }
    return result;

}
QList<GHNode*> GHGrafo::barrier(GHEdge *brokeedge)
{
    qDebug() << "barrier: ";
    QList<GHNode*> listaux;
    foreach (GHNode *node, *GHNodelist) {
        node->setColor(GHNode::WHITE);
        node->setDistance(0);
        node->setParent(NULL);
        qDebug() << node->getName();
    }

    QList<GHNode*> q;
    GHNode *adjacentNodeA = brokeedge->getStartNode();
    GHNode *adjacentNodeB = brokeedge->getEndNode();

    adjacentNodeA->setColor(GHNode::GRAY);
    adjacentNodeA->setDistance(0);
    adjacentNodeA->setParent(NULL);
    adjacentNodeB->setColor(GHNode::GRAY);
    adjacentNodeB->setDistance(0);
    adjacentNodeB->setParent(NULL);



    q.append(adjacentNodeA);

    while( !q.isEmpty() ){
        GHNode *u = q.first();
        q.removeFirst();

        foreach (GHNode *v, u->getAdjacentNodes(u)) {
            if( v->getColor()==GHNode::WHITE ){
                v->setColor(GHNode::GRAY);
                v->setParent(u);
                v->setDistance(u->getDistance()+1);
                if (v->isBarrier())
                {
                    v->setIsOpen(false);
                    listaux.append(v);
                }

                else
                {
                    q.append(v);
                }
            }
        }
        u->setColor(GHNode::BLACK);
    }
    return listaux;
}

QString GHGrafo::breadthSearch(GHNode *firstnode)
{
    qDebug() << "breadth: ";
    QString straux;
    foreach (GHNode *node, *GHNodelist) {
        node->setColor(GHNode::WHITE);
        node->setDistance(0);
        node->setParent(NULL);
        qDebug() << node->getName();
    }

    QList<GHNode*> q;

    firstnode->setColor(GHNode::GRAY);
    firstnode->setDistance(0);
    firstnode->setParent(NULL);

    q.append(firstnode);

    while( !q.isEmpty() ){
        GHNode *u = q.first();
        q.removeFirst();

        foreach (GHNode *v, u->getAdjacentNodes(u)) {
            if( v->getColor()==GHNode::WHITE ){
                v->setColor(GHNode::GRAY);
                v->setParent(u);
                v->setDistance(u->getDistance()+1);
                q.append(v);
            }
        }
        straux.append("Nó: "+u->getName() + " distância " + QString::number(u->getDistance()));
        straux.append('\n');
        u->setColor(GHNode::BLACK);
    }
    return straux;
}

QString GHGrafo::kruskal()
{
    QString straux;
    QList<GHGrafo*> X;

    foreach( GHNode *node,* GHNodelist ){
        GHGrafo *grafo = new GHGrafo();
        grafo->getGHNodeList()->append(node);
        X.append(grafo);
    }

    QList<GHEdge*> A = Utils::bubbleSort(getAllArrows());
    QList<GHEdge*> B;

    foreach(GHEdge *edge, A){
        GHNode *node1 = edge->getStartNode();
        GHNode *node2 = edge->getEndNode();
        int i1=-1, i2=-1;
        for ( int i=0; i<X.count(); i++ ) {
            if( X.at(i)->hasNode(node1)  ){
                i1 = i;
            }
            if( X.at(i)->hasNode(node2) ){
                i2 = i;
            }
        }
        if ( i1!=i2 )
        {
            X.at(i1)->getGHNodeList()->append(*(X.at(i2)->getGHNodeList()));
            X.removeAt(i2);
            B.append(edge);
            straux.append(edge->getStartNode()->getName() + " + "+edge->getEndNode()->getName()) ;
            straux.append('\n');
        }
    }
    return straux;


}

QString GHGrafo::prim(GHNode *firstnode)
{
    QString straux;
    QList<GHNode*> Q;


    foreach( GHNode *node,* GHNodelist ){
        node->setParent(NULL);
        node->setKey(0);
        node->setNumberChanged(false);
    }

    firstnode->setNumberChanged(true);
    Q.append(*GHNodelist);


    QList<GHEdge*> S;

    while (!Q.isEmpty()) {
        GHNode* minnode = extractMin(&Q);

        GHEdge* edgeaux = findPrimEdgeWith(minnode,minnode->getParent());
        if (edgeaux!=NULL)
            S.append(edgeaux);

        foreach( GHNode *u, GHNode::getAdjacentNodes(minnode) ){
            if(Q.contains(u) )
            {
                if ((!u->getNumberChanged()) ||
                        findPrimEdgeWith(minnode,u)->getWeight() < u->getKey())
                {

                    u->setKey(findPrimEdgeWith(minnode,u)->getWeight());

                    u->setParent(minnode);

                    u->setNumberChanged(true);
                }
            }
        }
    }
    foreach (GHEdge *edge, S) {
        straux.append("Aresta: "+edge->getStartNode()->getName()+" : "+edge->getEndNode()->getName());
                straux.append('\n')        ;
    }
    return straux;
}
GHNode * GHGrafo::extractMin(QList<GHNode*> *list)
{
    GHNode *minnode = list->first();
    int key = minnode->getKey();
    for(int i=1;i<list->count();i++)
    {
        if (list->at(i)->getNumberChanged())
        {
            if (list->at(i)->getKey()<=key)
            {
                minnode = list->at(i);
                key = minnode->getKey();
            }
        }
    }
    list->removeAll(minnode);
    return minnode;
}

GHNode *GHGrafo::findByName(QString name)
{    
    foreach( GHNode *ghnode, *GHNodelist )
    {        
        if( ghnode->getName()==name )
        {            
            return ghnode;
        }
    }
    return NULL;
}

void GHGrafo::connectNodes(GHNode *ghnode1, GHNode *ghnode2, int weight)
{
    GHEdge *edge = new GHEdge();
    edge->setStartNode(ghnode1);
    edge->setEndNode(ghnode2);
    edge->setWeight(weight);
    ghnode1->getArrowList()->append(edge);
    ghnode2->getArrowList()->append(edge);
}

bool GHGrafo::hasEdge(GHEdge *edge)
{
    foreach( GHEdge *current, getAllArrows() ){
        if( current==edge ){
            return true;
        }
    }
    return false;
}

bool GHGrafo::hasNode(GHNode *node)
{
    foreach( GHNode *current, *GHNodelist ){
        if( node==current ){
            return true;
        }
    }
    return false;
}

void GHGrafo::deepFirstSearch(GHNode *node,int *time)
{
    node->setColor(GHNode::GRAY);
    *time = *time + 1;
    node->setTimeD(*time);
    node->printNodeState();
    switch(grafotype){
    case GHGrafo::ORIENTED:
        foreach (GHNode*nodeadj, GHNode::getAdjacentOrientedNodes(node)) {
            if (nodeadj->getColor()==GHNode::WHITE)
            {
                deepFirstSearch(nodeadj,time);
            }
        }
    break;
    case GHGrafo::NOT_ORIENTED:
        foreach (GHNode*nodeadj, GHNode::getAdjacentNodes(node)) {
            if (nodeadj->getColor()==GHNode::WHITE)
            {
                deepFirstSearch(nodeadj,time);
            }
        }
    break;
    default:
    break;
    }
    node->setColor(GHNode::BLACK);
    *time = *time+1;
    node->setTimeF(*time);
    node->printNodeState();
}

QString GHGrafo::checkConectivity()
{
    QString aux;
    QList<GHNode*> conectednodes;
    GHNode *firstnode = this->getGHNodeList()->at(0);
    checkAdjacentsConectivity(&conectednodes, firstnode);
    if (conectednodes.count() == this->getGHNodeList()->count())
    {
        return "O grafo é conexo";
    }
    else
    {
        return "O grafo é desconexo com: "+QString::number(conectednodes.count())+" nós";
    }
}


void GHGrafo::checkAdjacentsConectivity(QList<GHNode*> *conectedNodes, GHNode* node){
    if (!(conectedNodes->contains(node)))
    {
        conectedNodes->append(node);
        //checkAdjacentsConectivity();
        foreach(GHNode *adjacentnode, node->getAdjacentNodes(node))
        {
            checkAdjacentsConectivity(conectedNodes,adjacentnode);
        }
    }
}

void GHGrafo::initializes(GHNode *node)
{
    foreach( GHNode *current, *GHNodelist )
    {
        current->setDistance(9999);
        current->setParent(NULL);
    }
    node->setDistance(0);
}

void GHGrafo::relax(GHNode *u, GHNode *v, GHEdge *edge)
{
    if( edge==NULL )
    {
        return;
    }
    else if( v->getDistance()>u->getDistance()+edge->getWeight() )
    {
        v->setDistance(u->getDistance()+edge->getWeight());
        v->setParent(u);
    }
}

QString GHGrafo::bellmanford(GHNode *s)
{
    initializes(s);

    int numbernodes = GHNodelist->count();
    for( int i=0; numbernodes>i; i++ )
    {
        foreach( GHEdge *edge, getAllArrows() )
        {
            relax(edge->getStartNode(),edge->getEndNode(),edge);
        }
    }

    foreach( GHEdge *edge, getAllArrows() )
    {
        GHNode *u = edge->getStartNode();
        GHNode *v = edge->getEndNode();
        if( v->getDistance()>u->getDistance()+edge->getWeight() )
        {
            return "falso";
        }
    }

    //PARA VERIFICACAO DA RESPOSTA SE ESTA CERTO OU NAO
    //A RESPOSTA ESTA NA VARIAVEL nos nós pai do GHNodelist
    QString straux;
    foreach( GHNode *node, *GHNodelist )
    {
        if( node->getParent()==NULL )
        {
            straux.append(node->getName() + ": NULL");
            straux.append('\n');
        }
        else
        {
            straux.append(node->getName() +": " + node->getParent()->getName());
            straux.append('\n');
        }
    }

    return "verdadeiro: \n" + straux;
}

QString GHGrafo::dijsktra(GHNode *node)
{
    initializes(node);

    QList<GHNode*> solution;
    QList<GHNode*> *temporarynode = new QList<GHNode*>(*GHNodelist);

    while( !temporarynode->isEmpty() )
    {
        //---------------------------------------------
        GHNode *u = temporarynode->first();
        int distance = u->getDistance();
        for(int i=1;i<temporarynode->count();i++)
        {
            if (temporarynode->at(i)->getDistance()<distance)
            {
                u = temporarynode->at(i);
                distance = u->getDistance();
            }
        }
        temporarynode->removeAll(u);
        //---------------------------------------------
        solution.append(u);

        foreach( GHNode *v, GHNode::getAdjacentNodes(u) )
        {
            relax(u,v,findEdgeWith(u,v));
        }
    }

    //PARA VERIFICACAO DA RESPOSTA SE ESTA CERTO OU NAO
    //A RESPOSTA ESTA NO VARIAVEL solution
    QString straux;
    foreach( GHNode *node, solution )
    {
        if( node->getParent()==NULL )
        {
            straux.append(node->getName() + ": NULL");
            straux.append('\n');
        }
        else
        {
            straux.append(node->getName() +": " + node->getParent()->getName());
            straux.append('\n');
        }
    }
    return straux;
}

// FOR DEFAULT, 0 mean that the node has no color

QString GHGrafo::deepSearchColor()
{
    QList<GHNode*> *temporarynode = new QList<GHNode*>(*GHNodelist);

    // initialize
    foreach( GHNode *node, *temporarynode )
    {
        node->setColorIndex(0);
    }

    nodesColor(temporarynode->first());

    //PARA VERIFICACAO DA RESPOSTA SE ESTA CERTO OU NAO
    //A RESPOSTA ESTA NO VARIAVEL temporarynode
    QString straux = "";
    int amountColor = 0;
    foreach( GHNode *node, *temporarynode )
    {
        qDebug() << node->getName() + ": " + QString::number(node->getColorIndex()) + "\n";

        straux.append("node de nome " + node->getName() + " de cor " + QString::number(node->getColorIndex()));
        straux.append("\n");

        if( node->getColorIndex()>amountColor )
        {
            amountColor = node->getColorIndex();
        }
    }

    straux.append("Quantidade de cores: " + QString::number(amountColor));

    return straux;
}

void GHGrafo::nodesColor(GHNode *node)
{
    if( node->getColorIndex()==0 )
    {
        int color = searchForColor(node,1);
        node->setColorIndex(color);

        foreach( GHNode *sidenode, node->getAdjacentNodes(node) )
        {
            nodesColor(sidenode);
        }
    }
}

int GHGrafo::searchForColor(GHNode *node, int color)
{
    bool hasChange = true;
    int i=0;

    while(hasChange)
    {
        int size = node->getAdjacentNodes(node).size();
        for(; i<size; i++ )
        {
            GHNode *sidenode = node->getAdjacentNodes(node).at(i);
            if( color != sidenode->getColorIndex() )
            {
                hasChange = false;
            }
            else
            {
                hasChange = true;
                ++color;
                i = 0;
            }
        }
    }
    return color;
}

GHGrafo * GHGrafo::generateTranposedGraph()
{
    GHGrafo *ghgrafocopy = new GHGrafo();
    ghgrafocopy->setGrafoType(GHGrafo::ORIENTED);
    ghgrafocopy->setGHNodeList(new QList<GHNode*>(*GHNodelist));

    QList<GHEdge*> list = ghgrafocopy->getAllArrows();
    foreach( GHEdge *edge, list )
    {
        GHNode *nodeaux = edge->getStartNode();
        edge->setStartNode(edge->getEndNode());
        edge->setEndNode(nodeaux);
    }
    return ghgrafocopy;
}

GHEdge *GHGrafo::findEdgeWith(GHNode *u, GHNode *v)
{
    if (u==NULL || v==NULL)
    {
        return NULL;
    }
    foreach( GHEdge *edge, *u->getArrowList() )
    {
        if( (edge->getStartNode()==u && edge->getEndNode()==v))
        {
            return edge;
        }
    }
    return NULL;
}

GHEdge *GHGrafo::findPrimEdgeWith(GHNode *u, GHNode *v)
{
    if (u==NULL || v==NULL)
        return NULL;
    foreach( GHEdge *edge, *u->getArrowList() ){
        if( (edge->getStartNode()==u && edge->getEndNode()==v) ||
                (edge->getStartNode()==v && edge->getEndNode()==u))
            return edge;
    }
    return NULL;
}

QString GHGrafo::getFileContent()
{
    return filecontent;
}
QStringList GHGrafo::getVertexNames()
{
    QStringList list;
    foreach (GHNode*node, *(this->getGHNodeList())) {
        list.append(node->getName());
    }
    return list;
}

QList<GHEdge *> GHGrafo::getAllEdgeTimes()
{
    QList<GHEdge *> arrowlist ;
    foreach(GHNode*node, *GHNodelist )
    {
       arrowlist.append(* node->getArrowList());
    }
    qDebug()<<"sizeeeee"<<arrowlist.size();
}



