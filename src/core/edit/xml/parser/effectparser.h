/*
 * effectparser.h
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
#ifndef EFFECTPARSER_H
#define EFFECTPARSER_H

#include <vector>

#include <QDomDocument>

#include "src/core/data/object/effect.h"
#include "src/util/effectutils.h"
#include "modifierparser.h"

using namespace std;
/**
 * @brief Class for parsing effects
 */
class EffectParser
{
public:
    static QDomNode effectToNode(Effect *effect, QDomDocument *doc);
    static Effect *effectFromNode(QDomNode node);
private:
    EffectParser();
};

#endif // EFFECTPARSER_H
