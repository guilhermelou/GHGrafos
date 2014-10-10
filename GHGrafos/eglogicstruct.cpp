#include "eglogicstruct.h"

EGLogicStruct::EGLogicStruct(QObject *parent) :
    QObject(parent)
{
}

EGLogicStruct::EGLogicStruct(int ID)
{
    //inicialização de variáveis
    this->currentid = ID;
}

//---------------Set's;
void EGLogicStruct::setId(int id)
{
    this->currentid = id;
}

//---------------Get's;
int EGLogicStruct::getId()
{
    return (currentid);
}
