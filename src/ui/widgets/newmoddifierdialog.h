/*
 * newmodifierdialog.h
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
#ifndef NEWMODDIFIERDIALOG_H
#define NEWMODDIFIERDIALOG_H

#include <iostream>
#include <map>

#include <QDialog>
#include <QRegExp>

#include "src/core/data/object/modifier.h"
#include "src/util/modifierutils.h"
#include "src/ui/lang.h"
#include "src/util/text/textreader.h"

namespace Ui
{
class NewModdifierDialog;
}

class NewModdifierDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewModdifierDialog(QWidget *parent = 0);
    ~NewModdifierDialog();
    QString getType();
signals:
    void add(Modifier* m);
private:
    Ui::NewModdifierDialog *ui;
    void loadAttributesFor(ModifierType mod);
    void loadValuesFor(ModifierAtributeType attr);
private slots:
    void on_addB_clicked();
    void on_addAttrB_clicked();
    void on_typeCombo_currentIndexChanged(int id);
};

#endif // NEWMODDIFIERDIALOG_H
