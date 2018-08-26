/*
 * requirementparser.h
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
#ifndef REQUIREMENTPARSER_H
#define REQUIREMENTPARSER_H

#include <QDomDocument>

#include "src/core/data/object/requirement.h"
#include "src/util/requirementutils.h"

/**
 * @brief Class for requirements parser
 */
class RequirementParser
{
public:
    static QDomNode requirementToNode(Requirement *req, QDomDocument *doc);
    static Requirement requirementFromNode(QDomNode *node);
private:
    RequirementParser();
};

#endif // REQUIREMENTPARSER_H
