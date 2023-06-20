#ifndef JSONFILE_H
#define JSONFILE_H
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QObject>


class jsonFile: public QObject
{
public:
    jsonFile(QString fileName = "unname.json");
    bool writeToDoTaskToFile(qint16 id=0, QString toDoTask="brak");
    bool setToDoListName(QString name);
    QString getToDoListName();
    QJsonArray getActualValue();
    bool removeItemWithId(int id = 0);


private:
    bool createFileIfDontExist(QString path, QString name);
    bool updateFile();
    void readJsonFirstOpen();

    QFile *fileFile = new QFile();
    QJsonObject mainObject;
    QJsonArray toDoList;
    QJsonObject toDoTask;
    QString toDoName;
    QJsonValue value;
    QJsonDocument document;

public slots:


};

#endif // JSONFILE_H
