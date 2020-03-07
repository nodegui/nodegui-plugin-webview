macro(AddQtWebSupport addonName)
    
    execute_process(COMMAND node -p "require('@nodegui/nodegui/config/qtConfig.js').qtCmakeDir"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE QT_CMAKE_HOME_DIR
    )

    string(REPLACE "\n" "" QT_CMAKE_HOME_DIR "${QT_CMAKE_HOME_DIR}")
    string(REPLACE "\"" "" QT_CMAKE_HOME_DIR "${QT_CMAKE_HOME_DIR}")

    message(STATUS "Using QT installation for ${addonName} QT_CMAKE_HOME_DIR:${QT_CMAKE_HOME_DIR}")

    set(Qt5_DIR ${QT_CMAKE_HOME_DIR}) 
    find_package(Qt5 REQUIRED COMPONENTS WebEngine WebEngineCore WebEngineWidgets)
    
endmacro(AddQtWebSupport addonName)
