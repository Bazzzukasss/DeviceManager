#include <QStringList>
#include "treeitem.h"

TreeItem::TreeItem(const QVector<TreeItemData> &data, TreeItem *parent)
{
    mParent = parent;
    mData = data;
}

TreeItem::TreeItem(TreeItem *parent)
{
    mParent = parent;
}

TreeItem::TreeItem(const TreeItem* item, TreeItem *parent)
{
    mParent = parent;
    clone(item);
}

TreeItem::~TreeItem()
{
    qDeleteAll(mItems);
}

TreeItem *TreeItem::getItem(int getNumber)
{
    return mItems.value(getNumber);
}

const QList<TreeItem *>& TreeItem::getItems() const
{
    return mItems;
}

void TreeItem::addItem(TreeItem *item)
{
    mItems.append(item);
}

int TreeItem::itemsCount() const
{
    return mItems.count();
}

int TreeItem::getNumber() const
{
    if (mParent)
        return mParent->mItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const
{
    return mData.count();
}

bool TreeItem::insertItem(int position, int count)
{
    if (position < 0 || position > mItems.size())
        return false;

    for (int row = 0; row < count; ++row)
    {
        TreeItem *item;
        if(position >0)
            item = new TreeItem(mItems[position-1], this);
        else
            item = new TreeItem(this);

        mItems.insert(position, item);
    }
    return true;
}

bool TreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > mData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        mData.insert(position, TreeItemData());

    foreach (TreeItem *child, mItems)
        child->insertColumns(position, columns);

    return true;
}

TreeItem *TreeItem::getParent()
{
    return mParent;
}

void TreeItem::setParent(TreeItem *parent)
{
    mParent = parent;
}

bool TreeItem::removeItem(int position, int count)
{
    if (position < 0 || position + count > mItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete mItems.takeAt(position);

    return true;
}

bool TreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > mData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        mData.remove(position);

    foreach (TreeItem *child, mItems)
        child->removeColumns(position, columns);

    return true;
}

bool TreeItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= mData.size())
        return false;

    mData[column].second = value;
    return true;
}

bool TreeItem::setData(int column, const TreeItemData &value)
{
    if (column < 0 || column >= mData.size())
        return false;

    mData[column] = value;
    return true;
}

void TreeItem::setData(const QVector<TreeItemData> &data)
{
    mData = data;
}

TreeItem &TreeItem::operator=(const TreeItem &item)
{
    clone(&item);
    return *this;
}

void TreeItem::clone(const TreeItem *item)
{
    mData = item->mData;
    for(auto& it : item->mItems)
    {
        TreeItem* subItem = new TreeItem(it,this);
        mItems.append(subItem);
    }
}

QVariant TreeItem::getData(int column) const
{
    return mData.value(column).second;
}

QVector<TreeItemData> TreeItem::getData() const
{
    return mData;
}
