/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <xmlwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionOpen;
    QAction *actionToOldFormat;
    QAction *actionToNewFormat;
    QAction *actionDuplicate;
    QAction *actionDelete;
    QAction *actionInsertSubTag;
    QAction *actionAddHWDevice;
    QAction *actionAddDeviceProperty;
    QAction *actionAdd;
    QAction *actionAddPrismDevice;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    XMLWidget *xmlFrame;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1115, 667);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionToOldFormat = new QAction(MainWindow);
        actionToOldFormat->setObjectName(QStringLiteral("actionToOldFormat"));
        actionToNewFormat = new QAction(MainWindow);
        actionToNewFormat->setObjectName(QStringLiteral("actionToNewFormat"));
        actionDuplicate = new QAction(MainWindow);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionInsertSubTag = new QAction(MainWindow);
        actionInsertSubTag->setObjectName(QStringLiteral("actionInsertSubTag"));
        actionAddHWDevice = new QAction(MainWindow);
        actionAddHWDevice->setObjectName(QStringLiteral("actionAddHWDevice"));
        actionAddDeviceProperty = new QAction(MainWindow);
        actionAddDeviceProperty->setObjectName(QStringLiteral("actionAddDeviceProperty"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAddPrismDevice = new QAction(MainWindow);
        actionAddPrismDevice->setObjectName(QStringLiteral("actionAddPrismDevice"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        xmlFrame = new XMLWidget(tab);
        xmlFrame->setObjectName(QStringLiteral("xmlFrame"));
        xmlFrame->setFrameShape(QFrame::StyledPanel);
        xmlFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(xmlFrame);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1115, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuEdit->addAction(actionAdd);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionDuplicate);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save as..", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0));
        actionToOldFormat->setText(QApplication::translate("MainWindow", "To old format", 0));
        actionToNewFormat->setText(QApplication::translate("MainWindow", "To new format", 0));
        actionDuplicate->setText(QApplication::translate("MainWindow", "Duplicate", 0));
#ifndef QT_NO_TOOLTIP
        actionDuplicate->setToolTip(QApplication::translate("MainWindow", "Duplicate Device Map,HWDevice,Prism Device,Device Property", 0));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0));
        actionInsertSubTag->setText(QApplication::translate("MainWindow", "Insert subtag", 0));
        actionAddHWDevice->setText(QApplication::translate("MainWindow", "Add HW Device", 0));
        actionAddDeviceProperty->setText(QApplication::translate("MainWindow", "Add DeviceProperty", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        actionAddPrismDevice->setText(QApplication::translate("MainWindow", "Add Prism Device", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Edit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Compare", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
