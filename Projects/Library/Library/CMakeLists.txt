cmake_minimum_required(VERSION 3.16)

project(Library LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Library main.cpp
    library.h
    library.cpp)

include(GNUInstallDirs)
install(TARGETS Library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
