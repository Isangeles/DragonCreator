/*
 * weaponseditorwidget.h
 *
 * Copyright (C) 2017-2018 Dariusz Sikora<dev@isangeles.pl>
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
#ifndef WEAPONSEDITORWIDGET_H
#define WEAPONSEDITORWIDGET_H

#include <iostream>
#include <string>
#include <vector>

#include <QWidget>
#include <QMessageBox>

#include "src/core/edit/weaponseditor.h"
#include "src/core/data/object/modifier.h"
#include "newmoddifierdialog.h"
#include "addeffectdialog.h"
#include "src/ui/util/modifierlistitem.h"
#include "src/util/text/textreader.h"

using namespace std;

namespace Ui
{
class WeaponsEditorWidget;
}
/**
 * @brief Class for widget of weapons editor
 */
class WeaponsEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeaponsEditorWidget(WeaponsEditor *editor, QWidget *parent = 0);
    ~WeaponsEditorWidget();
    NewModdifierDialog* getNMDialog();

signals:
    void itemAdded();

private:
    Ui::WeaponsEditorWidget *ui;
    WeaponsEditor *editor;
    NewModdifierDialog *newModifierD;
    AddEffectDialog *addEffectD;

private slots:
    void on_addB_clicked();
    void on_removeModifierB_clicked();
    void on_addBonusB_clicked();
    void on_addEffectEqB_clicked();
    void on_addEffectHitB_clicked();
    void on_removeEffectEqB_clicked();
    void on_removeEffectHitB_clicked();
    void modifierAdded(Modifier *m);
    void effectsEqAdded(vector<Effect*> effects);
    void effectsHitAdded(vector<Effect*> effects);
    void baseTreeObjectSelected(BaseObject *o);
};

#endif // WEAPONSEDITORWIDGET_H
