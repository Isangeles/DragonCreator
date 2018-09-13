/*
 * armor.cpp
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
#include "armor.h"

/**
 * @brief Armor::getArmorTypes Returns list with all armor types.
 * @return List with armor types.
 */
vector<ArmorType> *Armor::getArmorTypes()
{
    vector<ArmorType> *types = new vector<ArmorType>();
    types->push_back(ArmorType::FEET);
    types->push_back(ArmorType::HANDS);
    types->push_back(ArmorType::OFFHAND);
    types->push_back(ArmorType::CHEST);
    types->push_back(ArmorType::HEAD);
    return types;
}

Armor::Armor(string id, int level, ArmorType type, string material, int value, int armorRat, string icon, string spritesheet, vector<Modifier> &modifiers,
             vector<Requirement> &requirements, vector<string> &effectsEq)
{
    this->id = id;
    this->level = level;
    this->type = type;
    this->material = material;
    this->value = value;
    this->armorRat = armorRat;
    this->icon = icon;
    this->spritesheet = spritesheet;
    this->modifiers = modifiers;
    this->requirements = requirements;
    this->effectsEq = effectsEq;
}
/**
 * @brief Armor::~Armor Destructor
 */
Armor::~Armor()
{
}
/**
 * @brief Armor::toString
 * @return
 */
string Armor::toString()
{
    return id;
}

string Armor::getId()
{
    return id;
}

int Armor::getLevel()
{
    return level;
}

ArmorType Armor::getType()
{
    return type;
}

string Armor::getMaterial()
{
    return material;
}

int Armor::getValue()
{
    return value;
}

int Armor::getArmorRat()
{
    return armorRat;
}

string Armor::getIcon()
{
    return icon;
}

string Armor::getSpritesheet()
{
    return spritesheet;
}

vector<Modifier> *Armor::getModifiers()
{
    return &modifiers;
}

vector<Requirement> *Armor::getRequirement()
{
    return &requirements;
}

vector<string> *Armor::getEffectsEq()
{
    return &effectsEq;
}

