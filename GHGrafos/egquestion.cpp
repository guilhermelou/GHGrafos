#include "egquestion.h"

EGQuestion::EGQuestion(QObject *parent) :
    QObject(parent)
{
}

EGQuestion::EGQuestion(int id, QString question, QObject *parent):
    QObject(parent)
{
    this->id = id;
    this->question = question;
}

int EGQuestion::getId()
{
    return this->id;
}

QString EGQuestion::getQuestion()
{
    return this->question;
}

void EGQuestion::setId(int id)
{
    this->id = id;
}

void EGQuestion::setQuestion(QString question)
{
    this->question = question;
}
