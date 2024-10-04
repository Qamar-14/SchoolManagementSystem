#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QObject>
#include "externalDataTypes.h"

using namespace std;
int static g_teacherID = 0;

class Teacher: public QObject {
    Q_OBJECT

private:
    QString m_firstName;
    QString m_lastName;
    QString m_email;
    int m_teacherID;
    Gender m_gender;
    int m_age;
    QString m_registeredCourse;
    QString m_course;
    QString m_address;

public:

    explicit Teacher(QObject *parent = nullptr);

    Teacher(QString firstName,
            QString lastName,
            QString email,
            Gender gender,
            int age,
            QString course,
            QString address
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
    QString getAddress() const;
    void setAddress(const QString &address);

    int getTeacherID() const;
    QString getCourse() const;

    QString getProfileInfo() const;


};

#endif // TEACHER_H
