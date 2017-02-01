/* This file is part of KDevelop
 * Copyright 2011 Mathieu Lornac <mathieu.lornac@gmail.com>
 * Copyright 2011 Damien Coppel <damien.coppel@gmail.com>
 * Copyright 2011 Lionel Duc <lionel.data@gmail.com>
 * Copyright 2011 Lucas Sarie <lucas.sarie@gmail.com>
 * Copyright 2017 Anton Anikin <anton.anikin@htower.ru>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#pragma once

#include "interfaces/imodel.h"

#include <QAbstractItemModel>

namespace valgrind
{
class CachegrindItem;

class CachegrindModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit CachegrindModel(QObject* parent = nullptr);
    ~CachegrindModel() override;

    QModelIndex index(int, int, const QModelIndex&) const override;
    QModelIndex parent(const QModelIndex&) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    CachegrindItem* itemForIndex(const QModelIndex& index) const;

    /**
     * Reception of a new item in the model
     */
    void newItem(ModelItem* item);
    /**
     * Resets the model content
     */
    void reset();

signals:
    void modelChanged();

private:
    CachegrindItem* m_rootItem;
};

}
