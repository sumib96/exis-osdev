CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Exis)

FILE(GLOB C_SRCS Kernel.c)

ADD_EXECUTABLE(Kernel ${C_SRCS})