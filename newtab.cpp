#include "newtab.h"

NewTab::NewTab(QWidget *parent) : QWidget(parent)
{

    const QSize buttonSize = QSize(60, 60);

    addWorkspaceBtn = new QPushButton(tr("+W"));
    addWorkspaceBtn->setFixedSize(buttonSize);
    connect(addWorkspaceBtn, &QPushButton::clicked, this, &NewTab::addWorkspace);

    addTaskBtn = new QPushButton(tr("+T"));
    addTaskBtn->setFixedSize(buttonSize);
    connect(addTaskBtn, &QPushButton::clicked, this, &NewTab::addTask);

    cloneWorkspaceBtn = new QPushButton(tr("CW"));
    cloneWorkspaceBtn->setFixedSize(buttonSize);
    connect(cloneWorkspaceBtn, &QPushButton::clicked, this, &NewTab::cloneWorkspace);

    cloneTaskBtn = new QPushButton(tr("CT"));
    cloneTaskBtn->setFixedSize(buttonSize);
    connect(cloneTaskBtn, &QPushButton::clicked, this, &NewTab::cloneTask);

    filterBtn = new QPushButton(tr("F"));
    filterBtn->setFixedSize(buttonSize);
    connect(filterBtn, &QPushButton::clicked, this, &NewTab::filter);

    QHBoxLayout* headerLayout = new QHBoxLayout/*(this)*/;
    headerLayout->setMargin(3);
    headerLayout->addWidget(addWorkspaceBtn);
    headerLayout->addWidget(addTaskBtn);
    headerLayout->addWidget(cloneWorkspaceBtn);
    headerLayout->addWidget(cloneTaskBtn);
    headerLayout->addWidget(filterBtn);
    headerLayout->addStretch(1);

    lblWorkspace = new QLabel(tr("Workspaces"));
    lstWdgtWorkspace = new QListWidget;

    QVBoxLayout* workspaceLayout = new QVBoxLayout;
    workspaceLayout->setMargin(3);
    workspaceLayout->addWidget(lblWorkspace);
    workspaceLayout->addWidget(lstWdgtWorkspace);

    teditSearch = new QTextEdit;
    btnSearch = new QPushButton(tr("S"));
    QHBoxLayout* searchLayout = new QHBoxLayout;
    searchLayout->setMargin(3);
    searchLayout->addWidget(teditSearch);
    searchLayout->addWidget(btnSearch);

    lblTask = new QLabel(tr("Tasks"));
    lstwdgtTask = new QListWidget;
    QVBoxLayout* taskLayout = new QVBoxLayout;
    taskLayout->setMargin(3);
    taskLayout->addWidget(lblTask);
    taskLayout->addLayout(searchLayout);
    taskLayout->addWidget(lstwdgtTask);

    QHBoxLayout* workareaLayout = new QHBoxLayout;
    workareaLayout->setMargin(3);
    workareaLayout->addLayout(workspaceLayout);
    workareaLayout->addLayout(taskLayout);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addLayout(headerLayout);
    layout->addLayout(workareaLayout);

    setLayout(layout);
}

void NewTab::addWorkspace(){
    emit clickAddWorkspaceBtn();
}

void NewTab::addTask(){
    emit clickAddTaskBtn();
}

void NewTab::cloneWorkspace(){
    emit clickCloneWorkspaceBtn();
}

void NewTab::cloneTask(){
    emit clickCloneTaskBtn();
}

void NewTab::filter(){
    emit clickFilterBtn();
}
