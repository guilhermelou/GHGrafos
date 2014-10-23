/********************************************************************************
** Form generated from reading UI file 'groupboxoption.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPBOXOPTION_H
#define UI_GROUPBOXOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupBoxOption
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnbarrier;
    QPushButton *btngeneratetranposed;
    QPushButton *btndeepsearchcolor;
    QHBoxLayout *horizontalLayout;
    QPushButton *btndeepsearch;
    QPushButton *btnbreadhsearch;
    QPushButton *btnconectivity;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnprim;
    QPushButton *btnkruskal;
    QPushButton *btndjkstra;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnbellmanford;
    QLabel *label;
    QComboBox *cbxstartnode;
    QLabel *label_2;
    QComboBox *cbxfinalnode;

    void setupUi(QGroupBox *GroupBoxOption)
    {
        if (GroupBoxOption->objectName().isEmpty())
            GroupBoxOption->setObjectName(QStringLiteral("GroupBoxOption"));
        GroupBoxOption->resize(645, 362);
        layoutWidget = new QWidget(GroupBoxOption);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 20, 641, 120));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnbarrier = new QPushButton(layoutWidget);
        btnbarrier->setObjectName(QStringLiteral("btnbarrier"));

        horizontalLayout_4->addWidget(btnbarrier);

        btngeneratetranposed = new QPushButton(layoutWidget);
        btngeneratetranposed->setObjectName(QStringLiteral("btngeneratetranposed"));

        horizontalLayout_4->addWidget(btngeneratetranposed);

        btndeepsearchcolor = new QPushButton(layoutWidget);
        btndeepsearchcolor->setObjectName(QStringLiteral("btndeepsearchcolor"));

        horizontalLayout_4->addWidget(btndeepsearchcolor);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btndeepsearch = new QPushButton(layoutWidget);
        btndeepsearch->setObjectName(QStringLiteral("btndeepsearch"));

        horizontalLayout->addWidget(btndeepsearch);

        btnbreadhsearch = new QPushButton(layoutWidget);
        btnbreadhsearch->setObjectName(QStringLiteral("btnbreadhsearch"));

        horizontalLayout->addWidget(btnbreadhsearch);

        btnconectivity = new QPushButton(layoutWidget);
        btnconectivity->setObjectName(QStringLiteral("btnconectivity"));

        horizontalLayout->addWidget(btnconectivity);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnprim = new QPushButton(layoutWidget);
        btnprim->setObjectName(QStringLiteral("btnprim"));

        horizontalLayout_2->addWidget(btnprim);

        btnkruskal = new QPushButton(layoutWidget);
        btnkruskal->setObjectName(QStringLiteral("btnkruskal"));

        horizontalLayout_2->addWidget(btnkruskal);

        btndjkstra = new QPushButton(layoutWidget);
        btndjkstra->setObjectName(QStringLiteral("btndjkstra"));

        horizontalLayout_2->addWidget(btndjkstra);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnbellmanford = new QPushButton(layoutWidget);
        btnbellmanford->setObjectName(QStringLiteral("btnbellmanford"));

        horizontalLayout_3->addWidget(btnbellmanford);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        cbxstartnode = new QComboBox(layoutWidget);
        cbxstartnode->setObjectName(QStringLiteral("cbxstartnode"));

        horizontalLayout_3->addWidget(cbxstartnode);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        cbxfinalnode = new QComboBox(layoutWidget);
        cbxfinalnode->setObjectName(QStringLiteral("cbxfinalnode"));

        horizontalLayout_3->addWidget(cbxfinalnode);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget->raise();
        btndeepsearchcolor->raise();

        retranslateUi(GroupBoxOption);

        QMetaObject::connectSlotsByName(GroupBoxOption);
    } // setupUi

    void retranslateUi(QGroupBox *GroupBoxOption)
    {
        GroupBoxOption->setWindowTitle(QApplication::translate("GroupBoxOption", "GroupBox", 0));
        GroupBoxOption->setTitle(QApplication::translate("GroupBoxOption", "Algor\303\255tmos", 0));
        btnbarrier->setText(QApplication::translate("GroupBoxOption", "Barreira", 0));
        btngeneratetranposed->setText(QApplication::translate("GroupBoxOption", "Transpor", 0));
        btndeepsearchcolor->setText(QApplication::translate("GroupBoxOption", "Colora\303\247\303\243o", 0));
        btndeepsearch->setText(QApplication::translate("GroupBoxOption", "Busca em profundidade", 0));
        btnbreadhsearch->setText(QApplication::translate("GroupBoxOption", "Busca em largura", 0));
        btnconectivity->setText(QApplication::translate("GroupBoxOption", "Checar conexidade", 0));
        btnprim->setText(QApplication::translate("GroupBoxOption", "Prim", 0));
        btnkruskal->setText(QApplication::translate("GroupBoxOption", "Kruskal", 0));
        btndjkstra->setText(QApplication::translate("GroupBoxOption", "Dijkstra", 0));
        btnbellmanford->setText(QApplication::translate("GroupBoxOption", "Bellman-Ford", 0));
        label->setText(QApplication::translate("GroupBoxOption", "N\303\263 inicial", 0));
        label_2->setText(QApplication::translate("GroupBoxOption", "N\303\263 final", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupBoxOption: public Ui_GroupBoxOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPBOXOPTION_H
