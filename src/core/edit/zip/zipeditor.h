/*
 * zipeditor.h
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
#ifndef ZIPEDITOR_H
#define ZIPEDITOR_H

#include <iostream>

#include <quazip.h>

using namespace std;
/**
 * @brief Class for reading and editing ZIP archives
 * Uses quazip library
 */
class ZipEditor
{
public:
    ZipEditor(string pathToZip);
    ~ZipEditor();
    bool isOpen();
    vector<string> getFilesNamesIn(string zipPath);

private:
//    QuaZip *zip;
};

#endif // ZIPEDITOR_H
