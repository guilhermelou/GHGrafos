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
    QWidget *widget;
    QVBoxLayout *verticalLayout;
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
        GroupBoxOption->resize(400, 300);
        widget = new QWidget(GroupBoxOption);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(12, 20, 326, 89));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btndeepsearch = new QPushButton(widget);
        btndeepsearch->setObjectName(QStringLiteral("btndeepsearch"));

        horizontalLayout->addWidget(btndeepsearch);

        btnbreadhsearch = new QPushButton(widget);
        btnbreadhsearch->setObjectName(QStringLiteral("btnbreadhsearch"));

        horizontalLayout->addWidget(btnbreadhsearch);

        btnconectivity = new QPushButton(widget);
        btnconectivity->setObjectName(QStringLiteral("btnconectivity"));

        horizontalLayout->addWidget(btnconectivity);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnprim = new QPushButton(widget);
        btnprim->setObjectName(QStringLiteral("btnprim"));

        horizontalLayout_2->addWidget(btnprim);

        btnkruskal = new QPushButton(widget);
        btnkruskal->setObjectName(QStringLiteral("btnkruskal"));

        horizontalLayout_2->addWidget(btnkruskal);

        btndjkstra = new QPushButton(widget);
        btndjkstra->setObjectName(QStringLiteral("btndjkstra"));

        horizontalLayout_2->addWidget(btndjkstra);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnbellmanford = new QPushButton(widget);
        btnbellmanford->setObjectName(QStringLiteral("btnbellmanford"));

        horizontalLayout_3->addWidget(btnbellmanford);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        cbxstartnode = new QComboBox(widget);
        cbxstartnode->setObjectName(QStringLiteral("cbxstartnode"));

        horizontalLayout_3->addWidget(cbxstartnode);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        cbxfinalnode = new QComboBox(widget);
        cbxfinalnode->setObjectName(QStringLiteral("cbxfinalnode"));

        horizontalLayout_3->addWidget(cbxfinalnode);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(GroupBoxOption);

        QMetaObject::connectSlotsByName(GroupBoxOption);
    } // setupUi

    void retranslateUi(QGroupBox *GroupBoxOption)
    {
        GroupBoxOption->setWindowTitle(QApplication::translate("GroupBoxOption", "GroupBox", 0));
        GroupBoxOption->setTitle(QApplication::translate("GroupBoxOption", "Algor\303\255tmos", 0));
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
