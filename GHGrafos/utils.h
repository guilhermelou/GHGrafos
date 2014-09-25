#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <ghedge.h>

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = 0);

    static QList<GHEdge*> bubbleSort(QList<GHEdge*> edges);

signals:

public slots:

};

#endif // UTILS_H
