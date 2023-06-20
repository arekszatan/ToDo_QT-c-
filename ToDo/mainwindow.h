#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custombutton.h"
#include "todotask.h"
#include "jsonfile.h"
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startPageButton_clicked();

    void on_addNewToDoButton_clicked();

private:
    Ui::MainWindow *ui;
    qint16 id;
    jsonFile *file = new jsonFile("data.json");
    void setInitialToDo();
};
#endif // MAINWINDOW_H
