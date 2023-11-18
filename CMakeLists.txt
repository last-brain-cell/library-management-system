cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled main.c
        headers/library.h
        headers/logsystem.h
        Auxilary_Files/library.c
        Auxilary_Files/logsystem.c
        headers/login.h
        Auxilary_Files/login.c
)
