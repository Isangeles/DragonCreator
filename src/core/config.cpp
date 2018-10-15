/*
 * config.cpp
 * Copyright (C) 2017 Dariusz Sikora<darek@dellins-solus>
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
#include "config.h"

const string Config::CONF_FILE_PATH = "dragoncreator.conf";
const string Config::REQ_ENGINE_VERSION = "0.7";
string Config::gdata_path = TConnector::getSetting("game_path");//"/home/darek/Senlin"; //TEST DIR
/**
 * @brief Config::Config Private constructor to prevent initialization
 */
Config::Config()
{
}
/**
 * @brief Config::getEngineVer Returns required version of game engine
 * @return String with version number
 */
string Config::getEngineVer()
{
    return REQ_ENGINE_VERSION;
}
/**
 * @brief Config::getGameDir Returns current path to graphic archive.
 * @return String with absolute path to graphic archive.
 */
string Config::getGdataPath()
{
    return gdata_path;
}
/**
 * @brief Config::setGameDir Sets specified path as grpahic archive path.
 * @param path String with system path.
 * @return True if specified path was susscessfully set, false otherwise.
 */
bool Config::setGdataPath(string path)
{
    if(isGdataPathValid(path))
    {
        gdata_path = path;
        return true;
    }
    else
        return false;
}

/**
 * @brief Config::isGameDirValid Validates whether specifeid path is valid
 *        system path to grphical archive.
 * @param path String with system path to archive.
 * @return True if specified path is valid, false otherwise.
 */
bool Config::isGdataPathValid(string path)
{
    //TODO path validation
    return true;
}

/**
 * @brief Config::saveConf Saves current configuration parameters to
 *        config file.
 * @return True if configuration was successfully saved, false otherwise.
 */
bool Config::saveConf()
{
    string conf = "";
    conf += "game_path:" + gdata_path + ";\n";

    filebuf fb;
    fb.open(CONF_FILE_PATH, ios::out);
    if(fb.is_open())
    {
        ostream os(&fb);
        os << conf;
        fb.close();
        return true;
    }
    else
        return false;
}
