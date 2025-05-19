#include "BinhSi.h"

bool BinhSi::baoCaoNV() {
    return tinhTrangNV;
}

void BinhSi::hienThiThongTin() const {
    cout << "--------Binh Si--------" << endl;
    QuanNhan::hienThiThongTin();
    cout << "-----------------------" << endl;
}