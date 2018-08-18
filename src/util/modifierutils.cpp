/*
 * modifierutils.cpp
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
#include "modifierutils.h"
/**
 * @brief ModifierUtils::ModifierUtils Private constructor
 */
ModifierUtils::ModifierUtils(){}
/**
 * @brief Modifier::getAttributesListFor Returns list with attributes for specified modifier type
 * @param mod Modifier type
 * @return List with modifier attributes types
 */
vector<ModifierAtributeType> ModifierUtils::getAttributesListFor(ModifierType mod)
{
    vector<ModifierAtributeType> attrs;

    switch(mod)
    {
    case ModifierType::HEALTH: case ModifierType::MANA: case ModifierType::DUALWIELD: case ModifierType::ATTITUDE: case ModifierType::DODGE: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::VALUE));
        break;
    }
    case ModifierType::DAMAGE: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::VALUE));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::WEAPON_TYPE));
        break;
    }
    case ModifierType::UNDETECT: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::STEALTH_LEVEL));
        break;
    }
    case ModifierType::UNLOCK: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::LOCK_LEVEL));
        break;
    }
    case ModifierType::RESISTANCE: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::VALUE));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::RESI_TYPE));
        break;
    }
    case ModifierType::FLAG: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::FLAG_NAME));
        break;
    }
    case ModifierType::STATS: {
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::STR));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::CON));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::DEX));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::WIS));
        attrs.push_back(ModifierAtributeType(ModifierAtributeType::INT));
        break;
    }
    default: break;
    }
    return attrs;
}
/**
 * @brief Modifier::getValuesListFor Returns list with attributes for specified attribute type
 * @param attr Attribute type
 * @return List with attributes
 * @deprecated
 */
vector<string> ModifierUtils::getValuesListFor(ModifierAtributeType attr)
{
    vector<string> values;
    switch (attr)
    {
    case ModifierAtributeType::STEALTH_LEVEL: {
        values.push_back("1");
        values.push_back("2");
        values.push_back("3");
        break;
    }
    case ModifierAtributeType::LOCK_LEVEL: {
        values.push_back("1");
        values.push_back("2");
        values.push_back("3");
        break;
    }
    case ModifierAtributeType::RESI_TYPE: {
        values.push_back("fire");
        values.push_back("ice");
        values.push_back("nature");
        values.push_back("magic");
        break;
    }
    default: break;
    }
    return values;
}
/**
 * @brief ModifierUtils::typeFromOrdinal Converts specified attribute type ordinal to attribute type
 * @param ordinal Ordinal number of attribute type
 * @return Modifier attrubite type
 * @deprecated UNUSED now int is just casted to enum
 */
ModifierAtributeType ModifierUtils::typeFromOrdinal(int ordinal)
{
    switch(ordinal)
    {
    case 0:
        return ModifierAtributeType(ModifierType::HEALTH);
    default:
        return ModifierAtributeType(ModifierType::NONE);
    }
}
/**
 * @brief ModifierUtils::typeFromTagName Returns modifier type for specified XML tag name
 * @param name Tage name
 * @return Modifier type
 */
ModifierType ModifierUtils::typeFromTagName(string name)
{
    if(name == "statsModifier" || name == "statsBonus")
        return ModifierType::STATS;
    else if(name == "healthModifier" || name == "healthBonus")
        return ModifierType::HEALTH;
    else if(name == "manaModifier" || name == "manaBonus")
        return ModifierType::MANA;
    else if(name == "hasteModifier" || name == "hasteBonus")
        return ModifierType::HASTE;
    else if(name == "dodgeModifier" || name == "dodgeBonus")
        return ModifierType::DODGE;
    else if(name == "damageModifier" || name == "damageBonus")
        return ModifierType::DAMAGE;
    else if(name == "undetectModifier" || name == "undetectBonus")
        return ModifierType::UNDETECT;
    else if(name == "dualwieldModifier" || name == "dualwieldBonus")
        return ModifierType::DUALWIELD;
    else if(name == "resistanceModifier" || name == "resistanceBonus")
        return ModifierType::RESISTANCE;
    else if(name == "unlockModifier" || name == "unlockBonus")
        return ModifierType::UNLOCK;
    else if(name == "attitudeModifier" || name == "attitudeBonus")
        return ModifierType::ATTITUDE;
    else if(name == "flagModifier" || name == "flagBonus")
        return ModifierType::FLAG;
    else
        return ModifierType::NONE;
}
/**
 * @brief ModifierUtils::tagNameFromType Returns name of this modifier(for document node)
 * @return String with name
 */
string ModifierUtils::tagNameFromType(ModifierType type)
{
    switch(type)
    {
    case ModifierType::STATS:
        return "statsModifier";
    case ModifierType::HEALTH:
        return "healthModifier";
    case ModifierType::MANA:
        return "manaModifier";
    case ModifierType::HASTE:
        return "hasteModifier";
    case ModifierType::DODGE:
        return "dodgeModifier";
    case ModifierType::DAMAGE:
        return "damageModifier";
    case ModifierType::UNDETECT:
        return "undetectModifier";
    case ModifierType::DUALWIELD:
        return "dualwieldModifier";
    case ModifierType::RESISTANCE:
        return "resistanceModifier";
    case ModifierType::UNLOCK:
        return "unlockModifier";
    case ModifierType::ATTITUDE:
        return "attitudeModifier";
    case ModifierType::FLAG:
        return "flagModifier";
    default:
        return "noneModifier";
    }
}
/**
 * @brief ModifierUtils::getNameForAttr Converts attribute type to name(for XML document node)
 * @param attr Attribute type
 * @return String with attribute name
 */
string ModifierUtils::getNameFor(ModifierAtributeType attr)
{
    switch(attr)
    {
    case ModifierAtributeType::VALUE:
        return "value";
    case ModifierAtributeType::STEALTH_LEVEL: case ModifierAtributeType::LOCK_LEVEL:
        return "level";
    case ModifierAtributeType::WEAPON_TYPE: case ModifierAtributeType::RESI_TYPE:
        return "type";
    case ModifierAtributeType::FLAG_NAME:
        return "flag";
    case ModifierAtributeType::STR:
        return "str";
    case ModifierAtributeType::CON:
        return "con";
    case ModifierAtributeType::DEX:
        return "dex";
    case ModifierAtributeType::WIS:
        return "wis";
    case ModifierAtributeType::INT:
        return "int";
    default:
        return "error";
    }
}
