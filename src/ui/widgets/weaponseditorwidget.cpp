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

    //newModifierD = new NewModdifierDialog(this);
    //newRequirementD = new NewRequirementDialog(this);

    QObject::connect(this, SIGNAL(itemAdded()), parent, SLOT(onBaseObjectEdit()));
    QObject::connect(parent, SIGNAL(baseObjectSelected(BaseObject*)), this, SLOT(baseTreeObjectSelected(BaseObject*)));

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
 * @brief WeaponsEditorWidget::editWeapon fills editor fields with data of specified weapon object
 * @param w Weapon
 */
void WeaponsEditorWidget::editWeapon(Weapon *w)
{
    ui->idEdit->setText(QString::fromStdString(w->getId()));
    ui->typeCombo->setCurrentIndex(static_cast<int>(w->getType()));
    ui->levelEdit->setValue(w->getLevel());
    ui->valueEdit->setValue(w->getValue());
    ui->dmgMaxEdit->setValue(w->getDamageMax());
    ui->dmgMinEdit->setValue(w->getDamageMin());
    ui->bonusesList->clear();
    for(Modifier m : *w->getModifiers())
    {
        ModifierListItem *mItem = new ModifierListItem(m);
        ui->bonusesList->addItem(mItem);
    }
    ui->effectsEqList->clear();
    for(string eId : *w->getEffectsEq())
    {
        ui->effectsEqList->addItem(QString::fromStdString(eId));
    }
    ui->effectsHitList->clear();
    for(string eId : *w->getEffectsHit())
    {
        ui->effectsHitList->addItem(QString::fromStdString(eId));
    }
}
/**
 * @brief WeaponsEditorWidget::on_addB_clicked Method triggered on UI add button clicked
 */
void WeaponsEditorWidget::on_addB_clicked()
{
   string id = ui->idEdit->text().toStdString();
   WeaponType type = static_cast<WeaponType>(ui->typeCombo->currentIndex());
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

   vector<string> *effectsEq = new vector<string>;
   for(int i = 0; i < ui->effectsEqList->count(); i++)
   {
       QListWidgetItem* item = ui->effectsEqList->item(i);

       //BaseObjectListItem *eItem = static_cast<BaseObjectListItem*>(item);
       //Effect *e = static_cast<Effect*>(eItem->getObject());
       effectsEq->push_back(item->text().toStdString());
   }

   vector<string> *effectsHit = new vector<string>;
   for(int i = 0; i < ui->effectsHitList->count(); i++)
   {
       QListWidgetItem* item = ui->effectsHitList->item(i);

       //BaseObjectListItem *eItem = static_cast<BaseObjectListItem*>(item);
       //Effect *e = static_cast<Effect*>(eItem->getObject());
       effectsHit->push_back(item->text().toStdString());
   }

   //TODO translate messages
   if(editor->newWeapon(id, level, type, material, value, dmgMin, dmgMax, icon, ss, *modifiers, *effectsEq, *effectsHit))
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
 * @brief WeaponsEditorWidget::on_addReqB_clicked Triggered on add requirement button clicked
 */
void WeaponsEditorWidget::on_addReqB_clicked()
{
    newRequirementD = new NewRequirementDialog(this);
    newRequirementD->show();
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
 * @brief WeaponsEditorWidget::on_removeEffectEqB_clicked Triggered on remove on-equip effect button clicked
 */
void WeaponsEditorWidget::on_removeEffectEqB_clicked()
{
    QList<QListWidgetItem*> selection = ui->effectsEqList->selectedItems();
    for(QListWidgetItem *i : selection)
    {
        delete i;
    }
}
/**
 * @brief WeaponsEditorWidget::on_removeEffectHitB_clicked Triggered on remove hit effect button clicked
 */
void WeaponsEditorWidget::on_removeEffectHitB_clicked()
{
    QList<QListWidgetItem*> selection = ui->effectsHitList->selectedItems();
    for(QListWidgetItem *i : selection)
    {
        delete i;
    }
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
 * @brief WeaponsEditorWidget::requirementAdded Triggered on adding new requirement
 * @param r New requirement
 */
void WeaponsEditorWidget::requirementAdded(Requirement* r)
{
    // TODO add requirement object to list
    cout << "req_added:" << RequirementUtils::tagNameFromType(r->getType()) << endl; // debug
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
/**
 * @brief WeaponsEditorWidget::baseTreeObjectSelected
 * @param o Selected base object
 */
void WeaponsEditorWidget::baseTreeObjectSelected(BaseObject *o)
{
    if(typeid(*o) == typeid(Weapon))
    {
        if(Weapon *w = static_cast<Weapon*>(o))
        {
            editWeapon(w);
        }
    }
}
