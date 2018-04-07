/*
 * lang.h
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
#ifndef LANG_H
#define LANG_H

#include <QObject>
#include <QString>

#include "src/core/data/object/modifier.h"
#include "src/core/data/object/item/weapon.h"

using namespace std;
/**
 * @brief Static class for UI text localization
 */
class Lang
{
public:
    static string getModifierAttributeName(ModifierAtributeType attr);
    static string getModifierAttributeValueName(string value);
    static string getWeaponTypeName(WeaponType type);
private:
    Lang();
};

#endif // LANG_H
