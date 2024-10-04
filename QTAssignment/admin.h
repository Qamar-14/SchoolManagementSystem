#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QStringList>

#include "student.h"
#include "teacher.h"

class Admin : public QWidget {
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    bool courseExists(const QString &courseName) const;
    QVector<shared_ptr<Student>> getStudentList();
    QVector<shared_ptr<Teacher>> getTeacherList();

signals:
    void studentAdded(const QString &studentName);
    void teacherAdded(const QString &teacherName);

public slots:
    static Admin* getInstance();
    void openAddStudentDialog();
    void openAddTeacherDialog();
    void addSubject();

private:
    static Admin* admanInstance; // Static instance of Admin

    QVector<shared_ptr<Student>> m_studentList;
    QVector<shared_ptr<Teacher>> m_teacherList;
    QStringList m_courses;

    QPushButton *AddStudent;
    QPushButton *AddTeacher;
    QPushButton *AddSubject;
    QPushButton *ModifyStudent;
    QPushButton *ModifyTeacher;


};


#endif // ADMIN_H
