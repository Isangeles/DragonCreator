/*
 *
 *
 * Copyright (C) 2018 Dariusz Sikora<darek@dellins-solus>
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
#ifndef MODULEINFOWIDGET_H
#define MODULEINFOWIDGET_H

#include <QWidget>

#include "src/core/data/object/module.h"

namespace Ui {
class ModuleInfoWidget;
}
/**
 * @brief Class for widget with details about open module
 */
class ModuleInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModuleInfoWidget(Module *module, QWidget *parent = 0);
    ~ModuleInfoWidget();

private:
    Ui::ModuleInfoWidget *ui;
};

#endif // MODULEINFOWIDGET_H
