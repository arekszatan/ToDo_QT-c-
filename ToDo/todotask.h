#ifndef TODOTASK_H
#define TODOTASK_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QLabel>
#include <QCheckBox>
#include <QObject>
#include "jsonfile.h"

class ToDoTask : public QWidget
{
    Q_OBJECT
    Q_EMIT
public:
    ToDoTask(QWidget *parent = nullptr, qint16 id = 0, QString toDoTask = "brak", jsonFile *file = nullptr);
    ~ToDoTask();

public slots:

private:
    QPushButton *delButton = new QPushButton;
    QGridLayout *gridLayOut = new QGridLayout;
    QLabel *nr = new QLabel;
    QLabel *task = new QLabel;
    QCheckBox *check = new QCheckBox;
    int idGlobal = 0;
    void removeToJson();
    jsonFile *file;

signals:

};

#endif // TODOTASK_H
