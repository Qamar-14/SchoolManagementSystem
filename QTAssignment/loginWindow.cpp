#include "loginWindow.h"

#include "admin.h"

#include <QMessageBox>
#include <QLabel>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    usernameInput = new QLineEdit(this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Username:", this));
    layout->addWidget(usernameInput);
    layout->addWidget(new QLabel("Password:", this));
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, [=](){verifyLogin();});
}

void LoginWindow::verifyLogin() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    Admin *adminWindow = Admin::getInstance(); // Use singleton instance

    if (username == "admin" && password == "admin") {
        // Open the Admin window
        adminWindow->show();
        this->close();
    }
    // Logic for student
    else if (username.startsWith("student_")) {
        // temp student object here
        //auto student = std::make_shared<Student>("John", "Doe", "john@example.com", male, 20);
        auto student = adminWindow->findStudent(username);
        studentWindow = std::make_shared<StudentWindow>(student);
        studentWindow->show();        
        this->close();
    }
    // Logic for teacher
    else if (username.startsWith("teacher_")) {
        // temp teacher object here
        //std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>(QString("John"), QString("Doe"), QString("john@example.com"), Gender::male, 20, "Math","New Cairo");
        auto teacher = adminWindow->findTeacher(username);
        teacherWindow = std::make_shared<TeacherWindow>(teacher);
        teacherWindow->show();
        this->close();

    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
