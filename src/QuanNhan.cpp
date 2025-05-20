#include "QuanNhan.h"

// ===== HÀM CHUYỂN ĐỔI ENUM <-> STRING =====
CapBac chuyenCapBac(const string& s) {
    if (s == "Binh nhi") return BINH_NHI;
    if (s == "Binh nhat") return BINH_NHAT;
    if (s == "Ha si") return HA_SI;
    if (s == "Trung si") return TRUNG_SI;
    if (s == "Thuong si") return THUONG_SI;
    if (s == "Thieu uy") return THIEU_UY;
    if (s == "Trung uy") return TRUNG_UY;
    if (s == "Thuong uy") return THUONG_UY;
    if (s == "Dai uy") return DAI_UY;
    if (s == "Thieu ta") return THIEU_TA;
    if (s == "Trung ta") return TRUNG_TA;
    if (s == "Thuong ta") return THUONG_TA;
    if (s == "Dai ta") return DAI_TA;
    return KHAC;
}

string capBacToString(CapBac cb) {
    switch (cb) {
        case BINH_NHI: return "Binh nhi";
        case BINH_NHAT: return "Binh nhat";
        case HA_SI: return "Ha si";
        case TRUNG_SI: return "Trung si";
        case THUONG_SI: return "Thuong si";
        case THIEU_UY: return "Thieu uy";
        case TRUNG_UY: return "Trung uy";
        case THUONG_UY: return "Thuong uy";
        case DAI_UY: return "Dai uy";
        case THIEU_TA: return "Thieu ta";
        case TRUNG_TA: return "Trung ta";
        case THUONG_TA: return "Thuong ta";
        case DAI_TA: return "Dai ta";
        default: return "Khac";
    }
}
QuanNhan::QuanNhan() {
    maSo = "";
    hoTen = "";
    capBac = KHAC;
    donVi = "";
    ngaySinh = "";
    ngayNhapNgu = "";
}

QuanNhan::QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn)
        : hoTen(ht), donVi(dv), queQuan(qq), maSo(ms), ngaySinh(ns), ngayNhapNgu(nnn) {
            capBac = chuyenCapBac(cb);
            taoLuong();
        }

QuanNhan::QuanNhan(const QuanNhan& qn)
        : hoTen(qn.hoTen) , maSo(qn.maSo), donVi(qn.donVi), queQuan(qn.queQuan), ngaySinh(qn.ngaySinh), ngayNhapNgu(qn.ngayNhapNgu), capBac(qn.capBac), Luong (qn.Luong) {}

QuanNhan::~QuanNhan() {}

void QuanNhan::hienThiThongTin() const{
    cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
    cout << "Cap bac: " << capBacToString(capBac) << ", Don vi: " << donVi << endl;
    cout << "Que quan: " << queQuan << ", ngay sinh: " << ngaySinh << endl;
    cout << "Ngay nhap ngu: " << ngayNhapNgu << endl;
}

string QuanNhan::getMaSo() const { return maSo; }
string QuanNhan::getHoTen() const { return hoTen; }
CapBac QuanNhan::getCapBac() const { return capBac; }
string QuanNhan::getDonVi() const { return donVi; }
string QuanNhan::getQueQuan() const { return queQuan; }
string QuanNhan::getNgaySinh() const { return ngaySinh; }
string QuanNhan::getNgayNhapNgu() const { return ngayNhapNgu; }
vector<string> QuanNhan::getDSNhiemVu() const { return DSNhiemVu; }

void QuanNhan::setMaSo(string ms) { maSo = ms; }
void QuanNhan::setHoTen(string ht) { hoTen = ht; }
void QuanNhan::setCapBac(string cb) { capBac = chuyenCapBac(cb);}
void QuanNhan::setDonVi(string dv) { donVi = dv; }
void QuanNhan::setQueQuan(string qq) { queQuan = qq; }
void QuanNhan::setNgaySinh(string ns) { ngaySinh = ns; }
void QuanNhan::setNgayNhapNgu(string nnn) { ngayNhapNgu = nnn;}
void QuanNhan::themNhiemVu(string NV) {DSNhiemVu.push_back(NV);}
void QuanNhan::xoaNhiemVu(string NV) {
      int j = 0;
      for (string x : DSNhiemVu) {
        if (x == NV) {
          DSNhiemVu.erase(DSNhiemVu.begin() + j);
        }
        j++;
      }
 }

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

istream& operator>>(istream& is , QuanNhan& p){
   string temp;
   is >> p.maSo >> p.hoTen >> temp >> p.donVi >> p.queQuan >> p.ngaySinh >> p.ngayNhapNgu;
   p.capBac = chuyenCapBac(temp);
   return is;
}
ostream& operator<<(ostream& out , const QuanNhan& p) {
    out << "Ma so: " << p.maSo << ", Ho ten: " << p.hoTen << endl;
    out << "Cap bac: " << capBacToString(p.capBac) << ", Don vi: " << p.donVi << endl;
    out << "Que quan: " << p.queQuan << ", ngay sinh: " << p.ngaySinh << endl;
    out << "Ngay nhap ngu: " << p.ngayNhapNgu << endl;
    return out;
}