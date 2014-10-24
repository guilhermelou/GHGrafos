#include "groupboxoption.h"
#include "ui_groupboxoption.h"

GroupBoxOption::GroupBoxOption(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GroupBoxOption)
{
    ui->setupUi(this);
}

GroupBoxOption::~GroupBoxOption()
{
    delete ui;
}

void GroupBoxOption::on_btndeepsearch_clicked()
{
    emit btndeepsearch_clicked();
}

void GroupBoxOption::on_btndeepsearchcolor_clicked()
{
    emit btndeepsearchcolor_clicked();
}

void GroupBoxOption::on_btnbreadhsearch_clicked()
{
    emit btnbreadhsearch_clicked();
}

void GroupBoxOption::on_btnconectivity_clicked()
{
    emit btnconectivity_clicked();
}

void GroupBoxOption::on_btnprim_clicked()
{
    emit btnprim_clicked();

}

void GroupBoxOption::on_btnkruskal_clicked()
{
    emit btnkruskal_clicked();
}

void GroupBoxOption::on_btndjkstra_clicked()
{
    emit btndjkstra_clicked();
}

void GroupBoxOption::on_btnbellmanford_clicked()
{
    emit  btnbellmanford_clicked();
}

void GroupBoxOption::on_cbxstartnode_currentIndexChanged(const QString &arg1)
{
    emit cbxstartnode_currentIndexChanged(arg1);
}

void GroupBoxOption::on_cbxfinalnode_currentIndexChanged(const QString &arg1)
{
    emit cbxfinalnode_currentIndexChanged(arg1);
}

void GroupBoxOption::on_btngeneratetranposed_clicked()
{
    emit btngeneratetransposed_clicked();
}

void GroupBoxOption::on_btnbarrier_clicked()
{
    emit btnbarrier();
}

QString GroupBoxOption::getCbxStartNodeContent()
{
    return ui->cbxstartnode->currentText();
}

QString GroupBoxOption::getCbxFinalNodeContent()
{
    return ui->cbxfinalnode->currentText();
}

void GroupBoxOption::setNameNodes(QStringList aux)
{
    ui->cbxfinalnode->clear();
    ui->cbxfinalnode->addItems(aux);
    ui->cbxstartnode->clear();
    ui->cbxstartnode->addItems(aux);
}

void GroupBoxOption::on_btntopologicalsort_clicked()
{
    emit btntopologicalsort();
}
