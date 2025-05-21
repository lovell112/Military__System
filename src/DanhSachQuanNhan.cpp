#include "DanhSachQuanNhan.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Constructor mặc định
DanhSachQuanNhan::DanhSachQuanNhan() : tenDanhSach("Danh sach quan nhan") {}

// Constructor với tham số
DanhSachQuanNhan::DanhSachQuanNhan(const string& ten, int maxSize) : tenDanhSach(ten) {}

// Copy constructor
DanhSachQuanNhan::DanhSachQuanNhan(const DanhSachQuanNhan& other) {
    tenDanhSach = other.tenDanhSach;
    // Deep copy các quân nhân
    for (auto qn : other.danhSach) {
        if (dynamic_cast<SiQuan*>(qn)) {
            danhSach.push_back(new SiQuan(*dynamic_cast<SiQuan*>(qn)));
        } else if (dynamic_cast<BinhSi*>(qn)) {
            danhSach.push_back(new BinhSi(*dynamic_cast<BinhSi*>(qn)));
        }
    }
}

// Destructor
DanhSachQuanNhan::~DanhSachQuanNhan() {
    for (auto qn : danhSach) {
        delete qn;
    }
    danhSach.clear();
}

bool DanhSachQuanNhan::docFile(const string& tenFile)  {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file " << tenFile << endl;
        return false;
    }

    // Xóa dữ liệu cũ
    for (auto qn : danhSach) {
        delete qn;
    }
    danhSach.clear();

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        char loai;
        iss >> loai;

        // Bỏ qua khoảng trắng sau loại
        if (iss.peek() == ' ') {
            iss.ignore();
        }

        QuanNhan* qn = nullptr;

        try {
            if (loai == 'S') {
                SiQuan* sq = new SiQuan();
                iss >> *sq;
                qn = sq;

            } else if (loai == 'B') {
                BinhSi* bs = new BinhSi();
                iss >> *bs;
                qn = bs;
            } else {
                cout << "Loai quan nhan khong hop le: " << loai << endl;
                continue;
            }

            danhSach.push_back(qn);
        } catch (const exception& e) {
            cout << "Loi khi doc quan nhan: " << e.what() << endl;
            delete qn;
        }
    }

    file.close();
    cout << "Da doc " << danhSach.size() << " quan nhan tu file." << endl;
    return true;
}

bool DanhSachQuanNhan::ghiFile(const string& tenFile) const {
    ofstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file " << tenFile << " de ghi." << endl;
        return false;
    }

    for (const auto& qn : danhSach) {
        SiQuan* sq = dynamic_cast<SiQuan*>(qn);
        BinhSi* bs = dynamic_cast<BinhSi*>(qn);

        if (sq) {
            file << "S," << sq->getMaSo() << "," << sq->getHoTen() << ","
                 << capBacToString(sq->getCapBac()) << "," << sq->getDonVi() << ","
                 << sq->getQueQuan() << "," << sq->getNgaySinh() << ","
                 << sq->getNgayNhapNgu();

            const vector<string>& dvql = sq->getDonViQuanLy();
            for (const auto& dv : dvql) {
                file << "," << dv;
            }
            file << endl;
        }
        else if (bs) {
            file << "B," << bs->getMaSo() << "," << bs->getHoTen() << ","
                 << capBacToString(bs->getCapBac()) << "," << bs->getDonVi() << ","
                 << bs->getQueQuan() << "," << bs->getNgaySinh() << ","
                 << bs->getNgayNhapNgu();

            const vector<string>& dsnv = bs->getDSNhiemVu();
            for (const auto& nv : dsnv) {
                file << "," << nv;
            }
            file << endl;
        }
    }

    file.close();
    cout << "Da ghi " << danhSach.size() << " quan nhan ra file." << endl;

    return true;
}

void DanhSachQuanNhan::themQuanNhan(QuanNhan* quanNhan) {
    danhSach.push_back(quanNhan);
}

bool DanhSachQuanNhan::xoaQuanNhan(const string& maSo) {
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if ((*it)->getMaSo() == maSo) {
            delete *it;
            danhSach.erase(it);
            return true;
        }
    }
    return false;
}

QuanNhan* DanhSachQuanNhan::getQuanNhan(const string& maSo) const {
    for (auto qn : danhSach) {
        if (qn->getMaSo() == maSo) {
            return qn;
        }
    }
    return nullptr;
}

vector<BinhSi*> DanhSachQuanNhan::layDanhSachBinhSi() const {
    vector<BinhSi*> dsBinhSi;
    for (auto qn : danhSach) {
        if (BinhSi* bs = dynamic_cast<BinhSi*>(qn)) {
            dsBinhSi.push_back(bs);
        }
    }
    return dsBinhSi;
}

vector<SiQuan*> DanhSachQuanNhan::layDanhSachSiQuan() const {
    vector<SiQuan*> dsSiQuan;
    for (auto qn : danhSach) {
        if (SiQuan* sq = dynamic_cast<SiQuan*>(qn)) {
            dsSiQuan.push_back(sq);
        }
    }
    return dsSiQuan;
}

int DanhSachQuanNhan::demSoBinhSi() const {
    int count = 0;
    for (auto qn : danhSach) {
        if (dynamic_cast<BinhSi*>(qn)) {
            count++;
        }
    }
    return count;
}

int DanhSachQuanNhan::demSoSiQuan() const {
    int count = 0;
    for (auto qn : danhSach) {
        if (dynamic_cast<SiQuan*>(qn)) {
            count++;
        }
    }
    return count;
}

string DanhSachQuanNhan::getTenDanhSach() const {
    return tenDanhSach;
}

void DanhSachQuanNhan::setTenDanhSach(const string& ten) {
    tenDanhSach = ten;
}

// Hàm hiển thị bảng thông tin chung
void printTableHeader() {
    cout << "+" << string(12, '-') << "+" << string(25, '-') << "+"
         << string(15, '-') << "+" << string(20, '-') << "+"
         << string(15, '-') << "+" << string(12, '-') << "+"
         << string(15, '-') << "+" << endl;

    cout << "| " << left << setw(10) << "Ma so" << " | "
         << setw(23) << "Ho ten" << " | "
         << setw(13) << "Cap bac" << " | "
         << setw(18) << "Don vi" << " | "
         << setw(13) << "Que quan" << " | "
         << setw(10) << "Ngay sinh" << " | "
         << setw(13) << "Nhap ngu" << " |" << endl;

    cout << "+" << string(12, '-') << "+" << string(25, '-') << "+"
         << string(15, '-') << "+" << string(20, '-') << "+"
         << string(15, '-') << "+" << string(12, '-') << "+"
         << string(15, '-') << "+" << endl;
}

// Hàm hiển thị dòng trong bảng
void printTableRow(const QuanNhan* qn) {
    cout << "| " << left << setw(10) << qn->getMaSo() << " | "
         << setw(23) << qn->getHoTen() << " | "
         << setw(13) << capBacToString(qn->getCapBac()) << " | "
         << setw(18) << qn->getDonVi() << " | "
         << setw(13) << qn->getQueQuan() << " | "
         << setw(10) << qn->getNgaySinh() << " | "
         << setw(13) << qn->getNgayNhapNgu() << " |" << endl;
}

// Hàm hiển thị footer của bảng
void printTableFooter() {
    cout << "+" << string(12, '-') << "+" << string(25, '-') << "+"
         << string(15, '-') << "+" << string(20, '-') << "+"
         << string(15, '-') << "+" << string(12, '-') << "+"
         << string(15, '-') << "+" << endl;
}

// Hàm hiển thị thông tin chi tiết của Sĩ quan
void hienThiChiTietSiQuan(const SiQuan* sq) {
    cout << "Don vi quan ly: ";
    vector<string> donViQuanLy = sq->getDonViQuanLy();
    if (donViQuanLy.empty()) {
        cout << "Khong co";
    } else {
        for (size_t i = 0; i < donViQuanLy.size(); ++i) {
            if (i > 0) cout << " / ";
            cout << donViQuanLy[i];
        }
    }
    cout << endl << endl;
}

// Hàm hiển thị thông tin chi tiết của Binh sĩ
void hienThiChiTietBinhSi(const BinhSi* bs) {
    cout << "Nhiem vu: ";
    vector<string> nhiemVu = bs->getDSNhiemVu();
    if (nhiemVu.empty()) {
        cout << "Khong co";
    } else {
        for (size_t i = 0; i < nhiemVu.size(); ++i) {
            if (i > 0) cout << " / ";
            cout << nhiemVu[i];
        }
    }
    cout << endl << endl;
}

void DanhSachQuanNhan::hienThiDanhSach() const {
    if (danhSach.empty()) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    cout << "Danh sach quan nhan (" << danhSach.size() << " nguoi):" << endl;
    for (size_t i = 0; i < danhSach.size(); i++) {
        cout << "Quan nhan #" << i+1 << ":" << endl;

        QuanNhan* qn = danhSach[i];
        if (!qn) {
            cout << "  Loi: Quan nhan NULL!" << endl;
            continue;
        }

        // Sử dụng cơ chế đa hình - gọi hienThiThongTin() của lớp tương ứng
        qn->hienThiThongTin();

        // Hiển thị thông tin bổ sung dựa trên loại quân nhân
        SiQuan* sq = dynamic_cast<SiQuan*>(qn);
        BinhSi* bs = dynamic_cast<BinhSi*>(qn);

        if (sq) {
            const vector<string>& dvql = sq->getDonViQuanLy();
            cout << "Danh sach don vi quan ly (" << dvql.size() << "): ";
            for (size_t j = 0; j < dvql.size(); j++) {
                cout << dvql[j];
                if (j < dvql.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        else if (bs) {
            const vector<string>& dsnv = bs->getDSNhiemVu();
            cout << "Danh sach nhiem vu (" << dsnv.size() << "): ";
            for (size_t j = 0; j < dsnv.size(); j++) {
                cout << dsnv[j];
                if (j < dsnv.size() - 1) cout << ", ";
            }
            cout << endl;
        }

        cout << endl;
    }
}

int DanhSachQuanNhan::getSoLuongToiDa() const {
    return danhSach.capacity();
}

void DanhSachQuanNhan::setSoLuongToiDa(int max) {
    danhSach.reserve(max);
}

int DanhSachQuanNhan::getSoLuongHienTai() const {
    return danhSach.size();
}

QuanNhan& DanhSachQuanNhan::operator[](int index) {
    if (index < 0 || index >= danhSach.size()) {
        throw out_of_range("Chi so nam ngoai pham vi cua danh sach");
    }
    return *danhSach[index];
}

ostream& operator<<(ostream& os, const DanhSachQuanNhan& ds) {
    os << "Danh sach " << ds.tenDanhSach << endl;
    os << "So luong quan nhan: " << ds.danhSach.size() << endl;

    for (auto qn : ds.danhSach) {
        if (SiQuan* sq = dynamic_cast<SiQuan*>(qn)) {
            os << *sq << endl;
        } else if (BinhSi* bs = dynamic_cast<BinhSi*>(qn)) {
            os << *bs << endl;
        }
    }

    return os;
}

istream& operator>>(istream& is, DanhSachQuanNhan& ds) {
    string loai;
    while (is >> loai) {
        if (loai == "S") {
            SiQuan* sq = new SiQuan();
            is >> *sq;
            ds.danhSach.push_back(sq);
        } else if (loai == "B") {
            BinhSi* bs = new BinhSi();
            is >> *bs;
            ds.danhSach.push_back(bs);
        }
    }
    return is;
}