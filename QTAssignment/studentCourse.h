#ifndef STUDENTCOURSE_H
#define STUDENTCOURSE_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class StudentCourse : public QDialog {
    Q_OBJECT
public:
    explicit StudentCourse(QWidget *parent = nullptr);

    QString getCourse() const;


private:

    QLineEdit *courseInput;

    QPushButton *submitButton;
    QPushButton *cancelButton;
};


#endif // STUDENTCOURSE_H
