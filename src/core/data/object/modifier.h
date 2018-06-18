/*
 * modifier.h
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
#ifndef MODIFIER_H
#define MODIFIER_H

#include <map>
#include <vector>

#include "baseobject.h"

using namespace std;
/**
 * @brief Enumeration for modifiers types assosiated with XML nodes names
 */
enum ModifierType {HEALTH = 0, MANA = 1, STATS = 2, HASTE = 3, DODGE = 4,
                   DAMAGE = 5, UNDETECT = 6, DUALWIELD = 7, RESISTANCE = 8, UNLOCK = 9,
                   ATTITUDE = 10, FLAG = 11, NONE};
/**
 * @brief Enumeration for modifier attributes types
 */
enum ModifierAtributeType {VALUE = 0, STEALTH_LEVEL = 1, LOCK_LEVEL = 2, RESI_TYPE = 3,
                           FLAG_NAME = 4, WEAPON_TYPE = 5, STR = 6, CON = 7, DEX = 8, WIS = 9, INT = 10};
/**
 * @brief Class for modifiers(a.k.a bonuses)
 */
class Modifier
{
public:
    Modifier(ModifierType type, map<string, string> &attributes);
    ~Modifier();
    ModifierType getType();
    map<string, string> getAttributes();
    string getName();
private:
    ModifierType type;
    map<string, string> attributes;
};

#endif // MODIFIER_H
