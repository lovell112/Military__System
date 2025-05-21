cmake_minimum_required(VERSION 3.10)
project(Military_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Military_System
        main.cpp
        QuanNhan.cpp
        SiQuan.cpp
        BinhSi.cpp
        DanhSachQuanNhan.cpp
        QuanLiQuanDoi.cpp
)