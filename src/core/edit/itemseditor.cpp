/*
 * itemeditor.cpp
 *
 * Copyright (C) 2017 Dariusz Sikora<darek@dellins-solus>
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
#include "itemseditor.h"
/**
 * @brief Items editor constructor
 * @param pathToBase Path to XML items base
 */
ItemsEditor::ItemsEditor(std::string pathToItems, Module *mod, ZipEditor* gData)
{
    itemsPath = pathToItems;

    armorsPath = itemsPath + "/armors" + Engine::BASE_EXT;
    weaponsPath = itemsPath + "/weapons" + Engine::BASE_EXT;
    miscPath = itemsPath + "/misc" + Engine::BASE_EXT;

    wEdit = new WeaponsEditor(weaponsPath, mod, gData);
    aEdit = new ArmorsEditor(armorsPath, mod, gData);
}
/**
 * @brief ItemEditor::~ItemEditor ItemEditor deconstructor
 */
ItemsEditor::~ItemsEditor()
{
    delete wEdit;
    delete aEdit;
}
/**
 * @brief ItemEditor::getChildEditors Returns all child editors
 * @deprecated
 */
vector<BaseEditor> ItemsEditor::getChildEditors()
{
    vector<BaseEditor> editors;

    return editors;
}
/**
 * @brief ItemEditor::getWeaponsEditor Returns weapons editor
 * @return Weapons editor
 */
WeaponsEditor* ItemsEditor::getWeaponsEditor()
{
    return wEdit;
}
/**
 * @brief ItemEditor::getArmorsEditor Returns armors editor
 * @return Armors editor
 */
ArmorsEditor* ItemsEditor::getArmorsEditor()
{
    return aEdit;
}
