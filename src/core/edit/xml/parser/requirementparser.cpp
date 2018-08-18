/*
 * requirementparser.cpp
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
#include "requirementparser.h"

/**
 * @brief RequirementParser::RequirementParser Private constructor
 */
RequirementParser::RequirementParser()
{
}
/**
 * @brief RequirementParser::requirementToNode Parses requirement to XML document node
 * @param req Requirement to parse
 * @param doc XML document
 * @return XML document node
 */
QDomNode RequirementParser::requirementToNode(Requirement *req, QDomDocument *doc)
{
    QDomElement reqE = doc->createElement(QString::fromStdString(RequirementUtils::tagNameFromType(req->getType())));

    QDomText reqNodeText = doc->createTextNode(QString::fromStdString(req->getValue()));
    reqE.appendChild(reqNodeText);
    for(pair<string, string> attr : req->getAttributes())
    {
        reqE.setAttribute(QString::fromStdString(attr.first), QString::fromStdString(attr.second));
    }

    return reqE;
}
/**
 * @brief RequirementParser::requirementFromNode Parses specified XML node to requirement object
 * @param node XML doc node from base
 * @return Requirement from specified node
 */
Requirement RequirementParser::requirementFromNode(QDomNode node)
{
    QDomElement reqE = node.toElement();

    RequirementType type = RequirementUtils::typeFromTagName(reqE.tagName().toStdString());

    string value = reqE.text().toStdString();

    map<string, string> attrs;
    QDomNamedNodeMap nodeAttrsMap = reqE.attributes();
    for(int i = 0; i < nodeAttrsMap.size(); i ++)
    {
        QDomNode attr = nodeAttrsMap.item(i);
        attrs.insert(make_pair(attr.nodeName().toStdString(), attr.nodeValue().toStdString()));
    }

    return Requirement(type, attrs, value);
}
