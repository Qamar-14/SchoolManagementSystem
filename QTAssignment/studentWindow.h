#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

#include "student.h"

class StudentWindow : public QWidget {
    Q_OBJECT
public:
    explicit StudentWindow(std::shared_ptr<Student> student, QWidget *parent = nullptr);

public slots:
    void viewProfile();
    void registerCourse();


private:
    std::shared_ptr<Student> m_student;

    QPushButton *viewProfileButton;
    QPushButton *addCourseButton;
};



#endif // STUDENTWINDOW_H
