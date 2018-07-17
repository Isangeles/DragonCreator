/*
 * weaponseditorwidget.cpp
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
    newModifierD = new NewModdifierDialog(this);
    QObject::connect(this, SIGNAL(itemAdded()), parent, SLOT(onBaseObjectEdit()));

    for(WeaponType type : *Weapon::getWeaponTypes())
    {
        string typeName = Lang::getWeaponTypeName(type);
        ui->typeCombo->addItem(QString::fromStdString(typeName));
    }
    for(string &file : editor->getIconsFiles())
    {
        ui->iconCombo->addItem(QString::fromStdString(file));
    }
    for(string &file : editor->getSpritesheetsFiles())
    {
        ui->spritesheetCombo->addItem(QString::fromStdString(file));
    }
}
/**
 * @brief WeaponsEditorWidget::~WeaponsEditorWidget Weapon editor widget destructor
 */
WeaponsEditorWidget::~WeaponsEditorWidget()
{
    delete ui;
    delete newModifierD;
}

NewModdifierDialog *WeaponsEditorWidget::getNMDialog()
{
    return newModifierD;
}
/**
 * @brief WeaponsEditorWidget::on_addB_clicked Method triggered on UI add button clicked
 */
void WeaponsEditorWidget::on_addB_clicked()
{
   string id = ui->idEdit->text().toStdString();
   WeaponType type = (WeaponType)ui->typeCombo->currentIndex();
   string material = ui->materialCombo->currentText().toStdString();

   int level = ui->levelEdit->value();
   int dmgMin = ui->dmgMinEdit->value();
   int dmgMax = ui->dmgMaxEdit->value();
   int value = ui->valueEdit->value();

   string icon = ui->iconCombo->currentText().toStdString();
   string ss = ui->spritesheetCombo->currentText().toStdString();

   vector<Modifier> *modifiers = new vector<Modifier>;

   for(int i = 0; i < ui->bonusesList->count(); i++)
   {
       QListWidgetItem* item = ui->bonusesList->item(i);

       ModifierListItem *m = static_cast<ModifierListItem*>(item);
       modifiers->push_back(*m->getModifier());
   }

   //TODO translate messages
   if(editor->newWeapon(id, level, type, material, value, dmgMin, dmgMax, icon, ss, modifiers))
   {
       emit itemAdded();
       QMessageBox::information(this, "Succes", "Items successfully added");
   }
   else
       QMessageBox::warning(this, "Error", "Fail to add item");
}
/**
 * @brief WeaponsEditorWidget::on_addBonusB_clicked Triggered on add bonus button clicked
 */
void WeaponsEditorWidget::on_addBonusB_clicked()
{
    newModifierD = new NewModdifierDialog(this);
    newModifierD->show();
}
/**
 * @brief WeaponsEditorWidget::on_removeB_clicked Triggered on remove modiffer button clicked
 */
void WeaponsEditorWidget::on_removeModifierB_clicked()
{
    QList<QListWidgetItem*> moddifiers = ui->bonusesList->selectedItems();
    for(QListWidgetItem* item : moddifiers)
    {
        ui->bonusesList->takeItem(ui->bonusesList->row(item));
    }
}
/**
 * @brief WeaponsEditorWidget::on_addEffectEqB_clicked Triggered on add on-equip effect button clicked
 */
void WeaponsEditorWidget::on_addEffectEqB_clicked()
{
    addEffectD = new AddEffectDialog(editor->getModule(), SLOT(effectsEqAdded(vector<Effect*>)), this);
    addEffectD->show();
}
/**
 * @brief WeaponsEditorWidget::on_addEffectHit_clicked Triggered on add hit effect button clicked
 */
void WeaponsEditorWidget::on_addEffectHitB_clicked()
{
    addEffectD = new AddEffectDialog(editor->getModule(), SLOT(effectsHitAdded(vector<Effect*>)), this);
    addEffectD->show();
}
/**
 * @brief WeaponsEditorWidget::on_modifer_add Triggered by adding new modifier
 * @param mod New modifier
 */
void WeaponsEditorWidget::modifierAdded(Modifier* m)
{
    ModifierListItem* mItem = new ModifierListItem(*m);
    ui->bonusesList->addItem(mItem);
}
/**
 * @brief WeaponsEditorWidget::effectsAdded Triggered by adding on-equip effects from add effect dialog
 * @param effects List with effects to add
 */
void WeaponsEditorWidget::effectsEqAdded(vector<Effect*> effects)
{
    for(Effect *e : effects)
    {
        BaseObjectListItem *effectListItem = new BaseObjectListItem(*e);
        ui->effectsEqList->addItem(effectListItem);
    }
}
/**
 * @brief WeaponsEditorWidget::effectsAdded Triggered by adding on-hit effects from add effect dialog
 * @param effects List with effects to add
 */
void WeaponsEditorWidget::effectsHitAdded(vector<Effect*> effects)
{
    for(Effect *e : effects)
    {
        BaseObjectListItem *effectListItem = new BaseObjectListItem(*e);
        ui->effectsHitList->addItem(effectListItem);
    }
}
