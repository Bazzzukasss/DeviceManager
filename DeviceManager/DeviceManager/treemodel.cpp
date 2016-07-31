/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "treeitem.h"
#include "treemodel.h"
#include "xmlprocessor.h"
#include "xmldata.h"

TreeModel::TreeModel(const QString &filename, QObject *parent)
    : QAbstractItemModel(parent),
      mFilename(filename)
{
    mRootItem = new TreeItem(QVector<TreeItemData>(8));
    XMLProcessor::Load(filename,mRootItem);
    mDeviceSet = GetItemDeviceSet(mRootItem);
}

TreeModel::~TreeModel()
{
    delete mRootItem;
}
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return item->getData(index.column());
}
bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    TreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return mRootItem->getData(section);

    return QVariant();
}

bool TreeModel::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = mRootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}
void TreeModel::Save(const QString &filename)
{
    mFilename = filename;
    Save();
}

void TreeModel::Save()
{
    XMLProcessor::Save(mFilename,mRootItem);
}

const QString &TreeModel::getFileName()
{
    return mFilename;
}

int TreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return mRootItem->columnCount();
}



Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    if(index.column()>0)
        return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
    else
        return QAbstractItemModel::flags(index);
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return mRootItem;
}


QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeItem *mParent = getItem(parent);

    TreeItem *childItem = mParent->getItem(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

bool TreeModel::insertColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginInsertColumns(parent, position, position + columns - 1);
    success = mRootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *mParent = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = mParent->insertItem(position, rows, mRootItem->columnCount());
    endInsertRows();
    mDeviceSet = GetItemDeviceSet(mRootItem);
    return success;
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *mParent = childItem->getParent();

    if (mParent == mRootItem)
        return QModelIndex();

    return createIndex(mParent->getNumber(), 0, mParent);
}

bool TreeModel::removeColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginRemoveColumns(parent, position, position + columns - 1);
    success = mRootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (mRootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *mParent = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = mParent->removeItem(position, rows);
    endRemoveRows();
    mDeviceSet = GetItemDeviceSet(mRootItem);
    return success;
}

QSet<QString> TreeModel::GetItemDeviceSet(TreeItem *item)
{
    QSet<QString> devSet;
    XMLData data(item->getData());
    if(data.getName() == "device")
    {
        if(data.getAttributes().hasAttribute("name"))
            devSet.insert(data.getAttributes().value("name").toString());
    }
    else
    {
        for(const auto& i : item->getItems())
            devSet.unite( GetItemDeviceSet(i) );
    }
    return devSet;
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *mParent = getItem(parent);

    return mParent->itemsCount();
}

