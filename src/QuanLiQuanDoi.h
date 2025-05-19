#include "SiQuan.h"
#include "BinhSi.h"

class QuanLiQuanDoi {
    vector<QuanNhan*> danhSach;
    long long nganSachToiThieu;
public:
    QuanLiQuanDoi();
    ~QuanLiQuanDoi();

    // reading data from solider__list.txt
    void docDuLieuTuFile();

    // update data in solider__list.txt after edit danhSach
    void capNhatDuLieu();

    // add a new solider
    void them();

    // delete a solider
    void xoa(string);

    // return number of rank
    int thongKeCapBac(string);

    // treturn number of SiQuan
    int thongKeSiQuan();

    // return number of BinhSi
    int thongKeBinhSi();

    // return budget
    long long getNganSach();
};