/*
 * addeffectdialog.h
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
#ifndef ADDEFFECTDIALOG_H
#define ADDEFFECTDIALOG_H

#include <QDialog>

#include "vector"

#include "src/core/data/object/module.h"
#include "src/core/data/object/effect.h"
#include "src/core/data/dconnector.h"
#include "src/ui/util/baseobjectlistitem.h"

namespace Ui {
class AddEffectDialog;
}

/**
 * @brief Dialog for adding effects from base
 */
class AddEffectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEffectDialog(Module *mod, const char *callbackSlot, QWidget *parent = 0);
    ~AddEffectDialog();

signals:
    void add(vector<Effect*> effect);

private:
    Ui::AddEffectDialog *ui;

private slots:
    void on_addEffectB_clicked();
};

#endif // ADDEFFECTDIALOG_H
