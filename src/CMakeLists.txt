add_library(FileSystem
        core/FileSystemService.cpp
        core/PathUtils.cpp
        core/CommandParser.cpp
        commands/BasicCommands.cpp
        commands/FileCommands.cpp
        commands/FindCommands.cpp)

target_include_directories(FileSystem PUBLIC ${CMAKE_SOURCE_DIR}/include/core)
target_include_directories(FileSystem PUBLIC ${CMAKE_SOURCE_DIR}/include/commands)