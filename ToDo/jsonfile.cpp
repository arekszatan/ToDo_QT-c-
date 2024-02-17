#include "jsonfile.h"


jsonFile::jsonFile(QString fileName)
{
    createFileIfDontExist(QDir::currentPath(), fileName);
    readJsonFirstOpen();
    mainObject.insert("name","noname");
}

bool jsonFile::createFileIfDontExist(QString path, QString name)
{
    QDir dir;
    if (!dir.exists(path))
        dir.mkpath(path);

    if (QFile::exists(path + "/" + name))
    {
        fileFile->setFileName(path + "/" + name);
        qInfo()<<"File already exist "<<path + "/" + name;
        return true;
    }
    fileFile->setFileName(path + "/" + name);
    fileFile->open(QIODevice::ReadWrite);
    fileFile->close();
    if (fileFile->exists())
    {
        qInfo()<<"New file was created "<<path + "/" + name;
        return true;
    }
    return false;
}

bool jsonFile::updateFile()
{
    if(!fileFile->exists())
        return false;

    if(fileFile->open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate ) )
    {
        document.setObject(mainObject);
        QByteArray bytes = document.toJson( QJsonDocument::Indented );
        QTextStream iStream(fileFile);
        iStream.setCodec("utf-8");
        iStream << bytes;
        fileFile->close();
        qInfo() << "file open success: " << QDir::currentPath();
        return true;
    }
    else
    {
        qInfo() << "file open failed: " << QDir::currentPath();
        return false;
    }
}

void jsonFile::readJsonFirstOpen()
{
    QString val;
    fileFile->open(QIODevice::ReadOnly | QIODevice::Text);
    val = fileFile->readAll();
    fileFile->close();
    document = QJsonDocument::fromJson(val.toUtf8());
    mainObject = document.object();
    value = mainObject.value("toDoList");
    for (const auto& value : value.toArray()) {
        QJsonObject obj = value.toObject();
        if(obj["id"].isNull() or obj["toDo"].isNull() or obj["isChecked"].isNull())
            continue;
        writeToDoTaskToFile(obj["id"].toString().toInt(), obj["toDo"].toString());
    }
}

bool jsonFile::writeToDoTaskToFile(qint16 id, QString toDoTaskText)
{
    if(id<0)
        return false;

    toDoTask.insert("isChecked", "0");
    toDoTask.insert("toDo", toDoTaskText);
    toDoTask.insert("id", QString::number(id));
    if(toDoTask["id"].isNull() or toDoTask["toDo"].isNull() or toDoTask["isChecked"].isNull())
    {
        return false;
    }
    toDoList.push_back(toDoTask);
    mainObject.insert("toDoList",toDoList);
    updateFile();
    return true;
}

bool jsonFile::setToDoListName(QString name)
{
    if (name.isNull())
        return false;

    toDoName = name;
    mainObject.insert("name",name);
    updateFile();
    return true;
}

QString jsonFile::getToDoListName()
{
    return toDoName;
}

QJsonArray jsonFile::getActualValue()
{
    return value.toArray();
}

bool jsonFile::removeItemWithId(int id)
{
    if (id<0)
        return false;
    value = mainObject.value("toDoList");
    mainObject.remove("toDoList");
    while (!toDoList.isEmpty()) {
        toDoList.pop_back();
    }
    updateFile();

    for (const auto& value : value.toArray()) {
        QJsonObject obj = value.toObject();
        if(obj["id"].isNull() or obj["toDo"].isNull() or obj["isChecked"].isNull())
            continue;
        if (obj["id"] == QString::number(id))
            continue;
        writeToDoTaskToFile(obj["id"].toString().toInt(), obj["toDo"].toString());
    }

    qInfo()<<"Item with id "<< id << "was delete";
    return true;
}
