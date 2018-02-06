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

const std::string Config::REQ_ENGINE_VERSION = "0.7";
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
std::string Config::getEngineVer()
{
    return REQ_ENGINE_VERSION;
}
