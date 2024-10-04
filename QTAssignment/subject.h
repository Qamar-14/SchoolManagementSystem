#ifndef SUBJECT_H
#define SUBJECT_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class Subject : public QDialog {
    Q_OBJECT
public:
    explicit Subject(QWidget *parent = nullptr);

    QString getSubject() const;


private:

    QLineEdit *subjectInput;

    QPushButton *submitButton;
    QPushButton *cancelButton;
};


#endif // SUBJECT_H
