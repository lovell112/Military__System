#include "QuanNhan.h"

class SiQuan : public QuanNhan {
    string chucVu;
    static int soLuong;
    long long luong;
public:
    SiQuan();
    SiQuan(string, string, string, string, string, string, string, string);
    SiQuan(const SiQuan&);
    ~SiQuan();
    void getDonViQuanLy();
    void hienThiThongTin() const;
    void giaoNV(string MSQN, string nhiemVu);
    void kiemTraNVQN(string MSQN);
    long long getLuong() const;
    string getTrachNhiem() override;
    void updateChucVu(string);
    void updateLuong();
    string getLoai() override;

    friend istream& operator>>(istream&, SiQuan&);
    friend ostream& operator<<(ostream&, SiQuan);
};
