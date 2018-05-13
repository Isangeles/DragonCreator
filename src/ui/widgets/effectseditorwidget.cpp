/*
 * effectseditorwidget.cpp
 * Copyright (C) 2018 Dariusz Sikora<darek@pc-solus>
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
#include "effectseditorwidget.h"
#include "ui_effectseditorwidget.h"
/**
 * @brief EffectsEditorWidget::EffectsEditorWidget Construcotr of effects edditor widget
 * @param eEdit Effects editor
 * @param parent Main window
 */
EffectsEditorWidget::EffectsEditorWidget(EffectsEditor *eEdit, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EffectsEditorWidget)
{
    ui->setupUi(this);
    this->edit = eEdit;

    QObject::connect(this, SIGNAL(effectAdded()), parent, SLOT(updateSource()));
}
/**
 * @brief EffectsEditorWidget::~EffectsEditorWidget Destrcutor of effects editor widget
 */
EffectsEditorWidget::~EffectsEditorWidget()
{
    delete ui;
    delete edit;
}
/**
 * @brief EffectsEditorWidget::on_addB_clicked Triggered on add buton clicked
 */
void EffectsEditorWidget::on_addB_clicked()
{
    string id = ui->idEdit->text().toStdString();
    EffectType type = (EffectType)ui->typeCombo->currentIndex();

    int duration = ui->durationEdit->value();

    vector<Modifier> *modifiers = new vector<Modifier>;

    for(int i = 0; i < ui->modifiersList->count(); i++)
    {
        QListWidgetItem* item = ui->modifiersList->item(i);

        ModifierListItem *m = static_cast<ModifierListItem*>(item);
        modifiers->push_back(*m->getModifier());
    }

    //TODO translate messages
    if(edit->newEffect(id, type, duration, modifiers))
    {
        emit effectAdded();
        QMessageBox::information(this, "Succes", "Effect successfully added");
    }
    else
        QMessageBox::warning(this, "Error", "Fail to add effect");
}
/**
 * @brief EffectsEditorWidget::on_modifierAddB_clicked Triggered on modifier add button clicked
 */
void EffectsEditorWidget::on_modifierAddB_clicked()
{
    modD = new NewModdifierDialog(this);
    modD->show();
}
/**
 * @brief EffectsEditorWidget::on_modifierRemoveB_clicked Triggered on remove modifier button clicked
 */
void EffectsEditorWidget::on_modifierRemoveB_clicked()
{
    //TODO: remove modifier from list action
}
/**
 * @brief WeaponsEditorWidget::on_modifer_add Triggered by adding new modifier
 * @param m New modifier
 */
void EffectsEditorWidget::modifierAdded(Modifier *m)
{
    ModifierListItem *mItem = new ModifierListItem(m);
    ui->modifiersList->addItem(mItem);
}

