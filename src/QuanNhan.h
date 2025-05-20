#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class QuanNhan {
    string maSo, hoTen, capBac, donVi, queQuan, ngaySinh, ngayNhapNgu;
    vector<string> DSNhiemVu;
public:

    // default constructor
    QuanNhan();

    // constructor
    QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn);
 
    // copy constructor
    QuanNhan(const QuanNhan& qn);

    // destructor
    virtual ~QuanNhan();

    // virtual method display infomation of person
    virtual void hienThiThongTin() const;

    // get ID of person
    string getMaSo() const;
    // get full name of person
    string getHoTen() const;
    // get rank of person
    string getCapBac() const;
    // get unit of person
    string getDonVi() const;
    // get hometown of person
    string getQueQuan() const;
    // get birthday of person
    string getNgaySinh() const;
    // get enlistment day of person
    string getNgayNhapNgu() const;
    virtual string getTrachNhiem() = 0;
    // get 
    vector<string> getDSNhiemVu() const;
    void setMaSo(string ms);
    void setHoTen(string ht);
    void setCapBac(string cb);
    void setDonVi(string dv);
    void setQueQuan(string qq);
    void setNgaySinh(string ns);
    void setNgayNhapNgu(string nnn);
    void setNhiemVu(string NV);
    int maHoaCapBac();

    virtual string getLoai() = 0;

    friend istream& operator>>(istream&, QuanNhan&);
    friend ostream& operator<<(ostream&, QuanNhan&);
};