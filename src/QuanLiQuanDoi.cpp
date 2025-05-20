#include "QuanLiQuanDoi.h"


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

void QuanLiQuanDoi::capNhatDuLieu() {
    ofstream outFile("../data/solider__list.txt");
    bool flag = false;
    for (int i = 0; i < danhSach.size(); i++) {
        if (flag)
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
        // No need to write outFile << line; here, as it's already below
        outFile << line;
        flag = true;
    }
}

int QuanLiQuanDoi::timKiem(string _maSo) {
    for (int i = 0; i < danhSach.size(); i++)
        if (danhSach[i]->getMaSo()==_maSo)
            return i;
    return -1;
}

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