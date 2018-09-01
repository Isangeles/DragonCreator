/*
 * addrequirementdialog.h
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
#ifndef NEWREQUIREMENTDIALOG_H
#define NEWREQUIREMENTDIALOG_H

#include <QDialog>

#include "src/core/data/object/requirement.h"
#include "src/core/data/object/module.h"
#include "src/util/requirementutils.h"

namespace Ui {
class NewRequirementDialog;
}
/**
 * @brief Class for add requirement dialog window.
 */
class NewRequirementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewRequirementDialog(QWidget *parent = nullptr);
    ~NewRequirementDialog();
private:
    Ui::NewRequirementDialog *ui;
    void loadsAttributesFor(RequirementType type);
private slots:
    void on_typeCombo_currentIndexChanged(int id);
    void on_attrAddB_clicked();
    void on_addB_clicked();
signals:
    void add(Requirement *req);
};

#endif // NEWREQUIREMENTDIALOG_H
