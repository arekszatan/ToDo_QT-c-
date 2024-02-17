#include "todotask.h"

ToDoTask::ToDoTask(QWidget *parent, qint16 id, QString toDoTask, jsonFile *file):
    file(file)
{
    idGlobal = id;
    this->setLayout(gridLayOut);
    QString sid = QString::number(id);
    nr->setText(sid);
    nr->setFixedWidth(20);
    nr->setAlignment(Qt::AlignCenter);
    gridLayOut->addWidget(nr, 0, 0);

    task->setText(toDoTask);
    gridLayOut->addWidget(task, 0, 1);

    check->setCheckState(Qt::Checked);
    check->setFixedWidth(50);
    gridLayOut->addWidget(check, 0, 3);


    delButton->setText("Usuń");
    delButton->setFixedWidth(100);
    connect(delButton, &QPushButton::clicked, [&](bool) {
        qInfo()<<"Delete button was clicked";
        removeToJson();
         });
    gridLayOut->addWidget(delButton, 0, 4);

    qInfo()<<"Task to do was created";
    //jsonFile::removeItemWithId(id);

}

ToDoTask::~ToDoTask()
{   
    qInfo()<<"Task to do was deleted";
}

void ToDoTask::removeToJson()
{
    bool success = file->removeItemWithId(idGlobal);
    if (success)
        this->deleteLater();
    else
        qInfo()<<"Cant delete this becouse remove in file isnt success";
}
