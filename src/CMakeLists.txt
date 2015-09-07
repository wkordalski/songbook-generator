set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5 REQUIRED COMPONENTS Widgets Sql)

add_executable(cantionale
    main.cpp
    
    model.cpp
    source.cpp

    window.cpp
    sources_list_widget.cpp
    song_widget.cpp
    
    database_source.cpp
)

target_compile_features(cantionale PRIVATE cxx_auto_type)

qt5_use_modules(cantionale Widgets Sql)