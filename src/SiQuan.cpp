#include "SiQuan.h"
#include <sstream>


// Constructor
SiQuan::SiQuan()
    : QuanNhan() {
    setCapBac(CapBac::THIEU_UY);
    donViQuanLy = {};
}
SiQuan::SiQuan(string ms, string ht, CapBac cb, string dv, string qq, string ns, string nnn, vector<string> dvql)
    : QuanNhan(ms, ht, cb, dv, qq, ns, nnn), donViQuanLy(dvql) {
    setCapBac(cb);
}

SiQuan::SiQuan(const SiQuan& q): QuanNhan(q) {
    donViQuanLy = q.donViQuanLy;
}

SiQuan::~SiQuan() {}

void SiQuan::setCapBac(CapBac capBac) {
    if (capBac >= CapBac::THIEU_UY && capBac <= CapBac::DAI_TA) {
        this->capBac = capBac;
    } else {
        this->capBac = CapBac::BINH_NHI;
    }
}

vector<string> SiQuan::getDonViQuanLy() const{
   return donViQuanLy;
}

void SiQuan::hienThiThongTin() const {
    QuanNhan::hienThiThongTin();

    cout << "Danh sach don vi quan ly: ";
    if (donViQuanLy.empty()) {
        cout << "Khong co" << endl;
    } else {
        for (size_t i = 0; i < donViQuanLy.size(); i++) {
            cout << donViQuanLy[i];
            if (i < donViQuanLy.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

istream& operator>>(istream& is, SiQuan& p) {
    is >> dynamic_cast<QuanNhan&>(p);

    p.donViQuanLy.clear();

    string temp;

    if (is.peek() == ',') {
        is.ignore();
    }

    while (getline(is, temp, ',')) {
        size_t pos = temp.find(';');
        if (pos != string::npos) {
            string value = temp.substr(0, pos);
            if (!value.empty()) {
                p.donViQuanLy.push_back(value);
            }
            break;
        }

        if (!temp.empty()) {
            p.donViQuanLy.push_back(temp);
        }
    }

    return is;
}

ostream& operator<<(ostream& out, const SiQuan& p) {
    out << "S ";
    out << p.maSo << "," << p.hoTen << ","
        << capBacToString(p.capBac) << "," << p.donVi << ","
        << p.queQuan << "," << p.ngaySinh << "," << p.ngayNhapNgu;

    for (size_t i = 0; i < p.donViQuanLy.size(); i++) {
        out << ", " << p.donViQuanLy[i];
    }

    out << ";";
    return out;
}
