#pragma once
#include "QuanNhan.h"
using namespace std;

class QuanLiQuanDoi {
    vector<QuanNhan*> danhSach;
    long long nganSachToiThieu;
    public:
    QuanLiQuanDoi();
    ~QuanLiQuanDoi();
    vector<QuanNhan*> getDanhsach();

    void docFile();
    void ghiFile();

    void them();

    void xoa(string);

    int thongKeCapBac(string);

    int thongKeSiQuan();
    int thongKeBinhSi();

    long long getNganSach();
};