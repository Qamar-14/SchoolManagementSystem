#include "teacher.h"

Teacher::Teacher(QString firstName,
                 QString lastName,
                 QString email,
                 Gender gender,
                 int age,
                 QString course,
                 QString address
                 ) : m_firstName(firstName), m_lastName(lastName), m_email(email), m_gender(gender),  m_age(age), m_course(course), m_address(address)
{
    this->m_teacherID = g_teacherID++;
}

// Constructor with default parent
Teacher::Teacher(QObject *parent) : QObject(parent) {
    // Initialize default values
    this->m_teacherID = g_teacherID++;
    this->m_age = 0; // Default age
    this->m_gender = male; // Default gender
    //m_academicBackground.clear(); // Initialize academic background as empty
    this->m_address.clear(); // Initialize address as empty
    this->m_course.clear(); // Initialize course as empty
}


// Getters
QString Teacher::getFirstName() const {
    return m_firstName;
}

void Teacher::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

QString Teacher::getLastName() const {
    return m_lastName;
}

void Teacher::setLastName(const QString &lastName) {
    m_lastName = lastName;
}

QString Teacher::getEmail() const {
    return m_email;
}

void Teacher::setEmail(const QString &email) {
    m_email = email;
}

int Teacher::getAge() const {
    return m_age;
}

void Teacher::setAge(const int &age) {
    m_age = age;
}

Gender Teacher::getGender() const {
    return m_gender;
}

void Teacher::setGender(const Gender &gender) {
    m_gender = gender;
}

QString Teacher::getAddress() const {
    return m_address;
}

void Teacher::setAddress(const QString &address) {
    m_address = address;
}

int Teacher::getTeacherID() const {
    return m_teacherID;
}

QString Teacher::getCourse() const {
    return m_course;
}

// Method to return the profile information as a QString
QString Teacher::getProfileInfo() const {
    return QString("Name: %1 %2\nEmail: %3\nAge: %4\nGender: %5\nCourse: %6")
    .arg(m_firstName)
        .arg(m_lastName)
        .arg(m_email)
        .arg(m_age)
        .arg(m_gender)
        .arg(m_course);
}


