#include "QuanNhan.h"

QuanNhan::QuanNhan() {
    maSo = "";
    hoTen = "";
    capBac = "";
    donVi = "";
    ngaySinh = "";
    ngayNhapNgu = "";
}

QuanNhan::QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn)
        : hoTen(ht), capBac(cb), donVi(dv), queQuan(qq), maSo(ms), ngaySinh(ns), ngayNhapNgu(nnn) {}

QuanNhan::QuanNhan(const QuanNhan& qn) {}

QuanNhan::~QuanNhan() {}

void QuanNhan::hienThiThongTin() const {
    cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
    cout << "Cap bac: " << getCapBac() << ", Don vi: " << donVi << endl;
    cout << "Que quan: " << queQuan << ", ngay sinh: " << ngaySinh << endl;
    cout << "Ngay nhap ngu: " << ngayNhapNgu << endl;
}

string QuanNhan::getMaSo() const { return maSo; }
string QuanNhan::getHoTen() const { return hoTen; }
string QuanNhan::getCapBac() const { return capBac; }
string QuanNhan::getDonVi() const { return donVi; }
string QuanNhan::getQueQuan() const { return queQuan; }
string QuanNhan::getNgaySinh() const { return ngaySinh; }
string QuanNhan::getNgayNhapNgu() const { return ngayNhapNgu; }
vector<string> QuanNhan::getDSNhiemVu() const { return DSNhiemVu; }

void QuanNhan::setMaSo(string ms) { maSo = ms; }
void QuanNhan::setHoTen(string ht) { hoTen = ht; }
void QuanNhan::setCapBac(string cb) { capBac = cb; }
void QuanNhan::setDonVi(string dv) { donVi = dv; }
void QuanNhan::setQueQuan(string qq) { queQuan = qq; }
void QuanNhan::setNgaySinh(string ns) { ngaySinh = ns; }
void QuanNhan::setNgayNhapNgu(string nnn) { ngayNhapNgu = nnn; }
void QuanNhan::setNhiemVu(string NV) {DSNhiemVu.push_back(NV);}


int QuanNhan::maHoaCapBac() {
    if (capBac == "Binh nhi") return 1;
    if (capBac == "Binh nhat") return 2;
    if (capBac == "Ha si") return 3;
    if (capBac == "Trung si") return 4;
    if (capBac == "Thuong si") return 5;
    if (capBac == "Thieu uy") return 6;
    if (capBac == "Trung uy") return 7;
    if (capBac == "Thuong uy") return 8;
    if (capBac == "Dai uy") return 9;
    if (capBac == "Thieu ta") return 10;
    if (capBac == "Trung ta") return 11;
    if (capBac == "Thuong ta") return 12;
    if (capBac == "Dai ta") return 13;
    if (capBac == "Thieu tuong") return 14;
    if (capBac == "Trung tuong") return 15;
    if (capBac == "Thuong tuong") return 16;
    if (capBac == "Dai tuong") return 17;
    return 0;
}