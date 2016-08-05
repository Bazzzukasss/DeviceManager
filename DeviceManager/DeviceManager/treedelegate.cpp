#include "treedelegate.h"
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QItemDelegate>
#include "xmldata.h"
#include "treemodel.h"

TreeDelegate::TreeDelegate(QObject* parent):QStyledItemDelegate(parent)
{
    pWidget = new QLineEdit();
    pWidget ->setFrame(false);
}

TreeDelegate::~TreeDelegate()
{
    delete pWidget;
}
/*
void TreeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
*/

void TreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
        QStyledItemDelegate::paint(painter,option,index);
}

/*
QSize TreeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return pWidget->size();
}
*/
QWidget *TreeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
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
}
void TreeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.isValid())
    {
        if(isComboBoxItem(index))
        {
            QComboBox* pEditor=qobject_cast<QComboBox*>(editor);
            QSet<QString> devSet=dynamic_cast<const TreeModel*> (index.model())->getDeviceSet();
            for(auto& str : devSet)
                pEditor->addItem(str);
            QString value=index.model()->data(index).value<QString>();
            pEditor->setCurrentText(value);
        }
        else
        {
            QLineEdit* pEditor=qobject_cast<QLineEdit*>(editor);
            QString value=index.model()->data(index).value<QString>();
            pEditor->setText(value);
        }
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
    if(index.isValid())
    {
        TreeItem* item = dynamic_cast<const TreeModel*> (index.model())->getItem(index);
        if(item)
        {
            XMLData data(item->getData());
            if(data.getName() == "DeviceMap")
            {
                int i = index.column()-2;
                if((i>0)&&(i < data.getAttributes().size()))
                {
                    if(data.getAttributes().at(i).name() == "currentDevice")
                        return true;
                }
            }
        }
    }
    return false;
}

void TreeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.isValid())
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
}
