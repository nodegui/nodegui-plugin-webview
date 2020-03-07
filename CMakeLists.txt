cmake_minimum_required(VERSION 3.1)
# -------------- Plugin Config ---------------
execute_process(COMMAND node -p "require('@nodegui/nodegui/plugin').CMAKE_HELPER_FILE"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE NODEGUI_PLUGIN_CMAKE_HELPER
)
string(REPLACE "\n" "" NODEGUI_PLUGIN_CMAKE_HELPER ${NODEGUI_PLUGIN_CMAKE_HELPER})
string(REPLACE "\"" "" NODEGUI_PLUGIN_CMAKE_HELPER ${NODEGUI_PLUGIN_CMAKE_HELPER})

include("${NODEGUI_PLUGIN_CMAKE_HELPER}")
include(./config/init.cmake)

# -------------- User Config ---------------
set(PLUGIN_ADDON_NAME "nodegui_plugin_webview")

project(${PLUGIN_ADDON_NAME})

add_library(${PLUGIN_ADDON_NAME} SHARED  
    "${CMAKE_JS_SRC}"
    "${PROJECT_SOURCE_DIR}/src/cpp/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QWebEngineView/qwebengineview_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QWebEngineView/nwebengineview.hpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QWebEngineSettings/qwebenginesettings_wrap.cpp"
) 

AddPluginConfig(${PLUGIN_ADDON_NAME})
AddQtWebSupport(${PLUGIN_ADDON_NAME})

target_include_directories(${PLUGIN_ADDON_NAME} PRIVATE 
    "${CMAKE_JS_INC}" 
    "${PROJECT_SOURCE_DIR}"
)
target_link_libraries(${PLUGIN_ADDON_NAME} PRIVATE
    "${CMAKE_JS_LIB}"
    Qt5::WebEngineCore 
    Qt5::WebEngineWidgets
)

