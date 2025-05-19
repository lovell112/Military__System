#include "SiQuan.h"

SiQuan::SiQuan(): QuanNhan(), donViQuanLy(NULL) {}
SiQuan::SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn,DanhSachQuanNhan dvql)
    : QuanNhan(), donViQuanLy(dvql) {}
SiQuan::SiQuan(const SiQuan& q): QuanNhan(q), donViQuanLy(q.donViQuanLy) {}

SiQuan::~SiQuan() {}

void SiQuan::getDonViQuanLy() {
    if (donViQuanLy != NULL) {
        cout << "Si Quan khong quan ly don vi nao" << endl;
        return;
    }
    cout << donViQuanLy.getTenDonVI() << endl;
}

void SiQuan::hienThiThongTin() const {
    cout << "---Thong Tin Si Quan---" << endl;
    cout << "DonViQuanLy: " << donViQuanLy.getTenDonVi() << endl;
    QuanNhan::hienThiThongTin();
    cout << "-----------------------" << endl;
}

void SiQuan::giaoNV(string MSQN, string nhiemVu) {
    bool flag = false;
    for (QuanNhan qn : donViQuanLy) {
        if (qn.getMaSo() == MSQN) {
            flag = true;
            if (maHoaCapBac() <= qn.maHoaCapBac()) {
                cout << "Ban khong co quyen ra lenh cho cap tren" << endl;
                return;
            }
            qn.setNhiemVu(nhiemVu);
        }
        cout << "Da giao nhiem vu cho binh si " << qn.getMaSo() <<'.' << endl;
    }
    if (!flag) {
        cout << "Si Quan khong co quyen giao nhiem vu cho quan nhan nay" << endl;
    }
}

void SiQuan::kiemTraNVQN(string MSQN) {
    bool flag = false;
    for (QuanNhan qn : donViQuanLy) {
        if (qn.getMaSo() == MSQN) {
            flag = true;
            for (string NV : qn.getDSNhiemVu()) {
                cout << NV << ": ";
                if (qn.baoCaoNhiemVu()) cout << "Da hoan thanh" << endl;
                else cout << "chua hoan thanh" << endl;
            }
        }
        cout << "Da giao nhiem vu cho quan nhan " << qn.getMaSo() <<'.' << endl;
    }
    if (!flag) {
        cout << "Si Quan khong co quyen kiem tra nhiem vu cua quan Nhan nay" << endl;
    }
}