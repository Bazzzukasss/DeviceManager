#include "treedelegate.h"
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include "xmldata.h"
#include "treemodel.h"

TreeDelegate::TreeDelegate(QObject* parent):QStyledItemDelegate(parent)
{
    pLineEdit = new QLineEdit();
    pComboBox = new QComboBox();
    pLineEdit->setFrame(false);
    pComboBox->setFrame(false);
}

TreeDelegate::~TreeDelegate()
{
    delete pLineEdit;
    delete pComboBox;
}
void TreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant var=index.model()->data(index);
    if(var.isValid())
    {
        QString value=var.value<QString>();
        pLineEdit->setText(value);
        pLineEdit->setFixedSize(option.rect.width(),option.rect.height());
        QPixmap pixmap(pLineEdit->size());
        pLineEdit->render(&pixmap);
        painter->drawPixmap(option.rect,pixmap);
    }
}
/*
QSize TreeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return pWidget->size();
}
*/
QWidget *TreeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(isComboBoxItem(index))
    {
        QComboBox* pEditor=new QComboBox(parent);
        pEditor->setFrame(false);
        connect(pEditor,SIGNAL(currentIndexChanged(int)),this,SLOT(slotCommit()));
        return pEditor;

    }
    else
    {
        QLineEdit* pEditor=new QLineEdit(parent);
        pEditor->setFrame(false);
        connect(pEditor,SIGNAL(editingFinished()),this,SLOT(slotCommit()));
        return pEditor;
    }
}
void TreeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(isComboBoxItem(index))
    {
        QComboBox* pEditor=qobject_cast<QComboBox*>(editor);
        QSet<QString> devSet=dynamic_cast<const TreeModel*> (index.model())->mDeviceSet;
        for(auto& str : devSet)
            pEditor->addItem(str);
    }
    else
    {
        QLineEdit* pEditor=qobject_cast<QLineEdit*>(editor);
        QString value=index.model()->data(index).value<QString>();
        pEditor->setText(value);
    }
}

void TreeDelegate::slotCommit()
{
    QWidget* pEditor=qobject_cast<QWidget*>(sender());
    emit commitData(pEditor);
    emit closeEditor(pEditor);
}

bool TreeDelegate::isComboBoxItem(const QModelIndex &index) const
{
    TreeItem* item = dynamic_cast<const TreeModel*> (index.model())->getItem(index);
    XMLData data(item->getData());
    if(data.getName() == "DeviceMap")
    {
        if(data.getAttributes().at(index.column()-2).name() == "currentDevice")
            return true;
    }
    return false;
}

void TreeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QString str;
    if(isComboBoxItem(index))
    {
        QComboBox* pEditor=qobject_cast<QComboBox*>(editor);
        str = pEditor->currentText();
    }
    else
    {
        QLineEdit* pEditor=qobject_cast<QLineEdit*>(editor);
        str = pEditor->text();
    }
    model->setData(index,QVariant().fromValue(str));
}
