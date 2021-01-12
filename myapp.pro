QT       += core gui serialport quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttonhoverwatcher.cpp \
    dialogtllogin.cpp \
    formOxygen.cpp \
    formaccess.cpp \
    formvaccum.cpp \
    frameabout.cpp \
    framecontact.cpp \
    framelang.cpp \
    framelogin.cpp \
    frameozone.cpp \
    framepassword.cpp \
    frametimeleft.cpp \
    frametllogin.cpp \
    infection.cpp \
    infectionconf.cpp \
    main.cpp \
    mainwindow.cpp \
    mylineedit.cpp \
    myserialport.cpp \
    ozonect.cpp \
    ozonegeneral.cpp \
    ozonegeneralconf.cpp \
    qtouchspinbox.cpp \
    softkeyboard.cpp \
    timeleft.cpp

HEADERS += \
    buttonhoverwatcher.h \
    dialogtllogin.h \
    formOxygen.h \
    formaccess.h \
    formvaccum.h \
    frameabout.h \
    framecontact.h \
    framelang.h \
    framelogin.h \
    frameozone.h \
    framepassword.h \
    frametimeleft.h \
    frametllogin.h \
    infection.h \
    infectionconf.h \
    mainwindow.h \
    mylineedit.h \
    myserialport.h \
    ozonect.h \
    ozonegeneral.h \
    ozonegeneralconf.h \
    qtouchspinbox.h \
    softkeyboard.h \
    timeleft.h

FORMS += \
    dialogtllogin.ui \
    formOxygen.ui \
    formaccess.ui \
    formvaccum.ui \
    frameabout.ui \
    framecontact.ui \
    framelang.ui \
    framelogin.ui \
    frameozone.ui \
    framepassword.ui \
    frametimeleft.ui \
    frametllogin.ui \
    infection.ui \
    infectionconf.ui \
    mainwindow.ui \
    ozonect.ui \
    ozonegeneral.ui \
    ozonegeneralconf.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

target.path = /home/pi/$${TARGET}/

RESOURCES += \
    images/images.qrc

DISTFILES +=


