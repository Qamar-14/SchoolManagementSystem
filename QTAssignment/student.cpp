#include "student.h"

Student::Student(QString firstName,
                 QString lastName,
                 QString email,
                 Gender gender,
                 int age) : m_firstName(firstName), m_lastName(lastName), m_email(email), m_age(age), m_gender(gender)
{
    this->m_studentID = g_studentID++;
}

// Constructor with default parent
Student::Student(QObject *parent) : QObject(parent) {
    // Initialize default values
    m_studentID = g_studentID++;
}


// Getters
QString Student::getFirstName() const {
    return m_firstName;
}

void Student::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

QString Student::getLastName() const {
    return m_lastName;
}

void Student::setLastName(const QString &lastName) {
    m_lastName = lastName;
}

QString Student::getEmail() const {
    return m_email;
}

void Student::setEmail(const QString &email) {
    m_email = email;
}

int Student::getAge() const {
    return m_age;
}

void Student::setAge(const int &age) {
    m_age = age;
}

Gender Student::getGender() const {
    return m_gender;
}

void Student::setGender(const Gender &gender) {
    m_gender = gender;
}

int Student::getStudentID() const {
    return m_studentID;
}
void Student::setRegisteredCourse(const QString &RegisteredCourse){
    m_registeredCourse = RegisteredCourse;
}

QString Student::getRegisteredCourse() const {
    return m_registeredCourse;
}

// Method to return the profile information as a QString
QString Student::getProfileInfo() const {
    return QString("Name: %1 %2\nEmail: %3\nAge: %4\nGender: %5")
    .arg(m_firstName)
        .arg(m_lastName)
        .arg(m_email)
        .arg(m_age)
        .arg(m_gender);
}
