/*
 * baseobjectlistitem.cpp
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
#include "baseobjectlistitem.h"
/**
 * @brief BaseObjectListItem::BaseObjectListItem Base object list item constructor
 * @param object Base object
 */
BaseObjectListItem::BaseObjectListItem(BaseObject *object)
{
    this->object = object;
    this->setText(QString::fromStdString(object->getId()));
}
/**
 * @brief BaseObjectListItem::~BaseObjectListItem Base object item destructor
 */
BaseObjectListItem::~BaseObjectListItem()
{
    delete object;
}
/**
 * @brief BaseObjectListItem::getObject Returns base object contained by this item
 * @return Base object
 */
BaseObject *BaseObjectListItem::getObject()
{
    return object;
}
