#include "SiQuan.h"
#include "BinhSi.h"

class QuanLiQuanDoi {
    long long nganSachToiThieu;
    public:
    vector<QuanNhan*> danhSach;
    QuanLiQuanDoi();
    ~QuanLiQuanDoi();

    // reading data from solider__list.txt
    void docDuLieuTuFile();

    // update data in solider__list.txt after edit danhSach
    void capNhatDuLieu();

    // add a new solider
    void them(string, string, string, string, string, string, string, string);

    // delete a solider
    void xoa(string);

    int timKiem(string);
    // return number of rank
    int thongKeCapBac(string);

    // treturn number of SiQuan
    int thongKeSiQuan();

    // return number of BinhSi
    int thongKeBinhSi();

    // return budget
    long long getNganSach();
};