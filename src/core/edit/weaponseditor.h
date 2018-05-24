/*
 * weaponseditor.h
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
#ifndef WEAPONSEDITOR_H
#define WEAPONSEDITOR_H

#include <vector>

#include "baseeditor.h"
#include "src/core/data/object/item/weapon.h"
#include "src/core/data/object/modifier.h"
#include "src/core/data/dconnector.h"
#include "zip/zipeditor.h"

using namespace std;
/**
 * @brief Class for weapons editor
 */
class WeaponsEditor : public BaseEditor
{
public:
    WeaponsEditor(string pathToBase, ZipEditor *gData) : BaseEditor(pathToBase, gData){}
    ~WeaponsEditor();
    vector<string> getIconsFiles();
    vector<string> getSpritesheetsFiles();
    bool newWeapon(string id, int level, WeaponType type, string material, int value, int damageMin, int damageMax,
                   string icon, string spritesheet, vector<Modifier> *modifiers);
    vector<BaseObject *> getBaseObjects();
private:
    Weapon *getEditedWeapon(); //UNUSED
    Weapon *editedWeapon;
    static const string WEAPONS_ICONS_PATH;
    static const string WEAPONS_SPRITESHEETS_PATH;
};

#endif // WEAPONSEDITOR_H
