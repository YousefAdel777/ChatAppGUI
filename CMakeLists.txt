cmake_minimum_required(VERSION 3.16)
project(UnifiedApp VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Source files for both projects
set(PROJECT_SOURCES
    # Privacy project files
    PrivacySettings.cpp
    PrivacySettings.h
    PrivacySettings.ui
    img.qrc
    # untitled7 project files
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    About.h
    About.cpp
    About.ui
    res.qrc
    header.h
    header.cpp
    header.ui
    chatroommenu.h
    chatroommenu.cpp
    chatroommenu.ui
    # main.cpp (Choose one or merge content)
    main.cpp # Assuming this main.cpp is for untitled7.  You might need to merge the contents of the two main.cpp files.
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UnifiedApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    set_property(TARGET UnifiedApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/android)
else()
    if(ANDROID)
        add_library(UnifiedApp SHARED
            ${PROJECT_SOURCES}
        )
        set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(UnifiedApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(UnifiedApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.UnifiedApp) # Changed Bundle ID
endif()

set_target_properties(UnifiedApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS UnifiedApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UnifiedApp)
endif()
