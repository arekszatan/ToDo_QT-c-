#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QPushButton>
#include <QDebug>



class CustomButton : public QPushButton
{
public:
    CustomButton(QPushButton *parent = nullptr);
    QPushButton *parenta = new QPushButton;
    ~CustomButton();

    virtual void setText(const QString &text) ;

protected:
    bool event(QEvent *e) override;
};

#endif // CUSTOMBUTTON_H
