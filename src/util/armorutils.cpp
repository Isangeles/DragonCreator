/*
 * armorutils.cpp
 * Copyright (C) 2018 Dariusz Sikora<dev@isangeles.pl>
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
#include "armorutils.h"
/**
 * @brief ArmorUtils::ArmorUtils Private constructor
 */
ArmorUtils::ArmorUtils(){}
/**
 * @brief ArmorUtils::typeToId Converts type to XML atribute name
 * @param type Armor type enum class
 * @return String with atribute name for XML node
 */
string ArmorUtils::typeToId(ArmorType type)
{
    switch(type)
    {
    case ArmorType::FEET:
        return "feet";
    case ArmorType::HANDS:
        return "hands";
    case ArmorType::OFFHAND:
        return "offhand";
    case ArmorType::CHEST:
        return "chest";
    case ArmorType::HEAD:
        return "head";
    default:
        return "feet";
    }
}
/**
 * @brief ArmorUtils::typeFromId Converts specified ID to armor type
 * @param id String with type ID
 * @return Armor type enum class
 */
ArmorType ArmorUtils::typeFromId(string id)
{
    if(id == "feet")
        return ArmorType::FEET;
    else if(id == "hands")
        return ArmorType::HANDS;
    else if(id == "offhand")
        return ArmorType::OFFHAND;
    else if(id == "chest")
        return ArmorType::CHEST;
    else if(id == "head")
        return ArmorType::HEAD;
    else
        return ArmorType::FEET;
}


