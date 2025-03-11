cmake_minimum_required(VERSION 3.30)
project(JNI_LIB)

set(CMAKE_CXX_STANDARD 17)

add_library(JNI_LIB SHARED UnsafeObjectModify.cpp
        UnsafeObjectRead.cpp)
include_directories($ENV{JAVA_HOME}/include)
if(UNIX)
    message("current platform: Linux")
    include_directories($ENV{JAVA_HOME}/include/linux)
elseif(WIN32)
    message("current platform: windows")
    include_directories($ENV{JAVA_HOME}/include/win32)
else()
    message("current platform: unkonw")
endif()
