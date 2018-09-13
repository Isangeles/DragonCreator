/*
 * armor.h
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
#ifndef ARMOR_H
#define ARMOR_H

#include <vector>

#include "src/core/data/object/baseobject.h"
#include "src/core/data/object/modifier.h"
#include "src/core/data/object/requirement.h"

using namespace std;

/**
 * @brief Enumeration class for armor types.
 */
enum class ArmorType { FEET = 0, HANDS = 1, OFFHAND = 2, CHEST = 3, HEAD = 4 };
/**
 * @brief Class for armors.
 */
class Armor : public BaseObject
{
public:
    static vector<ArmorType> *getArmorTypes();
    Armor(string getId, int level, ArmorType type, string material, int value,
          int armorRat, string icon, string spritesheet, vector<Modifier> &modifiers,
          vector<Requirement> &requirements, vector<string> &effectsEq);
    virtual ~Armor();
    string toString();
    string getId();
    int getLevel();
    ArmorType getType();
    string getMaterial();
    int getValue();
    int getArmorRat();
    string getIcon();
    string getSpritesheet();
    vector<Modifier> *getModifiers();
    vector<Requirement> *getRequirement();
    vector<string> *getEffectsEq();
private:
    string id;
    int level;
    ArmorType type;
    string material;
    int value;
    int armorRat;
    string icon;
    string spritesheet;
    vector<Modifier> modifiers;
    vector<Requirement> requirements;
    vector<string> effectsEq;
};

#endif // ARMOR_H
