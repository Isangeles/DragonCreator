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
        //cout << "list_item:" << item->text().toStdString() << endl;

        //Modifier *m = (Modifier*)&item; //TODO cast to modifier dont work
        Modifier *m = new Modifier(ModifierType::HEALTH, new map<string, string>);
        //cout << "from_list:" << m->getName() << endl;
        modifiers->push_back(*m);
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
    //cout << "to_list:" << m->getName() << endl;
    ui->modifiersList->addItem(m);
}

