/*
 * module.h
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
#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <fstream>

#include "src/util/engine.h"
#include "src/util/text/textreader.h"
#include "src/core/config.h"

using namespace std;
/**
 * @brief Class representing game modules
 */
class Module
{
public:
    Module(string modulePath);
    string getRootPath();
    string getItemsPath();
    string getModName();
    string getModInfo();
    string getEngineVer();
private:
    string modRoot;
    bool isValidDir(string path);
};

#endif // MODULE_H
