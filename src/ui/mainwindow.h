/*
 * mainwindow.h
 * Copyright (C) 2017-2018 Dariusz Sikora<darek@dellins-solus>
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <unistd.h>

#include <QMainWindow>
#include <QDesktopWidget>
#include <QFontDatabase>
#include <QFile>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>
#include <QPlainTextEdit>

#include <zlib.h>

#include "src/core/moduleeditor.h"
#include "widgets/weaponseditorwidget.h"
#include "widgets/armorseditorwidget.h"
#include "widgets/welcomewidget.h"
#include "widgets/moduleinfowidget.h"
#include "widgets/settingswidget.h"
#include "widgets/effectseditorwidget.h"
#include "util/baseobjectlistitem.h"
#include "src/core/edit/baseeditor.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief Class for main window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ModuleEditor *editor;

    BaseEditor *activeEditor;
    QPlainTextEdit *activeSource;

    WelcomeWidget *welcomeScreen;
    SettingsWidget *settingsWindow;
    ModuleInfoWidget *modInfo;
    WeaponsEditorWidget *weWidget;
    ArmorsEditorWidget *arWidget;
    EffectsEditorWidget *efWidget;

    void setModuleTree(ModuleEditor *mEditor);
    void setBaseTree(BaseEditor *bEditor);
    void loadRobotoFonts();
    QWidget* getEditorWidget(string editorId);
    BaseEditor* getBaseEditor(string editorId);

    void updateSource();
    void updateBaseTree();
signals:
    void baseObjectSelected(BaseObject *object);

private slots:
    void on_actionOpen_module_triggered();
    void on_actionSettings_triggered();
    void on_actionClose_triggered();
    void on_moduleTree_clicked(const QModelIndex &index);
    void on_baseTree_itemClicked(const QListWidgetItem &item);
    void on_baseTree_clicked(const QModelIndex &index);
    void on_workspace_tabCloseRequested(int id);
    void onBaseObjectEdit();
};

#endif // MAINWINDOW_H
