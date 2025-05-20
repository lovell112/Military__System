#include "BinhSi.h"

BinhSi::BinhSi() : QuanNhan(), tinhTrangNV(false) {
    soLuong++;
}

BinhSi::BinhSi(string ms, string ht, string cb, string dv, string qq, string ns, string nnn, string nv )
    : QuanNhan(ms, ht, cb, dv, qq, ns, nnn), nhiemVu(nv), tinhTrangNV(false) {
        soLuong++;
    }

BinhSi::BinhSi(const BinhSi& b) : QuanNhan(b), tinhTrangNV(b.tinhTrangNV) {
    soLuong++;
}

BinhSi::~BinhSi() {
    soLuong--;
}

int BinhSi::soLuong = 0;

bool BinhSi::baoCaoNV() {
    return tinhTrangNV;
}

string BinhSi::getLoai() {
    return "Binh Si";
}

string BinhSi::getTrachNhiem() {return nhiemVu;}

void BinhSi::hienThiThongTin() const {
    cout << "--------Binh Si--------" << endl;
    QuanNhan::hienThiThongTin();
    cout << "-----------------------" << endl;
}