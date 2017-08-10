#ifndef NEWTAB_H
#define NEWTAB_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
//#include <QAction>

class NewTab : public QWidget
{
    Q_OBJECT
public:
    explicit NewTab(QWidget *parent = 0);

signals:
    void clickAddWorkspaceBtn();
    void clickAddTaskBtn();
    void clickCloneWorkspaceBtn();
    void clickCloneTaskBtn();
    void clickFilterBtn();

public slots:
    void addWorkspace();
    void addTask();
    void cloneWorkspace();
    void cloneTask();
    void filter();

private:
    QPushButton* addWorkspaceBtn;
    QPushButton* addTaskBtn;
    QPushButton* cloneWorkspaceBtn;
    QPushButton* cloneTaskBtn;
    QPushButton* filterBtn;

    QLabel* filler;

//    QAction* addWorkspaceAct;
//    QAction* addTaskAct;
//    QAction* cloneWorkspaceAct;
//    QAction* cloneTaskAct;
//    QAction* filterAct;

};

#endif // NEWTAB_H
