/*
 * modifierutils.h
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
#ifndef MODIFIERUTILS_H
#define MODIFIERUTILS_H

#include <vector>

#include "src/core/data/object/modifier.h"

using namespace std;
/**
 * @brief Static class for modifiers utils
 */
class ModifierUtils
{
public:
    static vector<ModifierAtributeType> getAttributesListFor(ModifierType mod);
    static vector<string> getValuesListFor(ModifierAtributeType attr);
    static ModifierAtributeType typeFromOrdinal(int ordinal);
    static ModifierType typeFromTagName(string name);
    static string tagNameFromType(ModifierType type);
    static string getNameFor(ModifierAtributeType attr);
private:
    ModifierUtils();
};

#endif // MODIFIERUTILS_H
