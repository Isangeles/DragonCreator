/*
 * textreader.h
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
#ifndef TEXTREADER_H
#define TEXTREADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/**
 * @brief Class for reading module text files(like .conf, .lang, etc.)
 */
class TextReader
{
public:
    TextReader(string pathToFile);
    string getText(string textId);
    bool close();
    const vector<string> getListFromLine(const string &line, const char &delimeter);

private:
    static string COMMENT_PREFIX;
    static string ENDL_CHAR;
    ifstream *fileS;
};

#endif // TEXTREADER_H
