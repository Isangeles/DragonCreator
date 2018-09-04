/*
 * addrequirementdialog.cpp
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
#include "newrequirementdialog.h"
#include "ui_newrequirementdialog.h"
/**
 * @brief NewRequirementDialog::NewRequirementDialog Constructor
 * @param parent Parent widget
 */
NewRequirementDialog::NewRequirementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRequirementDialog)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(add(Requirement*)), parent, SLOT(requirementAdded(Requirement*)));

    RequirementType activeReqType = static_cast<RequirementType>(ui->attrCombo->currentIndex());
    loadsAttributesFor(activeReqType);
}
/**
 * @brief NewRequirementDialog::~NewRequirementDialog Destructor
 */
NewRequirementDialog::~NewRequirementDialog()
{
    delete ui;
}
/**
 * @brief NewRequirementDialog::loadsAttributesFor Loads UI combo with attributes for specified
 * @param type
 */
void NewRequirementDialog::loadsAttributesFor(RequirementType type)
{
    vector<RequirementAttributeType> attrs = RequirementUtils::getAttributesListFor(type);

    ui->attrCombo->clear();
    for(RequirementAttributeType a : attrs)
    {
        ui->attrCombo->addItem(QString::fromStdString(RequirementUtils::attrNameFromType(a)));
    }
}
/**
 * @brief NewRequirementDialog::on_typeCombo_currentIndexChanged Triggered on type combo change
 * @param id Index of currently active type combo item
 */
void NewRequirementDialog::on_typeCombo_currentIndexChanged(int id)
{
    RequirementType activeReqType = static_cast<RequirementType>(id);
    loadsAttributesFor(activeReqType);
}
/**
 * @brief NewRequirementDialog::on_addAttrB_clicked Triggered on add attribute button click
 */
void NewRequirementDialog::on_attrAddB_clicked()
{
    QString attrName = ui->attrCombo->currentText();
    if(!attrName.isEmpty())
    {
        // to avoid attributes duplication
        for(int i = 0; i < ui->attrsList->count(); i ++)
        {
            QListWidgetItem *it = ui->attrsList->item(i);
            if(TextReader::startsWith(attrName.toStdString(), it->text().toStdString()))
                delete it;
        }
        attrName += "='" + ui->attrValueEdit->text() + "'";
        ui->attrsList->addItem(attrName);
    }
}
/**
 * @brief NewRequirementDialog::on_addB_clicked Triggered on add button click
 */
void NewRequirementDialog::on_addB_clicked()
{
    RequirementType type = static_cast<RequirementType>(ui->typeCombo->currentIndex());
    string value = ui->valueEdit->text().toStdString();
    map<string, string> attributes;
    for(int i = 0; i < ui->attrsList->count(); i ++)
    {
        QListWidgetItem* attr = ui->attrsList->item(i);
        QString label = attr->text();

        // VOODOO
        //QRegExp regex("'(.*)'");
        QList<QString> a = label.split("=");
        if(a.length() > 1)
        {
            QString aName = a.at(0);
            QString aValue = a.at(1);
            aValue = aValue.replace("'", "");

            attributes.insert(make_pair(aName.toStdString(), aValue.toStdString()));
        }
    }
    Requirement *req = new Requirement(type, attributes, value);
    emit add(req);
    close();
}
