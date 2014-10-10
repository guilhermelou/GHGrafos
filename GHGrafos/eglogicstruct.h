#ifndef EGLOGICSTRUCT_H
#define EGLOGICSTRUCT_H

#include <QObject>

class EGLogicStruct : public QObject
{
    Q_OBJECT
public:
    explicit EGLogicStruct(QObject *parent = 0);
    EGLogicStruct(int ID);

    //sets
    void setId(int id);
    //~sets

    //gets
    int getId();
    //~gets
    
signals:
    
public slots:

private:
    int currentid;
    
};

#endif // EGLOGICSTRUCT_H
