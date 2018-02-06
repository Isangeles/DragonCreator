/*
 * xmlelement.cpp
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
#include "xmlelement.h"
/**
 * @brief XmlElement::XmlElement XML element constructor
 * @param name Element name
 * @param text Element text content
 * @param attributes List with element attributes
 */
XmlElement::XmlElement(string name, string text, vector<XmlAttribute> *attributes)
{
    this->name = name;
    this->text = text;
    this->attributes = attributes;
}
/**
 * @brief XmlElement::~XmlElement XML element destructor
 */
XmlElement::~XmlElement()
{
    delete attributes;
}
/**
 * @brief XmlElement::getName Returns element name
 * @return Element name
 */
string XmlElement::getName()
{
    return name;
}
/**
 * @brief XmlElement::getTxt Returns element text content
 * @return Element text content
 */
string XmlElement::getTxt()
{
    return text;
}
/**
 * @brief XmlElement::getAttributes Returns element attributes
 * @return List with tuples
 */
vector<XmlAttribute> *XmlElement::getAttributes()
{
    return attributes;
}
