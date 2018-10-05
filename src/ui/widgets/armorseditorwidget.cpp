 /*
 * armorseditorwidget.cpp
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
#include "armorseditorwidget.h"
#include "ui_armorseditorwidget.h"
/**
 * @brief ArmorsEditorWidget::ArmorsEditorWidget Constructor
 * @param editor Armors editor
 * @param parent Parent widget
 */
ArmorsEditorWidget::ArmorsEditorWidget(ArmorsEditor *editor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArmorsEditorWidget)
{
    ui->setupUi(this);
    this->editor = editor;

    newModifierD = new NewModdifierDialog(this);
    newRequirementD = new NewRequirementDialog(this);
    addEffectD = new AddEffectDialog(editor->getModule(), SLOT(effectsEqAdded(vector<Effect*>)), this);

    QObject::connect(this, SIGNAL(itemAdded()), parent, SLOT(onBaseObjectEdit()));
    QObject::connect(parent, SIGNAL(baseObjectSelected(BaseObject*)), this, SLOT(baseTreeObjectSelected(BaseObject*)));

    // TODO: fill armor type combobox.
    for(string &file : editor->getIconFiles())
    {
        ui->iconComboBox->addItem(QString::fromStdString(file));
    }
    for(string &file : editor->getSpritesheetFiles())
    {
        ui->spritesheetComboBox->addItem(QString::fromStdString(file));
    }
}
/**
 * @brief ArmorsEditorWidget::~ArmorsEditorWidget Destructor
 */
ArmorsEditorWidget::~ArmorsEditorWidget()
{
    delete ui;
    delete newModifierD;
    delete newRequirementD;
    delete addEffectD;
}

/**
 * @brief ArmorsEditorWidget::editArmor Fills edditor field with parameters
 *        from specified armor.
 * @param armor Armor.
 */
void ArmorsEditorWidget::editArmor(Armor* a)
{
    ui->idEdit->setText(QString::fromStdString(a->getId()));
    ui->typeComboBox->setCurrentIndex(static_cast<int>(a->getType()));
    ui->levelSpinBox->setValue(a->getLevel());
    ui->valueSpinBox->setValue(a->getValue());
    ui->armorRatSpinBox->setValue(a->getArmorRat());
    ui->modifiersList->clear();
    for(Modifier m : *a->getModifiers())
    {
        ModifierListItem *mItem = new ModifierListItem(m);
        ui->modifiersList->addItem(mItem);
    }
    ui->requirementsList->clear();
    for(Requirement r : *a->getRequirement())
    {
        RequirementListItem *rItem = new RequirementListItem(r);
        ui->requirementsList->addItem(rItem);
    }
    ui->effectsEqList->clear();
    for(string eId : *a->getEffectsEq())
    {
        ui->effectsEqList->addItem(QString::fromStdString(eId));
    }
}

/**
 * @brief ArmorsEditorWidget::addItem Creates and adds to base new item
 *        with parameters specified by widget fields.
 */
bool ArmorsEditorWidget::addItem()
{
    string id = ui->idEdit->text().toStdString();
    ArmorType type = static_cast<ArmorType>(ui->typeComboBox->currentIndex());
    string material = ui->materialComboBox->currentText().toStdString();

    // TODO: save level requirement as proper requirement,
    // i.e. add level requirement to requirements list.
    int level = ui->levelSpinBox->value();
    int arm = ui->armorRatSpinBox->value();
    int value = ui->valueSpinBox->value();

    string icon = ui->iconComboBox->currentText().toStdString();
    string ss = ui->spritesheetComboBox->currentText().toStdString();

    vector<Modifier> *modifiers = new vector<Modifier>();
    for(int i = 0; i < ui->modifiersList->count(); i ++)
    {
        QListWidgetItem* item = ui->modifiersList->item(i);

        ModifierListItem *m = static_cast<ModifierListItem*>(item);
        modifiers->push_back(*m->getModifier());
    }

    vector<Requirement> *requirements = new vector<Requirement>();
    for(int i = 0; i < ui->requirementsList->count(); i ++)
    {
        QListWidgetItem* item = ui->requirementsList->item(i);

        RequirementListItem *r = static_cast<RequirementListItem*>(item);
        requirements->push_back(*r->getRequirement());
    }

    vector<string> *effectsEq = new vector<string>();
    for(int i = 0; i < ui->effectsEqList->count(); i ++)
    {
        QListWidgetItem *item = ui->effectsEqList->item(i);

        effectsEq->push_back(item->text().toStdString());
    }

    if(editor->newArmor(id, level, type, material, value, arm, icon, ss, *modifiers, *requirements, *effectsEq))
    {
        emit itemAdded();
        return true;
    }
    else
        return false;
}

/**
 * @brief ArmorsEditorWidget::on_addButton_clicked Triggered on add button
 *        clicked.
 */
void ArmorsEditorWidget::on_addButton_clicked()
{
    // TODO translate messages.
    if(addItem())
        QMessageBox::information(this, "Succes", "Items successfully added");
    else
        QMessageBox::warning(this, "Error", "Fail to add item");
}

/**
 * @brief ArmorsEditorWidget::on_addModifierButton_clicked Triggered on add modifier button clicked
 */
void ArmorsEditorWidget::on_addModifierButton_clicked()
{
    newModifierD->open();
}

/**
 * @brief ArmorsEditorWidget::on_addRequiementButton_clicked Triggered on add requirement
 *        button clicked
 */
void ArmorsEditorWidget::on_addRequirementButton_clicked()
{
    newRequirementD->open();
}

/**
 * @brief ArmorsEditorWidget::on_addEffectEqButton_clickeds Triggered after
 *        add effect eq clicked.
 */
void ArmorsEditorWidget::on_addEffectEqButton_clicked()
{
    addEffectD->open();
}

/**
 * @brief ArmorsEditorWidget::on_removeModifierButton_clicked Triggered on remove
 *        modifier button clicked
 */
void ArmorsEditorWidget::on_removeModifierButton_clicked()
{
    QList<QListWidgetItem*> selection = ui->modifiersList->selectedItems();
    for(QListWidgetItem *i : selection)
    {
        delete i;
    }
}

/**
 * @brief ArmorsEditorWidget::on_removeRequirementButton_clicked Tiggered on remove
 *        requirement button clicked.
 */
void ArmorsEditorWidget::on_removeRequirementButton_clicked()
{
    QList<QListWidgetItem*> selection = ui->requirementsList->selectedItems();
    for(QListWidgetItem *i : selection)
    {
        delete i;
    }
}

/**
 * @brief ArmorsEditorWidget::on_removeEffectEqButton_clicked Triggered on effect
 *        eq button clicked.
 */
void ArmorsEditorWidget::on_removeEffectEqButton_clicked()
{
    QList<QListWidgetItem*> selection = ui->effectsEqList->selectedItems();
    for(QListWidgetItem *i : selection)
    {
        delete i;
    }
}

/**
 * @brief ArmorsEditorWidget::baseTreeObjectSelected Triggered on select item from
 *        base tree UI list.
 * @param o Selected object.
 */
void ArmorsEditorWidget::baseTreeObjectSelected(BaseObject* o)
{
    if(typeid(*o) == typeid(Armor))
    {
        if(Armor *a = static_cast<Armor*>(o))
        {
            editArmor(a);
        }
    }
}

/**
 * @brief ArmorsEditorWidget::modifierAdded Triggered on new modifier add.
 * @param m New modifier.
 */
void ArmorsEditorWidget::modifierAdded(Modifier *m)
{
    ModifierListItem* mItem = new ModifierListItem(*m);
    ui->modifiersList->addItem(mItem);
}

/**
 * @brief ArmorsEditorWidget::requirementAdded Triggered on new requirement add.
 * @param r New requirement.
 */
void ArmorsEditorWidget::requirementAdded(Requirement *r)
{
    RequirementListItem* rItem = new RequirementListItem(*r);
    ui->requirementsList->addItem(rItem);
}

/**
 * @brief ArmorsEditorWidget::effectsEqAdded Triggered on effect eq add.
 * @param effects Effect to add.
 */
void ArmorsEditorWidget::effectsEqAdded(vector<Effect*> effects)
{
    for(Effect *e : effects)
    {
        BaseObjectListItem *effectListItem = new BaseObjectListItem(*e);
        ui->effectsEqList->addItem(effectListItem);
    }
}
