/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Time;
    QLabel *label_3;
    QLabel *TTime;
    QSlider *Slide;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Open;
    QPushButton *Backward;
    QPushButton *Begin;
    QPushButton *Forward;
    QSlider *Voice;
    QComboBox *comboBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(733, 454);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 246, 255);"));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Time = new QLabel(widget_2);
        Time->setObjectName("Time");
        Time->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(Time);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        TTime = new QLabel(widget_2);
        TTime->setObjectName("TTime");
        TTime->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(TTime);

        Slide = new QSlider(widget_2);
        Slide->setObjectName("Slide");
        Slide->setMaximumSize(QSize(99999, 16777215));
        Slide->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Slide);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        Open = new QPushButton(widget);
        Open->setObjectName("Open");
        Open->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Open->sizePolicy().hasHeightForWidth());
        Open->setSizePolicy(sizePolicy);
        Open->setMinimumSize(QSize(50, 50));
        Open->setMaximumSize(QSize(50, 50));
        Open->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/open.png);"));

        horizontalLayout->addWidget(Open);

        Backward = new QPushButton(widget);
        Backward->setObjectName("Backward");
        Backward->setMinimumSize(QSize(50, 50));
        Backward->setMaximumSize(QSize(50, 50));
        Backward->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/rewind.png);"));

        horizontalLayout->addWidget(Backward);

        Begin = new QPushButton(widget);
        Begin->setObjectName("Begin");
        Begin->setMinimumSize(QSize(50, 50));
        Begin->setMaximumSize(QSize(50, 50));
        Begin->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/play.png);"));

        horizontalLayout->addWidget(Begin);

        Forward = new QPushButton(widget);
        Forward->setObjectName("Forward");
        Forward->setMinimumSize(QSize(50, 50));
        Forward->setMaximumSize(QSize(50, 50));
        Forward->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/forward.png);"));

        horizontalLayout->addWidget(Forward);

        Voice = new QSlider(widget);
        Voice->setObjectName("Voice");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Voice->sizePolicy().hasHeightForWidth());
        Voice->setSizePolicy(sizePolicy1);
        Voice->setMinimumSize(QSize(30, 10));
        Voice->setMaximumSize(QSize(170, 33));
        Voice->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(Voice);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMaximumSize(QSize(58, 20));

        horizontalLayout->addWidget(comboBox);


        gridLayout->addWidget(widget, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        Time->setText(QCoreApplication::translate("Widget", "00 : 00 ", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "/", nullptr));
        TTime->setText(QCoreApplication::translate("Widget", "00 : 00", nullptr));
        Open->setText(QString());
        Backward->setText(QString());
        Begin->setText(QString());
        Forward->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "0.75X", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "1X", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "1.5X", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "2X", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
