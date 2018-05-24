/*
 * weapon.h
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
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <vector>

#include "../baseobject.h"
#include "src/core/data/object/modifier.h"

using namespace std;

enum WeaponType{DAGGER = 0, SWORD = 1, AXE = 2, MACE = 3, SPEAR = 4, BOW = 5, FIST = 6};
/**
 * @brief Class for weapons to edit
 */
class Weapon
{
friend class ItemParser;
public:
    static vector<WeaponType> *getWeaponTypes();
    Weapon(string id, int level, WeaponType type, string material, int value, int damageMin, int damageMax, string icon, string spritesheet, vector<Modifier> *modifiers);
    string toString();
    string getId();
private:
    string id;
    int level;
    WeaponType type;
    string material;
    int value;
    int damageMin;
    int damageMax;
    string icon;
    string spritesheet;
    vector<Modifier> *bonuses;
    vector<string> effectEq; //TODO proper equip effects
    vector<string> effectsHt; //TODO proper hit effects
};

#endif // WEAPON_H
