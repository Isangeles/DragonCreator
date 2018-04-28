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
string Config::gameDir = TConnector::getSetting("game_path");//"/home/darek/Senlin"; //TEST DIR
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
 * @brief Config::getGameDir Returns current game directory
 * @return String with absolute path to game directory
 */
string Config::getGameDir()
{
    return gameDir;
}
/**
 * @brief Config::setGameDir Sets directory with specified path as game directory
 * @param path String with path to directory
 * @return  True if specified directory was susscessfully set, false otherwise
 */
bool Config::setGameDir(string path)
{
    if(isGameDirValid(path))
    {
        gameDir = path;
        return true;
    }
    else
        return false;
}

bool Config::isGameDirValid(string path)
{
    //TODO path validation
    return true;
}

bool Config::saveConf()
{
    string conf = "";
    conf += "game_path:" + gameDir + ";\n";

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
