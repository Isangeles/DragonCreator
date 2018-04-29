/*
 * moduleeditor.h
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
#ifndef MODULEEDITOR_H
#define MODULEEDITOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>

#include "config.h"
#include "edit/itemeditor.h"
#include "edit/effectseditor.h"
#include "src/util/engine.h"
#include "src/core/data/object/module.h"

using namespace std;
/**
 * @brief Enumeration for editor types
 */
enum EditorType{WEAPONS_EDITOR};
/**
 * @brief Class for module editor
 */
class ModuleEditor
{
public:
    ModuleEditor(string pathToModule);
    ~ModuleEditor();
    vector<BaseEditor> getChildEditors();
    BaseEditor* getEditor(EditorType type);
    ItemEditor *getItemEditor();
    EffectsEditor *getEffectsEditor();

    Module *getOpenModule();

private:
    Module* openMod;
    ItemEditor *iEdit;
    EffectsEditor *eEdit;
    bool isValidDir(string path);
};

#endif // MODULEEDITOR_H
