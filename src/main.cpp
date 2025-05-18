#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class QuanNhan {
    string maSo, hoTen, capBac, donVi, queQuan, ngaySinh, ngayNhapNgu;

public:
    QuanNhan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn)
        : hoTen(ht), capBac(cb), donVi(dv), queQuan(qq), maSo(ms), ngaySinh(ns), ngayNhapNgu(nnn) {}

    void hienThiThongTin() const {
        cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
        cout << "Cap bac: " << capBac << ", Don vi: " << donVi << endl;
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

};


class DanhSachQuanNhan {
    vector<QuanNhan> danhSach;

public:
    DanhSachQuanNhan() {}
    DanhSachQuanNhan(const vector<QuanNhan>& ds) {
        danhSach = ds;
    }
    void themQuanNhan(const QuanNhan& qn) {
        danhSach.push_back(qn);
    }
    vector<QuanNhan> getDanhSach() {
        return danhSach;
    }
    void Duyet() const {
        cout << "\n--- Danh sach quan nhan ---\n";
        for (const QuanNhan& qn : danhSach) {
            qn.hienThiThongTin();
            cout << "-------------------------\n";
        }
    }

    QuanNhan* getQuanNhan(string maSo) {
        for (QuanNhan& qn : danhSach) {
            if (qn.getMaSo() == maSo)
                return &qn;
        }
        return nullptr;
    }

    void ghiFile(const string& tenFile) const {
        ofstream out(tenFile);
        for (const QuanNhan& qn : danhSach) {
            out << qn.getMaSo() << "," << qn.getHoTen() << "," << qn.getCapBac()
                << "," << qn.getDonVi() << "," << qn.getQueQuan() << "," << qn.getNgaySinh() << "," << qn.getNgayNhapNgu() << "\n";
        }
        out.close();
    }

    void docFile(const string& tenFile) {
        ifstream in(tenFile);
        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string ma_so, ten, capBac, donVi, queQuan, ngaysinh, ngayNhapNgu;
            if (line.empty()) {
                continue;
            }
            getline(ss, ma_so, ',');
            getline(ss, ten, ',');
            getline(ss, capBac, ',');
            getline(ss, donVi, ',');
            getline(ss, queQuan, ',');
            getline(ss, ngaysinh, ',');
            getline(ss, ngayNhapNgu);
            danhSach.emplace_back(ma_so, ten, capBac, donVi, queQuan, ngaysinh, ngayNhapNgu);

        }
        in.close();
    }
    void thongKeTheoCapBac() const {
        cout << "\nThong ke theo cap bac:\n";
        vector<string> CapBac;
        for (const QuanNhan& qn : danhSach) {
            bool found = false;
            for (const string& x : CapBac) {
                if (x == qn.getCapBac()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                CapBac.push_back(qn.getCapBac());
            }
        }

        for (const string& x : CapBac) {
            int count = 0;
            for (const QuanNhan& qn : danhSach) {
                if (qn.getCapBac() == x) {
                    count++;
                }
            }
            cout << x << ": " << count << " nguoi\n";
        }
    }
    vector<QuanNhan> getDSSiQuan(const string& capbac) {
        vector<QuanNhan> DStmp;
        for (const QuanNhan& qn : danhSach) {
            if (capbac == qn.getCapBac()) {
                DStmp.push_back(qn);
            }
        }
        return DStmp;
    }
    void thongKeTheoDonVi() const {
        cout << "\nThong ke theo don vi:\n";
        vector<string> DonVi;
        for (const QuanNhan& qn : danhSach) {
            bool found = false;
            for (const string& x : DonVi) {
                if (x == qn.getDonVi()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                DonVi.push_back(qn.getDonVi());
            }
        }

        for (const string& x : DonVi) {
            int count = 0;
            for (const QuanNhan& qn : danhSach) {
                if (qn.getDonVi() == x) {
                    count++;
                }
            }
            cout << x << ": " << count << " nguoi\n";
        }
    }
    void duyetDonVi(const string& tuKhoa) const {
        cout << "\nKet qua tim kiem: \n";
        bool found = false;
        for (const QuanNhan& qn : danhSach) {
            if (qn.getHoTen().find(tuKhoa) != string::npos ||
                qn.getDonVi().find(tuKhoa) != string::npos ||
                qn.getQueQuan().find(tuKhoa) != string::npos)
            {
                qn.hienThiThongTin();
                cout << "-------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay ket qua nao.\n";
        }
    }

    bool isEmpty() const {
        return danhSach.empty();
    }
};

int main() {
    DanhSachQuanNhan DSQN;
    DSQN.docFile("quannhan.txt");
    DSQN.thongKeTheoCapBac();
    // DSQN.Duyet();
    // DSQN.duyetDonVi("Tieu đoan 1");
    DSQN.thongKeTheoDonVi();
    /*DanhSachQuanNhan ThieuUy(DSQN.getDSSiQuan("Thieu uy"));
    ThieuUy.Duyet();
    ThieuUy.ghiFile("DanhSachThieuUy.txt");
    DSQN.ghiFile("output.txt");*/
    return 0;
}