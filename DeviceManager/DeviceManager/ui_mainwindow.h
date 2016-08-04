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
    QAction *actionInsertTag;
    QAction *actionDelete;
    QAction *actionInsertSubTag;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    XMLWidget *xmlFrame;
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
        actionInsertTag = new QAction(MainWindow);
        actionInsertTag->setObjectName(QStringLiteral("actionInsertTag"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionInsertSubTag = new QAction(MainWindow);
        actionInsertSubTag->setObjectName(QStringLiteral("actionInsertSubTag"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        xmlFrame = new XMLWidget(centralWidget);
        xmlFrame->setObjectName(QStringLiteral("xmlFrame"));
        xmlFrame->setFrameShape(QFrame::StyledPanel);
        xmlFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(xmlFrame);

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
        menuEdit->addAction(actionInsertTag);
        menuEdit->addAction(actionInsertSubTag);
        menuEdit->addAction(actionDelete);

        retranslateUi(MainWindow);

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
        actionInsertTag->setText(QApplication::translate("MainWindow", "Insert tag", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete tag", 0));
        actionInsertSubTag->setText(QApplication::translate("MainWindow", "Insert subtag", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
