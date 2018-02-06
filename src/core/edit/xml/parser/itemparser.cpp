/*
 * itemparser.cpp
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
#include "itemparser.h"
/**
 * @brief ItemParser::ItemParser Private constructor
 */
ItemParser::ItemParser()
{
}
/**
 * @brief ItemParser::weaponToNode Parses specified weapon to XML node
 * @param weapon Weapon poitner
 * @return XML document node
 */
QDomNode ItemParser::weaponToNode(Weapon *weapon, QDomDocument *doc)
{
    QDomElement weaponE = doc->createElement("item");

    weaponE.setAttribute("id", QString::fromStdString(weapon->id));
    weaponE.setAttribute("reqLevel", QString::number(weapon->level));
    weaponE.setAttribute("type", QString::fromStdString(weapon->type));
    weaponE.setAttribute("material", QString::fromStdString(weapon->material));
    weaponE.setAttribute("value", QString::number(weapon->value));
    QString damage = QString::number(weapon->damageMin) + "-" + QString::number(weapon->damageMax);
    weaponE.setAttribute("damage", damage);

    QDomElement iconE = doc->createElement("icon");
    QDomText iconEText = doc->createTextNode(QString::fromStdString(weapon->icon));
    iconE.appendChild(iconEText);
    weaponE.appendChild(iconE);

    QDomElement spritesheetE = doc->createElement("spritesheet");
    QDomText spritesheetEText = doc->createTextNode(QString::fromStdString(weapon->spritesheet));
    spritesheetE.appendChild(spritesheetEText);
    weaponE.appendChild(spritesheetE);

    QDomElement bonusesE = doc->createElement("bonuses");
    for(Modifier mod : *weapon->bonuses)
    {
        QDomNode modNode = ModifierParser::modifierToNode(&mod, doc);
        bonusesE.appendChild(modNode);
    }
    weaponE.appendChild(bonusesE);
    QDomElement equipEffectsE = doc->createElement("equipEffects");
    //TODO weapon equip effects
    weaponE.appendChild(equipEffectsE);
    QDomElement hitEffectsE = doc->createElement("hitEffects");
    //TODO weapon hit effects
    weaponE.appendChild(hitEffectsE);

    return weaponE;
}
