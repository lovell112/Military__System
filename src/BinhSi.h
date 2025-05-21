#ifndef BINHSI_H
#define BINHSI_H
#include "QuanNhan.h"


class BinhSi: public QuanNhan {
    static int soLuong;
    vector<string> DSNhiemVu;
    public:

    BinhSi();
    BinhSi(string ms, string ht, CapBac cb, string dv, string qq, string ns, string nnn, vector<string> DSNV);
    BinhSi(const BinhSi&);
    ~BinhSi();
    void setCapBac(CapBac capBac) override;

    void themNhiemVu(const string& nv);
    void xoaNhiemVu(const string& nv);
    void hienThiThongTin() const override;
    vector<string> getDSNhiemVu() const;
    long long troCapXuatNgu() const;


    friend istream& operator>>(istream&, BinhSi&);
    friend ostream& operator<<(istream&, const BinhSi&);

};
#endif // BINHSI_H