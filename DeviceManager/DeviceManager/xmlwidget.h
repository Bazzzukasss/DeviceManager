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
#include "treeitem.h"

class XMLWidget : public QFrame
{
    Q_OBJECT
public:
    XMLWidget(QWidget *parent = Q_NULLPTR);
    ~XMLWidget();
    void setEditable(bool isEditable);
public slots:
    void slotOpen();
    void slotSave();
    void slotSaveAs();
    void slotToOldFormat();
    void slotToNewFormat();
    void slotHeadersRefresh(QModelIndex currentIndex, QModelIndex previosIndex);
    void slotUpdateActions(QModelIndex currentIndex, QModelIndex previosIndex);
    void slotViewResize();
    void slotRevertAll();
    void slotInsertTag();
    void slotInsertSubTag();
    void slotDelete();
    void slotDuplicate();
    void slotAdd();
private:
    QLabel* mCurrentFileLabel;
    QTreeView* mTreeView;
    TreeModel* mModel;
    QItemSelectionModel* mSelectionModel;
    bool mIsEditable;
    void updateFileLabel(const QString& filename);
    void build();
    void open(const QString& filename);
    void Add(QModelIndex& index,const QVector<TreeItemData>& newItemData);
};

#endif // XMLWIDGET_H
