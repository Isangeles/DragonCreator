/*
 * weaponseditor.cpp
 *
 * Copyright (C) 2017-2018 Dariusz Sikora<darek@dellins-solus>
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
#include "weaponseditor.h"
/**
 * @brief WeaponsEditor::WeaponsEditor Weapons editor constructor
 * @param pathToBase Path to weapons base
 */
WeaponsEditor::WeaponsEditor(string pathToBase)
{
    basePath = pathToBase;
}
/**
 * @brief WeaponsEditor::~WeaponsEditor Weapons editor consructor
 */
WeaponsEditor::~WeaponsEditor()
{
    delete editedWeapon;
}
/**
 * @brief WeaponsEditor::newWeapon Creates new weapon with specified parameters
 * @param id ID
 * @param level Item level
 * @param type Weapon type
 * @param material Weapon material
 * @param value Item value
 * @param damageMin Max damage of weapon
 * @param damageMax Min damage of weapon
 * @param modifiers List of modifiers
 * @return True if weapon was successfully created, false otherwise
 */
bool WeaponsEditor::newWeapon(string id, int level, string type, string material, int value, int damageMin, int damageMax,
                              string icon, string spritesheet, vector<Modifier> *modifiers)
{
    editedWeapon = new Weapon(id, level, type, material ,value, damageMin, damageMax, icon, spritesheet, modifiers);
    if(editedWeapon != NULL)
    {
        return DConnector::addWeaponToBase(basePath, editedWeapon);
    }
    else
        return false;
}
/**
 * @brief WeaponsEditor::getEditedWeapon Returns currently eddited weapon
 * @return Weapon
 */
Weapon *WeaponsEditor::getEditedWeapon()
{
    return editedWeapon;
}
/**
 * @brief WeaponsEditor::getBaseSource Returns current source of open base
 * @return String with base source
 */
string WeaponsEditor::getBaseSource()
{
    return DConnector::getXmlSource(basePath);
}

