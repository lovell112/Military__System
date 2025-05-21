#include "BinhSi.h"
BinhSi::BinhSi(string, string, string, string, string, string, string) : QuanNhan(){}
bool BinhSi::baoCaoNV(string NV){
    string tinhTrangNV;
    for(string nv : DSNhiemVu) {
        cout << "Ban da hoan thanh nhiem vu " << nv << " chua: ";
        cin >> tinhTrangNV;
        if (tinhTrangNV == "HoanThanh") {
          return true;
        }
        else if (tinhTrangNV == "ChuaHoanThanh") {
          return false;
        }
    }
}
void BinhSi::hienThiThongTin() const {
    cout << "--------Binh Si--------" << endl;
    QuanNhan::hienThiThongTin();
    cout << "-----------------------" << endl;
}