/*
 * requirement.cpp
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
#include "requirement.h"

/**
 * @brief Requirement::Requirement Requirement constructor
 * @param type Requirement type
 * @param attributes Map with attributes(key - attribute name, value - attribute value)
 * @param value Requirement value(node text content)
 */
Requirement::Requirement(RequirementType type, map<string, string> &attributes, string value)
{
    this->type = type;
    this->attributes = attributes;
    this->value = value;
}
/**
 * @brief Requirement::getType Retruns requirement type
 * @return Requirement type enum
 */
RequirementType Requirement::getType()
{
    return type;
}
/**
 * @brief Requirement::getAttributes Returns map with attributes
 * @return Map with attributes(key - attribute name, value - attribute value)
 */
map<string, string> Requirement::getAttributes()
{
    return attributes;
}
/**
 * @brief Requirement::getValue Returns requirement value
 * @return Requirement value
 */
string Requirement::getValue()
{
    return value;
}
/**
 * @brief Requirement::getName Return requirement XML node tag name
 * @return Requirement name
 */
string Requirement::getTagName()
{
    switch(type)
    {
    case LEVEL:
        return "levelReq";
    case STATS:
        return "statsReq";
    case GENDER:
        return "genderReq";
    case GUILD:
        return "guildReq";
    case GOLD:
        return "goldReq";
    case ITEMS:
        return "itemsReq";
    case POINTS:
        return "pointsReq";
    case MANA:
        return "manaReq";
    case HEALTH:
        return "healthReq";
    case WEAPON:
        return "wepaonReq";
    case FLAG:
        return "flagReq";
    default:
        return "noneReq";
    }
}
