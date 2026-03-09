add_executable(app
        main.cpp
)

target_link_libraries(app PRIVATE FileSystem)

target_include_directories(app PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)