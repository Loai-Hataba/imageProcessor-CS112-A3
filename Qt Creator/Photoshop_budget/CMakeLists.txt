cmake_minimum_required(VERSION 3.5)

project(Photoshop_budget VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
        main.cpp
        photoshop_budget.cpp
        photoshop_budget.h
        photoshop_budget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Photoshop_budget
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        image_processor_code.cpp
        Image_Class.h
        stb_image.h
        stb_image_write.h
        image_processor.h
        stb_implementation.cpp
        rsc.qrc

    )
else()
    if(ANDROID)
        add_library(Photoshop_budget SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Photoshop_budget
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Photoshop_budget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Photoshop_budget)
endif()

set_target_properties(Photoshop_budget PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Photoshop_budget
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Photoshop_budget)
endif()
