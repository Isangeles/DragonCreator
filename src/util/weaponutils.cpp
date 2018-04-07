/*
 * weaponutils.cpp
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
#include "weaponutils.h"
/**
 * @brief WeaponUtils::WeaponUtils Private constructor
 */
WeaponUtils::WeaponUtils() {}
/**
 * @brief WeaponUtils::typeToId Conerts specified type to type ID
 * @param type Weapon type
 * @return String with ID of specified type
 */
string WeaponUtils::typeToId(WeaponType type)
{
    switch(type)
    {
    case DAGGER:
        return "dagger";
    case SWORD:
        return "sword";
    case AXE:
        return "axe";
    case MACE:
        return "mace";
    case SPEAR:
        return "spear";
    case BOW:
        return "bow";
    case FIST:
        return "fist";
    default:
        return "fist";
    }
}
