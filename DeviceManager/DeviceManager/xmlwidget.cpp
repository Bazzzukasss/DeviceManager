#include <QDebug>
#include <QFileDialog>
#include <QFont>

#include "xmlwidget.h"
#include "xmlprocessor.h"
#include "treedelegate.h"
#include "xmldata.h"

XMLWidget::XMLWidget(QWidget *parent)
    :QFrame(parent)
{
    mIsEditable =true;
    mModel = nullptr;
    mSelectionModel = nullptr;
    mTreeView = new QTreeView(this);
    mCurrentFileLabel = new QLabel(this);
    mTreeView->setItemDelegate(new TreeDelegate());
    mTreeView->setAlternatingRowColors(true);
    mTreeView->setSelectionBehavior(QAbstractItemView::SelectItems);

    connect(mTreeView,          SIGNAL(expanded(QModelIndex)),  this,   SLOT(slotViewResize()));
    connect(mTreeView,          SIGNAL(collapsed(QModelIndex)), this,   SLOT(slotViewResize()));

    setModelData(":/res/res/xml_new_format.xml");
    build();
}

XMLWidget::~XMLWidget()
{
    delete mModel;
}

void XMLWidget::setEditable(bool isEditable)
{
    mIsEditable = isEditable;
    if(mModel)
        mModel->setEditable(isEditable);
}

void XMLWidget::build()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(mCurrentFileLabel);
    mainLayout->addWidget(mTreeView);

    mainLayout->setMargin(2);
    mainLayout->setSpacing(4);
}

void XMLWidget::setModelData(const QString &filename,TreeItem* rootItem)
{
    if(mModel)
        delete mModel;
    if(rootItem == nullptr)
        mModel = new TreeModel(filename);
    else
        mModel = new TreeModel(rootItem);
    mSelectionModel = new QItemSelectionModel(mModel);

    mModel->setEditable(mIsEditable);
    mTreeView->setModel(mModel);
    mTreeView->setSelectionModel(mSelectionModel);
    connect(mSelectionModel,    SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this,   SLOT(slotHeadersRefresh(QModelIndex,QModelIndex)));
    connect(mSelectionModel,    SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this,   SLOT(slotUpdateActions(QModelIndex,QModelIndex)));
    setCurFileName(filename);
}

const QString &XMLWidget::getCurFileName()
{
    return mCurFileName;
}
//SLOTS
void XMLWidget::slotOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", mCurFileName, "files(*.xml )");
    if(!filename.isEmpty())
        setModelData(filename);
}
void XMLWidget::slotSave()
{
    mModel->Save();
}
void XMLWidget::slotSaveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", mCurFileName, "files(*.xml )");
    if(!filename.isEmpty())
    {
        mModel->Save(filename);
        setCurFileName(filename);
    }
}

void XMLWidget::slotToOldFormat()
{

}

void XMLWidget::slotToNewFormat()
{

}

void XMLWidget::slotHeadersRefresh(QModelIndex currentIndex, QModelIndex )
{
    mModel->RefreshHeaders(currentIndex);
}

void XMLWidget::slotUpdateActions(QModelIndex currentIndex, QModelIndex previosIndex)
{
    QModelIndex index = mSelectionModel->currentIndex();

}

void XMLWidget::slotViewResize()
{
    for(int column=0;column<mModel->columnCount();++column)
        mTreeView->resizeColumnToContents(column);
}

void XMLWidget::slotRevertAll()
{
    //emit mModel->signalRevertAll();
    emit mModel->layoutChanged();
}

void XMLWidget::slotInsertSubTag()
{
    QModelIndex index = mSelectionModel->currentIndex();

    if (mModel->columnCount(index) == 0) {
        if (!mModel->insertColumn(0, index))
            return;
    }

    if (!mModel->insertRow(0, index))
        return;

    for (int column = 0; column < mModel->columnCount(index); ++column) {
        QModelIndex child = mModel->index(0, column, index);
        mModel->setData(child, QVariant("data"), Qt::EditRole);
        //if (!model->headerData(column, Qt::Horizontal).isValid())
          //  model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    }

    mSelectionModel->setCurrentIndex(mModel->index(0, 0, index), QItemSelectionModel::ClearAndSelect);
}

void XMLWidget::slotInsertTag()
{
    QModelIndex index = mSelectionModel->currentIndex();

    if (!mModel->insertRow(index.row()+1, index.parent()))
        return;
/*
    for (int column = 0; column < mModel->columnCount(index.parent()); ++column) {
        QModelIndex child = mModel->index(index.row()+1, column, index.parent());
        mModel->setData(child, QVariant("[No data]"), Qt::EditRole);
    }
*/
}
void XMLWidget::slotDelete()
{
    QModelIndex index = mSelectionModel->currentIndex();

    if(index.isValid())
        mModel->removeRow(index.row(), index.parent());
}

void XMLWidget::slotDuplicate()
{
    QModelIndex index = mSelectionModel->currentIndex();

    if(index.isValid())
    {
        TreeItem* item = mModel->getItem(index);
        XMLData data(item->getData());
        QString name = data.getName();
        if((name == "device") || (name == "DeviceMap") || (name == "property"))
            mModel->insertRow(index.row()+1, index.parent());
    }

}
void XMLWidget::Add(QModelIndex& index,const QVector<TreeItemData>& newItemData)
{
    if (mModel->columnCount(index) == 0)
    {
        if (!mModel->insertColumn(0, index))
            return;
    }

    if (!mModel->insertRow(0, index))
        return;

    QModelIndex child = mModel->index(0, 0, index);
    TreeItem* childItem = mModel->getItem(child);
    childItem->setData(newItemData);
}

void XMLWidget::slotAdd()
{
    QModelIndex index = mSelectionModel->currentIndex();
    if(index.isValid())
    {
        TreeItem* item = mModel->getItem(index);
        XMLData data(item->getData());
        QString name = data.getName();
        XMLData newItemData;
        bool res(false);
        QXmlStreamAttributes attributes;
        if(name == "HWdevices")
        {
            attributes.append("name","AF");
            newItemData.setAttributes(attributes);
            newItemData.setName("device");
            res = true;
        }
        if(name == "PRISM")
        {
            attributes.append("name","AAAAAA");
            newItemData.setAttributes(attributes);
            newItemData.setName("device");
            res = true;
        }
        if(name == "DevicesMapping")
        {
            attributes.append("name","DEVICE_GREEN_LASER");
            attributes.append("HWType","LASER");
            attributes.append("currentDevice","GreenLaser");
            newItemData.setAttributes(attributes);
            newItemData.setName("DeviceMap");
            res = true;
        }
        if(name == "device")
        {
            attributes.append("name","key");
            newItemData.setAttributes(attributes);
            newItemData.setName("property");
            newItemData.setValue("value");
            res = true;
        }
        if(res)
        {
            Add(index,newItemData.getData());
            mTreeView->expand(index);
        }
    }
}

void XMLWidget::setCurFileName(const QString& filename)
{
    mCurFileName = filename;
    mCurrentFileLabel->setText("<b>Curent file  :   </b>" + filename);
}
