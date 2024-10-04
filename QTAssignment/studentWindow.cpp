#include "studentWindow.h"
#include "studentCourse.h"
#include "admin.h"
#include <QLabel>
#include <QMessageBox>

StudentWindow::StudentWindow(std::shared_ptr<Student> student, QWidget *parent) : QWidget(parent), m_student(student) {
    viewProfileButton = new QPushButton("View Profile", this);
    addCourseButton = new QPushButton("Add Course", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(viewProfileButton);
    layout->addWidget(addCourseButton);

    setLayout(layout);

    // Connect buttons to slots
    connect(viewProfileButton, &QPushButton::clicked, this, [=]() {viewProfile();});
    connect(addCourseButton, &QPushButton::clicked, this, &StudentWindow::registerCourse);

}

void StudentWindow::viewProfile() {
    if (m_student) {  // Ensure m_student is initialized
        QString profileInfo = m_student->getProfileInfo();
        // Display the profile information in a message box
        QMessageBox::information(this, "Student Profile", profileInfo);

    } else {
        QMessageBox::warning(this, "Error", "Student information not available.");
    }
}


void StudentWindow::registerCourse(){
    if (m_student) {  // Ensure m_student is initialized
        StudentCourse subjectDialog(this);
        Admin* adminInstance = Admin::getInstance();
        if(adminInstance){
            // Check if course exists
            if (subjectDialog.exec() == QDialog::Accepted) {
                QString subjectName = subjectDialog.getCourse();
                if (adminInstance->courseExists(subjectName)) {
                    m_student->setRegisteredCourse(subjectName);
                    QMessageBox::information(this, "Course Registration", "Successfully registered for the course: " + subjectName);
                }
                else {
                    QMessageBox::warning(this, "Course Registration", "Failed to register for the course: " + subjectName);
                }
            }
            else {
                QMessageBox::warning(this, "Course Registration", "Failed to register. " );
            }
        }
        // no admin instance initialized
        else{
            QMessageBox::warning(this, "Error", " No admin in the system.");

        }
    }
    else {
        QMessageBox::warning(this, "Error", "Student not available.");
    }
}


