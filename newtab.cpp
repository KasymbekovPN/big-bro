#include "newtab.h"

NewTab::NewTab(QWidget *parent) : QWidget(parent)
{

    const QSize buttonSize = QSize(60, 60);

    addWorkspaceBtn = new QPushButton(tr("+W"));
    addWorkspaceBtn->setFixedSize(buttonSize);
//    addWorkspaceBtn->setStyleSheet("background-color: green");
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

    filler = new QLabel(tr("Label"), this);
    filler->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    filler->setStyleSheet("background-color: yellow");

    QVBoxLayout* layout = new QVBoxLayout/*(this)*/;
    layout->setMargin(5);
    layout->addLayout(headerLayout);
    layout->addWidget(filler);

    setLayout(layout);
}

void NewTab::addWorkspace(){
    filler->setText(tr("addWorkspace"));
    emit clickAddWorkspaceBtn();
}

void NewTab::addTask(){
    filler->setText(tr("addTask"));
    emit clickAddTaskBtn();
}

void NewTab::cloneWorkspace(){
    filler->setText(tr("cloneWorkspace"));
    emit clickCloneWorkspaceBtn();
}

void NewTab::cloneTask(){
    filler->setText(tr("cloneTask"));
    emit clickCloneTaskBtn();
}

void NewTab::filter(){
    filler->setText(tr("filter"));
    emit clickFilterBtn();
}
