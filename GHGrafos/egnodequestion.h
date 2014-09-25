#ifndef EGNODEQUESTION_H
#define EGNODEQUESTION_H

#include <QObject>
#include "egnode.h"
#include "egquestion.h"
class EGNodeQuestion : public EGNode
{
    Q_OBJECT
public:
    explicit EGNodeQuestion(EGNode *parent = 0);

    //set's
    void setListQuestion(QList<EGQuestion*> list);
    void setRandomQuestion(bool isrand);
    //~set's

    //get's
    QList<EGQuestion*> getListQuestion();
    bool isRandomQuestion();
    //~get's
    
signals:
    
public slots:

private:
    QList<EGQuestion*> listquestion;
    bool israndomquestion;

    
};

#endif // EGNODEQUESTION_H
