QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    loginWindow.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    studentCourse.cpp \
    studentDialog.cpp \
    studentWindow.cpp \
    subject.cpp \
    teacher.cpp \
    teacherDialog.cpp \
    teacherWindow.cpp

HEADERS += \
    admin.h \
    externalDataTypes.h \
    loginWindow.h \
    mainwindow.h \
    student.h \
    studentCourse.h \
    studentDialog.h \
    studentWindow.h \
    subject.h \
    teacher.h \
    teacherDialog.h \
    teacherWindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
