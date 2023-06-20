#include "custombutton.h"
#include "qcoreevent.h"
#include <QSize>

CustomButton::CustomButton(QPushButton *p)
{
    qInfo()<<"Custom button "<<this<<" >>>> was created";
}

CustomButton::~CustomButton()
{
    qInfo()<<"Custom button "<<this<<" >>>> was deleted";
}

void CustomButton::setText(const QString &text)
{
    QPushButton::setText(text);
    qInfo()<<"Text for custom button "<<this<<" >>>>"<<text;
}

bool CustomButton::event(QEvent *e)
{
    QPushButton::event(e);
    //qInfo()<<"Event for "<<this<<" >>>>"<<e;
    switch (e->type()) {
    case QEvent::MouseButtonPress:
        qInfo()<<"Event for"<<this<<" >>>> press";
        QPushButton::setMaximumSize(QPushButton::size()-QSize(10, 0));
        qInfo()<<QPushButton::size();
        return false;
    case QEvent::MouseButtonRelease:
        qInfo()<<"Event for"<<this<<" >>>> relese";
        //QPushButton::setMaximumWidth(9999);
        return true;
    default:
        //qInfo()<<"Event for"<<this<<" >>>> other";
        return false;
    }
}

