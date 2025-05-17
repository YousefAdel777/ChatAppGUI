include("C:/Users/Dell/Desktop/chat-2/ChatAppGUI/cmake-build-debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/ChatApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/Dell/Desktop/chat-2/ChatAppGUI/cmake-build-debug/ChatApp.exe
    GENERATE_QT_CONF
)
