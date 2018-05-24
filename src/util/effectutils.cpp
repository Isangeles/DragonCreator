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
    //TODO
    return "TODO";
}
/**
 * @brief EffectUtils::typeFromTagName Converts specified XML tag name to effect type
 * @param tagName Tag name
 * @return Effect type enum
 */
EffectType EffectUtils::typeFromTagName(string tagName)
{
    //TODO tag name to effect type conversion
    return EffectType::NORMAL;
}
