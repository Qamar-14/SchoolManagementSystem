#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include "externalDataTypes.h"

class TeacherDialog : public QDialog {
    Q_OBJECT
public:
    explicit TeacherDialog(QWidget *parent = nullptr);

    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getCourse() const;
    QString getAddress()const;
    Gender getGender() const;
    int getAge() const;

private:
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *emailInput;
    QLineEdit *ageInput;
    QLineEdit *courseInput;
    QLineEdit *addressInput;

    QComboBox *genderInput;

    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;
    QButtonGroup *genderGroup;

    QPushButton *submitButton;
    QPushButton *cancelButton;
};


#endif // TEACHERDIALOG_H
