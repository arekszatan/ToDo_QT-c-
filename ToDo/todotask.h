#ifndef TODOTASK_H
#define TODOTASK_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QLabel>
#include <QCheckBox>

class ToDoTask : public QWidget
{
public:
    ToDoTask(QWidget *parent = nullptr);
    ~ToDoTask();

public slots:
    void delButtonClicked();

private:
    QPushButton *delButton = new QPushButton;
    QGridLayout *gridLayOut = new QGridLayout;
    QLabel *nr = new QLabel;
    QLabel *task = new QLabel;
    QCheckBox *check = new QCheckBox;

};

#endif // TODOTASK_H
