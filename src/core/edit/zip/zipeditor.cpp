/*
 * zipeditor.cpp
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
#include "zipeditor.h"
/**
 * @brief ZipEditor::ZipEditor Zip editor constructor
 * @param pathToZip String with path to ZIP archive
 */
ZipEditor::ZipEditor(string pathToZip)
{
    zip = new QuaZip(QString::fromStdString(pathToZip));
    if(!zip->open(QuaZip::mdNotOpen))
        throw runtime_error("zip not found in:" + pathToZip);
}
/**
 * @brief ZipEditor::~ZipEditor Zip editor destructor
 */
ZipEditor::~ZipEditor()
{
    delete zip;
}
/**
 * @brief ZipEditor::getFilesNamesIn Returns list with names of all files in specified directory inside open zip
 * @param zipPath Path to directory inside open zip
 * @return List with files names
 */
vector<string> ZipEditor::getFilesNamesIn(string zipPath)
{
    //TODO list files in specified path
    return vector<string>();
}
/**
 * @brief ZipEditor::isOpen Checks if editor has zip archive open
 * @return True if zip archive is open and ready to edit, false otherwise
 */
bool ZipEditor::isOpen()
{
    if(zip != NULL)
        return zip->isOpen();
    else
        return false;
}
