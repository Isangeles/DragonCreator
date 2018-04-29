/*
 * tconnector.cpp
 *
 * Copyright (C) 2018 Dariusz Sikora<darek@dell-ins-ant>
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
#include "tconnector.h"
/**
 * @brief TConnector::TConnector Private constructor
 */
TConnector::TConnector(){}
/**
 * @brief TConnector::getSetting Returns settings parameter with specified ID from conf file
 * @param id ID of desired conf parameter
 * @return Value of parameter with specified ID
 */
string TConnector::getSetting(string id)
{
    try
    {
        string text = TextReader("dragoncreator.conf").getText(id);
        return text;
    }
    catch(runtime_error &e)
    {
        //TODO create conf file if not exists
        return "";
    }
}
