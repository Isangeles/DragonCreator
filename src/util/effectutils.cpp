/*
 * effectutils.cpp
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
#include "effectutils.h"
/**
 * @brief EffectUtils::EffectUtils Private construcor
 */
EffectUtils::EffectUtils(){}
/**
 * @brief EffectUtils::typeToId Converts specified effect type to ID
 * @param type Effect type enum
 * @return String with effect type ID
 */
string EffectUtils::typeToId(EffectType type)
{
    switch(type)
    {
    case EffectType::MAGIC:
        return "magic";
    case EffectType::FIRE:
        return "fire";
    case EffectType::ICE:
        return "ice";
    case EffectType::NATURE:
        return "nature";
    default:
        return "normal";
    }
}
/**
 * @brief EffectUtils::typeFromTagName Converts specified XML tag name to effect type
 * @param tagName Tag name
 * @return Effect type enum
 */
EffectType EffectUtils::typeFromId(string tagName)
{
    if(tagName == "magic")
        return EffectType::MAGIC;
    else if(tagName == "fire")
        return EffectType::FIRE;
    else if(tagName == "ice")
        return EffectType::ICE;
    else if(tagName == "nature")
        return EffectType::NATURE;
    else
        return EffectType::NORMAL;
}
