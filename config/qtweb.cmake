function(AddQtWebSupport addonName)

    # execute_process(COMMAND node -p "require('@nodegui/qode').qtHome"
    #     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    #     OUTPUT_VARIABLE QT_HOME_DIR
    # )
    # set(QT_HOME_DIR "/Users/atulr/Tools/qt/5.13.0/clang_642")
    
    if(DEFINED ENV{QT_INSTALL_DIR})
        # Allows to use custom Qt installation via QT_INSTALL_DIR env variable
        message(STATUS "Using Custom QT installation for ${addonName} QT_INSTALL_DIR:$ENV{QT_INSTALL_DIR}")
        set(QT_HOME_DIR "$ENV{QT_INSTALL_DIR}")
    endif()
   
    string(REPLACE "\n" "" QT_HOME_DIR "${QT_HOME_DIR}")
    string(REPLACE "\"" "" QT_HOME_DIR "${QT_HOME_DIR}")
    
    if (APPLE) 
        target_include_directories(${addonName} PRIVATE
            "${QT_HOME_DIR}/include"
            "${QT_HOME_DIR}/lib/QtWebEngineWidgets.framework/Versions/5/Headers"
            "${QT_HOME_DIR}/lib/QtWebEngine.framework/Versions/5/Headers"
        )
        target_link_libraries(${addonName} PRIVATE
            "${QT_HOME_DIR}/lib/QtWebEngineWidgets.framework/Versions/5/QtWebEngineWidgets"
            "${QT_HOME_DIR}/lib/QtWebEngine.framework/Versions/5/QtWebEngine"
        )
    endif()

    if (WIN32)       
        target_include_directories(${addonName} PRIVATE
            "${QT_HOME_DIR}\\include"
            "${QT_HOME_DIR}\\include\\QtWebEngineWidgets"
            "${QT_HOME_DIR}\\include\\QtWebEngine"
        )
        target_link_libraries(${addonName} PRIVATE
            "${QT_HOME_DIR}\\lib\\QtWebEngineWidgets.lib"
            "${QT_HOME_DIR}\\lib\\QtWebEngine.lib"
        )
    endif()

    if(UNIX AND NOT APPLE)
        set(LINUX TRUE)
    endif()

    if(LINUX)
        target_include_directories(${addonName} PRIVATE
            "${QT_HOME_DIR}/include"
            "${QT_HOME_DIR}/include/QtWebEngine"
            "${QT_HOME_DIR}/include/QtWebEngineWidgets"
        )
        target_link_libraries(${addonName} PRIVATE
            "${QT_HOME_DIR}/lib/QtWebEngine.so"
            "${QT_HOME_DIR}/lib/QtWebEngineWidgets.so"
        )
    endif()    

  
endfunction(AddQtWebSupport addonName)
