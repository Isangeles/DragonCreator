/*
 * dconnector.h
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
#ifndef DCONNECTOR_H
#define DCONNECTOR_H

#include <iostream>

#include "src/core/data/object/item/weapon.h"
#include "src/core/data/object/effect.h"
#include "src/core/edit/xml/qxmleditor.h"
#include "src/core/edit/xml/parser/itemparser.h"
#include "src/core/edit/xml/parser/effectparser.h"

using namespace std;
/**
 * @brief Class for editing game data archives
 */
class DConnector
{
public:
    static bool addWeaponToBase(string basePath, Weapon *weapon);
    static bool addEffectToBase(string basePath, Effect *effect);
    static bool removeBaseObjectById(string basePath, string id);
    static vector<Effect> *getEffectsFromBase(string basePath);
    static vector<Weapon> *getWeaponsFromBase(string basePath);
    static string getXmlSource(string xmlPath);
private:
    DConnector();
};

#endif // DCONNECTOR_H
