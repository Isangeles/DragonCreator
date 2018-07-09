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

    QObject::connect(this, SIGNAL(effectAdded()), parent, SLOT(onBaseObjectEdit()));
    QObject::connect(parent, SIGNAL(baseObjectSelected(BaseObject*)), this, SLOT(baseTreeObjectSelected(BaseObject*)));
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

    vector<Modifier> modifiers;

    for(int i = 0; i < ui->modifiersList->count(); i++)
    {
        QListWidgetItem* item = ui->modifiersList->item(i);

        ModifierListItem *m = static_cast<ModifierListItem*>(item);
        modifiers.push_back(*m->getModifier());
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
    QList<QListWidgetItem*> selection = ui->modifiersList->selectedItems();
    for(QListWidgetItem* i : selection)
    {
        delete i;
    }
}
/**
 * @brief WeaponsEditorWidget::on_modifer_add Triggered by adding new modifier
 * @param m New modifier
 */
void EffectsEditorWidget::modifierAdded(Modifier *m)
{
    ModifierListItem *mItem = new ModifierListItem(*m);
    ui->modifiersList->addItem(mItem);
}
/**
 * @brief EffectsEditorWidget::baseTreeObjectSelected Triggered when item from base object list is selected
 * @param o Selected object
 */
void EffectsEditorWidget::baseTreeObjectSelected(BaseObject *o)
{
    if(Effect *e = static_cast<Effect*>(o))
    {
         /* //DEBUG
        for(Modifier &mod : *e->getModifiers())
        {
            cout << "e_sel_mod:" << mod.getName() << endl;
        }
        */
        editEffect(e);
    }
}
/**
 * @brief EffectsEditorWidget::editEffect Edits specified effect(sets all values of specified effect to editor fields)
 * @param e Effect to edit
 */
void EffectsEditorWidget::editEffect(Effect *e)
{
    clearEditor();
    ui->idEdit->setText(QString::fromStdString(e->getId()));
    ui->durationEdit->setValue(e->getDuration());
    for(Modifier &m : *e->getModifiers())
    {
        ModifierListItem *mItem = new ModifierListItem(m);
        ui->modifiersList->addItem(mItem);
    }
}
/**
 * @brief EffectsEditorWidget::clearEditor Clears all editor fields
 */
void EffectsEditorWidget::clearEditor()
{
    ui->idEdit->setText("");
    ui->durationEdit->setValue(0);
    ui->modifiersList->clear();
}

