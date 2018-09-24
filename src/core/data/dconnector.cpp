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
 * @brief DConnector::addArmorToBase Adds specified armor to game armors base.
 * @param basePath System path to armors base.
 * @param armor Armor item to add.
 * @return True if specified item was successfully added, false otherwise.
 */
bool DConnector::addArmorToBase(string basePath, Armor *armor)
{
    try
    {
        QXmlEditor baseEdit(basePath);
        QDomNode itemNode = ItemParser::armorToNode(armor, baseEdit.getDoc());
        if(baseEdit.addNode(itemNode))
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
    catch(runtime_error *e)
    {
        cerr << "add_armor_to_base_fail:" << e->what() << endl;
    }
    return false;
}
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
 * @brief DConnector::addEffectToBase Adds specified effect to game effects base
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
 * @brief DConnector::removeBaseObjectById Removes object(node) with specified ID from specified base
 * @param id ID of object(node) to remove
 * @return True if object was successfully removed, false otherwise
 */
bool DConnector::removeBaseObjectById(string basePath, string id)
{
    try
    {
        QXmlEditor baseEdit(basePath);
        if(baseEdit.removeNode("id", id))
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
    catch(runtime_error* e)
    {
        cerr << e->what() <<endl;
        return false;
    }
}
/**
 * @brief DConnector::getEffectsFromBase Returns all effects form effects base in specified path
 * @param basePath Path to XML effect base
 * @return List with effects
 */
vector<Effect> *DConnector::getEffectsFromBase(string basePath)
{
    vector<Effect> *effects = new vector<Effect>();
    try
    {
        QXmlEditor xml(basePath);

        QDomNodeList nl = xml.getDoc()->elementsByTagName("effect");
        for(int i = 0; i < nl.size(); i ++)
        {
            QDomNode effectNode = nl.at(i);
            Effect *effect = EffectParser::effectFromNode(effectNode);
            //cout << "e_from_node:" << effect->getId() << endl; //DEBUG
            effects->push_back(*effect);
        }

        xml.close();
    }
    catch(runtime_error e)
    {
        cerr << "get_effects_from_base_fail:" << e.what() << endl;
    }

    return effects;
}
/**
 * @brief DConnector::getArmorsFromBase Returns all armors from
 *        base in specified system path.
 * @param basePath System path to base.
 * @return List with armors from base.
 */
vector<Armor> *DConnector::getArmorsFromBase(string basePath)
{
    vector<Armor> *armors = new vector<Armor>;
    try
    {
        QXmlEditor xml(basePath);

        QDomNodeList nl = xml.getDoc()->elementsByTagName("item");
        for(int i = 0; i < nl.size(); i ++)
        {
            QDomNode itemNode = nl.at(i);
            Armor item = ItemParser::armorFromNode(itemNode);
            armors->push_back(item);
        }
    }
    catch(runtime_error *e)
    {
        cerr << "get_armors_from_base_fail:" << e->what() << endl;
    }
    return armors;
}
/**
 * @brief DConnector::getWeaponsFromBase Returns all wapons for base in specified path
 * @param path Path to XML wapons base
 * @return List with weapons
 */
vector<Weapon> *DConnector::getWeaponsFromBase(string basePath)
{
    vector<Weapon> *weapons = new vector<Weapon>;
    try
    {
        QXmlEditor xml(basePath);

        QDomNodeList nl = xml.getDoc()->elementsByTagName("item");
        for(int i = 0; i < nl.size(); i ++)
        {
            QDomNode itemNode = nl.at(i);
            Weapon item = ItemParser::weaponFromNode(itemNode);
            //cout << "w_from_node:" << item.getId() << endl; // DEBUG
            weapons->push_back(item);
        }
    }
    catch (runtime_error e)
    {
        cerr << "get_weapons_from_base_fail:" << e.what() << endl;
    }
    return weapons;
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
