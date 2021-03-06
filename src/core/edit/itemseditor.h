/*
 * itemeditor.h
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
#ifndef ITEMESDITOR_H
#define ITEMESDITOR_H

#include <string>
#include <QtXml>
#include <vector>

#include "src/util/engine.h"
#include "src/core/config.h"
#include "baseeditor.h"
#include "weaponseditor.h"
#include "armorseditor.h"

using namespace std;
/**
 * @brief Class for items bases editor
 */
class ItemsEditor
{
public:
    ItemsEditor(std::string pathToItems, Module *mod, ZipEditor *gData);
    ~ItemsEditor();
    vector<BaseEditor> getChildEditors();
    WeaponsEditor* getWeaponsEditor();
    ArmorsEditor* getArmorsEditor();

private:
    string itemsPath;
    string armorsPath;
    string weaponsPath;
    string miscPath;
    WeaponsEditor* wEdit;
    ArmorsEditor* aEdit;
};

#endif // ITEMESDITOR_H
