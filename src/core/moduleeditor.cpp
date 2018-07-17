/*
 * moduleeditor.cpp
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
#include "moduleeditor.h"
/**
 * @brief ModuleEditor::ModuleEditor Module editor constructor
 * @param pathToModule String with path to game module
 * @throws Exception if specified path is not path to game module directory
 */

ModuleEditor::ModuleEditor(string pathToModule)
{
    try
    {
        openMod = new Module(pathToModule);

        ZipEditor *gData = new ZipEditor(Config::getGameDir() + "/" + Engine::GBASE_PATH);

        iEdit = new ItemEditor(openMod->getItemsPath(), openMod, gData);
        eEdit = new EffectsEditor(openMod->getEffectsPath(), openMod, gData);
    }
    catch(runtime_error &e)
    {
        cerr << "module_editor_init_fail_msg:" << e.what() << endl;
        throw runtime_error("Invalid path to game module direcotry!");
    }
}
/**
 * @brief ModuleEditor::~ModuleEditor Module editor deconstructor
 */
ModuleEditor::~ModuleEditor()
{
    delete iEdit;
}
/**
 * @brief ModuleEditor::getChildEditors Returns all child editors
 */
vector<BaseEditor> ModuleEditor::getChildEditors()
{
    vector<BaseEditor> editors;

    return editors;
}
/**
 * @brief ModuleEditor::getEditor Returns editor of specified type
 * @param type Editor type
 * @return Base editor with specified type
 */
BaseEditor* ModuleEditor::getEditor(EditorType type)
{
    return iEdit->getWeaponsEditor(); //TODO for now returns only weapons editor
}
/**
 * @brief ModuleEditor::getItemEditor Returns items editor
 * @return Items editor
 */
ItemEditor *ModuleEditor::getItemEditor()
{
    return iEdit;
}
/**
 * @brief ModuleEditor::getEffectsEditor Returns effects editor
 * @return Effects editor
 */
EffectsEditor *ModuleEditor::getEffectsEditor()
{
    return eEdit;
}
/**
 * @brief ModuleEditor::getPath Returns currently open module
 * @return Game module object
 */
Module *ModuleEditor::getOpenModule()
{
    return openMod;
}
