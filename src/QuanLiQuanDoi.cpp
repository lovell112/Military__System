#include "QuanLiQuanDoi.h"
#include <iostream>

// Constructor
QuanLiQuanDoi::QuanLiQuanDoi() {
    // Sử dụng constructor mặc định cho DANHSACH
    nganSachToiThieu = 0;
}

// Destructor
QuanLiQuanDoi::~QuanLiQuanDoi() {
    // Không cần làm gì đặc biệt vì DanhSachQuanNhan sẽ tự giải phóng bộ nhớ
}

// Trả về danh sách quân nhân
DanhSachQuanNhan QuanLiQuanDoi::getDS() const {
    return DANHSACH;
}

// Thống kê số lượng quân nhân theo cấp bậc
int QuanLiQuanDoi::thongKeCapBac(string capBac) {
    int count = 0;
    int soLuong = DANHSACH.getSoLuongHienTai();

    for (int i = 0; i < soLuong; i++) {
        try {
            QuanNhan& quanNhan = DANHSACH[i];
            SiQuan* siquan = dynamic_cast<SiQuan*>(&quanNhan);

            if (siquan) {
                // Chuyển đổi enum CapBac thành string để so sánh
                string capBacStr = "";
                CapBac cb = siquan->getCapBac();

                capBacStr = capBacToString(cb);

                if (capBacStr == capBac) {
                    count++;
                }
            }

            BinhSi* binhsi = dynamic_cast<BinhSi*>(&quanNhan);
            if (binhsi) {
                // Tương tự với BinhSi
                string capBacStr = "";
                CapBac cb = siquan->getCapBac();

                capBacStr = capBacToString(cb);

                if (capBacStr == capBac) {
                    count++;
                }
            }
        } catch (const std::exception& e) {
            // Xử lý ngoại lệ nếu có
        }
    }

    return count;
}

// Thống kê số lượng sĩ quan
int QuanLiQuanDoi::thongKeSiQuan() {
    int count = 0;
    int soLuong = DANHSACH.getSoLuongHienTai();

    for (int i = 0; i < soLuong; i++) {
        try {
            QuanNhan& quanNhan = DANHSACH[i];
            SiQuan* siquan = dynamic_cast<SiQuan*>(&quanNhan);

            if (siquan != nullptr) {
                count++;
            }
        } catch (const std::exception& e) {
            // Xử lý ngoại lệ nếu có
        }
    }

    return count;
}

// Thống kê số lượng binh sĩ
int QuanLiQuanDoi::thongKeBinhSi() {
    int count = 0;
    int soLuong = DANHSACH.getSoLuongHienTai();

    for (int i = 0; i < soLuong; i++) {
        try {
            QuanNhan& quanNhan = DANHSACH[i];
            BinhSi* binhsi = dynamic_cast<BinhSi*>(&quanNhan);

            if (binhsi != nullptr) {
                count++;
            }
        } catch (const std::exception& e) {
            // Xử lý ngoại lệ nếu có
        }
    }

    return count;
}

// Lấy ngân sách tối thiểu
long long QuanLiQuanDoi::getNganSachToiThieu() {
    // Tính toán ngân sách tối thiểu dựa trên lương của tất cả quân nhân
    nganSachToiThieu = 0;
    int soLuong = DANHSACH.getSoLuongHienTai();

    for (int i = 0; i < soLuong; i++) {
        try {
            QuanNhan& quanNhan = DANHSACH[i];
            nganSachToiThieu += quanNhan.getLuong();
        } catch (const std::exception& e) {
            // Xử lý ngoại lệ nếu có
        }
    }

    return nganSachToiThieu;
}