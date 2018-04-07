/*
 * lang.cpp
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
#include "lang.h"
/**
 * @brief Lang::Lang Private constructor
 */
Lang::Lang(){}
/**
 * @brief Lang::getModifierAttributeName Converts specified
 * @param attr
 * @return
 */
string Lang::getModifierAttributeName(ModifierAtributeType attr)
{
    switch(attr)
    {
    case VALUE:
        return QObject::tr("Value").toStdString();
    case STEALTH_LEVEL: case LOCK_LEVEL:
        return QObject::tr("Level").toStdString();
    case RESI_TYPE: case WEAPON_TYPE:
        return QObject::tr("Type").toStdString();
    case FLAG_NAME:
        return QObject::tr("Flag").toStdString();
    case STR:
        return QObject::tr("Strength").toStdString();
    case CON:
        return QObject::tr("Constitution").toStdString();
    case DEX:
        return QObject::tr("Dexterity").toStdString();
    case WIS:
        return QObject::tr("Wisdom").toStdString();
    case INT:
        return QObject::tr("Inteliegence").toStdString();
    default:
        return QObject::tr("Unknown").toStdString();
    }
}
/**
 * @brief Lang::getWeaponTypeName Returns translated name for specified weapon type
 * @param type Weapon type
 * @return String with translated name of specified weapon type
 */
string Lang::getWeaponTypeName(WeaponType type)
{
    switch (type)
    {
    case DAGGER:
        return QObject::tr("Dagger").toStdString();
    case SWORD:
        return QObject::tr("Sword").toStdString();
    case AXE:
        return QObject::tr("Axe").toStdString();
    case MACE:
        return QObject::tr("Mace").toStdString();
    case SPEAR:
        return QObject::tr("Spear").toStdString();
    case BOW:
        return QObject::tr("Bow").toStdString();
    case FIST:
        return QObject::tr("Fist").toStdString();
    default:
        return QObject::tr("Unknown").toStdString();
    }
}

string Lang::getModifierAttributeValueName(string value)
{
    return value;
}
