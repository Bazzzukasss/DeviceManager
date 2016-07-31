#ifndef TREEDELEGATE_H
#define TREEDELEGATE_H
#include <QLineEdit>
#include <QComboBox>
#include <QStyledItemDelegate>

class TreeDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TreeDelegate(QObject* parent =0);
    ~TreeDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
public slots:
    void slotCommit();
private:
    QLineEdit* pLineEdit;
    QComboBox* pComboBox;
    bool isComboBoxItem(const QModelIndex &index) const;
};

#endif // TREEDELEGATE_H
