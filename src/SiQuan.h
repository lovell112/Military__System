#include "QuanNhan.h"

class SiQuan : public QuanNhan {
    DSQN donViQuanLy;
    static int soLuong;
    public:
    SiQuan();
    SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn,DSQN dvql);
    SiQuan(const SiQuan& q);
    ~SiQuan();
    void getDonViQuanLy();
    void hienThiThongTin() const;
    void giaoNV(string MSQN, string nhiemVu);
    void kiemTraNVQN(string MSQN);
    friend istream& operator>>(istream&, SiQuan&);
    friend ostream& operator<<(ostream&, const SiQuan&);
};