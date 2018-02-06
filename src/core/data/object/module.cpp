/*
 * module.cpp
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
#include "module.h"
/**
 * @brief module::module Module constructor
 * @param modulePath Path to module
 * @throws runtime_error Throwed if specified path is not a valid game module directory
 */
Module::Module(string modulePath)
{
    if(isValidDir(modulePath))
        modRoot = modulePath;
    else
        throw std::runtime_error("Not a game module direcotry!");
}
/**
 * @brief Module::getRootPath Returns module root path
 * @return String with path to module root directory
 */
string Module::getRootPath()
{
    return modRoot;
}
/**
 * @brief Module::getItemsPath Returns path to mod directory with items bases
 * @return String with path to items directory
 */
string Module::getItemsPath()
{
    return modRoot + "/items";
}
/**
 * @brief Module::getModName Returns module name
 * @return String with module name
 */
string Module::getModName()
{
    return ""; //TODO module name
}
/**
 * @brief Module::getModInfo Returns module info
 * @return String with module info
 */
string Module::getModInfo()
{
    return ""; //TODO module info
}
/**
 * @brief Module::getEngineVer Returns engine version required by this module
 * @return String with engine version
 */
string Module::getEngineVer()
{
    return ""; //TODO engine version
}
/**
 * @brief ModuleEditor::isValidDir Checks if specified directory is valid module directory
 * @return True if specified path is valid, false otheriwse
 */
bool Module::isValidDir(string path)
{
    string modConfPath = path + "/" + Engine::MOD_CONF_NAME;
    ifstream modConfS(modConfPath);
    if(modConfS.is_open())
    {
        TextReader reader(modConfPath);
        string modVer = reader.getText("engine_ver");
        if(!modVer.compare(0, modVer.size(), Config::getEngineVer()))
            return true;
        else
            return false;
    }
    else
        return false;
}
