#include "teacherWindow.h"
#include "admin.h"

#include <QLabel>
#include <QMessageBox>

TeacherWindow::TeacherWindow(shared_ptr<Teacher> teacher, QWidget *parent) : QWidget(parent), m_teacher(teacher)  {

    viewProfileButton = new QPushButton("View Profile", this);
    viewStudentsButton = new QPushButton("View Students", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(viewProfileButton);
    layout->addWidget(viewStudentsButton);

    setLayout(layout);

    // Connect buttons to slots
    connect(viewProfileButton, &QPushButton::clicked, this, [=](){viewProfile();});
    connect(viewStudentsButton, &QPushButton::clicked, this,  [=](){viewStudents();});

}

void TeacherWindow::viewProfile() {
    if (m_teacher) {
        QString profileInfo = m_teacher->getProfileInfo();
        // Display the profile information in a message box
        QMessageBox::information(this, "Teacher Profile", profileInfo);

    } else {
        QMessageBox::warning(this, "Error", "Teacher information not available.");
    }
}


void TeacherWindow::viewStudents() {
    Admin* adminInstance = Admin::getInstance();
    if (adminInstance) {
        QVector<shared_ptr<Student>> studentList = adminInstance->getStudentList();
        QStringList studentsInCourse; // To hold names of students in the same course

        for (auto& stud : studentList) {
            if (stud->getRegisteredCourse() == m_teacher->getCourse()) {
                studentsInCourse << (stud->getFirstName() + " " + stud->getLastName());
            }
        }

        // Check if there are students registered for the course
        if (!studentsInCourse.isEmpty()) {
            // Create a string with the list of students
            QString studentNames = studentsInCourse.join("\n");
            QMessageBox::information(this, "Students in Course", "Students registered for " + m_teacher->getCourse() + ":\n" + studentNames);
        } else {
            QMessageBox::information(this, "No Students Found", "No students are registered for the course: " + m_teacher->getCourse());
        }
    } else {
        QMessageBox::warning(this, "Error", "Admin instance not initialized. Unable to retrieve student list.");
    }
}
