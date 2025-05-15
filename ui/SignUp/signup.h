//
// Created by Dell on 5/1/2025.
//

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class SignUp; }
QT_END_NAMESPACE

class SignUp : public QWidget {
Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp() override;

private slots:
    void handleSignUp();
    void redirectToLogin();

private:
    Ui::SignUp *ui;
};


#endif //SIGNUP_H
