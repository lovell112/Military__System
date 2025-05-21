#include "BinhSi.h"



// Constructor
BinhSi::BinhSi()
    : QuanNhan() {
    setCapBac(CapBac::BINH_NHI); // Đặt giá trị mặc định là cấp bậc binh sĩ thấp nhất
    DSNhiemVu = {};
}
BinhSi::BinhSi(string ms, string ht, CapBac cb, string dv, string qq, string ns, string nnn, vector<string> DSNV)
    : QuanNhan(ms, ht, cb, dv, qq, ns, nnn), DSNhiemVu(DSNV) {
    setCapBac(cb); // Gọi lại setCapBac để đảm bảo giới hạn cấp bậc
}
BinhSi::BinhSi(const BinhSi& b) : QuanNhan(b), DSNhiemVu(b.DSNhiemVu) {}
BinhSi::~BinhSi() {}

vector<string> BinhSi::getDSNhiemVu() const {
    return DSNhiemVu;
}
void BinhSi::setCapBac(CapBac capBac) {
    // Kiểm tra nếu là cấp bậc binh sĩ
    if (capBac >= CapBac::BINH_NHI && capBac <= CapBac::TRUNG_SI) {
        this->capBac = capBac;
    } else {
        // Nếu không phải cấp bậc binh sĩ, mặc định là Binh nhì
        this->capBac = CapBac::BINH_NHI;
    }
}

void BinhSi::themNhiemVu(const string& nv){
  	DSNhiemVu.push_back(nv);
}

void BinhSi::xoaNhiemVu(const string& nv){
    DSNhiemVu.erase(
        remove(DSNhiemVu.begin(), DSNhiemVu.end(), nv),
        DSNhiemVu.end()
    );
}

void BinhSi::hienThiThongTin() const {
    QuanNhan::hienThiThongTin();

    // Hiển thị danh sách nhiệm vụ
    cout << "Danh sach nhiem vu: ";
    if (DSNhiemVu.empty()) {
        cout << "Khong co" << endl;
    } else {
        for (size_t i = 0; i < DSNhiemVu.size(); i++) {
            cout << DSNhiemVu[i];
            if (i < DSNhiemVu.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

istream& operator>>(istream& is, BinhSi& p) {
    is >> dynamic_cast<QuanNhan&>(p);

    p.DSNhiemVu.clear();

    string temp;

    if (is.peek() == ',') {
        is.ignore();
    }

    while (getline(is, temp, ',')) {
        size_t pos = temp.find(';');
        if (pos != string::npos) {
            string value = temp.substr(0, pos);
            if (!value.empty()) {
                p.DSNhiemVu.push_back(value);
            }
            break;
        }

        if (!temp.empty()) {
            p.DSNhiemVu.push_back(temp);
        }
    }

    return is;
}

ostream& operator<<(ostream& os, const BinhSi& b) {
    os << "--------Binh Si--------" << endl;
    os << dynamic_cast<const QuanNhan&>(b);
    os << "Nhiem vu: ";
    vector<string> nhiemVu = b.getDSNhiemVu();
    for (size_t i = 0; i < nhiemVu.size(); ++i) {
        os << ", " << nhiemVu[i];
    }
    os << "-----------------------" << endl;

    return os;
}