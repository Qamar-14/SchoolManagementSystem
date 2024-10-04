#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

#include "teacher.h"

class TeacherWindow : public QWidget {
    Q_OBJECT
public:
    explicit TeacherWindow(shared_ptr<Teacher> teacher, QWidget *parent = nullptr);

public slots:
    void viewProfile();
    void viewStudents();


private:
    shared_ptr<Teacher> m_teacher;

    QPushButton *viewProfileButton;
    QPushButton *viewStudentsButton;
};



#endif // TEACHERWINDOW_H
