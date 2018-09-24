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

const string WeaponsEditor::WEAPONS_ICONS_PATH = "graphic/icon/item/weapon";
const string WeaponsEditor::WEAPONS_SPRITESHEETS_PATH = "graphic/sprite/item";

/**
 * @brief WeaponsEditor::WeaponsEditor Weapons editor constructor
 * @param pathToBase
 * @param mod
 * @param gData
 */
WeaponsEditor::WeaponsEditor(string pathToBase, Module *mod, ZipEditor *gData) : BaseEditor(pathToBase, mod, gData)
{
    weapons = DConnector::getWeaponsFromBase(pathToBase);
}
/**
 * @brief WeaponsEditor::~WeaponsEditor Weapons editor consructor
 */
WeaponsEditor::~WeaponsEditor()
{
    delete editedWeapon;
    delete weapons;
}
/**
 * @brief WeaponsEditor::newWeapon Adds new weapon with specified parameters to base,
 *        if armor with specified ID already exist in base then old
 *        item will be deleted from base.
 * @param id ID
 * @param level Item level
 * @param type Weapon type
 * @param material Weapon material
 * @param value Item value
 * @param damageMin Max damage of weapon
 * @param damageMax Min damage of weapon
 * @param modifiers List of modifiers
 * @param requirements List with equip requirements
 * @param effectsEq List with on-equip effects
 * @param effectsHit List with on-hit effects
 * @return True if weapon was successfully created, false otherwise
 */
bool WeaponsEditor::newWeapon(string id, int level, WeaponType type, string material, int value, int damageMin, int damageMax,
                              string icon, string spritesheet, vector<Modifier> &modifiers, vector<Requirement> &requirements,
                              vector<string> &effectsEq, vector<string> &effectsHit)
{
    editedWeapon = new Weapon(id, level, type, material, value, damageMin, damageMax, icon, spritesheet, modifiers, requirements, effectsEq, effectsHit);
    removeWeapon(id); // if already exists, removes previous item with same ID
    if(DConnector::addWeaponToBase(basePath, editedWeapon))
    {
        weapons = DConnector::getWeaponsFromBase(basePath);
        return true;
    }
    else
        return false;
}
/**
 * @brief WeaponsEditor::removeWeapon Removes weapons with specified ID from weapons base
 * @param id ID of weapon to remove
 * @return True if weapon with specified id was successfully removed, false otherwise
 */
bool WeaponsEditor::removeWeapon(string id)
{
    return DConnector::removeBaseObjectById(basePath, id);
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
 * @brief WeaponsEditor::getIconsFiles Returns names of avalible icons files from graphic archive
 * @return List with files names
 */
vector<string> WeaponsEditor::getIconsFiles()
{
    try
    {
        return gData->getFilesNamesIn(WEAPONS_ICONS_PATH);
    }
    catch(runtime_error er)
    {
        cerr << "weapons_editor_get_icons_fail:" << er.what() << endl;
        return vector<string>(); //empty list
    }
}
/**
 * @brief WeaponsEditor::getSpritesheetsFiles Returns names of avalibel spritesheets files from graphic archive
 * @return List with files names
 */
vector<string> WeaponsEditor::getSpritesheetsFiles()
{
    try
    {
        return gData->getFilesNamesIn(WEAPONS_SPRITESHEETS_PATH);
    }
    catch(runtime_error er)
    {
        cerr << "weapons_editor_get_spritesheets_fail:" << er.what() << endl;
        return vector<string>(); //empty list
    }
}
/**
 * @brief WeaponsEditor::getBaseObjects Returns all objects from open base
 * @return List with base objects
 */
vector<BaseObject *> WeaponsEditor::getBaseObjects()
{
    vector<BaseObject *> objects = vector<BaseObject *>();
    for(Weapon &w : *weapons)
    {
        objects.push_back(&w);
    }
    return objects;
}
