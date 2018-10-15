/*
 * engine.h
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
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
/**
 * @brief Static class with game engine properties like file extensions, configuration files names, etc.
 */
class Engine
{
public:
    static const std::string BASE_EXT;
    static const std::string CONF_EXT;
    static const std::string MOD_CONF_NAME;
    static const std::string GDATA_NAME;
private:
    Engine();
};

#endif // ENGINE_H
