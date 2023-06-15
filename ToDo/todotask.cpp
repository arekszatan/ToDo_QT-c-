#include "todotask.h"


ToDoTask::ToDoTask(QWidget *parent)
{
    this->setLayout(gridLayOut);

    nr->setText("1");
    nr->setFixedWidth(20);
    nr->setAlignment(Qt::AlignCenter);
    gridLayOut->addWidget(nr, 0, 0);

    task->setText("firs task cos csaca");
    gridLayOut->addWidget(task, 0, 1);

    check->setCheckState(Qt::Checked);
    check->setFixedWidth(50);
    gridLayOut->addWidget(check, 0, 3);


    delButton->setText("Usuń");
    delButton->setFixedWidth(100);
    connect(delButton, &QPushButton::clicked, [&](bool) {
        qInfo()<<"Delete button was clicked";
        this->deleteLater();
         });
    gridLayOut->addWidget(delButton, 0, 4);

    qInfo()<<"Task to do was created";
}

ToDoTask::~ToDoTask()
{
    qInfo()<<"Task to do was deleted";
}

void ToDoTask::delButtonClicked()
{

}
