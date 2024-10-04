#include "subject.h"
#include <QLabel>

Subject::Subject(QWidget *parent) : QDialog(parent) {

    subjectInput = new QLineEdit(this);

    submitButton = new QPushButton("Submit", this);
    cancelButton = new QPushButton("Cancel", this);

    QHBoxLayout *courseLayout = new QHBoxLayout();
    courseLayout->addWidget(new QLabel("Subject:", this));
    courseLayout->addWidget(subjectInput);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(courseLayout);

    layout->addWidget(submitButton);
    layout->addWidget(cancelButton);

    // Use QDialog's accept() and reject() methods
    connect(submitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    setLayout(layout);
}

QString Subject::getSubject() const {
    return subjectInput->text();
}
