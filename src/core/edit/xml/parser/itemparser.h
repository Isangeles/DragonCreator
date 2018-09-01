/*
 * itemparser.h
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
#ifndef ITEMPARSER_H
#define ITEMPARSER_H

#include <vector>
#include <sstream>

#include <QDomDocument>

#include "src/core/data/object/item/weapon.h"
#include "src/util/weaponutils.h"
#include "modifierparser.h"
#include "requirementparser.h"
#include "effectparser.h"
#include "src/util/text/textreader.h"

using namespace std;
/**
 * @brief Static class for parsing items to XML nodes
 */
class ItemParser
{
public:
    static QDomNode weaponToNode(Weapon *weapon, QDomDocument *doc);
    static Weapon weaponFromNode(QDomNode weaponNode);
private:
    ItemParser();

};

#endif // ITEMPARSER_H
