cmake_minimum_required(VERSION 4.2)
project(TARVB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TARVB
        "gabarito/Q4.c"
        estruturas/TLista.c
        estruturas/TLista.h
        gabarito/resposta.h
        gabarito/Q9.c
        estruturas/hash.c
        estruturas/hash.h
        gabarito/Q6.c
        gabarito/Q7.c
        main.c
        gabarito/Q5.c
        gabarito/Q3.c)
