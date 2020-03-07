
include(./config/qtweb.cmake)

# Create a separate init plugin to be loaded before Nodegui loads
set(PLUGIN_ADDON_NAME "nodegui_plugin_webview_init")

project(${PLUGIN_ADDON_NAME})

add_library(${PLUGIN_ADDON_NAME} SHARED  
    "${CMAKE_JS_SRC}"
    "${PROJECT_SOURCE_DIR}/src/cpp/init/init.cpp"
) 
AddNapiSupport(${PLUGIN_ADDON_NAME})
AddQtWebSupport(${PLUGIN_ADDON_NAME})

target_include_directories(${PLUGIN_ADDON_NAME} PRIVATE 
    "${CMAKE_JS_INC}" 
    "${PROJECT_SOURCE_DIR}"
)
target_link_libraries(${PLUGIN_ADDON_NAME} PRIVATE
    "${CMAKE_JS_LIB}"
    Qt5::WebEngine
)
