/*
 * zipeditor.cpp
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
#include "zipeditor.h"
/**
 * @brief ZipEditor::ZipEditor Zip editor constructor
 * @param pathToZip String with path to ZIP archive
 * @throw runtime_error If specified path is invalid
 */
ZipEditor::ZipEditor(string pathToZip)
{
    //QUAZIP
    zip = new QuaZip(QString::fromStdString(pathToZip));
    if(!zip->open(QuaZip::mdUnzip))
        throw runtime_error("zip not found or unable to open:" + pathToZip);

    //ZIPIOS
    /*
    cout << "zip_editor_open:" << pathToZip << endl; //DEBUG

    zip = new zipios::ZipFile(pathToZip);
    if(!zip->isValid())
        throw std::runtime_error("zip_editor_fail_msg//can't open:" + pathToZip);
    */
}
/**
 * @brief ZipEditor::~ZipEditor Zip editor destructor
 */
ZipEditor::~ZipEditor()
{
    zip->close();
    delete zip;
}
/**
 * @brief ZipEditor::getFilesNamesIn Returns list with names of all files in specified directory inside open zip
 * @param zipPath Path to directory inside open zip
 * @return List with files names
 * @throws runtime_error If specified path was not found
 */
vector<string> ZipEditor::getFilesNamesIn(string zipPath)
{
    vector<string> files;
    //QUAZIP
    QuaZipDir zipDir(zip);
    //cout << "zip_edit_attempt_to_open:" << zipPath << endl; //TEST
    zipDir.cd(QString::fromStdString(zipPath));

    if(zipDir.exists())
    {
        QList<QuaZipFileInfo> entries = zipDir.entryInfoList(QDir::Files);
        for(QuaZipFileInfo &file : entries)
        {
            files.push_back(file.name.toStdString());
        }
        return files;
    }
    else
        throw runtime_error("zip_dir_not_found:" + zipPath);
    //ZIPIOS
    /*
    vector<string> *files = new vector<string>();
    zipios::FileEntry::pointer_t zipDir = zip->getEntry(zipPath, zipios::FileCollection::MatchPath::IGNORE);

    for(auto it = zipEntries.begin(); it != zipEntries.end(); ++it)
    {
        std::cout << "file:" << *(*it) << std::endl;
        //files->push_back(*(*it));
    }
    return files;
    */
}
/*
istream *ZipEditor::getFile(string path)
{
    zipios::FileCollection::stream_pointer_t s(zip->getEntry(path));

}
*/
/**
 * @brief ZipEditor::isOpen Checks if editor has zip archive open
 * @return True if zip archive is open and ready to edit, false otherwise
 */
bool ZipEditor::isOpen()
{
    //QUAZIP
    if(zip != NULL)
        return zip->isOpen();
    else
        return false;

    //ZIPIOS
    //return (zip != NULL && zip->isValid());
}
