cmake_minimum_required (VERSION 2.8.11)
project (BasicShell)

add_executable(main main.c execute.c builtinsfunc.c arguments.c)