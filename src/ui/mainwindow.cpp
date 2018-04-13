/*
 * mainwindow.cpp
 *
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
#include "mainwindow.h"
#include "ui_mainwindow.h"

//TODO translate tabs names


/**
 * @brief MainWindow::MainWindow Main window constructor
 * @param parent Parent widget for window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadRobotoFonts();
    ui->setupUi(this);

    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    this->setWindowTitle("Dragon Creator@" + QString::fromLocal8Bit(hostname));

    //sets max size for window
    QDesktopWidget* dw = qApp->desktop();
    resize(dw->availableGeometry(this).size());

    //Can't remove default tabs in UI designer(?)
    ui->workspace->removeTab(0);
    ui->workspace->removeTab(0);

    //activeSource = new QPlainTextEdit(this);

    welcomeScreen = new WelcomeWidget(this);
    ui->workspace->addTab(welcomeScreen, "Welcome");
}
/**
 * @brief MainWindow::~MainWindow Main window deconstructor
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete welcomeScreen;
    delete settingsWindow;
    delete weWidget;
}
/**
 * @brief MainWindow::setModuleTree Displays specified module editor in module tree
 * @param mEditor Module editor
 */
void MainWindow::setModuleTree(ModuleEditor *mEditor)
{
    QStandardItemModel *sim = new QStandardItemModel;
    QStandardItem *parentItem = sim->invisibleRootItem();

    QStandardItem *items = new QStandardItem(QString("items"));
    parentItem->appendRow(items);
    parentItem = items;
    QStandardItem *armors = new QStandardItem(QString("armors"));
    parentItem->appendRow(armors);
    QStandardItem *weapons = new QStandardItem(QString("weapons"));
    parentItem->appendRow(weapons);
    QStandardItem *misc = new QStandardItem(QString("misc"));
    parentItem->appendRow(misc);

    ui->moduleTree->setModel(sim);
}
/**
 * @brief MainWindow::loadRobotoFonts Loads all font from Roboto family in 'fonts' catalog
 */
void MainWindow::loadRobotoFonts()
{
    QFontDatabase::addApplicationFont("fonts/Roboto-Black.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-BlackItalic.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Bold.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-BoldItalic.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Italic.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Light.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-LightItalic.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-MediumItalic.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-Thin.ttf");
    QFontDatabase::addApplicationFont("fonts/Roboto-ThinItalic.ttf");
}
/**
 * @brief MainWindow::getEditorWidget Returns widget for editor with specified ID
 * @param editorId String with editor ID
 * @return One of editor widgets
 */
QWidget* MainWindow::getEditorWidget(string editorId)
{
    if(editorId == "weapons")
        return weWidget;
    else
        return NULL;
}
/**
 * @brief MainWindow::getBaseEditor Returns base editor with specified ID
 * @param editorId Editor ID
 * @return Pointer to base editor
 */
BaseEditor* MainWindow::getBaseEditor(string editorId)
{
    if(editorId == "weapons")
        return editor->getItemEditor()->getWeaponsEditor();
    else
        return NULL;
}
/**
 * @brief MainWindow::on_actionOpen_module_triggered Opens module editor in new directory, triggered on menu->open module clicked
 */
void MainWindow::on_actionOpen_module_triggered()
{
    QFileDialog* fd = new QFileDialog(this);

    QString path = fd->getExistingDirectory();
    try
    {
        editor = new ModuleEditor(path.toStdString());
        weWidget = new WeaponsEditorWidget(editor->getItemEditor()->getWeaponsEditor(), this);
        setModuleTree(editor);
        modInfo = new ModuleInfoWidget(editor->getOpenModule(), this);
        ui->workspace->removeTab(0); //remove welcome tab
        ui->workspace->addTab(modInfo, "Module");
    }
    catch(runtime_error e)
    {
        QMessageBox::warning(this, "Directory error", QString::fromUtf8(e.what()));
        cerr << e.what() << endl;
    }
}
/**
 * @brief MainWindow::on_actionSettings_triggered Triggered on menu->settings clicked
 */
void MainWindow::on_actionSettings_triggered()
{
    settingsWindow = new SettingsWidget();
    settingsWindow->show();
}
/**
 * @brief MainWindow::on_actionClose_triggered Triggered on menu->close clicked
 */
void MainWindow::on_actionClose_triggered()
{
    qApp->quit();
}
/**
 * @brief MainWindow::on_moduleTree_clicked Triggered on moduleTree click
 * @param index Index of clicked model item
 */
void MainWindow::on_moduleTree_clicked(const QModelIndex &index)
{
    QStandardItemModel *model = (QStandardItemModel*)ui->moduleTree->model();
    QStandardItem *item = model->itemFromIndex(index);

    QWidget *widgetToSet = getEditorWidget(item->text().toStdString());
    ui->workspace->removeTab(0); //remove module info tab
    ui->workspace->addTab(widgetToSet, "Editor");

    BaseEditor* editor = getBaseEditor(item->text().toStdString());
    activeEditor = editor;
    activeSource = new QPlainTextEdit(QString::fromStdString(editor->getBaseSource()));
    ui->workspace->addTab(activeSource, "Source");
}
/**
 * @brief MainWindow::sourceUpdate Updates source tab
 */
void MainWindow::updateSource()
{
    QPlainTextEdit* sourceTab = (QPlainTextEdit*)ui->workspace->widget(1);
    sourceTab->clear();
    sourceTab->insertPlainText(QString::fromStdString(activeEditor->getBaseSource()));
}
