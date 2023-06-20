#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , id(0)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    /*
    CustomButton *customBut = new CustomButton;
    connect(customBut, &QPushButton::clicked, [&](bool) {
        qInfo()<<"Button was clicked";
         });
    customBut->setText("dadsadadad");
    ui->gridLayout->addWidget(customBut,ui->gridLayout->rowCount(), ui->gridLayout->columnCount()-1, Qt::AlignHCenter);
    */
    file->setToDoListName("Arek");
    ui->toDoListName->setText(file->getToDoListName());
    setInitialToDo();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startPageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_addNewToDoButton_clicked()
{
    QString textToDo = ui->toDolineEdit->text();
    if (textToDo == nullptr)
        return;
    ToDoTask *task = new ToDoTask(nullptr, id, textToDo, file);
    bool success = file->writeToDoTaskToFile(id, textToDo);
    if (success)
    {
        ui->scrollToDo->addWidget(task);
        ui->toDolineEdit->clear();
        id ++;
    }
}

void MainWindow::setInitialToDo()
{

    for (const auto& value : file->getActualValue()) {
        QJsonObject obj = value.toObject();
        if(obj["id"].isNull() or obj["toDo"].isNull() or obj["isChecked"].isNull())
            continue;
        ToDoTask *task = new ToDoTask(nullptr, obj["id"].toString().toInt(), obj["toDo"].toString(), file);
        ui->scrollToDo->addWidget(task);
        id ++;
    }
}

