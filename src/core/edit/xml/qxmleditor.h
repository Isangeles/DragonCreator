/*
 * qxmleditor.h
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
#ifndef XMLEDITOR_H
#define XMLEDITOR_H

#include <iostream>
#include <fstream>

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTemporaryFile>
#include <QDomDocument>
#include <QException>

/**
 * @brief Class to editing XML documents, using Qt XML library
 */
class QXmlEditor
{
public:
    QXmlEditor(std::string path);
    ~QXmlEditor();
    QDomDocument *getDoc();
    bool addNode(QDomNode element);
    QString getSource();
    bool isOpen();
    bool save();
    void close();
private:
    QFile *xml;
    QTemporaryFile *tempXml;
    QDomDocument *doc;
};

#endif // QXMLEDITOR_H
