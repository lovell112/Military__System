#include "QuanNhan.h"

class SiQuan : public QuanNhan {
    DanhSachQuanNhan donViQuanLy;
    string chucVu;
    static int soLuong;
    long long luong;
    public:
    SiQuan();
    SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn,DanhSachQuanNhan dvql);
    SiQuan(const SiQuan& q);
    ~SiQuan();
    void getDonViQuanLy();
    void hienThiThongTin() const;
    void giaoNV(string MSQN, string nhiemVu);
    void kiemTraNVQN(string MSQN);
    long long getLuong();
    string getChucVu();
    void updateChucVu(string);
    void updateLuong();

    friend istream& operator>>(istream&, SiQuan&);
    friend ostream& operator<<(ostream&, SiQuan);
};