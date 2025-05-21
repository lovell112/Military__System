#pragma once
#ifndef QUANLIQUANDOI_H
#define QUANLIQUANDOI_H
#include "DanhSachQuanNhan.h"
using namespace std;

class QuanLiQuanDoi {
    DanhSachQuanNhan DANHSACH;
    long long nganSachToiThieu;
    public:
    QuanLiQuanDoi();
    ~QuanLiQuanDoi();
    DanhSachQuanNhan getDS() const;
    int thongKeCapBac(string);
    int thongKeSiQuan();
    int thongKeBinhSi();
    long long getNganSachToiThieu();
};
#endif
