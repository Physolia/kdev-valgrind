/* This file is part of KDevelop
* Copyright 2006-2008 Hamish Rodda <rodda@kde.org>
* Copyright 2011 Mathieu Lornac <mathieu.lornac@gmail.com>
* Copyright 2011 Damien Coppel <damien.coppel@gmail.com>
* Copyright 2011 Lionel Duc <lionel.data@gmail.com>
* Copyright 2011 Sarie Lucas <lucas.sarie@gmail.com>
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

#include <interfaces/iproblem.h>

#include <QList>

namespace Valgrind
{

namespace Memcheck
{

struct Frame
{
    void setValue(const QString& name, const QString& value);

    KDevelop::IProblem::Ptr toIProblem(bool showInstructionPointer) const;

    int line = 0;

    QString function = QStringLiteral("???");
    QString instructionPointer;

    QString objectFile;

    QString directory;
    QString file;
};

struct Stack
{
    void addFrame();
    Frame& lastFrame();

    void setValue(const QString& name, const QString& value);

    KDevelop::IProblem::Ptr toIProblem(bool showInstructionPointer) const;

    QList<Frame> frames;
};

struct Error
{
    void clear();

    void addStack();
    Stack& lastStack();

    void setValue(const QString& name, const QString& value);

    KDevelop::IProblem::Ptr toIProblem(bool showInstructionPointer) const;

    QList<Stack> stacks;

    QStringList messages;
};

}

}
