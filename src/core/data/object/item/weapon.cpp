/*
 * weapon.cpp
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
#include "weapon.h"
/**
 * @brief Weapon::getWeaponTypes Returns list with weapons types
 * @return List with weapons types
 */
vector<WeaponType> *Weapon::getWeaponTypes()
{
    vector<WeaponType> *types = new vector<WeaponType>();

    types->push_back(WeaponType(DAGGER));
    types->push_back(WeaponType(SWORD));
    types->push_back(WeaponType(AXE));
    types->push_back(WeaponType(MACE));
    types->push_back(WeaponType(SPEAR));
    types->push_back(WeaponType(BOW));
    types->push_back(WeaponType(FIST));

    return types;
}
/**
 * @brief Weapon::Weapon Weapon constructor
 */
Weapon::Weapon(string id, int level, WeaponType type, string material, int value, int damageMin, int damageMax, string icon, string spritesheet, vector<Modifier> *modifiers)
{
    this->id = id;
    this->level = level;
    this->type = type;
    this->material = material;
    this->value = value;
    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->icon = icon;
    this->spritesheet = spritesheet;
    this->bonuses = modifiers;
}
/**
 * @brief Weapon::toString Returns string with ID of this weapon
 * @return Standard string
 */
string Weapon::toString()
{
    return id;
}

string Weapon::getId()
{
    return id;
}
