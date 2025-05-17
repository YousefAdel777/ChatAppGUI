include("C:/Users/Dell/Desktop/chat-2/ChatAppGUI/build/Desktop_Qt_6_9_0_MinGW_64_bit-RelWithDebInfo/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/ChatApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/Dell/Desktop/chat-2/ChatAppGUI/build/Desktop_Qt_6_9_0_MinGW_64_bit-RelWithDebInfo/ChatApp.exe
    GENERATE_QT_CONF
)
