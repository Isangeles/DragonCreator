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

#include "src/core/data/object/baseobject.h"
#include "src/core/data/object/effect.h"
#include "src/core/data/object/modifier.h"

using namespace std;

enum WeaponType{FIST = 0, DAGGER = 1, SWORD = 2, AXE = 3, MACE = 4, SPEAR = 5, BOW = 6};
/**
 * @brief Class for weapons to edit
 * TODO: IMPLEMENT REQUIREMENTS
 */
class Weapon : public BaseObject
{
friend class ItemParser;
public:
    static vector<WeaponType> *getWeaponTypes();
    Weapon(string id, int level, WeaponType type, string material, int value, int damageMin, int damageMax, string icon, string spritesheet,
           vector<Modifier> &modifiers, vector<Effect> &effectsEq, vector<Effect> &effectsHit);
    string toString();
    string getId();
    int getLevel();
    WeaponType getType();
    string getMaterial();
    int getValue();
    int getDamageMax();
    int getDamageMin();
    string getIcon();
    string getSpritesheet();
    vector<Modifier> getModifiers();
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
    vector<Modifier> bonuses;
    vector<Effect> effectsEq;
    vector<Effect> effectsHit;
};

#endif // WEAPON_H
