#include "egnodequestion.h"

EGNodeQuestion::EGNodeQuestion(EGNode *parent) :
    EGNode(parent)
{
}

void EGNodeQuestion::setListQuestion(QList<EGQuestion *> list)
{
    this->listquestion = list;
}

void EGNodeQuestion::setRandomQuestion(bool isrand)
{
    this->israndomquestion = isrand;
}

QList<EGQuestion *> EGNodeQuestion::getListQuestion()
{
    return this->listquestion;
}

bool EGNodeQuestion::isRandomQuestion()
{
    return this->israndomquestion;
}
