include("E:/Projects/qtesting/ChatApp/cmake-build-debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/ChatApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE E:/Projects/qtesting/ChatApp/cmake-build-debug/ChatApp.exe
    GENERATE_QT_CONF
)
