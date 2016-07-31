#ifndef XMLWIDGET_H
#define XMLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QTreeView>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QItemSelectionModel>
#include <QLabel>
#include "treemodel.h"

class XMLWidget : public QFrame
{
    Q_OBJECT
public:
    XMLWidget(QWidget *parent = Q_NULLPTR);
    ~XMLWidget();
public slots:
    void slotOpen();
    void slotSave();
    void slotSaveAs();
    void slotToOldFormat();
    void slotToNewFormat();
    void slotViewResize();
    void slotRevertAll();
    void slotInsertTag();
    void slotInsertSubTag();
    void slotDelete();
private:
    QLabel* mCurrentFileLabel;
    QTreeView* mTreeView;
    TreeModel* mModel;
    QItemSelectionModel* mSelectionModel;
    void updateFileLabel(const QString& filename);
    void build();
};

#endif // XMLWIDGET_H
