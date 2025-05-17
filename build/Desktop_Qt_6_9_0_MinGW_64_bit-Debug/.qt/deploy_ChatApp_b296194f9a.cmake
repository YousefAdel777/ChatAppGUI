include("E:/Projects/qtesting/ChatApp/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/ChatApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE E:/Projects/qtesting/ChatApp/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/ChatApp.exe
    GENERATE_QT_CONF
)
