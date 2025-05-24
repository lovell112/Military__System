#include "QuanLiQuanDoi.h"

void menu() {
    QuanLiQuanDoi ql;

    int luaChon;
    do {
        cout << "\n===== MENU QUAN LY QUAN NHAN =====\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them quan nhan\n";
        cout << "3. Sua thong tin\n";
        cout << "4. Xoa quan nhan\n";
        cout << "5. Thong ke Si Quan\n";
        cout << "6. Thong ke Binh Si\n";
        cout << "7. Thong ke theo cap bac\n";
        cout << "8. Tinh ngan sach toi thieu\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1:
                for (auto& qn : ql.danhSach)
                    qn->hienThiThongTin();
                break;
            case 2: {
                string ms, ht, cb, dv, qq, ns, nnn, trach;
                cout << "Nhap ma so: "; getline(cin, ms);
                cout << "Nhap ho ten: "; getline(cin, ht);
                cout << "Nhap cap bac: "; getline(cin, cb);
                cout << "Nhap don vi: "; getline(cin, dv);
                cout << "Nhap que quan: "; getline(cin, qq);
                cout << "Nhap ngay sinh: "; getline(cin, ns);
                cout << "Nhap ngay nhap ngu: "; getline(cin, nnn);
                cout << "Nhap chuc vu hoac nhiem vu: "; getline(cin, trach);
                ql.them(ms, ht, cb, dv, qq, ns, nnn, trach);
                break;
            }
            case 3: {
                string maso;
                cout << "Nhap ma so can sua: ";
                getline(cin, maso);
                ql.sua(maso);
                break;
            }
            case 4: {
                string maso;
                cout << "Nhap ma so can xoa: ";
                getline(cin, maso);
                ql.xoa(maso);
                break;
            }
            case 5:
                cout << "So luong Si Quan: " << ql.thongKeSiQuan() << endl;
                break;
            case 6:
                cout << "So luong Binh Si: " << ql.thongKeBinhSi() << endl;
                break;
            case 7: {
                string capBac;
                cout << "Nhap cap bac can thong ke: ";
                getline(cin, capBac);
                cout << "So luong cap bac \"" << capBac << "\": " << ql.thongKeCapBac(capBac) << endl;
                break;
            }
            case 8:
                cout << "Ngan sach toi thieu: " << ql.NganSachToiThieu() << " VND\n";
                break;
            case 0:
                cout << "Dang thoat...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Thu lai.\n";
        }
    } while (luaChon != 0);
}

int main() {
    menu();
    return 0;
}
