/*
 * modifier.cpp
 *
 * Copyright (C) 2018 Dariusz Sikora<darek@dellins-solus>
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
#include "modifier.h"
/**
 * @brief Modifier::Modifier Modifier constructor
 * @param type Modifier type
 * @param attributes Map with modifier attributes(key-name, value-value)
 * @param value Attribute value
 */
Modifier::Modifier(ModifierType type, map<string, string> *attributes)
{
    this->type = type;
    this->attributes = attributes;
}
/**
 * @brief Modifier::getType Retruns moodifier type
 * @return Modifier type enumeration
 */
ModifierType Modifier::getType()
{
    return type;
}
/**
 * @brief getAttributes Returns modifier attributes
 * @return Pointer to map with modifier attributes
 */
map<string, string> *Modifier::getAttributes()
{
    return attributes;
}
/**
 * @brief Modifier::getName Returns name of this modifier(for document node)
 * @return String with name
 */
string Modifier::getName()
{
    switch(type)
    {
    case STATS:
        return "statsBonus";
    case HEALTH:
        return "healthBonus";
    case MANA:
        return "manaBonus";
    case HASTE:
        return "hasteBonus";
    case DODGE:
        return "dodgeBonus";
    case DAMAGE:
        return "damageBonus";
    case UNDETECT:
        return "undetectBonus";
    case DUALWIELD:
        return "dualwieldBonus";
    case RESISTANCE:
        return "resistanceBonus";
    case UNLOCK:
        return "unlockBonus";
    case ATTITUDE:
        return "attitudeModifier";
    case FLAG:
        return "flagModifier";
    default:
        return "noneModifier";
    }
}
