/*
 * baseeditor.h
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
#ifndef BASEEDITOR_H
#define BASEEDITOR_H

#include <iostream>
#include <vector>

#include "zip/zipeditor.h"
#include "src/core/data/dconnector.h"

using namespace std;
/**
 * @brief Abstract class for editors
 */
class BaseEditor
{
public:
    BaseEditor(string pathToBase, ZipEditor *gData);
    string getBaseSource();
    virtual vector<BaseObject *> getBaseObjects() = 0;
protected:
    string basePath;
    ZipEditor *gData;
};

#endif // BASEEDITOR_H
