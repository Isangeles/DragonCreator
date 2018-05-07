/*
 * effectparser.cpp
 * Copyright (C) 2018 Dariusz Sikora<darek@pc-solus>
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
#include "effectparser.h"
/**
 * @brief EffectParser::EffectParser Private constructor
 */
EffectParser::EffectParser(){}
/**
 * @brief EffectParser::effectToNode Parses specified effect to MXL document node
 * @param effect Effect to parse
 * @param doc Document for effect node
 * @return Document node
 */
QDomNode EffectParser::effectToNode(Effect *effect, QDomDocument *doc)
{
    QDomElement effectE = doc->createElement("effect");

    effectE.setAttribute("id", QString::fromStdString(effect->id));

    string typeId = EffectUtils::typeToId(effect->type);
    effectE.setAttribute("type", QString::fromStdString(typeId));

    QDomElement bonusesE = doc->createElement("bonuses");
    for(Modifier mod : *effect->modifiers)
    {
        QDomNode modNode = ModifierParser::modifierToNode(&mod, doc);
        bonusesE.appendChild(modNode);
    }

    return effectE;
}