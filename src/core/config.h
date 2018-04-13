/*
 * config.h
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
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;
/**
 * @brief Static class for configuration parameters
 */
class Config
{
public:
    static string getEngineVer();
    static string getGameDir();
    static bool setGameDir(string path);
private:
    Config();
    static bool isGameDirValid(string path);
    static const string REQ_ENGINE_VERSION;
    static string gameDir;
};

#endif // CONFIG_H
