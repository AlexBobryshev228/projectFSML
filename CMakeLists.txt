cmake_minimum_required(VERSION 3.16)

project(ProjectFSML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appProjectFSML
    main.cpp
    src/app/AppController.cpp
    src/app/AppController.h
    src/data/DataStore.cpp
    src/data/DataStore.h
    src/data/ExerciseRepository.cpp
    src/data/ExerciseRepository.h
    src/data/Exercise.h
    src/data/MuscleInfo.h
    src/data/muscleregion.h
    src/data/muscleregionmodel.cpp
    src/data/muscleregionmodel.h
)
qt_add_qml_module(appProjectFSML
    URI ProjectFSML
    VERSION 1.0
    QML_FILES
        Main.qml
        BodyView.qml
        InfoPanel.qml
        MuscleZone.qml
    RESOURCES
        images/body.png
        data/data.json
        SOURCES src/data/muscleinfo.h
        SOURCES src/data/muscleregion.h
        SOURCES src/data/muscleregionmodel.h src/data/muscleregionmodel.cpp
        QML_FILES
        QML_FILES ClickableMuscleNorm.qml
)

set_target_properties(appProjectFSML PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appProjectFSML
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appProjectFSML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
