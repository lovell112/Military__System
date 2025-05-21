#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== ENUM CẤP BẬC =====
enum CapBac {
    BINH_NHI, BINH_NHAT, HA_SI, TRUNG_SI, THUONG_SI,
    THIEU_UY, TRUNG_UY, THUONG_UY, DAI_UY,
    THIEU_TA, TRUNG_TA, THUONG_TA, DAI_TA,
    KHAC
};
CapBac chuyenCapBac(const string& s);
string capBacToString(CapBac cb) ;

class QuanNhan {
protected:
    string maSo, hoTen, donVi, queQuan, ngaySinh, ngayNhapNgu;
    CapBac capBac;
    vector<string> DSNhiemVu;
    int Luong;
public:

    QuanNhan();

    QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn);
 
    QuanNhan(const QuanNhan& qn);

    virtual ~QuanNhan();

//     Get
    string getMaSo() const;
    string getHoTen() const;
    string getDonVi() const;
    string getQueQuan() const;
    string getNgaySinh() const;
    string getNgayNhapNgu() const;
	CapBac getCapBac() const;
    int getLuong() const;
//    Set
    vector<string> getDSNhiemVu() const;
    void setMaSo(string ms);
    void setHoTen(string ht);
    void setCapBac(string cb);
    void setDonVi(string dv);
    void setQueQuan(string qq);
    void setNgaySinh(string ns);
    void setNgayNhapNgu(string nnn);
    void setLuong(int luong);
    void getQuanNhan(string);
//    Hàm mặc định
    void taoLuong();
    void themNhiemVu(string NV);
    void xoaNhiemVu(string NV);

//     Hàm ảo
    virtual void thangCap();
    virtual bool baoCaoNV(string NV);
    virtual void hienThiThongTin() const;
    friend istream& operator>>(istream&, QuanNhan&);
    friend ostream& operator<<(ostream&, const QuanNhan&);
};