#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "studentWindow.h"
#include "teacherWindow.h"

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;

    // Add member variables to keep windows alive
    std::shared_ptr<StudentWindow> studentWindow;
    std::shared_ptr<TeacherWindow> teacherWindow;

private slots:
    void verifyLogin();
};

#endif // LOGINWINDOW_H
