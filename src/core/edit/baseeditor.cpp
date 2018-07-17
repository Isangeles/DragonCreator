/*
 * baseeditor.cpp
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
#include "baseeditor.h"
/**
 * @brief Editor::Editor Base editor constructor
 */
BaseEditor::BaseEditor(string pathToBase, Module *mod, ZipEditor *gData)
{
    basePath = pathToBase;
    this->gData = gData;
    this->mod = mod;
}
/**
 * @brief BaseEditor::getBaseSource Returns current source of open base
 * @return String with base source
 */
string BaseEditor::getBaseSource()
{
    return DConnector::getXmlSource(basePath);
}
/**
 * @brief BaseEditor::getModule Returns edited module
 * @return Pointer to module
 */
Module *BaseEditor::getModule()
{
    return mod;
}
