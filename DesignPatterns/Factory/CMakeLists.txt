cmake_minimum_required(VERSION 3.16)

project(Factory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Factory main.cpp
    factory.h
    factory.cpp)

include(GNUInstallDirs)
install(TARGETS Factory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
