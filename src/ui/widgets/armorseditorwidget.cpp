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
}
/**
 * @brief ArmorsEditorWidget::~ArmorsEditorWidget Destructor
 */
ArmorsEditorWidget::~ArmorsEditorWidget()
{
    delete ui;
}
