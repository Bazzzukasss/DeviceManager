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
    connect(ui->actionToNewFormat,      SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotToNewFormat()));
    connect(ui->actionToOldFormat,      SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotToOldFormat()));
    connect(ui->actionDuplicate,        SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotDuplicate()));
    connect(ui->actionInsertSubTag,     SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotInsertSubTag()));
    connect(ui->actionDelete,           SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotDelete()));
    connect(ui->actionAdd,              SIGNAL(triggered(bool)),    ui->xmlFrame,   SLOT(slotAdd()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
