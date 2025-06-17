cmake_minimum_required(VERSION 3.16)

project(QtLearning VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qml Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Qml Quick Multimedia)


include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Messages/GUI)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Messages)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Messages/GUI/Normal)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Messages/GUI/Reply)

include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/src/libs)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Footer)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom/Header)

include_directories(${CMAKE_SOURCE_DIR}/ui/ChatRoom)

include_directories(${CMAKE_SOURCE_DIR}/ui)

include_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/ui/Login)

include_directories(${CMAKE_SOURCE_DIR}/ui/Setting)

include_directories(${CMAKE_SOURCE_DIR}/ui/SignUp)

include_directories(${CMAKE_SOURCE_DIR}/ui/Privacy)


link_directories("E:\\vcpkg\\vcpkg\\installed\\x64-windows\\lib")

set(PROJECT_SOURCES



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtLearning
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}



        main.cpp
         Helper.h
         assets.qrc
         src/data/images/freepik__upload__31384.png src/data/chatRooms.json src/data/currentUser.json src/data/users.json src/libs/bcrypt/src/bcrypt.cpp src/libs/bcrypt/src/bcrypt.h src/libs/bcrypt/src/blowfish.cpp src/libs/bcrypt/src/node_blf.h src/libs/bcrypt/src/openbsd.h src/libs/json.hpp src/ChatRoomModel.cpp src/ChatRoomModel.h src/Database.cpp src/Database.h src/Date.cpp src/Date.h src/Group.cpp src/Group.h  src/MessageModel.cpp src/MessageModel.h src/Privacy.cpp src/Privacy.h src/SearchEngine.cpp src/SearchEngine.h src/Status.cpp src/status.h src/Story.cpp src/Story.h src/User.cpp src/User.h src/UserProfileDescription.cpp src/UserProfileDescription.h ui/ChatRoom/Footer/currentselectedcontainer.cpp ui/ChatRoom/Footer/currentselectedcontainer.h ui/ChatRoom/Footer/currentselectedcontainer.ui ui/ChatRoom/Footer/filescomponent.cpp ui/ChatRoom/Footer/filescomponent.h ui/ChatRoom/Footer/filescomponent.ui ui/ChatRoom/Footer/photocomponent.cpp ui/ChatRoom/Footer/photocomponent.h ui/ChatRoom/Footer/photocomponent.ui ui/ChatRoom/Footer/recorder.cpp ui/ChatRoom/Footer/recorder.h ui/ChatRoom/Footer/recording.cpp ui/ChatRoom/Footer/recording.h ui/ChatRoom/Footer/recording.ui ui/ChatRoom/Footer/sending.cpp ui/ChatRoom/Footer/sending.h ui/ChatRoom/Footer/sending.ui ui/ChatRoom/Header/About.cpp ui/ChatRoom/Header/About.h ui/ChatRoom/Header/About.ui ui/ChatRoom/Header/header.cpp ui/ChatRoom/Header/Header.h ui/ChatRoom/Header/header.ui ui/ChatRoom/Messages/GUI/Normal/AttachmentCard.cpp ui/ChatRoom/Messages/GUI/Normal/AttachmentCard.h ui/ChatRoom/Messages/GUI/Normal/imagemessage.cpp ui/ChatRoom/Messages/GUI/Normal/imagemessage.h ui/ChatRoom/Messages/GUI/Normal/textmessage.cpp ui/ChatRoom/Messages/GUI/Normal/TextMessage.h ui/ChatRoom/Messages/GUI/Normal/voicemessage.cpp ui/ChatRoom/Messages/GUI/Normal/VoiceMessage.h ui/ChatRoom/Messages/GUI/Normal/waveformslilder.cpp ui/ChatRoom/Messages/GUI/Normal/waveformslilder.h ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.cpp ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.h ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.ui ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.cpp ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.h ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.ui ui/ChatRoom/Messages/GUI/Reply/replytextmessage.cpp ui/ChatRoom/Messages/GUI/Reply/replytextmessage.h ui/ChatRoom/Messages/GUI/Reply/replytextmessage.ui ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.cpp ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.h ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.ui ui/ChatRoom/Messages/GUI/container.cpp ui/ChatRoom/Messages/GUI/container.h ui/ChatRoom/Messages/GUI/container.ui ui/ChatRoom/Messages/GUI/message.cpp ui/ChatRoom/Messages/GUI/message.h ui/ChatRoom/Messages/GUI/messagereceived.cpp ui/ChatRoom/Messages/GUI/messagereceived.h ui/ChatRoom/Messages/GUI/messagesent.cpp ui/ChatRoom/Messages/GUI/messagesent.h ui/ChatRoom/chatroom.cpp ui/ChatRoom/ChatRoom.h ui/ChatRoom/chatroom.ui ui/Login/login.cpp ui/Login/login.h ui/Login/login.ui ui/Privacy/PrivacySettings.cpp ui/Privacy/PrivacySettings.h ui/Privacy/PrivacySettings.ui ui/Settings/SocialLinksDialog/sociallinksdialog.cpp ui/Settings/SocialLinksDialog/sociallinksdialog.h ui/Settings/SocialLinksDialog/sociallinksdialog.ui ui/Settings/settings.cpp ui/Settings/settings.h ui/Settings/settings.ui ui/SignUp/signup.cpp ui/SignUp/signup.h ui/SignUp/signup.ui
         ui/ChatRoom/Footer/blockerwidget.h ui/ChatRoom/Footer/blockerwidget.cpp ui/ChatRoom/Footer/blockerwidget.ui
         ui/ChatRoom/Footer/blockedwidget.h ui/ChatRoom/Footer/blockedwidget.cpp ui/ChatRoom/Footer/blockedwidget.ui
         chatcard.cpp chatcard.h chatcard.ui mainwindow.cpp mainwindow.h mainwindow.ui utilities.cpp utilities.h
         chatlist.h chatlist.cpp chatlist.ui
         ui/Search/search.cpp ui/Search/search.h ui/Search/search.ui
         ui/StatusWindow/StatusWindow.cpp ui/StatusWindow/StatusWindow.h ui/StatusWindow/StatusWindow.ui
         ui/AddStoryPage/AddStoryPage.cpp ui/AddStoryPage/AddStoryPage.h ui/AddStoryPage/addStoryPage.ui
         chatwidget.h chatwidget.cpp chatwidget.ui
        ui/AddContact/addcontact.cpp ui/AddContact/addcontact.h ui/AddContact/addcontact.ui ui/AddStoryPage/AddStoryPage.cpp ui/AddStoryPage/AddStoryPage.h ui/AddStoryPage/addStoryPage.ui
        ui/CreateGroup/creategroup.cpp ui/CreateGroup/creategroup.h ui/CreateGroup/creategroup.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtLearning APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtLearning SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtLearning
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtLearning PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Multimedia Qt6::Qml Qt6::Quick)

# Copy DLL after build so it's available at runtime

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtLearning)
endif()
set_target_properties(QtLearning PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtLearning
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtLearning)
endif()
