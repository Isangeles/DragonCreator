/*
 * newmodifierdialog.cpp
 *
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
#include "newmoddifierdialog.h"
#include "ui_newmoddifierdialog.h"

/**
 * @brief NewModdifierDialog::NewModdifierDialog New modifier dialog constructor
 * @param parent QWidget parent
 */
NewModdifierDialog::NewModdifierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewModdifierDialog)
{
    ui->setupUi(this);
    bool connResult = QObject::connect(this, SIGNAL(add(Modifier*)), parent, SLOT(modifierAdded(Modifier*)));

    ModifierType activeModType = static_cast<ModifierType>(ui->typeCombo->currentIndex());
    loadAttributesFor(activeModType);
}
/**
 * @brief NewModdifierDialog::~NewModdifierDialog New modifier dialog descructor
 */
NewModdifierDialog::~NewModdifierDialog()
{
    delete ui;
}
/**
 * @brief NewModdifierDialog::loadAttributesFor Fills attributes combobox with attributes for specified modifier type
 * @param mod Modifier type
 */
void NewModdifierDialog::loadAttributesFor(ModifierType mod)
{
    vector<ModifierAtributeType> attributes = ModifierUtils::getAttributesListFor(mod);

    ui->attrCombo->clear();
    for(ModifierAtributeType type : attributes)
    {
        ui->attrCombo->addItem(QString::fromStdString(ModifierUtils::getNameFor(type)));
    }
}
/**
 * @brief NewModdifierDialog::loadValuesFor Fills attribute values combobox with values for specified attribute type
 * @param attr Modifier attribute type
 * @deprecated Now value is just a text edit
 */
void NewModdifierDialog::loadValuesFor(ModifierAtributeType attr)
{
    //value is now pure edit
    /*
    vector<string> values = ModifierUtils::getValuesListFor(attr);

    ui->attrValueCombo->clear();
    for(string value : values)
    {
        ui->attrValueCombo->addItem(QString::fromStdString(Lang::getModifierAttributeValueName(value)));
    }
    */
}
/**
 * @brief NewModdifierDialog::on_addB_clicked Triggered on add button clicked
 */
void NewModdifierDialog::on_addB_clicked()
{
    ModifierType type = static_cast<ModifierType>(ui->typeCombo->currentIndex());
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
    Modifier *m = new Modifier(type, attributes);
    emit add(m);
    close();
}
/**
 * @brief NewModdifierDialog::on_addAttrB_clicked Triggered on add attribute button clicked
 */
void NewModdifierDialog::on_addAttrB_clicked()
{
    QString attrName = ui->attrCombo->currentText();
    if(!attrName.isEmpty())
    {
        // to avoid attributes duplications
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
 * @brief NewModdifierDialog::on_typeCombo_currentIndexChanged Triggered on type combobox item change
 * @param id ID of selected item
 */
void NewModdifierDialog::on_typeCombo_currentIndexChanged(int id)
{
    ModifierType type = static_cast<ModifierType>(id); // Ordinal to type
    loadAttributesFor(type);
    ui->attrValueEdit->clear();
    ui->attrsList->clear();
}
