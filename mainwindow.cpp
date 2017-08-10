#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QActionGroup>
#include <QContextMenuEvent>
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QPushButton>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(640, 480);

    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

//    addTabWidget = new QPushButton(tr("+"));

    tabWidget = new QTabWidget;
    tabWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
//    tabWidget->setStyleSheet("background-color: yellow");

//    QWidget* tabwidget1 = new QWidget;
//    QWidget* tabwidget2 = new QWidget;
//    tabWidget->addTab(tabwidget1, tr("+"));
//    tabWidget->addTab(tabwidget2, tr("tab2"));

    statusBar = new QStatusBar;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(tabWidget);
    layout->addWidget(statusBar);
    centralWidget->setLayout(layout);

    createActions();
    createMenus();

    emit newTabAct->triggered();
}

MainWindow::~MainWindow()
{

}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent* event){
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}
#endif//QT_NO_CONTEXTMENU

void MainWindow::newTab(){
//    statusBar->showMessage(tr("File|New Tab"));
    /*QWidget*/NewTab* newTabWidget = new NewTab(this);
    tabWidget->addTab(newTabWidget, tr("New Tab"));

    connect(newTabWidget, &NewTab::clickAddWorkspaceBtn, this, &MainWindow::newWorkSpace);
    connect(newTabWidget, &NewTab::clickAddTaskBtn, this, &MainWindow::newTask);
    connect(newTabWidget, &NewTab::clickCloneWorkspaceBtn, this, &MainWindow::cloneWorkSpace);
    connect(newTabWidget, &NewTab::clickCloneTaskBtn, this, &MainWindow::cloneTask);
    connect(newTabWidget, &NewTab::clickFilterBtn, this, &MainWindow::filter);

    if (tabWidget->count() > 1){
        tabWidget->setTabsClosable(true);
    }
}

void MainWindow::newWorkSpace(){
    statusBar->showMessage(tr("File|New Work Space"));
}

void MainWindow::newTask(){
    statusBar->showMessage(tr("File|New Task"));
}

void MainWindow::saveAll(){
    statusBar->showMessage(tr("File|Save All"));
}

void MainWindow::saveWorkSpace(){
    statusBar->showMessage(tr("File|Save Work Space"));
}

void MainWindow::saveTask(){
    statusBar->showMessage(tr("File|Save task"));
}

void MainWindow::cloneWorkSpace(){
    statusBar->showMessage(tr("File|Clone WorkSpace"));
}

void MainWindow::cloneTask(){
    statusBar->showMessage(tr("File|Clone task"));
}

void MainWindow::selectWorkSpace(){
    statusBar->showMessage(tr("File|Select WorkSpace"));
}

void MainWindow::filter(){
    statusBar->showMessage(tr("File|Filter"));
}

void MainWindow::undo(){
    statusBar->showMessage(tr("Edit|Undo"));
}

void MainWindow::redo(){
    statusBar->showMessage(tr("Edit|Redo"));
}

void MainWindow::cut(){
    statusBar->showMessage(tr("Edit|Cut"));
}

void MainWindow::paste(){
    statusBar->showMessage(tr("Edit|paste"));
}

void MainWindow::copy(){
    statusBar->showMessage(tr("Edit|copy"));
}

void MainWindow::selectAll(){
    statusBar->showMessage(tr("Edit|select all"));
}

void MainWindow::about(){
    statusBar->showMessage(tr("Help|About"));
}

void MainWindow::aboutQt(){
    statusBar->showMessage(tr("Help|About Qt"));
}

void MainWindow::closeTab(int tabIdx){

    if (tabIdx < 0){
        return;
    }

    tabWidget->removeTab(tabIdx);

    if (tabWidget->count() < 2){
        tabWidget->setTabsClosable(false);
    }
}

void MainWindow::createActions(){

    newTabAct = new QAction(tr("New Tab"), this);
    connect(newTabAct, &QAction::triggered, this, &MainWindow::newTab);

    newWorkSpaceAct = new QAction(tr("New workspace"), this);
    connect(newWorkSpaceAct, &QAction::triggered, this, &MainWindow::newWorkSpace);

    newTaskAct = new QAction(tr("New Task"), this);
    connect(newTaskAct, &QAction::triggered, this, &MainWindow::newTask);

    saveAllAct = new QAction(tr("Save All"), this);
    connect(saveAllAct, &QAction::triggered, this, &MainWindow::saveAll);

    saveWorkSpaceAct = new QAction(tr("Save Workspace"), this);
    connect(saveWorkSpaceAct, &QAction::triggered, this, &MainWindow::saveWorkSpace);

    saveTaskAct = new QAction(tr("Save Task"), this);
    connect(saveTaskAct, &QAction::triggered, this, &MainWindow::saveTask);

    cloneWorkSpaceAct = new QAction(tr("Clone Workspace"), this);
    connect(cloneWorkSpaceAct, &QAction::triggered, this, &MainWindow::cloneWorkSpace);

    cloneTaskAct = new QAction(tr("Clone Task"), this);
    connect(cloneTaskAct, &QAction::triggered, this, &MainWindow::cloneTask);

    selectWorkSpaceAct = new QAction(tr("Select Workspace"), this);
    connect(selectWorkSpaceAct, &QAction::triggered, this, &MainWindow::selectWorkSpace);

    filterAct = new QAction(tr("Filter"), this);
    connect(filterAct, &QAction::triggered, this, &MainWindow::filter);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut current selection's contentsto the clipboard"));
    connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy current selection's"
                             "contents to the clipboard"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents"
                              "into the current selection"));
    connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    selectAllAct = new QAction(tr("Select All"), this);
    selectAllAct->setShortcuts(QKeySequence::SelectAll);
    selectAllAct->setStatusTip(tr("Select all"));
    connect(selectAllAct, &QAction::triggered, this, &MainWindow::selectAll);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

}

void MainWindow::createMenus(){

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newTabAct);
    fileMenu->addAction(newWorkSpaceAct);
    fileMenu->addAction(newTaskAct);
    fileMenu->addAction(saveAllAct);
    fileMenu->addAction(saveWorkSpaceAct);
    fileMenu->addAction(saveTaskAct);
    fileMenu->addAction(cloneWorkSpaceAct);
    fileMenu->addAction(cloneTaskAct);
    fileMenu->addAction(selectWorkSpaceAct);
    fileMenu->addAction(filterAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

}
