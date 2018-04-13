/*
 * settingswidget.cpp
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
#include "settingswidget.h"
#include "ui_settingswidget.h"
/**
 * @brief SettingsWidget::SettingsWidget Settings widget constructor
 * @param parent Parent for settings window
 */
SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);

    setWindowTitle(tr("Settings"));

    ui->settingTitle->setText(tr("Settings"));
    ui->gameDirLabel->setText(tr("Game directory:"));
    ui->gameDirB->setText(tr("Change"));
    ui->gameDirEdit->setText(QString::fromStdString(Config::getGameDir()));
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}
/**
 * @brief SettingsWidget::on_gameDirB_clicked Triggered on change game directory button clicked
 */
void SettingsWidget::on_gameDirB_clicked()
{
    QFileDialog* fd = new QFileDialog(this);

    QString path = fd->getExistingDirectory();
    if(!path.isEmpty())
    {
        ui->gameDirEdit->setText(path);
    }
}
/**
 * @brief SettingsWidget::on_settingsDialog_accepted Triggered on settings confirmed
 */
void SettingsWidget::on_settingsDialog_accepted()
{
    QString gameDir = ui->gameDirEdit->text();

    if(Config::setGameDir(gameDir.toStdString()))
        QMessageBox::information(this, tr("Information"), tr("Settings saved"));
    else
        QMessageBox::warning(this, tr("Warning"), tr("Game directory is invalid"));

    close();
}
/**
 * @brief SettingsWidget::on_settingsDialog_rejected Triggered on settings rejected
 */
void SettingsWidget::on_settingsDialog_rejected()
{
    close();
}
