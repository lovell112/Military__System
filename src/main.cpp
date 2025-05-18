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
    QuanNhan() {
        maSo = "";
        hoTen = "";
        capBac = "";
        donVi = "";
        ngaySinh = "";
        ngayNhapNgu = "";
    }
    QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn)
        : hoTen(ht), capBac(cb), donVi(dv), queQuan(qq), maSo(ms), ngaySinh(ns), ngayNhapNgu(nnn) {}
    QuanNhan(const QuanNhan& qn) {}

    ~QuanNhan() {}
    virtual void hienThiThongTin() const {
        cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
        cout << "Cap bac: " << getCapBac() << ", Don vi: " << donVi << endl;
        cout << "Que quan: " << queQuan << ", ngay sinh: " << ngaySinh << endl;
        cout << "Ngay nhap ngu: " << ngayNhapNgu << endl;
    }
    string getMaSo() const { return maSo; }
    string getHoTen() const { return hoTen; }
    string getCapBac() const { return capBac; }
    string getDonVi() const { return donVi; }
    string getQueQuan() const { return queQuan; }
    string getNgaySinh() const { return ngaySinh; }
    string getNgayNhapNgu() const { return ngayNhapNgu; }
    vector<string> getDSNhiemVu() const { return DSNhiemVu; }
    void setMaSo(string ms) { maSo = ms; }
    void setHoTen(string ht) { hoTen = ht; }
    void setCapBac(string cb) { capBac = cb; }
    void setDonVi(string dv) { donVi = dv; }
    void setQueQuan(string qq) { queQuan = qq; }
    void setNgaySinh(string ns) { ngaySinh = ns; }
    void setNgayNhapNgu(string nnn) { ngayNhapNgu = nnn; }
    void setNhiemVu(string NV) {DSNhiemVu.push_back(NV);}
    bool baoCaoNhiemVu(string NV) {
        string x; bool flag = false;
        cout << "Bao cao tien do nhiem vu:" << endl;
        cout << "Ban da hoan thanh nhiem vu (roi/chua): "; cin >> x;
        if (x == "roi" || x == "Roi")
            flag = true;
        return flag;
    }
    int maHoaCapBac() {
        if (capBac == "Binh nhi") return 1;
        if (capBac == "Binh nhat") return 2;
        if (capBac == "Ha si") return 3;
        if (capBac == "Trung si") return 4;
        if (capBac == "Thuong si") return 5;
        if (capBac == "Thieu uy") return 6;
        if (capBac == "Trung uy") return 7;
        if (capBac == "Thuong uy") return 8;
        if (capBac == "Dai uy") return 9;
        if (capBac == "Thieu ta") return 10;
        if (capBac == "Trung ta") return 11;
        if (capBac == "Thuong ta") return 12;
        if (capBac == "Dai ta") return 13;
        return 0;
    }
};
class SiQuan : public QuanNhan {
    DanhSachQuanNhan donViQuanLy;
    public:
    SiQuan(): QuanNhan(), donViQuanLy(NULL) {}
    SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn,DanhSachQuanNhan dvql)
        : QuanNhan(), donViQuanLy(dvql) {}
    SiQuan(const SiQuan& q): QuanNhan(q), donViQuanLy(q.donViQuanLy) {}

    ~SiQuan() {}
    void getDonViQuanLy() {
        if (donViQuanLy != NULL) {
            cout << "Si Quan khong quan ly don vi nao" << endl;
            return;
        }
        cout << donViQuanLy.getTenDonVI() << endl;
    }
    void hienThiThongTin() const {
        cout << "---Thong Tin Si Quan---" << endl;
        cout << "DonViQuanLy: " << donViQuanLy.getTenDonVi() << endl;
        QuanNhan::hienThiThongTin();
        cout << "-----------------------" << endl;
    }
    void giaoNV(string MSQN, string nhiemVu) {
        bool flag = false;
        for (QuanNhan qn : donViQuanLy) {
            if (qn.getMaSo() == MSQN) {
                flag = true;
                if (maHoaCapBac() <= qn.maHoaCapBac()) {
                    cout << "Ban khong co quyen ra lenh cho cap tren" << endl;
                    return;
                }
                qn.setNhiemVu(nhiemVu);
            }
            cout << "Da giao nhiem vu cho binh si " << qn.getMaSo() <<'.' << endl;
        }
        if (!flag) {
            cout << "Si Quan khong co quyen giao nhiem vu cho quan nhan nay" << endl;
        }
    }
    void kiemTraNVQN(string MSQN) {
        bool flag = false;
        for (QuanNhan qn : donViQuanLy) {
            if (qn.getMaSo() == MSQN) {
                flag = true;
                for (string NV : qn.getDSNhiemVu()) {
                    cout << NV << ": ";
                    if (qn.baoCaoNhiemVu()) cout << "Da hoan thanh" << endl;
                    else cout << "chua hoan thanh" << endl;
                }
            }
            cout << "Da giao nhiem vu cho quan nhan " << qn.getMaSo() <<'.' << endl;
        }
        if (!flag) {
            cout << "Si Quan khong co quyen kiem tra nhiem vu cua quan Nhan nay" << endl;
        }
    }
};
class BinhSi: public QuanNhan {
    void hienThiThongTin() const {
        cout << "--------Binh Si--------" << endl;
        QuanNhan::hienThiThongTin();
        cout << "-----------------------" << endl;
    }
};



int main() {
    return 0;
}