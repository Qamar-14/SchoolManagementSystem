#include "teacherDialog.h"

#include <QLabel>

TeacherDialog::TeacherDialog(QWidget *parent) : QDialog(parent) {
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

    QHBoxLayout *courseLayout = new QHBoxLayout();
    courseLayout->addWidget(new QLabel("Course:", this));
    courseLayout->addWidget(courseInput);

    QHBoxLayout *addressLayout = new QHBoxLayout();
    addressLayout->addWidget(new QLabel("Address:", this));
    addressLayout->addWidget(addressInput);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(firstNameLayout);
    layout->addLayout(lastNameLayout);
    layout->addLayout(emailLayout);
    layout->addLayout(ageLayout);
    layout->addLayout(genderLayout);
    layout->addLayout(courseLayout);
    layout->addLayout(addressLayout);

    layout->addWidget(submitButton);
    layout->addWidget(cancelButton);

    connect(submitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    setLayout(layout);
}

QString TeacherDialog::getFirstName() const {
    return firstNameInput->text();
}

QString TeacherDialog::getLastName() const {
    return lastNameInput->text();
}

QString TeacherDialog::getEmail() const {
    return emailInput->text();
}

QString TeacherDialog::getCourse() const {
    return courseInput->text();
}

QString TeacherDialog::getAddress()const {
    return courseInput->text();
}

int TeacherDialog::getAge() const {
    return ageInput->text().toInt();
}

Gender TeacherDialog::getGender() const {
    if (maleRadioButton->isChecked()) {
        return male;
    } else if (femaleRadioButton->isChecked()) {
        return female;
    }
    return male; // Default value if no selection is made
}
