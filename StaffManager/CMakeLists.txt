cmake_minimum_required(VERSION 3.16)

project(StaffManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Widgets Sql QUIET)
if (NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Core Widgets Sql)
endif()

set(PROJECT_SOURCES
    main.cpp
    staffmanager.h
    staffmanager.cpp
    employeeeditor.h
    employeeeditor.cpp
)

add_executable(StaffManager ${PROJECT_SOURCES})

if (Qt6_FOUND)
    target_link_libraries(StaffManager PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)
else()
    target_link_libraries(StaffManager PRIVATE Qt5::Core Qt5::Widgets Qt5::Sql)
endif()

# Copy SQL file to build directory
configure_file(create_tables_staffmanager.sql create_tables_staffmanager.sql COPYONLY)
