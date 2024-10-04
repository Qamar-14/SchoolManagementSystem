#include "studentCourse.h"
#include <QLabel>
#include <QPushButton>

StudentCourse::StudentCourse(QWidget *parent) : QDialog(parent) {
    QLabel *courseLabel = new QLabel("Course: ", this);
    courseInput = new QLineEdit(this);

    submitButton = new QPushButton("Submit", this);
    cancelButton = new QPushButton("Cancel", this);

    QHBoxLayout *courseLayout = new QHBoxLayout();
    courseLayout->addWidget(courseLabel);
    courseLayout->addWidget(courseInput);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(courseLayout);
    layout->addWidget(submitButton);
    layout->addWidget(cancelButton);

    setLayout(layout);

    // Use QDialog's accept() and reject() methods
    connect(submitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString StudentCourse::getCourse() const {
    return courseInput->text();
}
