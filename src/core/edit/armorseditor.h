/*
 * armorseditor.h
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
#ifndef ARMORSEDITOR_H
#define ARMORSEDITOR_H

#include "baseeditor.h"
#include "src/core/data/object/module.h"
#include "src/core/data/dconnector.h"
#include "zip/zipeditor.h"

/**
 * @brief Class for armors editor.
 */
class ArmorsEditor : public BaseEditor
{
public:
    ArmorsEditor(string pathToBase, Module *mod, ZipEditor *gData);
    virtual ~ArmorsEditor();
    vector<BaseObject *> getBaseObjects();
    vector<string> getIconFiles();
    vector<string> getSpritesheetFiles();
    bool newArmor(string id, int level, ArmorType type, string material, int value, int armorRat, string icon, string spritesheet, vector<Modifier> &modifiers,
                  vector<Requirement> &requirements, vector<string> &effectsEq);
    bool removeArmor(string id);
private:
    static const string ARMORS_ICONS_PATH;
    static const string ARMORS_SPRITESHEETS_PATH;
    vector<Armor> *armors;
};

#endif // ARMORSEDITOR_H
