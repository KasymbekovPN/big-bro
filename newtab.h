#ifndef NEWTAB_H
#define NEWTAB_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>
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
    void newContent(int row);

private:
    QPushButton* addWorkspaceBtn;
    QPushButton* addTaskBtn;
    QPushButton* cloneWorkspaceBtn;
    QPushButton* cloneTaskBtn;
    QPushButton* filterBtn;

    QPushButton* btnSearch;
    QTextEdit* teditSearch;

    QLabel* lblWorkspace;
    QLabel* lblTask;

    QListWidget* lstWdgtWorkspace;
    QListWidget* lstwdgtTask;

    QListWidgetItem* p_item[3];
    QListWidgetItem* j_item[5];

};

#endif // NEWTAB_H
