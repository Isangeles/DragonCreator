/*
 * weaponseditorwidget.cpp
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
#include "weaponseditorwidget.h"
#include "ui_weaponseditorwidget.h"
/**
 * @brief WeaponsEditorWidget::WeaponsEditorWidget Weapons editor widget constructor
 * @param editor Weapons editor
 * @param parent Optional parent
 */
WeaponsEditorWidget::WeaponsEditorWidget(WeaponsEditor *editor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeaponsEditorWidget)
{
    ui->setupUi(this);
    this->editor = editor;
    newModifier = new NewModdifierDialog(this);
    //bool connResult = QObject::connect(newModifier, SIGNAL(add()), this, SLOT(modifierAdded())); //TODO conncet new modifier dialog to widget
    //emit newModifier->add();
    //cout << connResult << endl;
}
/**
 * @brief WeaponsEditorWidget::~WeaponsEditorWidget Weapon editor widget destructor
 */
WeaponsEditorWidget::~WeaponsEditorWidget()
{
    delete ui;
    delete newModifier;
}

NewModdifierDialog *WeaponsEditorWidget::getNMDialog()
{
    return newModifier;
}
/**
 * @brief WeaponsEditorWidget::on_addB_clicked Method triggered on UI add button clicked
 */
void WeaponsEditorWidget::on_addB_clicked()
{
   string id = ui->idEdit->text().toStdString();
   string type = ui->typeCombo->currentText().toStdString();
   string material = ui->materialCombo->currentText().toStdString();

   int level = ui->levelEdit->value();
   int dmgMin = ui->dmgMinEdit->value();
   int dmgMax = ui->dmgMaxEdit->value();
   int value = ui->valueEdit->value();

   string icon = ui->iconCombo->currentText().toStdString();
   string ss = ui->spritesheetCombo->currentText().toStdString();

   vector<Modifier> *modifiers = new vector<Modifier>;
   Modifier mod(ModifierType::HEALTH, new map<string, string>);
   modifiers->push_back(mod);

   if(editor->newWeapon(id, level, type, material, value, dmgMin, dmgMax, icon, ss, modifiers))
       QMessageBox::information(this, "Succes", "Items successfully added");
   else
       QMessageBox::warning(this, "Error", "Fail to add item");
}
/**
 * @brief WeaponsEditorWidget::on_addBonusB_clicked Triggered on add bonus button clicked
 */
void WeaponsEditorWidget::on_addBonusB_clicked()
{
    newModifier = new NewModdifierDialog(this);
    newModifier->show();
}
/**
 * @brief WeaponsEditorWidget::on_modifer_add Triggered by adding new modifier
 * @param mod New modifier
 */
void WeaponsEditorWidget::modifierAdded(Modifier* m)
{
    QString label = QString::fromStdString(m->getName());
    label += "  ";
    for(pair<string, string> attr : *m->getAttributes())
    {
        label += QString::fromStdString(attr.first) + "='" + QString::fromStdString(attr.second) + "'  ";
    }
    ui->bonusesList->addItem(label);
}
