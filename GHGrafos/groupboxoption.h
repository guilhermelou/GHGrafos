#ifndef GROUPBOXOPTION_H
#define GROUPBOXOPTION_H

#include <QGroupBox>

namespace Ui {
class GroupBoxOption;
}

class GroupBoxOption : public QGroupBox
{
    Q_OBJECT

public:
    explicit GroupBoxOption(QWidget *parent = 0);
    ~GroupBoxOption();
    QString getCbxStartNodeContent();
    QString getCbxFinalNodeContent();
    void setNameNodes(QStringList aux);
private slots:
    void on_btndeepsearch_clicked();

    void on_btnbreadhsearch_clicked();

    void on_btnconectivity_clicked();

    void on_btnprim_clicked();

    void on_btnkruskal_clicked();

    void on_btndjkstra_clicked();

    void on_btnbellmanford_clicked();

    void on_cbxstartnode_currentIndexChanged(const QString &arg1);

    void on_cbxfinalnode_currentIndexChanged(const QString &arg1);

    void on_btndeepsearchcolor_clicked();

    void on_btngeneratetranposed_clicked();

    void on_btnbarrier_clicked();

    void on_btntopologicalsort_clicked();

signals:
    void btntopologicalsort();

    void btnbarrier();

    void btndeepsearch_clicked();

    void btnbreadhsearch_clicked();

    void btndeepsearchcolor_clicked();

    void btnconectivity_clicked();

    void btnprim_clicked();

    void btnkruskal_clicked();

    void btndjkstra_clicked();

    void btnbellmanford_clicked();

    void btngeneratetransposed_clicked();

    void cbxstartnode_currentIndexChanged(const QString &arg1);

    void cbxfinalnode_currentIndexChanged(const QString &arg1);

private:
    Ui::GroupBoxOption *ui;
};

#endif // GROUPBOXOPTION_H
