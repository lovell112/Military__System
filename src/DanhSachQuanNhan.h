#ifndef DANHSACHQUANNHAN_H
#define DANHSACHQUANNHAN_H
#include "BinhSi.h"
#include "SiQuan.h"

using namespace std;

class DanhSachQuanNhan {
    vector<QuanNhan*> danhSach;
    string tenDanhSach;
public:
    // Constructor mặc định
    DanhSachQuanNhan();
    // Constructor với tham số
    DanhSachQuanNhan(const string& ten, int maxSize);
    // Copy constructor
    DanhSachQuanNhan(const DanhSachQuanNhan& other);
    // Destructor
    ~DanhSachQuanNhan();

    bool ghiFile(const string& tenFile) const;
    bool docFile(const string& tenFile) ;

    void themQuanNhan(QuanNhan* quanNhan);

    bool xoaQuanNhan(const string &maSo);

    QuanNhan* getQuanNhan(const string& maSo) const;

    vector<BinhSi*> layDanhSachBinhSi() const;
    vector<SiQuan*> layDanhSachSiQuan() const;

    // Phương thức đếm số lượng mỗi loại
    int demSoBinhSi() const;
    int demSoSiQuan() const;


    string getTenDanhSach() const;
    void setTenDanhSach(const string& ten);

    void hienThiDanhSach() const;

    int getSoLuongToiDa() const;
    void setSoLuongToiDa(int max);

    int getSoLuongHienTai() const;

    QuanNhan& operator[](int index);
    friend ostream& operator<<(ostream& os, const DanhSachQuanNhan& ds);
    friend istream& operator>>(istream& is, DanhSachQuanNhan& ds);

};

#endif // DANHSACHQUANNHAN_H