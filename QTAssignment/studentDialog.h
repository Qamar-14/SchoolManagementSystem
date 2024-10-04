#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include "externalDataTypes.h"

class StudentDialog : public QDialog {
    Q_OBJECT
public:
    explicit StudentDialog(QWidget *parent = nullptr);

    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    Gender getGender() const;
    int getAge() const;

private:
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *emailInput;
    QLineEdit *ageInput;

    QComboBox *genderInput;

    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;
    QButtonGroup *genderGroup;

    QPushButton *submitButton;
    QPushButton *cancelButton;
};

#endif // STUDENTDIALOG_H
