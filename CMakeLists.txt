cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp ZorkUL.h bedroom.cpp bedroom.h  Room.cpp Room.h Parser.cpp Parser.h item.cpp item.h CommandWords.cpp CommandWords.h Command.cpp Command.h Character.cpp Character.h Inventory.cpp Inventory.h ZorkUL.cpp "Date.cpp" "Date.h")