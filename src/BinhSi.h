#include "QuanNhan.h"


class BinhSi: public QuanNhan {
    static int soLuong;
    public:
    BinhSi();
    BinhSi(string, string, string, string, string, string, string);
    BinhSi(const BinhSi&);
    bool baoCaoNV(string NV);
    void hienThiThongTin() const;
    long long troCapXuatNgu();
    friend istream& operator>>(istream&, BinhSi&);
    friend ostream& operator<<(istream&, const BinhSi&);
};