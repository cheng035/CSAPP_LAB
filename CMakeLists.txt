cmake_minimum_required(VERSION 3.16.3)
project(CSAPP_LAB C)

set(CMAKE_C_STANDARD 11)

include_directories(datalab-handout)

add_executable(CSAPP_LAB
        datalab-handout/bits.c
        datalab-handout/bits.h
        datalab-handout/btest.c
        datalab-handout/btest.h
        datalab-handout/decl.c
        datalab-handout/fshow.c
        datalab-handout/ishow.c
        datalab-handout/tests.c)
