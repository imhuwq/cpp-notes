cmake_minimum_required(VERSION 3.8)
project(cpp_notes)

set(CMAKE_CXX_STANDARD 11)

set(NOTE_SOURCES "")
file(GLOB_RECURSE NOTE_SOURCES notes/note_*.cpp)
message(STATUS ${NOTE_SOURCES})

foreach (note_src ${NOTE_SOURCES})
    get_filename_component(note_name ${note_src} NAME_WE)
    add_executable(${note_name} ${note_src})
endforeach ()
