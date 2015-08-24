set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(cantionale main.cpp)
qt5_use_modules(cantionale Widgets)
