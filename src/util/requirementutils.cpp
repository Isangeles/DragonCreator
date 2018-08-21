/*
 * requirementutils.cpp
 * Copyright (C) 2018 Dariusz Sikora<dev@isangeles.pl>
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
#include "requirementutils.h"

/**
 * @brief RequirementUtils::RequirementUtils Private constructor
 */
RequirementUtils::RequirementUtils()
{
}
/**
 * @brief RequirementUtils::typeFromTagName Returns requirement type for specfied tag name
 * @param tagName Tag name of XML doc node
 * @return Requirement type enum
 */
RequirementType RequirementUtils::typeFromTagName(string tagName)
{
    if(tagName == "levelReq")
        return RequirementType::LEVEL;
    else if(tagName == "statsReq")
        return RequirementType::STATS;
    else if(tagName == "genderReq")
        return RequirementType::GENDER;
    else if(tagName == "guildReq")
        return RequirementType::GUILD;
    else if(tagName == "goldReq")
        return RequirementType::GOLD;
    else if(tagName == "itemsReq")
        return RequirementType::ITEMS;
    else if(tagName == "pointsReq")
        return RequirementType::POINTS;
    else if(tagName == "manaReq")
        return RequirementType::MANA;
    else if(tagName == "healthReq" || tagName == "hpReq")
        return RequirementType::HEALTH;
    else if(tagName == "weaponReq")
        return RequirementType::WEAPON;
    else if(tagName == "flagReq")
        return RequirementType::FLAG;
    else
        return RequirementType::NONE;
}
/**
 * @brief RequirementUtils::tagNameFromType Return requirement XML node tag name
 * @param type Requirement type
 * @return Requirement name
 */
string RequirementUtils::tagNameFromType(RequirementType type)
{
    switch(type)
    {
    case RequirementType::LEVEL:
        return "levelReq";
    case RequirementType::STATS:
        return "statsReq";
    case RequirementType::GENDER:
        return "genderReq";
    case RequirementType::GUILD:
        return "guildReq";
    case RequirementType::GOLD:
        return "goldReq";
    case RequirementType::ITEMS:
        return "itemsReq";
    case RequirementType::POINTS:
        return "pointsReq";
    case RequirementType::MANA:
        return "manaReq";
    case RequirementType::HEALTH:
        return "healthReq";
    case RequirementType::WEAPON:
        return "wepaonReq";
    case RequirementType::FLAG:
        return "flagReq";
    default:
        return "noneReq";
    }
}
/**
 * @brief RequirementUtils::getAttributesListFor Returns list with attributes for specified requirement type
 * @param type Type of requirement
 * @return List with attributes for specified type
 */
vector<RequirementAttributeType> RequirementUtils::getAttributesListFor(RequirementType type)
{
    vector<RequirementAttributeType> attrs;
    switch(type)
    {
    case RequirementType::FLAG:
        attrs.push_back(RequirementAttributeType::EXPECT);
        break;
    case RequirementType::ITEMS:
        attrs.push_back(RequirementAttributeType::AMOUNT);
        break;
    default:
        break;
    }
    return attrs;
}
/**
 * @brief RequirementUtils::attrNameFromType Returns name of attribute for specified attribute type
 * @param type Attribute type
 * @return Name of attribute
 */
string RequirementUtils::attrNameFromType(RequirementAttributeType type)
{
    switch(type)
    {
    case RequirementAttributeType::AMOUNT:
        return "amount";
    case RequirementAttributeType::EXPECT:
        return "expect";
    default:
        return "none";
    }
}
