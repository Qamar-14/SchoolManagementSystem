#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QObject>
#include "externalDataTypes.h"
using namespace std;

static int g_studentID = 0;

class Student : public QObject {
    Q_OBJECT
private:
    QString m_firstName;
    QString m_lastName;
    QString m_email;
    int m_studentID;
    Gender m_gender;
    int m_age;
    QString m_registeredCourse;

public:

    explicit Student(QObject *parent = nullptr);

    Student(QString firstName,
            QString lastName,
            QString email,
            Gender gender,
            int age
            );

    // Getters and Setters
    QString getFirstName() const;
    void setFirstName(const QString &firstName);
    QString getLastName() const;
    void setLastName(const QString &lastName);
    QString getEmail() const;
    void setEmail(const QString &email);
    int getAge() const;
    void setAge(const int &age);
    Gender getGender() const;
    void setGender(const Gender &gender);
    int getStudentID() const;
    void setRegisteredCourse(const QString &RegisteredCourse);
    QString getRegisteredCourse() const;

    QString getProfileInfo() const;

};

#endif // STUDENT_H

