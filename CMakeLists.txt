project(CLEO4)
cmake_minimum_required(VERSION 3.0)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB PLUGIN_SDK_HEADERS "plugin-sdk/plugin_sa/game_sa/*.h")

set(PLUGIN_SDK_SRC 
  plugin-sdk/plugin_sa/game_sa/CVector.cpp
  plugin-sdk/plugin_sa/game_sa/CRGBA.cpp
  plugin-sdk/plugin_sa/game_sa/CPed.cpp
)

set(CLEO4_SRC
  CLEO4/CCodeInjector.cpp
  CLEO4/CCodeInjector.h
  CLEO4/CCustomOpcodeSystem.cpp
  CLEO4/CCustomOpcodeSystem.h
  CLEO4/CDebug.cpp
  CLEO4/CDebug.h
  CLEO4/CDmaFix.cpp
  CLEO4/CDmaFix.h
  CLEO4/CGameMenu.cpp
  CLEO4/CGameMenu.h
  CLEO4/CGameVersionManager.cpp
  CLEO4/CGameVersionManager.h
  CLEO4/CLegacy.cpp
  CLEO4/CLegacy.h
  CLEO4/cleo.cpp
  CLEO4/cleo.def
  CLEO4/cleo.h
  CLEO4/CLEO.rc
  CLEO4/CPluginSystem.h
  CLEO4/crc32.cpp
  CLEO4/crc32.h
  CLEO4/CScriptEngine.cpp
  CLEO4/CScriptEngine.h
  CLEO4/CSoundSystem.cpp
  CLEO4/CSoundSystem.h
  CLEO4/CTextManager.cpp
  CLEO4/CTextManager.h
  CLEO4/CTheScripts.h
  CLEO4/dllmain.cpp
  CLEO4/FileEnumerator.h
  CLEO4/Mem.h
  CLEO4/resource.h
  CLEO4/stdafx.cpp
  CLEO4/stdafx.h
)

add_library(CLEO4 SHARED ${CLEO4_SRC})
target_compile_definitions(CLEO4 PUBLIC CLEO4_EXPORTS)

add_library(plugin-sdk STATIC ${PLUGIN_SDK_SRC} ${PLUGIN_SDK_HEADERS})
target_link_libraries(CLEO4 plugin-sdk)
target_include_directories(plugin-sdk PUBLIC plugin-sdk/plugin_sa)
target_include_directories(CLEO4 PUBLIC plugin-sdk/plugin_sa)

target_include_directories(CLEO4 PUBLIC .)
target_link_libraries(CLEO4 "${CMAKE_SOURCE_DIR}/bass/bass.lib")

set_target_properties(CLEO4 PROPERTIES PREFIX "")
set_target_properties(CLEO4 PROPERTIES OUTPUT_NAME "CLEO")
set_target_properties(CLEO4 PROPERTIES SUFFIX ".asi")

# Use the Static CRT on Release
if(MSVC)
    foreach(flag_var CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endforeach(flag_var)
    if(NOT CMAKE_CXX_FLAGS_RELEASE MATCHES "/MT")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    endif()
    if(NOT CMAKE_CXX_FLAGS_RELWITHDEBINFO MATCHES "/MT")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")
    endif()
endif(MSVC)

# XP doesn't support thread safe init
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:threadSafeInit-")
endif(MSVC)

# TODO precompiled header