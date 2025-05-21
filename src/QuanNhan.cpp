#include "QuanNhan.h"
#include <sstream>
// ===== HÀM CHUYỂN ĐỔI ENUM <-> STRING =====
CapBac chuyenCapBac(const string& s) {
    if (s == "BINH_NHI") return BINH_NHI;
    if (s == "BINH_NHAT") return BINH_NHAT;
    if (s == "HA_SI") return HA_SI;
    if (s == "TRUNG_SI") return TRUNG_SI;
    if (s == "THUONG_SI") return THUONG_SI;
    if (s == "THIEU_UY") return THIEU_UY;
    if (s == "TRUNG_UY") return TRUNG_UY;
    if (s == "THUONG_UY") return THUONG_UY;
    if (s == "DAI_UY") return DAI_UY;
    if (s == "THIEU_TA") return THIEU_TA;
    if (s == "TRUNG_TA") return TRUNG_TA;
    if (s == "THUONG_TA") return THUONG_TA;
    if (s == "DAI_TA") return DAI_TA;
    return KHAC;
}

string capBacToString(CapBac cb) {
    switch (cb) {
        case BINH_NHI: return "Binh Nhi";
        case BINH_NHAT: return "Binh Nhat";
        case HA_SI: return "Ha Si";
        case TRUNG_SI: return "Trung Si";
        case THUONG_SI: return "Thuong Si";
        case THIEU_UY: return "Thieu Uy";
        case TRUNG_UY: return "Trung Uy";
        case THUONG_UY: return "Thuong Uy";
        case DAI_UY: return "Dai Uy";
        case THIEU_TA: return "Thieu Ta";
        case TRUNG_TA: return "Trung Ta";
        case DAI_TA: return "Dai Ta";
        default: return "Khong xac dinh";
    }
}

QuanNhan::QuanNhan()
    : maSo(""), hoTen(""), capBac(CapBac::BINH_NHI), donVi(""), queQuan(""), ngaySinh(""), ngayNhapNgu("") {
}
QuanNhan::QuanNhan(string ms, string ht, CapBac cb, string dv, string qq, string ns, string nnn)
    : maSo(ms), hoTen(ht), capBac(cb), donVi(dv), queQuan(qq), ngaySinh(ns), ngayNhapNgu(nnn) {
}



QuanNhan::QuanNhan(const QuanNhan& qn)
        : hoTen(qn.hoTen) , maSo(qn.maSo), donVi(qn.donVi), queQuan(qn.queQuan), ngaySinh(qn.ngaySinh), ngayNhapNgu(qn.ngayNhapNgu), capBac(qn.capBac), Luong (qn.Luong) {}

QuanNhan::~QuanNhan() {}

void QuanNhan::hienThiThongTin() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Cap bac: " << capBacToString(capBac) << endl;
    cout << "Don vi: " << donVi << endl;
    cout << "Que quan: " << queQuan << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Ngay nhap ngu: " << ngayNhapNgu << endl;
}

string QuanNhan::getMaSo() const { return maSo; }
string QuanNhan::getHoTen() const { return hoTen; }
CapBac QuanNhan::getCapBac() const { return capBac; }
string QuanNhan::getDonVi() const { return donVi; }
string QuanNhan::getQueQuan() const { return queQuan; }
string QuanNhan::getNgaySinh() const { return ngaySinh; }
string QuanNhan::getNgayNhapNgu() const { return ngayNhapNgu; }
int QuanNhan::getLuong() const { return Luong; }

void QuanNhan::setMaSo(string ms) { maSo = ms; }
void QuanNhan::setHoTen(string ht) { hoTen = ht; }
void QuanNhan::setCapBac(CapBac capBac) {
    this->capBac = capBac;
}
void QuanNhan::setDonVi(string dv) { donVi = dv; }
void QuanNhan::setQueQuan(string qq) { queQuan = qq; }
void QuanNhan::setNgaySinh(string ns) { ngaySinh = ns; }
void QuanNhan::setNgayNhapNgu(string nnn) { ngayNhapNgu = nnn;}

void QuanNhan::taoLuong() {
  int LuongCoSo = 2340000;
  switch (capBac) {
    case BINH_NHI: Luong = 3.4 * LuongCoSo; break;
    case BINH_NHAT: Luong = 3.6 * LuongCoSo; break;
    case HA_SI: Luong = 4.2 * LuongCoSo; break;
    case TRUNG_SI: Luong = 4.6 * LuongCoSo; break;
    case THUONG_SI: Luong = 5.0 * LuongCoSo; break;
    case THIEU_UY: Luong = 5.4 * LuongCoSo; break;
    case TRUNG_UY: Luong = 5.6 * LuongCoSo; break;
    case THUONG_UY: Luong = 6.0 * LuongCoSo; break;
    case DAI_UY: Luong = 7.0 * LuongCoSo; break;
    case THIEU_TA: Luong = 7.4 * LuongCoSo; break;
    case TRUNG_TA: Luong = 7.8 * LuongCoSo; break;
    case THUONG_TA: Luong = 9.0 * LuongCoSo; break;
    case DAI_TA: Luong = 10.0 * LuongCoSo; break;
    default: Luong = 0*LuongCoSo; break;
  }
}

istream& operator>>(istream& is, QuanNhan& p) {
    string _capBac;
    getline(is, p.maSo, ',');
    getline(is, p.hoTen, ',');
    getline(is, _capBac, ',');
    p.capBac = chuyenCapBac(_capBac);
    getline(is, p.donVi, ',');
    getline(is, p.queQuan, ',');
    getline(is, p.ngaySinh, ',');
    getline(is, p.ngayNhapNgu, ',');
    return is;
}

ostream& operator<<(ostream& os, const QuanNhan& p) {
    os << p.maSo << ", " << p.hoTen << ", "
       << capBacToString(p.capBac) << ", " << p.donVi << ", "
       << p.queQuan << ", " << p.ngaySinh << ", " << p.ngayNhapNgu;
    return os;
}
