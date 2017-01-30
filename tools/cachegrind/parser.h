/* This file is part of KDevelop
   Copyright 2011 Mathieu Lornac <mathieu.lornac@gmail.com>
   Copyright 2011 Damien Coppel <damien.coppel@gmail.com>
   Copyright 2011 Lionel Duc <lionel.data@gmail.com>
   Copyright 2016 Anton Anikin <anton.anikin@htower.ru>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#pragma once

#include <QObject>

namespace valgrind
{

class CachegrindItem;
class ModelItem;

/**
 * A class which parses cachegrind's output
 * and emits signals when items are parsed
 */
class CachegrindParser : public QObject
{
    Q_OBJECT

public:
    explicit CachegrindParser(QObject* parent = nullptr);
    ~CachegrindParser() override;

    void parse(QByteArray& data);

signals:
    void newItem(ModelItem*);

private:
    /**
     * build the root node of the tree
     * it return false if some error happens
     */
    bool parseRootModel(const QString& buffer);

    void parseNewCachegrindItem(const QString& buffer, bool totalProgram = false);

    QList<CachegrindItem*> m_caller;
    CachegrindItem* m_lastCall;

    QString m_programTotalStr;
    QStringList m_headersList;

    CachegrindItem* totalCountItem;
};

}
