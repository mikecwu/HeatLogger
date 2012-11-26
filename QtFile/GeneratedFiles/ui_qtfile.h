/********************************************************************************
** Form generated from reading UI file 'qtfile.ui'
**
** Created: Fri Oct 19 13:19:22 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTFILE_H
#define UI_QTFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QtFileClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Disp_Temp;
    QLabel *Disp_Hum;
    QGridLayout *gridLayout_2;
    QCustomPlot *qCustomGraph;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *Hum_Mean;
    QRadioButton *Hum_Radio;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLabel *Hum_Median;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLabel *Hum_STD;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLabel *Hum_Max;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_7;
    QLabel *Hum_Min;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *Single_Mode;
    QRadioButton *Continious_Mode;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_25;
    QLabel *Alarm_Status;
    QPushButton *Suppress_Button;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QLabel *Temp_Label;
    QRadioButton *Temp_Radio;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLabel *Temp_Median;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_15;
    QLabel *Temp_STD;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QLabel *Temp_Max;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QLabel *Temp_Min;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *From_Label;
    QLabel *label_23;
    QLabel *To_Label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtFileClass)
    {
        if (QtFileClass->objectName().isEmpty())
            QtFileClass->setObjectName(QString::fromUtf8("QtFileClass"));
        QtFileClass->resize(1040, 599);
        centralWidget = new QWidget(QtFileClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(316, 105));
        widget_7->setMaximumSize(QSize(316, 105));
        verticalLayout_7 = new QVBoxLayout(widget_7);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(34);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Disp_Temp = new QLabel(widget_7);
        Disp_Temp->setObjectName(QString::fromUtf8("Disp_Temp"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        Disp_Temp->setFont(font);
        Disp_Temp->setFrameShape(QFrame::Box);
        Disp_Temp->setLineWidth(1);
        Disp_Temp->setMidLineWidth(1);
        Disp_Temp->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(Disp_Temp);

        Disp_Hum = new QLabel(widget_7);
        Disp_Hum->setObjectName(QString::fromUtf8("Disp_Hum"));
        Disp_Hum->setFont(font);
        Disp_Hum->setFrameShape(QFrame::Box);
        Disp_Hum->setLineWidth(1);
        Disp_Hum->setMidLineWidth(1);
        Disp_Hum->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(Disp_Hum);


        verticalLayout_7->addLayout(horizontalLayout_4);


        gridLayout_3->addWidget(widget_7, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        qCustomGraph = new QCustomPlot(centralWidget);
        qCustomGraph->setObjectName(QString::fromUtf8("qCustomGraph"));
        qCustomGraph->setMinimumSize(QSize(480, 190));

        gridLayout_2->addWidget(qCustomGraph, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 2, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(316, 0));
        tableWidget->setMaximumSize(QSize(316, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::DashDotLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(20);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(14);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(tableWidget, 1, 1, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(201, 131));
        groupBox_2->setMaximumSize(QSize(201, 131));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(56, 13));

        horizontalLayout_8->addWidget(label_3);

        Hum_Mean = new QLabel(groupBox_2);
        Hum_Mean->setObjectName(QString::fromUtf8("Hum_Mean"));
        Hum_Mean->setMinimumSize(QSize(0, 14));
        Hum_Mean->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(Hum_Mean);

        Hum_Radio = new QRadioButton(groupBox_2);
        Hum_Radio->setObjectName(QString::fromUtf8("Hum_Radio"));
        Hum_Radio->setLayoutDirection(Qt::RightToLeft);
        Hum_Radio->setAutoRepeatDelay(0);

        horizontalLayout_8->addWidget(Hum_Radio);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        Hum_Median = new QLabel(groupBox_2);
        Hum_Median->setObjectName(QString::fromUtf8("Hum_Median"));
        Hum_Median->setMinimumSize(QSize(0, 14));

        horizontalLayout_9->addWidget(Hum_Median);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        Hum_STD = new QLabel(groupBox_2);
        Hum_STD->setObjectName(QString::fromUtf8("Hum_STD"));
        Hum_STD->setMinimumSize(QSize(0, 14));

        horizontalLayout_10->addWidget(Hum_STD);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_11->addWidget(label_6);

        Hum_Max = new QLabel(groupBox_2);
        Hum_Max->setObjectName(QString::fromUtf8("Hum_Max"));
        Hum_Max->setMinimumSize(QSize(0, 14));

        horizontalLayout_11->addWidget(Hum_Max);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_12->addWidget(label_7);

        Hum_Min = new QLabel(groupBox_2);
        Hum_Min->setObjectName(QString::fromUtf8("Hum_Min"));
        Hum_Min->setMinimumSize(QSize(0, 14));

        horizontalLayout_12->addWidget(Hum_Min);


        verticalLayout_5->addLayout(horizontalLayout_12);


        gridLayout->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(181, 83));
        groupBox->setMaximumSize(QSize(16777215, 83));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Single_Mode = new QRadioButton(groupBox);
        Single_Mode->setObjectName(QString::fromUtf8("Single_Mode"));

        verticalLayout_3->addWidget(Single_Mode);

        Continious_Mode = new QRadioButton(groupBox);
        Continious_Mode->setObjectName(QString::fromUtf8("Continious_Mode"));

        verticalLayout_3->addWidget(Continious_Mode);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(181, 83));
        groupBox_4->setMaximumSize(QSize(16777215, 83));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout->addWidget(label_25);

        Alarm_Status = new QLabel(groupBox_4);
        Alarm_Status->setObjectName(QString::fromUtf8("Alarm_Status"));

        horizontalLayout->addWidget(Alarm_Status);


        verticalLayout_4->addLayout(horizontalLayout);

        Suppress_Button = new QPushButton(groupBox_4);
        Suppress_Button->setObjectName(QString::fromUtf8("Suppress_Button"));

        verticalLayout_4->addWidget(Suppress_Button);


        gridLayout->addWidget(groupBox_4, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(201, 131));
        groupBox_3->setMaximumSize(QSize(201, 131));
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_7->addWidget(label_13);

        Temp_Label = new QLabel(groupBox_3);
        Temp_Label->setObjectName(QString::fromUtf8("Temp_Label"));
        Temp_Label->setMinimumSize(QSize(0, 14));

        horizontalLayout_7->addWidget(Temp_Label);

        Temp_Radio = new QRadioButton(groupBox_3);
        Temp_Radio->setObjectName(QString::fromUtf8("Temp_Radio"));
        Temp_Radio->setLayoutDirection(Qt::RightToLeft);
        Temp_Radio->setAutoRepeatDelay(0);

        horizontalLayout_7->addWidget(Temp_Radio);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_6->addWidget(label_14);

        Temp_Median = new QLabel(groupBox_3);
        Temp_Median->setObjectName(QString::fromUtf8("Temp_Median"));
        Temp_Median->setMinimumSize(QSize(0, 14));

        horizontalLayout_6->addWidget(Temp_Median);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_5->addWidget(label_15);

        Temp_STD = new QLabel(groupBox_3);
        Temp_STD->setObjectName(QString::fromUtf8("Temp_STD"));
        Temp_STD->setMinimumSize(QSize(0, 14));

        horizontalLayout_5->addWidget(Temp_STD);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_3->addWidget(label_16);

        Temp_Max = new QLabel(groupBox_3);
        Temp_Max->setObjectName(QString::fromUtf8("Temp_Max"));
        Temp_Max->setMinimumSize(QSize(0, 14));

        horizontalLayout_3->addWidget(Temp_Max);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_2->addWidget(label_17);

        Temp_Min = new QLabel(groupBox_3);
        Temp_Min->setObjectName(QString::fromUtf8("Temp_Min"));
        Temp_Min->setMinimumSize(QSize(0, 14));

        horizontalLayout_2->addWidget(Temp_Min);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        From_Label = new QLabel(centralWidget);
        From_Label->setObjectName(QString::fromUtf8("From_Label"));

        verticalLayout->addWidget(From_Label);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font1);

        verticalLayout->addWidget(label_23);

        To_Label = new QLabel(centralWidget);
        To_Label->setObjectName(QString::fromUtf8("To_Label"));

        verticalLayout->addWidget(To_Label);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);

        QtFileClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtFileClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtFileClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtFileClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtFileClass->setStatusBar(statusBar);

        retranslateUi(QtFileClass);

        QMetaObject::connectSlotsByName(QtFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtFileClass)
    {
        QtFileClass->setWindowTitle(QApplication::translate("QtFileClass", "QtFile", 0, QApplication::UnicodeUTF8));
        Disp_Temp->setText(QApplication::translate("QtFileClass", "100C", 0, QApplication::UnicodeUTF8));
        Disp_Hum->setText(QApplication::translate("QtFileClass", "100%", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QtFileClass", "TimeStamp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QtFileClass", "Temp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("QtFileClass", "Humidity", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("QtFileClass", "Humidity", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QtFileClass", "Mean:", 0, QApplication::UnicodeUTF8));
        Hum_Mean->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        Hum_Radio->setText(QString());
        label_4->setText(QApplication::translate("QtFileClass", "Median:", 0, QApplication::UnicodeUTF8));
        Hum_Median->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QtFileClass", "Standard Deviation:", 0, QApplication::UnicodeUTF8));
        Hum_STD->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QtFileClass", "Maximun:", 0, QApplication::UnicodeUTF8));
        Hum_Max->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QtFileClass", "Minimun:", 0, QApplication::UnicodeUTF8));
        Hum_Min->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QtFileClass", "Sample Mode", 0, QApplication::UnicodeUTF8));
        Single_Mode->setText(QApplication::translate("QtFileClass", "Single Sample", 0, QApplication::UnicodeUTF8));
        Continious_Mode->setText(QApplication::translate("QtFileClass", "Continious", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("QtFileClass", "Alarm", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("QtFileClass", "Alarm State:", 0, QApplication::UnicodeUTF8));
        Alarm_Status->setText(QApplication::translate("QtFileClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        Suppress_Button->setText(QApplication::translate("QtFileClass", "Suppress", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("QtFileClass", "Temperature", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QtFileClass", "Mean:", 0, QApplication::UnicodeUTF8));
        Temp_Label->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        Temp_Radio->setText(QString());
        label_14->setText(QApplication::translate("QtFileClass", "Median:", 0, QApplication::UnicodeUTF8));
        Temp_Median->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QtFileClass", "Standard Deviation:", 0, QApplication::UnicodeUTF8));
        Temp_STD->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("QtFileClass", "Maximun:", 0, QApplication::UnicodeUTF8));
        Temp_Max->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("QtFileClass", "Minimun:", 0, QApplication::UnicodeUTF8));
        Temp_Min->setText(QApplication::translate("QtFileClass", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QtFileClass", "From", 0, QApplication::UnicodeUTF8));
        From_Label->setText(QApplication::translate("QtFileClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("QtFileClass", "To", 0, QApplication::UnicodeUTF8));
        To_Label->setText(QApplication::translate("QtFileClass", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtFileClass: public Ui_QtFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTFILE_H
