#include "SiQuan.h"

SiQuan::SiQuan(): QuanNhan(), chucVu(""), luong(0) {soLuong++;}
SiQuan::SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn, string cv )
    : QuanNhan(ms, ht, cb, dv, qq, ns, nnn), chucVu(cv)  {
        soLuong++;
        updateLuong();
    }
SiQuan::SiQuan(const SiQuan& q): QuanNhan(q), chucVu(q.chucVu), luong(q.luong) {soLuong++;}

SiQuan::~SiQuan() {soLuong--;}
int SiQuan::soLuong = 0;

string SiQuan::getLoai() {
    return "Si Quan";
}

void SiQuan::updateChucVu(string cv) {
    chucVu = cv;
    updateLuong();
}

void SiQuan::updateLuong() {
    if (chucVu == "Dai tuong") luong = 24336000;
    else if (chucVu == "Thuong tuong") luong = 22932000;
    else if (chucVu == "Trung tuong") luong = 21528000;
    else if (chucVu == "Thieu tuong") luong = 20124000;
    else if (chucVu == "Dai ta") luong = 18720000;
    else if (chucVu == "Thuong ta") luong = 17082000;
    else if (chucVu == "Trung ta") luong = 15444000;
    else if (chucVu == "Thieu ta") luong = 14040000;
    else if (chucVu == "Dai uy") luong = 12636000;
    else if (chucVu == "Thuong uy") luong = 11700000;
    else if (chucVu == "Trung uy") luong = 10764000;
    else if (chucVu == "Thieu uy") luong = 9828000;
    else luong = 0; // Trường hợp không khớp cấp bậc
}

void SiQuan::hienThiThongTin() const {
    cout << "--------Si Quan--------" << endl;
    QuanNhan::hienThiThongTin();
    cout << "Chuc vu: " << chucVu << endl;
    cout << "Luong: " << luong << endl;
    cout << "-----------------------" << endl;
}

string SiQuan::getTrachNhiem() {return chucVu;}

// void SiQuan::getDonViQuanLy() {
//     if (donViQuanLy != NULL) {
//         cout << "Si Quan khong quan ly don vi nao" << endl;
//         return;
//     }
//     cout << donViQuanLy.getTenDonVI() << endl;
// }

// void SiQuan::hienThiThongTin() const {
//     cout << "---Thong Tin Si Quan---" << endl;
//     cout << "DonViQuanLy: " << donViQuanLy.getTenDonVi() << endl;
//     QuanNhan::hienThiThongTin();
//     cout << "-----------------------" << endl;
// }

// void SiQuan::giaoNV(string MSQN, string nhiemVu) {
//     bool flag = false;
//     for (QuanNhan qn : donViQuanLy) {
//         if (qn.getMaSo() == MSQN) {
//             flag = true;
//             if (maHoaCapBac() <= qn.maHoaCapBac()) {
//                 cout << "Ban khong co quyen ra lenh cho cap tren" << endl;
//                 return;
//             }
//             qn.setNhiemVu(nhiemVu);
//         }
//         cout << "Da giao nhiem vu cho binh si " << qn.getMaSo() <<'.' << endl;
//     }
//     if (!flag) {
//         cout << "Si Quan khong co quyen giao nhiem vu cho quan nhan nay" << endl;
//     }
// }

// void SiQuan::kiemTraNVQN(string MSQN) {
//     bool flag = false;
//     for (QuanNhan qn : donViQuanLy) {
//         if (qn.getMaSo() == MSQN) {
//             flag = true;
//             for (string NV : qn.getDSNhiemVu()) {
//                 cout << NV << ": ";
//                 if (qn.baoCaoNhiemVu()) cout << "Da hoan thanh" << endl;
//                 else cout << "chua hoan thanh" << endl;
//             }
//         }
//         cout << "Da giao nhiem vu cho quan nhan " << qn.getMaSo() <<'.' << endl;
//     }
//     if (!flag) {
//         cout << "Si Quan khong co quyen kiem tra nhiem vu cua quan Nhan nay" << endl;
//     }
// }

long long SiQuan::getLuong() const {return luong;}