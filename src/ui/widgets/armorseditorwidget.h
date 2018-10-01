/*
 * armorseditorwidget.h
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
#ifndef ARMORSEDITORWIDGET_H
#define ARMORSEDITORWIDGET_H

#include <QWidget>
#include <QMessageBox>

#include "src/core/edit/armorseditor.h"
#include "src/ui/widgets/newmoddifierdialog.h"
#include "src/ui/widgets/newrequirementdialog.h"
#include "src/ui/widgets/addeffectdialog.h"
#include "src/ui/util/modifierlistitem.h"
#include "src/ui/util/requirementlistitem.h"
#include "src/ui/util/baseobjectlistitem.h"

namespace Ui {
class ArmorsEditorWidget;
}

/**
 * @brief The ArmorsEditorWidget class Class for armor items editor widget.
 */
class ArmorsEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ArmorsEditorWidget(ArmorsEditor *editor, QWidget *parent = nullptr);
    ~ArmorsEditorWidget();
    void editArmor(Armor *a);
signals:
    void itemAdded();

private:
    bool addItem();
    Ui::ArmorsEditorWidget *ui;
    ArmorsEditor *editor;
    NewModdifierDialog *newModifierD;
    NewRequirementDialog *newRequirementD;
    AddEffectDialog *addEffectD;

private slots:
    void on_addButton_clicked();
    void baseTreeObjectSelected(BaseObject *o);
    void modifierAdded(Modifier *m);
    void requirementAdded(Requirement *r);
};

#endif // ARMORSEDITORWIDGET_H
