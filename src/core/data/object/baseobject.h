/*
 * baseobject.h
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
#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <string>

using namespace std;
/**
 * @brief Abstract class for bases objects
 */
class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject();
    virtual string getId() = 0;
};

#endif // BASEOBJECT_H
