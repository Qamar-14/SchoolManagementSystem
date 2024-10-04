#include "admin.h"
#include "studentDialog.h"
#include "teacherDialog.h"
#include "subject.h"

Admin* Admin::admanInstance = nullptr;

Admin* Admin::getInstance() {
    if (!admanInstance) {
        admanInstance = new Admin(); // Create instance if it doesn't exist
    }
    return admanInstance;
}
Admin::Admin(QWidget *parent) : QWidget(parent) {

    AddStudent = new QPushButton("Add Student", this);
    AddTeacher = new QPushButton("Add Teacher", this);
    AddSubject = new QPushButton("Add Subject", this);
    ModifyStudent = new QPushButton("Modify Students", this);
    ModifyTeacher= new QPushButton("Modify Teachers", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(AddStudent);
    layout->addWidget(AddTeacher);
    layout->addWidget(AddSubject);
    layout->addWidget(ModifyStudent);
    layout->addWidget(ModifyTeacher);

    setLayout(layout);

    // Connect the button signal to the corresponding slot
    connect(AddStudent, &QPushButton::clicked, this, &Admin::openAddStudentDialog);
    connect(AddTeacher, &QPushButton::clicked, this, &Admin::openAddTeacherDialog);
    connect(AddSubject, &QPushButton::clicked, this, &Admin::addSubject);

}

void Admin::openAddStudentDialog() {
    StudentDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QString firstName = dialog.getFirstName();
        QString lastName = dialog.getLastName();
        QString email = dialog.getEmail();
        int age = dialog.getAge();
        Gender gender = dialog.getGender();

        shared_ptr<Student> newStudent = make_shared<Student>(firstName, lastName, email, gender, age);

        m_studentList.push_back(newStudent);

        emit studentAdded(firstName);


    }
}


void Admin::openAddTeacherDialog() {
    TeacherDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QString firstName = dialog.getFirstName();
        QString lastName = dialog.getLastName();
        QString email = dialog.getEmail();
        QString course = dialog.getCourse();
        QString address = dialog.getAddress();
        int age = dialog.getAge();
        Gender gender = dialog.getGender();

        shared_ptr<Teacher> newTeacher = make_shared<Teacher>(firstName, lastName, email, gender, age, course, address);

        m_teacherList.push_back(newTeacher);

        emit teacherAdded(firstName);

    }
}

bool Admin::courseExists(const QString &courseName) const {
    return m_courses.contains(courseName, Qt::CaseInsensitive); // Case insensitive check
}

void Admin::addSubject(){
    Subject subjectDialog(this);
    if (subjectDialog.exec() == QDialog::Accepted) {
        QString subjectName = subjectDialog.getSubject();
        if (!courseExists(subjectName)) {
            m_courses.append(subjectName);
        }
    } else {
        // Handle cancel
    }

}

QVector<shared_ptr<Student>> Admin::getStudentList(){
    return this->m_studentList;
}
QVector<shared_ptr<Teacher>> Admin::getTeacherList(){
    return this->m_teacherList;

}
