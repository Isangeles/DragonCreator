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
/**
 * @brief ArmorsEditor::ArmorsEditor Constructor
 * @param pathToBase Path to armors XML base
 * @param mod Pointer to game module
 * @param gData Pointer to game graphic archive
 */
ArmorsEditor::ArmorsEditor(string pathToBase, Module *mod, ZipEditor *gData) : BaseEditor (pathToBase, mod, gData)
{
    // TODO: load armors list from base.
}
/**
 * @brief ArmorsEditor::~ArmorsEditor Deconstructor
 */
ArmorsEditor::~ArmorsEditor()
{

}
/**
 * @brief ArmorsEditor::getBaseObjects Returns list with armors from base
 * @return List with armors
 */
vector<BaseObject *> ArmorsEditor::getBaseObjects()
{
    // TODO: return list with armors loaded from base.
    return vector<BaseObject *>();
}
