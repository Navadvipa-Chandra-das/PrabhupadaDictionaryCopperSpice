# Install script for directory: D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Bin")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Build/bin/PrabhupadaDictionary.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Build/src/CMakeFiles/PrabhupadaDictionary.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/ShrilaPrabhupada.jpg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Sanskrit.db")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/m_LanguageVector.ini")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/Start.bat")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/PrabhupadaPrimer.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/PrabhupadaLila.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Letter.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Help.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gtb.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gti.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gtr.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary_CS-CZ.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary_EN-US.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary_ES-ES.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary_PT-BR.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary_RU-RU.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsCore1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsGui1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsNetwork1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsOpenGL1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsScript1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsSql1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsSvg1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsXml1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsXmlPatterns1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "D:/CopperSpice/Release/Lib/bin/CsMultimedia1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./platforms" TYPE FILE FILES "D:/CopperSpice/Release/Lib/lib/CsGuiWin1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./mediaservices" TYPE FILE FILES "D:/CopperSpice/Release/Lib/lib/CsMultimedia_DirectShow1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./playlistformats" TYPE FILE FILES "D:/CopperSpice/Release/Lib/lib/CsMultimedia_m3u1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./sqldrivers" TYPE FILE FILES "D:/CopperSpice/Release/Lib/lib/CsSqlPsql1.9.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources" TYPE FILE FILES "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source/src/../resources/PrabhupadaDictionary.ico")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Build/src/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
