QMAKE_CXXFLAGS += -pedantic
isEqual(QT_MAJOR_VERSION, 5) {
    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_CXXFLAGS += -Wdouble-promotion
    QMAKE_CXXFLAGS += -Wunreachable-code

    OTHER_FILES += \
        rc/resources.rc

    RC_FILE += \
        rc/resources.rc
}
isEqual(QT_MAJOR_VERSION, 4) {
    QMAKE_CXXFLAGS += -std=c++0x
    QMAKE_CXXFLAGS += -Wno-psabi
    QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
QMAKE_CXXFLAGS += -O3

SOURCES += \
    src/main.cpp \
    src/mainWindow.cpp \
    src/engine.cpp \
    src/scene.cpp \
    src/models.cpp \
    src/renderer.cpp \
    src/shaders.cpp \
    src/maps.cpp \

HEADERS += \
    src/mainWindow.h \
    src/engine.h \
    src/scene.h \
    src/models.h \
    src/renderer.h \
    src/shaders.h \
    src/maps.h \
    src/camera.h \
    src/openGL.h \
    src/context.h \
    src/headers/types.h \
    src/headers/sceneTypes.h \
    src/headers/modelsTypes.h \
    src/headers/shadersTypes.h \
    src/headers/cameraTypes.h \
    src/headers/math.h \
    src/headers/rendererTypes.h \
    src/headers/mapsTypes.h \
    src/headers/openGLTypes.h

FORMS += \
    ui/mainWindow.ui

RESOURCES += \
    qrc/qresources.qrc

OTHER_FILES += \
    src/shaders/basic.vs \
    src/shaders/basic.fs \
    src/shaders/basicAlpha.fs \
    src/shaders/terrain.vs \
    src/shaders/terrain.fs \
    src/shaders/water.vs \
    src/shaders/water.fs \
    src/shaders/underWater.vs \
    src/shaders/underWater.fs
