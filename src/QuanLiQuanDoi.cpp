#include "QuanLiQuanDoi.h"

// đọc từng dòng trong cơ sở dữ liệu cho đến cuối, tách dòng ra thành từng thông tin nhỏ, lưu vào các biến, sau đó khởi tạo Quân Nhân hợp lệ theo từng loại (Sĩ Quan/Binh Sĩ)
void QuanLiQuanDoi::docDuLieuTuFile() {
    ifstream inFile("../data/solider__list.txt");
    if (!inFile){
        cout << "File khong ton tai!";
        return;
    }
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string _maSo, _hoTen, _capBac, _donVi, _queQuan, _ngaySinh, _ngayNhapNgu, _chucVu, _nhiemVu;
        getline(ss, _maSo, ',');
        getline(ss, _hoTen, ',');
        getline(ss, _capBac, ',');
        getline(ss, _donVi, ',');
        getline(ss, _queQuan, ',');
        getline(ss, _ngaySinh, ',');
        getline(ss, _ngayNhapNgu, ',');
        if (_maSo[0]=='B')
            getline(ss, _nhiemVu, ',');
        else
            getline(ss, _chucVu, ',');
        QuanNhan* temp = nullptr;
        if (_maSo[0]=='S') 
            temp = new SiQuan(_maSo, _hoTen, _capBac, _donVi, _queQuan, _ngaySinh, _ngayNhapNgu, _chucVu);
        else if (_maSo[0]=='B') 
            temp = new BinhSi(_maSo, _hoTen, _capBac, _donVi, _queQuan, _ngaySinh, _ngayNhapNgu, _nhiemVu);
        if (temp != nullptr)
            danhSach.push_back(temp);
    }
    inFile.close();
}

QuanLiQuanDoi::QuanLiQuanDoi(){
    docDuLieuTuFile();
}

QuanLiQuanDoi::~QuanLiQuanDoi() {
    for (int i = 0; i < danhSach.size(); i++) 
        delete danhSach[i];
}

// cập nhật thông tin mới vào cơ sở dữ liệu
void QuanLiQuanDoi::capNhatDuLieu() {
    ofstream outFile("../data/solider__list.txt");
    bool flag = true; // nhận diện xem có phải phần tử đầu tiên không để xuống dòng

    // gom tất cả thông tin thành 1 dòng sau đó xuất lên cơ sở dữ liệu
    for (int i = 0; i < danhSach.size(); i++) { 
        if (!flag)
            outFile << endl;
        string line;
        line = danhSach[i]->getMaSo() + ",";
        line += danhSach[i]->getHoTen() + ",";
        line += danhSach[i]->getCapBac() + ",";
        line += danhSach[i]->getDonVi() + ",";
        line += danhSach[i]->getQueQuan() + ",";
        line += danhSach[i]->getNgaySinh() + ",";
        line += danhSach[i]->getNgayNhapNgu() + ",";
        line += danhSach[i]->getTrachNhiem() + ",";
        line += danhSach[i]->getLoai();
        outFile << line;
        flag = false;
    }
}

int QuanLiQuanDoi::timKiem(string _maSo) { // kiểm tra phần tử có tồn tại không? nếu có return index, nếu không return -1
    for (int i = 0; i < danhSach.size(); i++)
        if (danhSach[i]->getMaSo()==_maSo)
            return i;
    return -1;
}

// truyền vào thông tin của phần tử muốn thêm, nếu mã số hợp lệ, thì thêm vào cuối danh sách, sau đó cập nhật lại dữ liệu, ngược lại ngừng hàm
void QuanLiQuanDoi::them(string _maSo, string _hoTen, string _capBac, string _donVi, string _queQuan, string _ngaySinh, string _ngayNhapNgu, string _trachNhiem) {
    QuanNhan* temp = nullptr;
    if (_maSo[0]=='B')
        temp = new BinhSi(_maSo, _hoTen, _capBac, _donVi, _queQuan, _ngaySinh, _ngayNhapNgu, _trachNhiem);
    else if (_maSo[0]=='S')
        temp = new SiQuan(_maSo, _hoTen, _capBac, _donVi, _queQuan, _ngaySinh, _ngayNhapNgu, _trachNhiem);
    else {
        cout << "Ma so Quan Nhan khong dung dinh dang!";
        return;
    }
    danhSach.push_back(temp);
    capNhatDuLieu();
}

// nhập vào mã số muốn xóa, nếu tồn tại, thì sẽ xóa dựa theo index tìm kiếm được, sau đó bù lại khoản trống của phần tử bị xóa, cập nhật số lượng phần tử, ngược lại ngừng hàm
void QuanLiQuanDoi::xoa(string _maSo) {
    int pos = timKiem(_maSo);
    if (pos==-1) {
        cout << "Khong ton tai quan nhan nay";
        return;
    }
    delete danhSach[pos];
    for (int i = pos; i < danhSach.size() - 1; i++)
        danhSach[i] = danhSach[i+1];
    danhSach[danhSach.size()-1] = nullptr;
    danhSach.resize(danhSach.size()-1);
    capNhatDuLieu();
}