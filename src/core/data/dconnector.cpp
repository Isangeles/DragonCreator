/*
 * dconnector.cpp
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
#include "dconnector.h"
/**
 * @brief DConnector::DConnector Private constructor
 */
DConnector::DConnector(){}
/**
 * @brief DConnector::addWeaponToBase Adds specified weapon to game weapons base
 * @param basePath Path to XML wapons base
 * @param weapon Weapon
 * @return  True if specified weapon was successfull added, false otherwsie
 */
bool DConnector::addWeaponToBase(string basePath, Weapon *weapon)
{
    try
    {
        QXmlEditor baseEdit(basePath);
        QDomNode weaponNode = ItemParser::weaponToNode(weapon, baseEdit.getDoc());
        if(baseEdit.addNode(weaponNode))
        {
            baseEdit.save();
            baseEdit.close();
            return true;
        }
        else
        {
            baseEdit.close();
            return false;
        }
    }
    catch(runtime_error msg)
    {
        cerr << msg.what() << endl;
        return false;
    }
}
/**
 * @brief DConnector::addEffectToBase Adds specified effect to game effect base
 * @param basePath Path to XML effect base
 * @param effect Effect
 * @return True if effect was successfull added, false otherwise
 */
bool DConnector::addEffectToBase(string basePath, Effect *effect)
{
    try
    {
        QXmlEditor baseEdit(basePath);
        QDomNode effectNode = EffectParser::effectToNode(effect, baseEdit.getDoc());
        if(baseEdit.addNode(effectNode))
        {
            baseEdit.save();
            baseEdit.close();
            return true;
        }
        else
        {
            baseEdit.close();
            return false;
        }
    }
    catch(runtime_error e)
    {
        cerr << e.what() << endl;
        return false;
    }
}
/**
 * @brief DConnector::getXmlSource Retruns source of XML document from specified path
 * @param xmlPath Path to XML document
 * @return String with source of XML document
 */
string DConnector::getXmlSource(string xmlPath)
{
    try
    {
        QXmlEditor xml(xmlPath);
        string source = xml.getSource().toStdString();
        xml.close();
        return source;
    }
    catch(runtime_error e)
    {
        cerr << e.what() << endl;
        return "Can't open:" + xmlPath;
    }
}
