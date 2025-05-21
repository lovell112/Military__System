#ifndef SIQUAN_H
#define SIQUAN_H

#include "QuanNhan.h"
using namespace std;

class SiQuan : public QuanNhan {
    vector<string> donViQuanLy;
    string chucVu;
    static int soLuong;
public:
    SiQuan();
    SiQuan(string ms, string ht, CapBac cb, string dv, string qq, string ns, string nnn, vector<string> dvql);
    SiQuan(const SiQuan& q);
    ~SiQuan();

    void setCapBac(CapBac capBac) override;

    vector<string> getDonViQuanLy() const;
    void giaoNV(string MSQN, string nhiemVu);
    void hienThiThongTin() const override;
    void kiemTraNVQN(string MSQN);

    friend istream& operator>>(istream&, SiQuan&);
    friend ostream& operator<<(ostream&, const SiQuan&);

};

#endif // SIQUAN_H
