cmake_minimum_required(VERSION 4.0.2)
project(TARVB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TARVB
        "respostas/Q4.c"
        estruturas/TLista.c
        estruturas/TLista.h
        respostas/questoes.h
        respostas/Q9.c
        estruturas/hash.c
        estruturas/hash.h
        respostas/Q6.c
        respostas/Q7.c
        main.c
        respostas/Q5.c
        respostas/Q3.c
        respostas/Q3.c
        respostas/Q3.c)
