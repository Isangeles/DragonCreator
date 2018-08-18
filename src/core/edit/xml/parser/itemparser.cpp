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

    string typeId = WeaponUtils::typeToId(weapon->type);
    weaponE.setAttribute("type", QString::fromStdString(typeId));

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
    for(Modifier mod : weapon->bonuses)
    {
        QDomNode modNode = ModifierParser::modifierToNode(&mod, doc);
        bonusesE.appendChild(modNode);
    }
    weaponE.appendChild(bonusesE);

    QDomElement equipEffectsE = doc->createElement("equipEffects");
    for(string eId : weapon->effectsEq)
    {
        QDomElement effectE = doc->createElement("effect");
        effectE.setNodeValue(QString::fromStdString(eId));
        equipEffectsE.appendChild(effectE);
    }
    weaponE.appendChild(equipEffectsE);

    QDomElement hitEffectsE = doc->createElement("hitEffects");
    for(string eId : weapon->effectsHit)
    {
        QDomElement effectE = doc->createElement("effect");
        QDomText effectIdText = doc->createTextNode(QString::fromStdString(eId));
        effectE.appendChild(effectIdText);
        hitEffectsE.appendChild(effectE);
    }
    weaponE.appendChild(hitEffectsE);

    return weaponE;
}
/**
 * @brief ItemParser::weaponFromNode Parses specified XML node from weapons base to weapon object
 * @param node XML document node
 * @return Weapon object
 */
Weapon ItemParser::weaponFromNode(QDomNode node)
{
    QDomElement itemE = node.toElement();
    string id = itemE.attribute("id").toStdString();
    int level = itemE.attribute("level").toInt();
    WeaponType type = WeaponUtils::typeFromId(itemE.attribute("type").toStdString());

    string material = itemE.attribute("material").toStdString();
    int value = itemE.attribute("value").toInt();

    string damageAttr = itemE.attribute("damage").toStdString();
    int damageMin = 0; // TODO: min damage parsing
    int damageMax = 0; // TODO: max damage parsing

    QDomElement iconE = itemE.elementsByTagName("icon").at(0).toElement();
    string icon = iconE.text().toStdString(); // TODO: check if works OK

    QDomElement spirtesheetE = itemE.elementsByTagName("spritesheet").at(0).toElement();
    string spritesheet = spirtesheetE.text().toStdString();

    vector<Modifier> modifiers;
    QDomElement bonusesE = itemE.elementsByTagName("bonuses").at(0).toElement();
    QDomNodeList modNl = bonusesE.childNodes();
    for(int i = 0; i < modNl.size(); i ++)
    {
        QDomNode modNode = modNl.at(i);
        modifiers.push_back(ModifierParser::modifierFromNode(&modNode));
    }

    vector<string> effectsEq;
    QDomElement equipEffectsE = itemE.elementsByTagName("equipEffects").at(0).toElement();
    QDomNodeList effectsEqNl = equipEffectsE.childNodes();
    for(int i = 0; i < effectsEqNl.size(); i ++)
    {
        QDomNode effectNode = effectsEqNl.at(i);
        string eId = effectNode.toElement().text().toStdString();
        effectsEq.push_back(eId);
    }

    vector<string> effectsHit;
    QDomElement hitEffectsE = itemE.elementsByTagName("hitEffects").at(0).toElement();
    QDomNodeList effectsHitNl = hitEffectsE.childNodes();
    for(int i = 0; i < effectsHitNl.size(); i ++)
    {
        QDomNode effectNode = effectsHitNl.at(i);
        string eId = effectNode.toElement().text().toStdString();
        effectsHit.push_back(eId);
    }

    return Weapon(id, level, type, material, value, damageMin, damageMax, icon, spritesheet,
                  modifiers, effectsEq, effectsHit);
}
