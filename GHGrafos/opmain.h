#ifndef OPMAIN_H
#define OPMAIN_H
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "viewmain.h"
#include "ghgrafo.h"


class OpMain : public QObject
{
    Q_OBJECT
public:
    explicit OpMain(QObject *parent = 0);
    void startProgram();
    void initOBjects();
    void connectingObjects();
    void settingView();
public slots:           
    void exitProgram();

private:    
    ViewMain *viewmain;
signals:

    
};

#endif // OPMAIN_H

