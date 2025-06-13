cmake_minimum_required(VERSION 3.16)

project(Observer_Behavioral LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Observer_Behavioral main.cpp
    observer.cpp
    observer.h)

include(GNUInstallDirs)
install(TARGETS Observer_Behavioral
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
