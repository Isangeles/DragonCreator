/*
 * addeffectdialog.cpp
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
#include "addeffectdialog.h"
#include "ui_addeffectdialog.h"
/**
 * @brief AddEffectDialog::AddEffectDialog Add effect dialog constructor
 * @param mod Pointer to edited module
 * @param callbackSlot Slot function that recive selected effects
 * @param parent Pointer to dialog parent window
 */
AddEffectDialog::AddEffectDialog(Module *mod, const char* callbackSlot, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEffectDialog)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(add(vector<Effect*>)), parent, callbackSlot);

    vector<Effect> *effects = DConnector::getEffectsFromBase(mod->getEffectsPath());

    for(Effect &e : *effects)
    {
        BaseObjectListItem *eListItem = new BaseObjectListItem(e);
        ui->effectsList->addItem(eListItem);
    }
}
/**
 * @brief AddEffectDialog::~AddEffectDialog Effects destructor
 */
AddEffectDialog::~AddEffectDialog()
{
    delete ui;
}
/**
 * @brief AddEffectDialog::on_addEffectB_clicked Triggered after add effect button clicked
 */
void AddEffectDialog::on_addEffectB_clicked()
{
    QList<QListWidgetItem*> selection = ui->effectsList->selectedItems();
    vector<Effect*> effects;
    for(QListWidgetItem *i : selection)
    {
        BaseObjectListItem *baseItem = static_cast<BaseObjectListItem*>(i);
        Effect *e = static_cast<Effect*>(baseItem->getObject());
        effects.push_back(e);
    }
    emit add(effects);
    close();
}
