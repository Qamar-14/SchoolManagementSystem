#include "studentDialog.h"

#include <QLabel>

StudentDialog::StudentDialog(QWidget *parent) : QDialog(parent) {

    firstNameInput = new QLineEdit(this);
    lastNameInput = new QLineEdit(this);
    emailInput = new QLineEdit(this);
    ageInput = new QLineEdit(this);

    genderInput = new QComboBox(this);

    maleRadioButton = new QRadioButton("Male", this);
    femaleRadioButton = new QRadioButton("Female", this);

    genderGroup = new QButtonGroup(this);
    genderGroup->addButton(maleRadioButton);
    genderGroup->addButton(femaleRadioButton);

    submitButton = new QPushButton("Submit", this);
    cancelButton = new QPushButton("Cancel", this);

    QHBoxLayout *firstNameLayout = new QHBoxLayout();
    firstNameLayout->addWidget(new QLabel("First Name:", this));
    firstNameLayout->addWidget(firstNameInput);

    QHBoxLayout *lastNameLayout = new QHBoxLayout();
    lastNameLayout->addWidget(new QLabel("Last Name:", this));
    lastNameLayout->addWidget(lastNameInput);

    QHBoxLayout *emailLayout = new QHBoxLayout();
    emailLayout->addWidget(new QLabel("Email:", this));
    emailLayout->addWidget(emailInput);

    QHBoxLayout *ageLayout = new QHBoxLayout();
    ageLayout->addWidget(new QLabel("Age:", this));
    ageLayout->addWidget(ageInput);

    QHBoxLayout *genderLayout = new QHBoxLayout();
    genderLayout->addWidget(maleRadioButton);
    genderLayout->addWidget(femaleRadioButton);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(firstNameLayout);
    layout->addLayout(lastNameLayout);
    layout->addLayout(emailLayout);
    layout->addLayout(ageLayout);
    layout->addLayout(genderLayout);

    layout->addWidget(submitButton);
    layout->addWidget(cancelButton);

    connect(submitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    setLayout(layout);
}

QString StudentDialog::getFirstName() const {
    return firstNameInput->text();
}

QString StudentDialog::getLastName() const {
    return lastNameInput->text();
}

QString StudentDialog::getEmail() const {
    return emailInput->text();
}

int StudentDialog::getAge() const {
    return ageInput->text().toInt();
}

Gender StudentDialog::getGender() const {
    if (maleRadioButton->isChecked()) {
        return male;
    } else if (femaleRadioButton->isChecked()) {
        return female;
    }
    return male; // Default value if no selection is made
}
