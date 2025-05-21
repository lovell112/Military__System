#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// Danh sách họ phổ biến ở Việt Nam (không dấu)
vector<string> danhSachHo = {
    "Nguyen", "Tran", "Le", "Pham", "Hoang", "Huynh", "Vu", "Vo", "Phan", "Truong",
    "Bui", "Dang", "Do", "Ngo", "Ho", "Duong", "Dinh", "Trinh", "Lam", "Mai"
};

// Danh sách tên đệm và tên chính cho nam (không dấu)
vector<string> danhSachTenDemNam = {
    "Van", "Duc", "Quoc", "Minh", "Quang", "The", "Tien", "Dinh", "Huu", "Cong",
    "Thanh", "Manh", "Trung", "Tuan", "Hong", "Xuan", "Ba", "Duy", "Anh", "Tung"
};

vector<string> danhSachTenNam = {
    "Hung", "Huy", "Phong", "Tuan", "Dat", "Son", "Anh", "Thang", "Dung", "Quan",
    "Vinh", "Khoa", "Long", "Cuong", "Khanh", "Duong", "Quang", "Hieu", "Tung", "Thanh"
};

// Danh sách đơn vị
vector<string> danhSachDonVi = {
    "Su doan 1", "Su doan 2", "Su doan 3", "Trung doan 5", "Trung doan 7",
    "Tieu doan 15", "Tieu doan 22", "Tieu doan 30", "Dai doi 45", "Dai doi 50"
};

// Danh sách quê quán (không dấu)
vector<string> danhSachQueQuan = {
    "Ha Noi", "TP.HCM", "Da Nang", "Hai Phong", "Can Tho", "Hue",
    "Nha Trang", "Vung Tau", "Buon Ma Thuot", "Phu Quoc", "Quy Nhon"
};

// Danh sách cấp bậc
vector<string> danhSachCapBacSQ = {
    "THIEU_UY", "TRUNG_UY", "THUONG_UY", "DAI_UY",
    "THIEU_TA", "TRUNG_TA", "THUONG_TA", "DAI_TA"
};

vector<string> danhSachCapBacBS = {
    "BINH_NHI", "BINH_NHAT", "HA_SI", "TRUNG_SI", "THUONG_SI"
};

// Danh sách đơn vị quản lý
vector<string> danhSachDonViQuanLy = {
    "Tieu doi 1", "Tieu doi 2", "Tieu doi 3", "Tieu doi 4", "Tieu doi 5",
    "Dai doi 1", "Dai doi 2", "Dai doi 3", "Dai doi 4", "Dai doi 5"
};

// Danh sách nhiệm vụ
vector<string> danhSachNhiemVu = {
    "Tuan tra", "Bao ve kho", "Truc ban", "Canh gac", "Bao ve bien gioi",
    "Kiem tra hanh chinh", "Huan luyen tan binh", "Van chuyen vat tu", "Bao ve lanh dao"
};

// Hàm tạo mã số quân nhân ngẫu nhiên
string taoMaSoNgauNhien(int index) {
    return string("QN") + (index < 10 ? "00" : (index < 100 ? "0" : "")) + to_string(index);
}

// Hàm tạo tên ngẫu nhiên
string taoTenNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> disHo(0, danhSachHo.size() - 1);
    uniform_int_distribution<> disTenDem(0, danhSachTenDemNam.size() - 1);
    uniform_int_distribution<> disTen(0, danhSachTenNam.size() - 1);

    return danhSachHo[disHo(gen)] + " " + danhSachTenDemNam[disTenDem(gen)] + " " + danhSachTenNam[disTen(gen)];
}

// Hàm tạo đơn vị ngẫu nhiên
string taoDonViNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, danhSachDonVi.size() - 1);

    return danhSachDonVi[dis(gen)];
}

// Hàm tạo quê quán ngẫu nhiên
string taoQueQuanNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, danhSachQueQuan.size() - 1);

    return danhSachQueQuan[dis(gen)];
}

// Hàm tạo ngày tháng ngẫu nhiên
string taoNgayThangNgauNhien(int minYear, int maxYear) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> disDay(1, 28);
    uniform_int_distribution<> disMonth(1, 12);
    uniform_int_distribution<> disYear(minYear, maxYear);

    int day = disDay(gen);
    int month = disMonth(gen);
    int year = disYear(gen);

    return (day < 10 ? "0" : "") + to_string(day) + "/" +
           (month < 10 ? "0" : "") + to_string(month) + "/" +
           to_string(year);
}

// Hàm tạo cấp bậc ngẫu nhiên cho sĩ quan
string taoCapBacSQNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, danhSachCapBacSQ.size() - 1);

    return danhSachCapBacSQ[dis(gen)];
}

// Hàm tạo cấp bậc ngẫu nhiên cho binh sĩ
string taoCapBacBSNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, danhSachCapBacBS.size() - 1);

    return danhSachCapBacBS[dis(gen)];
}

// Hàm tạo các đơn vị quản lý ngẫu nhiên cho sĩ quan
vector<string> taoDonViQuanLyNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> disCount(1, 3);
    uniform_int_distribution<> disUnit(0, danhSachDonViQuanLy.size() - 1);

    int count = disCount(gen);
    vector<string> result;
    for (int i = 0; i < count; i++) {
        result.push_back(danhSachDonViQuanLy[disUnit(gen)]);
    }

    return result;
}

// Hàm tạo các nhiệm vụ ngẫu nhiên cho binh sĩ
vector<string> taoNhiemVuNgauNhien() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> disCount(1, 3);
    uniform_int_distribution<> disTask(0, danhSachNhiemVu.size() - 1);

    int count = disCount(gen);
    vector<string> result;
    for (int i = 0; i < count; i++) {
        result.push_back(danhSachNhiemVu[disTask(gen)]);
    }

    return result;
}

int main() {
    int soLuongBinhSi, soLuongSiQuan;
    string tenFile;

    cout << "=== TAO DU LIEU NGAU NHIEN CHO HE THONG QUAN LY QUAN NHAN ===" << endl;
    cout << "Nhap ten file can tao: ";
    getline(cin, tenFile);

    cout << "Nhap so luong binh si: ";
    cin >> soLuongBinhSi;

    cout << "Nhap so luong si quan: ";
    cin >> soLuongSiQuan;

    ofstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Khong the mo file de ghi!" << endl;
        return 1;
    }

    int totalIndex = 1;

    // Tạo dữ liệu cho sĩ quan
    for (int i = 0; i < soLuongSiQuan; i++, totalIndex++) {
        file << "S ";
        file << taoMaSoNgauNhien(totalIndex) << ",";
        file << taoTenNgauNhien() << ",";
        file << taoCapBacSQNgauNhien() << ",";
        file << taoDonViNgauNhien() << ",";
        file << taoQueQuanNgauNhien() << ",";
        file << taoNgayThangNgauNhien(1970, 1990) << ",";  // Ngày sinh
        file << taoNgayThangNgauNhien(1990, 2010);          // Ngày nhập ngũ

        // Thêm đơn vị quản lý
        vector<string> donViQuanLy = taoDonViQuanLyNgauNhien();
        for (const auto& dv : donViQuanLy) {
            file << "," << dv;
        }

        file << ";" << endl;
    }

    // Tạo dữ liệu cho binh sĩ
    for (int i = 0; i < soLuongBinhSi; i++, totalIndex++) {
        file << "B ";
        file << taoMaSoNgauNhien(totalIndex) << ",";
        file << taoTenNgauNhien() << ",";
        file << taoCapBacBSNgauNhien() << ",";
        file << taoDonViNgauNhien() << ",";
        file << taoQueQuanNgauNhien() << ",";
        file << taoNgayThangNgauNhien(1980, 2000) << ",";  // Ngày sinh
        file << taoNgayThangNgauNhien(2000, 2023);         // Ngày nhập ngũ

        // Thêm nhiệm vụ
        vector<string> nhiemVu = taoNhiemVuNgauNhien();
        for (const auto& nv : nhiemVu) {
            file << "," << nv;
        }

        file << ";" << endl;
    }

    file.close();
    cout << "Da tao file " << tenFile << " thanh cong voi "
         << soLuongBinhSi << " binh si va "
         << soLuongSiQuan << " si quan." << endl;
    
    return 0;
}