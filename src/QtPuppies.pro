QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dog/boarding.cpp \
    Dog/breeding.cpp \
    Dog/date.cpp \
    Dog/dog.cpp \
    Dog/owner.cpp \
    breeds/amstaff.cpp \
    breeds/bulldog.cpp \
    main.cpp \
    memory/converter/json/Json.cpp \
    memory/converter/json/JsonVisitor.cpp \
    memory/converter/json/Reader.cpp \
    memory/datamapper/JsonFile.cpp \
    memory/repository/JsonRepo.cpp \
    sizes/large.cpp \
    sizes/medium.cpp \
    sizes/size.cpp \
    sizes/small.cpp \
    view/BoardingFilterWidget.cpp \
    view/BoardingPanel.cpp \
    view/BreedingFilterWidget.cpp \
    view/BreedingPanel.cpp \
    view/ButtonsWidget.cpp \
    view/DogList.cpp \
    view/DogListWidget.cpp \
    view/DogVisitorCard.cpp \
    view/DogVisitorEditPanel.cpp \
    view/DogVisitorInfoPanel.cpp \
    view/FinalButtonWidget.cpp \
    view/GeneralFilterWidget.cpp \
    view/GeneralPanel.cpp \
    view/MainWindow.cpp


HEADERS += \
    Dog/boarding.h \
    Dog/breeding.h \
    Dog/container.h \
    Dog/date.h \
    Dog/dog.h \
    Dog/dogvisitor.h \
    Dog/owner.h \
    breeds/amstaff.h \
    breeds/breed.h \
    breeds/bulldog.h \
    memory/converter/json/Json.h \
    memory/converter/json/JsonVisitor.h \
    memory/converter/json/Reader.h \
    memory/datamapper/JsonFile.h \
    memory/repository/JsonRepo.h \
    sizes/large.h \
    sizes/medium.h \
    sizes/size.h \
    sizes/small.h \
    view/BoardingFilterWidget.h \
    view/BoardingPanel.h \
    view/BreedingFilterWidget.h \
    view/BreedingPanel.h \
    view/ButtonsWidget.h \
    view/DogList.h \
    view/DogListWidget.h \
    view/DogVisitorCard.h \
    view/DogVisitorEditPanel.h \
    view/DogVisitorInfoPanel.h \
    view/FinalButtonWidget.h \
    view/GeneralFilterWidget.h \
    view/GeneralPanel.h \
    view/MainWindow.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

FORMS +=










