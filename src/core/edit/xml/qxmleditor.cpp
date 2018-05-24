/*
 * qxmleditor.cpp
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
#include "qxmleditor.h"
/**
 * @brief XmlEditor::XmlEditor XML document editor constructor
 * @param file XML file
 */
QXmlEditor::QXmlEditor(std::string path)
{
    xml = new QFile(QString::fromStdString(path));
    if(xml->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        doc = new QDomDocument("document");
        if(!doc->setContent(xml))
        {
            delete doc;
            throw std::runtime_error("qxmleditor_init_fail//Fail to parse document:" + path);
        }
        else
        {
            tempXml = new QTemporaryFile();
            if(!tempXml->open())
                throw std::runtime_error("qxmleditor_init_fail//Fail to create temp file:" + path);
        }
    }
    else
        throw std::runtime_error("qxmleditor_init_fail//Fail to open document:" + path);
}
/**
 * @brief XmlEditor::~XmlEditor XML edidor destrcutor
 */
QXmlEditor::~QXmlEditor()
{
    delete doc;
    delete xml;
    delete tempXml;
}
/**
 * @brief QXmlEditor::getNode Returns node with specified name
 * @param nodeName Desired node name
 * @return Node from open document or null if not found
 */
/*
QDomNode QXmlEditor::getNode(string nodeName)
{
    if(isOpen())
    {
        QDomNodeList nl = doc->childNodes();
        for(int i = 0; i < nl.size(); i++)
        {
            QDomNode n = nl.at(i);
            if(n.nodeName().toStdString() == nodeName)
                return n;
        }
    }
}
*/
/**
 * @brief XmlEditor::getDoc Rertuns edited document
 * @return XML document
 */
QDomDocument* QXmlEditor::getDoc()
{
    return doc;
}
/**
 * @brief XmlEditor::addNode Adds specified element to edited document
 * @param element Document element
 * @return True if element was successfully adde to edited document, false otherwise
 */
bool QXmlEditor::addNode(QDomNode node)
{
    if(isOpen())
    {
        QDomNodeList nList = doc->childNodes();
        QDomNode root = nList.at(1); //Main node at index 1

        root.appendChild(node.toElement());
        doc->appendChild(root);

        QByteArray docContent = doc->toByteArray();

        tempXml->write(docContent);
        QTextStream qts(tempXml);

        return true;
    }
    else
        return false;
}
/**
 * @brief QXmlEditor::getSource Returns source of open document
 * @return String with source of XML document
 */
QString QXmlEditor::getSource()
{
    if(isOpen())
        return doc->toString();
    else
        return "No document open";
}
/**
 * @brief XmlEditor::isOpen Checks if editor has open document
 * @return True if editor has opened document, false otherwise
 */
bool QXmlEditor::isOpen()
{
    return ((doc != NULL && xml != NULL) && xml->isOpen());
}
/**
 * @brief QXmlEditor::save Saves edited document
 * @return True if document was successfully saved, false otherwise
 */
bool QXmlEditor::save()
{
    tempXml->reset();
    xml->reset();
    QByteArray docContent = tempXml->readAll();
    //xml->resize(0); //clear file
    if(xml->write(docContent) != -1) //TODO check if everything is right with temp file(?)
        return true;
    else
        return false;
}
/**
 * @brief XmlEditor::close Closes edited file
 * @return True if file was successfully closed, false otherwise
 */
void QXmlEditor::close()
{
    xml->close();
    tempXml->close();
}
