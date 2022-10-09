cmake_minimum_required(VERSION 3.23)
project(CPP_ATM_MACHINE)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CPP_ATM_MACHINE
        src/main.cpp src/bankAccount.h src/transaction.h src/date.h)
