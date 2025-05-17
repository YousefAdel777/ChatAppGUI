cmake_minimum_required(VERSION 3.19)
project(ChatApp LANGUAGES CXX)

# Set path to Qt installation
set(CMAKE_PREFIX_PATH "D:/Qt/6.9.0/mingw_64/lib/cmake")

# Find required Qt components
find_package(Qt6 6.9 REQUIRED COMPONENTS Core Widgets Multimedia)

# Qt setup helper
qt_standard_project_setup()
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Include resource files
qt_add_resources(RESOURCE_FILES assets.qrc)

# Add include directories
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

include_directories(${CMAKE_SOURCE_DIR}/ui/AddStoryPage)

include_directories(${CMAKE_SOURCE_DIR}/ui/StatusWindow)


# Define executable and source files
qt_add_executable(ChatApp
    WIN32 MACOSX_BUNDLE
    main.cpp
            Helper.h
            assets.qrc
            src/data/images/freepik__upload__31384.png src/data/chatRooms.json src/data/currentUser.json src/data/users.json src/libs/bcrypt/src/bcrypt.cpp src/libs/bcrypt/src/bcrypt.h src/libs/bcrypt/src/blowfish.cpp src/libs/bcrypt/src/node_blf.h src/libs/bcrypt/src/openbsd.h src/libs/json.hpp src/ChatRoomModel.cpp src/ChatRoomModel.h src/Database.cpp src/Database.h src/Date.cpp src/Date.h src/Group.cpp src/Group.h  src/MessageModel.cpp src/MessageModel.h src/Privacy.cpp src/Privacy.h src/SearchEngine.cpp src/SearchEngine.h src/Status.cpp src/status.h src/Story.cpp src/Story.h src/User.cpp src/User.h src/UserProfileDescription.cpp src/UserProfileDescription.h ui/ChatRoom/Footer/currentselectedcontainer.cpp ui/ChatRoom/Footer/currentselectedcontainer.h ui/ChatRoom/Footer/currentselectedcontainer.ui ui/ChatRoom/Footer/filescomponent.cpp ui/ChatRoom/Footer/filescomponent.h ui/ChatRoom/Footer/filescomponent.ui ui/ChatRoom/Footer/photocomponent.cpp ui/ChatRoom/Footer/photocomponent.h ui/ChatRoom/Footer/photocomponent.ui ui/ChatRoom/Footer/recorder.cpp ui/ChatRoom/Footer/recorder.h ui/ChatRoom/Footer/recording.cpp ui/ChatRoom/Footer/recording.h ui/ChatRoom/Footer/recording.ui ui/ChatRoom/Footer/sending.cpp ui/ChatRoom/Footer/sending.h ui/ChatRoom/Footer/sending.ui ui/ChatRoom/Header/About.cpp ui/ChatRoom/Header/About.h ui/ChatRoom/Header/About.ui ui/ChatRoom/Header/header.cpp ui/ChatRoom/Header/Header.h ui/ChatRoom/Header/header.ui ui/ChatRoom/Messages/GUI/Normal/AttachmentCard.cpp ui/ChatRoom/Messages/GUI/Normal/AttachmentCard.h ui/ChatRoom/Messages/GUI/Normal/imagemessage.cpp ui/ChatRoom/Messages/GUI/Normal/imagemessage.h ui/ChatRoom/Messages/GUI/Normal/textmessage.cpp ui/ChatRoom/Messages/GUI/Normal/TextMessage.h ui/ChatRoom/Messages/GUI/Normal/voicemessage.cpp ui/ChatRoom/Messages/GUI/Normal/VoiceMessage.h ui/ChatRoom/Messages/GUI/Normal/waveformslilder.cpp ui/ChatRoom/Messages/GUI/Normal/waveformslilder.h ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.cpp ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.h ui/ChatRoom/Messages/GUI/Reply/replydocumentmessage.ui ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.cpp ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.h ui/ChatRoom/Messages/GUI/Reply/replyimagemessage.ui ui/ChatRoom/Messages/GUI/Reply/replytextmessage.cpp ui/ChatRoom/Messages/GUI/Reply/replytextmessage.h ui/ChatRoom/Messages/GUI/Reply/replytextmessage.ui ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.cpp ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.h ui/ChatRoom/Messages/GUI/Reply/replyvoicemessage.ui ui/ChatRoom/Messages/GUI/container.cpp ui/ChatRoom/Messages/GUI/container.h ui/ChatRoom/Messages/GUI/container.ui ui/ChatRoom/Messages/GUI/message.cpp ui/ChatRoom/Messages/GUI/message.h ui/ChatRoom/Messages/GUI/messagereceived.cpp ui/ChatRoom/Messages/GUI/messagereceived.h ui/ChatRoom/Messages/GUI/messagesent.cpp ui/ChatRoom/Messages/GUI/messagesent.h ui/ChatRoom/chatroom.cpp ui/ChatRoom/ChatRoom.h ui/ChatRoom/chatroom.ui ui/Login/login.cpp ui/Login/login.h ui/Login/login.ui ui/Privacy/PrivacySettings.cpp ui/Privacy/PrivacySettings.h ui/Privacy/PrivacySettings.ui ui/Settings/SocialLinksDialog/sociallinksdialog.cpp ui/Settings/SocialLinksDialog/sociallinksdialog.h ui/Settings/SocialLinksDialog/sociallinksdialog.ui ui/Settings/settings.cpp ui/Settings/settings.h ui/Settings/settings.ui ui/SignUp/signup.cpp ui/SignUp/signup.h ui/SignUp/signup.ui
            ui/Privacy/ContactWidget.cpp
            ui/Privacy/ContactWidget.h
            ui/Privacy/ContactWidget.ui
            ui/AddStoryPage/AddStoryPage.cpp
            ui/AddStoryPage/AddStoryPage.h
            ui/AddStoryPage/addStoryPage.ui
            ui/StatusWindow/StatusWindow.cpp
            ui/StatusWindow/StatusWindow.h
            ui/StatusWindow/StatusWindow.ui
    ${RESOURCE_FILES}
    ui/Search/search.cpp ui/Search/search.h ui/Search/search.ui
    chatcard.cpp chatcard.h chatcard.ui utilities.cpp utilities.h
    mainwindow.cpp mainwindow.h mainwindow.ui




)
# Link Qt libraries
target_link_libraries(ChatApp
    PRIVATE Qt::Core Qt::Widgets
    Qt6::Multimedia
)

# Installation and deployment
include(GNUInstallDirs)

install(TARGETS ChatApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ChatApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
