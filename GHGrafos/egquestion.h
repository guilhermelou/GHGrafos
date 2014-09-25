#ifndef EGQUESTION_H
#define EGQUESTION_H

#include <QObject>

class EGQuestion : public QObject
{
    Q_OBJECT
public:
    explicit EGQuestion(QObject *parent = 0);
    EGQuestion (int id, QString question, QObject *parent=0);
    int getId();
    QString getQuestion();
    void setId(int id);
    void setQuestion(QString question);
signals:
    
public slots:
private:
    int id;
    QString question;
    
};

#endif // EGQUESTION_H
