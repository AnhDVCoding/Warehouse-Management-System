QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_category.cpp \
    add_product.cpp \
    add_supplier.cpp \
    import_product.cpp \
    login.cpp \
    main.cpp \
    overview.cpp \
    profile.cpp \
    setpermission.cpp

HEADERS += \
    add_category.h \
    add_product.h \
    add_supplier.h \
    import_product.h \
    login.h \
    overview.h \
    profile.h \
    setpermission.h

FORMS += \
    add_category.ui \
    add_product.ui \
    add_supplier.ui \
    import_product.ui \
    login.ui \
    overview.ui \
    profile.ui \
    setpermission.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
