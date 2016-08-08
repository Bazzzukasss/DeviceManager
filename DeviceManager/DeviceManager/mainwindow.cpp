#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen,             SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotOpen()));
    connect(ui->actionSave,             SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotSave()));
    connect(ui->actionSaveAs,           SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotSaveAs()));
    connect(ui->actionDuplicate,        SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotDuplicate()));
    connect(ui->actionDelete,           SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotDelete()));
    connect(ui->actionAdd,              SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotAdd()));

    ui->mainToolBar->addAction("Open",ui->xmlFrame,SLOT(slotOpen()));
    ui->mainToolBar->addAction("Save",ui->xmlFrame,SLOT(slotSave()));
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction("Add",ui->xmlFrame,SLOT(slotAdd()));
    ui->mainToolBar->addAction("Delete",ui->xmlFrame,SLOT(slotDelete()));
    ui->mainToolBar->addAction("Duplicate",ui->xmlFrame,SLOT(slotDuplicate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
