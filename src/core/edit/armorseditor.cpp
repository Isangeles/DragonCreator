/*
 * armorseditor.cpp
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
#include "armorseditor.h"

const string ArmorsEditor::ARMORS_ICONS_PATH = "graphic/icon/armor";
const string ArmorsEditor::ARMORS_SPRITESHEETS_PATH = "graphic/sprite/item";

/**
 * @brief ArmorsEditor::ArmorsEditor Constructor
 * @param pathToBase Path to armors XML base
 * @param mod Pointer to game module
 * @param gData Pointer to game graphic archive
 */
ArmorsEditor::ArmorsEditor(string pathToBase, Module *mod, ZipEditor *gData) : BaseEditor (pathToBase, mod, gData)
{
    armors = DConnector::getArmorsFromBase(pathToBase);
}
/**
 * @brief ArmorsEditor::~ArmorsEditor Deconstructor
 */
ArmorsEditor::~ArmorsEditor()
{
    delete armors;
}
/**
 * @brief ArmorsEditor::newArmor Add new armor with specified parameters to
 *        base, if armor with specified ID already exist in base then old
 *        item will be deleted from base.
 * @param id Item ID
 * @param level Item equip level requirement
 * @param type Armor type
 * @param material Armor material
 * @param value Item value
 * @param armorRat Armor defence rating
 * @param icon Item icon
 * @param spritesheet Armor spritesheet
 * @param modifiers Armor on-equip modifiers
 * @param requirements Item equip requirements
 * @param effectsEq Armor on-equip effects
 * @return True if armor with specified parameters was successfully added to base,
 *         false otherwise
 */
bool ArmorsEditor::newArmor(string id, int level, ArmorType type, string material, int value, int armorRat, string icon, string spritesheet, vector<Modifier> &modifiers,
                            vector<Requirement> &requirements, vector<string> &effectsEq)
{
    Armor *editedArmor = new Armor(id, level, type, material, value, armorRat, icon, spritesheet, modifiers, requirements, effectsEq);
    removeArmor(id); // removes previous armor with such ID
    if(DConnector::addArmorToBase(basePath, editedArmor))
    {
        armors = DConnector::getArmorsFromBase(basePath);
        delete editedArmor;
        return true;
    }
    else
    {
        delete editedArmor;
        return false;
    }
}
/**
 * @brief ArmorsEditor::removeArmor Removes armor with specified ID
 *        from base.
 * @param id Armor ID.
 * @return  True if armor with specified ID was successfully removed,
 *          false otherwise.
 */
bool ArmorsEditor::removeArmor(string id)
{
    return DConnector::removeBaseObjectById(basePath, id);
}
/**
 * @brief ArmorsEditor::getIconFiles Rerturns list with names of all
 *        icons files for armors in graphic archive.
 * @return List with icons files names.
 */
vector<string> ArmorsEditor::getIconFiles()
{
    try
    {
        return gData->getFilesNamesIn(ARMORS_ICONS_PATH);
    }
    catch(runtime_error *e)
    {
        cerr << "armors_edditor_get_icons_files_fail:" << e->what() << endl;
        return vector<string>();
    }
}
/**
 * @brief ArmorsEditor::getSpritesheetFiles Returns list with names of all
 *        spritesheet files for armors in graphic archive.
 * @return List with spritesheet files names.
 */
vector<string> ArmorsEditor::getSpritesheetFiles()
{
    try
    {
        return gData->getFilesNamesIn(ARMORS_SPRITESHEETS_PATH);
    }
    catch (runtime_error *e)
    {
        cerr << "armors_editor_get_spritesheets_files_fail:" << e->what() << endl;
        return vector<string>();
    }
}
/**
 * @brief ArmorsEditor::getBaseObjects Returns list with armors from base
 * @return List with armors
 */
vector<BaseObject *> ArmorsEditor::getBaseObjects()
{
    vector<BaseObject*> objects = vector<BaseObject*>();
    for(Armor &a : *armors)
    {
        objects.push_back(&a);
    }
    return objects;
}
