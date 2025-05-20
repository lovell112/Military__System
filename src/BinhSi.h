#include "QuanNhan.h"


class BinhSi: public QuanNhan {
    bool tinhTrangNV;
    string nhiemVu;
    static int soLuong;
    public:
    // default constructor
    BinhSi();
    // construtor
    BinhSi(string, string, string, string, string, string, string, string);
    // copy constructor
    BinhSi(const BinhSi&);

    ~BinhSi();
    void hienThiThongTin() const;
    bool baoCaoNV();
    long long troCapXuatNgu();
    string getLoai() override;
    string getTrachNhiem() override;

    friend istream& operator>>(istream&, BinhSi&);
    friend ostream& operator<<(istream&, BinhSi);
};