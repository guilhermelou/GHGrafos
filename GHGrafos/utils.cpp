#include "utils.h"

Utils::Utils(QObject *parent) :
    QObject(parent)
{
}

QList<GHEdge *> Utils::bubbleSort(QList<GHEdge *> edges)
{    
    int k = edges.count()-1 ;

    for( int i=0; i<edges.count(); i++)
    {
       for( int j=0; j<k; j++)
       {
          if( edges.at(j)->getWeight() > edges.at(j+1)->getWeight() )
          {
              GHEdge *edge = edges.at(j);
              edges.replace(j,edges.at(j+1));
              edges.replace(j+1,edge);
          }
       }
       k--;
    }
    return edges;
}
