cmake_minimum_required(VERSION 3.14)
project(BlackJack C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(BlackJack
        core/Blackjack.c
        include/Card.c
        include/Card.h
        include/Player.c
        include/Player.h)
