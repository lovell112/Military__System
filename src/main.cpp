#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "QuanNhan.h"
#include "BinhSi.h"
#include "SiQuan.h"
#include "DanhSachQuanNhan.h"

using namespace std;

void inDuongKe() {
    cout << "---------------------------------------------\n";
}

void pauseScreen() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    // Khoi tao danh sach quan nhan
    DanhSachQuanNhan ds;
    ds.setTenDanhSach("Danh sach quan nhan");

    // Ten file input va output
    string fileInput = "input.txt";
    string fileOutput = "output.txt";

    int luaChon;
    do {
        system("cls"); // Xoa man hinh (Windows)

        cout << "\n========== HE THONG QUAN LY QUAN NHAN ==========\n";
        cout << "1. Doc danh sach tu file input.txt\n";
        cout << "2. Them quan nhan moi\n";
        cout << "3. Hien thi toan bo danh sach\n";
        cout << "4. Tim kiem quan nhan theo ma so\n";
        cout << "5. Xoa quan nhan theo ma so\n";
        cout << "6. Hien thi danh sach binh si\n";
        cout << "7. Hien thi danh sach si quan\n";
        cout << "8. Ghi danh sach vao file output.txt\n";
        cout << "0. Thoat chuong trinh\n";
        inDuongKe();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        // Xu ly lua chon
        switch(luaChon) {
            case 1: {
                // Doc du lieu tu file input.txt
                cout << "\nDang doc du lieu tu file " << fileInput << "...\n";
                bool ketQua = ds.docFile(fileInput);
                if (ketQua) {
                    cout << "Doc file thanh cong!\n";
                    cout << "So luong quan nhan: " << ds.getSoLuongHienTai() << "\n";
                } else {
                    cout << "Khong the mo file! Vui long kiem tra lai.\n";
                }
                pauseScreen();
                break;
            }

            case 2: {
                // Them quan nhan moi
                cout << "\n--- THEM QUAN NHAN MOI ---\n";
                cout << "Ban muon them: (B) Binh si hay (S) Si quan? ";
                char loai;
                cin >> loai;
                cin.ignore();

                if (loai == 'B' || loai == 'b') {
                    // Them binh si
                    BinhSi* bs = new BinhSi();
                    cout << "Nhap thong tin binh si:\n";
                    cin >> *bs; // Sử dụng toán tử nhập
                    ds.themQuanNhan(bs);
                    cout << "Da them binh si thanh cong!\n";
                }
                else if (loai == 'S' || loai == 's') {
                    // Them si quan
                    SiQuan* sq = new SiQuan();
                    cout << "Nhap thong tin si quan:\n";
                    cin >> *sq; // Sử dụng toán tử nhập
                    ds.themQuanNhan(sq);
                    cout << "Da them si quan thanh cong!\n";
                }
                else {
                    cout << "Lua chon khong hop le! Chi chap nhan 'B' hoac 'S'.\n";
                }
                pauseScreen();
                break;
            }

            case 3: {
                // Hien thi toan bo danh sach
                cout << "\n=== DANH SACH QUAN NHAN ===\n";
                if (ds.getSoLuongHienTai() == 0) {
                    cout << "Danh sach trong!\n";
                } else {
                    ds.hienThiDanhSach();
                }
                pauseScreen();
                break;
            }

            case 4: {
                // Tim kiem quan nhan theo ma so
                cout << "\n--- TIM KIEM QUAN NHAN ---\n";
                string maTimKiem;
                cout << "Nhap ma so can tim: ";
                getline(cin, maTimKiem);

                QuanNhan* qn = ds.getQuanNhan(maTimKiem);
                if (qn) {
                    cout << "Tim thay quan nhan!\n";
                    inDuongKe();
                    cout << *qn;
                } else {
                    cout << "Khong tim thay quan nhan co ma so " << maTimKiem << "!\n";
                }
                pauseScreen();
                break;
            }

            case 5: {
                // Xoa quan nhan theo ma so
                cout << "\n--- XOA QUAN NHAN ---\n";
                string maXoa;
                cout << "Nhap ma so quan nhan can xoa: ";
                getline(cin, maXoa);

                bool ketQua = ds.xoaQuanNhan(maXoa);
                if (ketQua) {
                    cout << "Da xoa quan nhan co ma so " << maXoa << " thanh cong!\n";
                } else {
                    cout << "Khong tim thay quan nhan co ma so " << maXoa << "!\n";
                }
                pauseScreen();
                break;
            }

            case 6: {
                // Hien thi danh sach binh si
                cout << "\n=== DANH SACH BINH SI ===\n";
                vector<BinhSi*> dsBinhSi = ds.getDanhSachBinhSi();

                if (dsBinhSi.empty()) {
                    cout << "Khong co binh si nao trong danh sach!\n";
                } else {
                    cout << "So luong binh si: " << ds.demSoBinhSi() << "\n";
                    inDuongKe();

                    for (size_t i = 0; i < dsBinhSi.size(); i++) {
                        cout << "Binh si thu " << (i+1) << ":\n";
                        cout << *dsBinhSi[i];
                        inDuongKe();
                    }
                }
                pauseScreen();
                break;
            }

            case 7: {
                // Hien thi danh sach si quan
                cout << "\n=== DANH SACH SI QUAN ===\n";
                vector<SiQuan*> dsSiQuan = ds.getDanhSachSiQuan();

                if (dsSiQuan.empty()) {
                    cout << "Khong co si quan nao trong danh sach!\n";
                } else {
                    cout << "So luong si quan: " << ds.demSoSiQuan() << "\n";
                    inDuongKe();

                    for (size_t i = 0; i < dsSiQuan.size(); i++) {
                        cout << "Si quan thu " << (i+1) << ":\n";
                        cout << *dsSiQuan[i];
                        inDuongKe();
                    }
                }
                pauseScreen();
                break;
            }

            case 8: {
                // Ghi danh sach vao file output.txt
                cout << "\nDang ghi danh sach vao file " << fileOutput << "...\n";
                bool ketQua = ds.ghiFile(fileOutput);
                if (ketQua) {
                    cout << "Ghi file thanh cong!\n";
                } else {
                    cout << "Khong the mo file! Vui long kiem tra lai.\n";
                }
                pauseScreen();
                break;
            }

            case 0:
                cout << "\nKet thuc chuong trinh. Tam biet!\n";
                break;

            default:
                cout << "\nLua chon khong hop le. Vui long thu lai!\n";
                pauseScreen();
        }

    } while (luaChon != 0);

    return 0;
}