/*
 * modifierparser.cpp
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
#include "modifierparser.h"
/**
 * @brief modifierparser::modifierparser Private constructor
 */
ModifierParser::ModifierParser() {}
/**
 * @brief ModifierParser::modifierToNode Parses specified modifier to XML node
 * @param modifier Modifier
 * @param doc Document for node
 * @return XML document node
 */
QDomNode ModifierParser::modifierToNode(Modifier *modifier, QDomDocument *doc)
{
    QDomElement modE = doc->createElement(QString::fromStdString(modifier->getName()));

    for(pair<string, string> attr : *modifier->getAttributes())
    {
        modE.setAttribute(QString::fromStdString(attr.first), QString::fromStdString(attr.second));
    }

    return modE;
}
/**
 * @brief ModifierParser::modifierFromNode Parses specified modifier node to modifier object
 * @param node XML node from modifiers base
 * @return Modifier from node
 */
Modifier ModifierParser::modifierFromNode(QDomNode *node)
{
    //TODO node parsing
    QDomElement modE = node->toElement();

    ModifierType type = ModifierUtils::typeFromTagName(modE.tagName().toStdString());

    map<string, string> *attrs = new map<string, string>;
    QDomNamedNodeMap nodeAttrsMap = modE.attributes();

    for(int i = 0; i < nodeAttrsMap.size(); i ++)
    {
        QDomNode attr = nodeAttrsMap.item(i);
        //cout << "node_attr_name:" << attr.nodeName().toStdString() << endl;
        attrs->insert(make_pair(attr.nodeName().toStdString(), attr.nodeValue().toStdString()));
    }

    Modifier mod(type, attrs);
    return mod;
}
