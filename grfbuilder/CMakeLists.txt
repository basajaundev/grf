cmake_minimum_required(VERSION 2.8.12)
project(grfbuilder CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED QtCore QtGui)

add_executable(${PROJECT_NAME} MainWindow.cpp main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} grf_static Qt4::QtCore Qt4::QtGui)
