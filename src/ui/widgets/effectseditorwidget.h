/*
 * effectseditorwidget.h
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
#ifndef EFFECTSEDITORWIDGET_H
#define EFFECTSEDITORWIDGET_H

#include <QWidget>
#include <QMessageBox>

#include "src/core/edit/effectseditor.h"
#include "src/core/data/object/modifier.h"
#include "newmoddifierdialog.h"
#include "src/ui/util/modifierlistitem.h"

namespace Ui {
class EffectsEditorWidget;
}

class EffectsEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EffectsEditorWidget(EffectsEditor *eEdit, QWidget *parent = 0);
    ~EffectsEditorWidget();

signals:
    void effectAdded();
private:
    Ui::EffectsEditorWidget *ui;
    EffectsEditor *edit;
    NewModdifierDialog *modD;
private slots:
    void on_addB_clicked();
    void on_modifierAddB_clicked();
    void on_modifierRemoveB_clicked();
    void modifierAdded(Modifier *m);
};

#endif // EFFECTSEDITORWIDGET_H
