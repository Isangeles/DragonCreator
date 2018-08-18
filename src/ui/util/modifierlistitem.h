/*
 * moddifierlistitem.h
 * Copyright (C) 2018 Dariusz Sikora<darek@pc-solus>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef MODIFIERLISTITEM_H
#define MODIFIERLISTITEM_H

#include <QListWidgetItem>

#include "src/core/data/object/modifier.h"
#include "src/util/modifierutils.h"
/**
 * @brief Modifier wrapper class for Qt qlistwidgetitem
 */
class ModifierListItem : public QListWidgetItem
{
public:
    ModifierListItem(Modifier &modifier);
    ~ModifierListItem();
    const Modifier *getModifier();
private:
    Modifier *modifier;
};

#endif // MODIFIERLISTITEM_H
