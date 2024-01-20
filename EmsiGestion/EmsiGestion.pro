QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console
SOURCES += \
    consultdialog.cpp \
    cours.cpp \
    coursdialog.cpp \
    enseignant.cpp \
    enseignantdialog.cpp \
    etudiant.cpp \
    etudiantdialog.cpp \
    msg.cpp \
    msgdialog.cpp \
    note.cpp


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    interadmi.cpp \
    interetud.cpp \
    main.cpp \
    mainwindow.cpp \
    validation.cpp

HEADERS += \
    consultdialog.h \
    cours.h \
    coursdialog.h \
    enseignant.h \
    enseignantdialog.h \
    etudiant.h \
    etudiantdialog.h \
    gestionbasedonnees.h \
    interadmi.h \
    interetud.h \
    mainwindow.h \
    msg.h \
    msgdialog.h \
    note.h \
    validation.h

FORMS += \
    consultdialog.ui \
    cours.ui \
    coursdialog.ui \
    enseignant.ui \
    enseignantdialog.ui \
    etudiant.ui \
    etudiantdialog.ui \
    gestionbasedonnees.ui \
    interadmi.ui \
    interetud.ui \
    mainwindow.ui \
    msg.ui \
    msgdialog.ui \
    note.ui \
    validation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
