/*
 * textreader.cpp
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
#include "textreader.h"
//TODO: handling speparator diferent then ':'
string TextReader::COMMENT_PREFIX = "#";
string TextReader::ENDL_CHAR = ";";
/**
 * @brief TextReader::getListFromLine Splits specified line by specified delimiter to list
 * @param line String with text line
 * @param delimeter Delimiter
 * @return Vector list with strings
 */
const vector<string> TextReader::getListFromLine(const string& line, const char& delimeter)
{
    string buff{""};
    vector<string> list;

    for(auto n : line)
    {
        if(n != delimeter)
            buff+=n;
        else if(n == delimeter && buff != "")
        {
            list.push_back(buff);
            buff = "";
        }
    }
    if(buff != "")
        list.push_back(buff);
    return list;
}
/**
 * @brief TextReader::startsWith Checks if specified text starts with specified prefix
 * @param prefix Prefix
 * @param text Text to check
 * @return True if text starts with prefix, false otherwise
 */
const bool TextReader::startsWith(const string &prefix, const string &text)
{
    return !text.compare(0, prefix.size(), prefix);
}
/**
 * @brief Text reader constructor, creates reader for specified file
 * @param pathToFile Path to file to read
 * @throws Exception if no such file was found
 */
TextReader::TextReader(string pathToFile)
{
    fileS = new ifstream(pathToFile);
    if(!fileS->is_open())
        throw runtime_error("No such file!");
}
/**
 * @brief TextReader::getText Returns text with specified ID from opened file
 * @param textId Desired text ID
 * @return String with text
 * @throws Exception if no file is opened
 */
string TextReader::getText(string textId)
{
    if(COMMENT_PREFIX == "")
        COMMENT_PREFIX = "#";
    if(ENDL_CHAR == "")
        ENDL_CHAR = ";";

    if(!fileS->is_open())
        throw runtime_error("No file open!");
    else
    {
        string line;
        try
        {
            while(getline(*fileS, line))
            {
                //cout << "text_reader_line:" << line << endl; //DEBUG
                //cout << "text_reader_com_prefix:" << COMMENT_PREFIX << endl; //DEBUG
                if(line.compare(0, COMMENT_PREFIX.size(), COMMENT_PREFIX))
                {
                    //cout << "text_reader_id_cmp:" << textId << endl; //DEBUG
                    if(!line.compare(0, textId.size(), textId))
                    {
                        vector<string> lineL = getListFromLine(line, ':');
                        string text = lineL.at(1);
                        if(!text.compare(text.size()-1, 1, ENDL_CHAR)) //removes end line char
                            text.pop_back();
                        return text;
                    }
                }
            }
        }
        catch(out_of_range &e)
        {
            cerr << "text_reader_fail:" << e.what() << endl;
        }
    }
    return "No text with such ID";
}
/**
 * @brief TextReader::close Closes open file
 * @return Ture if file was successfully closed, false if file was not open
 */
bool TextReader::close()
{
    if(fileS->is_open())
    {
        fileS->close();
        return true;
    }
    else
        return false;
}
