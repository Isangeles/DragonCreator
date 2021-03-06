/*
 * requirement.h
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
#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <map>
#include <string>

using namespace std;
/**
 * @brief Enumeration for requirement types
 */
enum class RequirementType {NONE, LEVEL, STATS, GENDER, GUILD, GOLD, ITEMS, POINTS, MANA, HEALTH, WEAPON, FLAG};
/**
 * @brief Enumeration for requirements attributes types
 */
enum class RequirementAttributeType {NONE, AMOUNT, EXPECT};
/**
 * @brief Class representing requirements(for items, skills, etc.)
 */
class Requirement
{
public:
    Requirement(RequirementType type, map<string, string> &attributes, string value);
    RequirementType getType();
    map<string, string> getAttributes();
    string getValue();
private:
    RequirementType type;
    map<string, string> attributes;
    string value;
};

#endif // REQUIREMENT_H
