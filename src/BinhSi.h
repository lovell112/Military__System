#include "QuanNhan.h"


class BinhSi: public QuanNhan {
    bool tinhTrangNV;
    static int soLuong;
    public:
    // default constructor
    BinhSi();
    // construtor
    BinhSi(string, string, string, string, string, string, string, string);
    // copy constructor
    BinhSi(const BinhSi&);
    void hienThiThongTin() const;
    bool baoCaoNV();
    long long troCapXuatNgu();

    friend istream& operator>>(istream&, BinhSi&);
    friend ostream& operator<<(istream&, BinhSi);
};