#include "treedelegate.h"
#include <QPainter>
#include <QDebug>
#include <QPushButton>

TreeDelegate::TreeDelegate(QObject* parent):QStyledItemDelegate(parent)
{
    pWidget=new QLineEdit();
    pWidget->setFrame(false);
}

TreeDelegate::~TreeDelegate()
{
    delete pWidget;
}
void TreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    //pWidget->setState(option.state);
    QVariant var=index.model()->data(index);
    if(var.isValid())
    {
        QString value=var.value<QString>();
        pWidget->setText(value);
        pWidget->setFixedSize(option.rect.width(),option.rect.height());
        QPixmap pixmap(pWidget->size());
        pWidget->render(&pixmap);
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
    QLineEdit* pEditor=new QLineEdit(parent);
    pEditor->setFrame(false);
    connect(pEditor,SIGNAL(editingFinished()),this,SLOT(slotCommit()));
    return pEditor;
}
void TreeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit* pEditor=qobject_cast<QLineEdit*>(editor);
    QString value=index.model()->data(index).value<QString>();
    pEditor->setText(value);
}

void TreeDelegate::slotCommit()
{
    QWidget* pEditor=qobject_cast<QWidget*>(sender());
    emit commitData(pEditor);
    emit closeEditor(pEditor);
}

void TreeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit* pEditor=qobject_cast<QLineEdit*>(editor);
    model->setData(index,QVariant().fromValue(pEditor->text()));
}
