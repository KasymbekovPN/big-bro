#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "newtab.h"

class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent* event) override;
#endif//QT_NO_CONTEXTMENU

private slots:
    void newTab();
    void newWorkSpace();
    void newTask();
    void saveAll();
    void saveWorkSpace();
    void saveTask();
    void cloneWorkSpace();
    void cloneTask();
    void selectWorkSpace();
    void filter();
    void undo();
    void redo();
    void cut();
    void paste();
    void copy();
    void selectAll();
    void about();
    void aboutQt();

    void closeTab(int tabIdx);

private:
    void createActions();
    void createMenus();

    QStatusBar* statusBar;
    QTabWidget* tabWidget;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;

    QAction* newTabAct;
    QAction* newWorkSpaceAct;
    QAction* newTaskAct;
    QAction* saveAllAct;
    QAction* saveWorkSpaceAct;
    QAction* saveTaskAct;
    QAction* cloneWorkSpaceAct;
    QAction* cloneTaskAct;
    QAction* selectWorkSpaceAct;
    QAction* filterAct;
    QAction* exitAct;

    QAction* undoAct;
    QAction* redoAct;
    QAction* cutAct;
    QAction* pasteAct;
    QAction* copyAct;
    QAction* selectAllAct;

    QAction* aboutAct;
    QAction* aboutQtAct;

};

#endif // MAINWINDOW_H
