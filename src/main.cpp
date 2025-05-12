#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class VuKhi {
protected:
    string ten, loai, trangThai;
    float tamBan, trongLuong;
    int satThuong;

public:
    VuKhi(string t, string l, float tb, int st, float tl, string tt)
        : ten(t), loai(l), tamBan(tb), satThuong(st), trongLuong(tl), trangThai(tt) {}
    virtual string getTen() const { return ten; }
    virtual void hienThiThongTin() const {
        cout << "Ten: " << ten << ", Loai: " << loai << endl
             << "Tam ban: " << tamBan << ", Sat thuong: " << satThuong << endl
             << "Trong luong: " << trongLuong << ", Trang thai: " << trangThai;
    }
    virtual ~VuKhi() {}

    virtual void khaiHoa() = 0;
    virtual void napDan() = 0;

};

class Sung : public VuKhi {
    int tocDoBan;
    int soLuongDan;
public:
    Sung(string t, float tb, int st, float tl, string tt, int td)
        : VuKhi(t, "Sung", tb, st, tl, tt), tocDoBan(td) {
        soLuongDan = 1;
    }

    void napDan() override {
            cout << "Dang nap dan cho: " << ten << endl;
            soLuongDan = 1;
        }
    void khaiHoa() override {
        if(soLuongDan == 0){
            cout << "Sung het dan.\n";
            napDan();
        }
        cout << ten << " dang ban o toc do " << tocDoBan << " vien/phut!\n";
        soLuongDan = 0;
    }
    void hienThiThongTin() const override {
        VuKhi::hienThiThongTin();
    }
};

class QuanNhan {
    string hoTen, capBac, donVi, queQuan;
    int maSo, namSinh;
    VuKhi* vuKhiDangDung;

public:
    QuanNhan(string ht, string cb, string dv, string qq, int ms, int ns)
        : hoTen(ht), capBac(cb), donVi(dv), queQuan(qq), maSo(ms), namSinh(ns), vuKhiDangDung(nullptr) {}

    void capPhatVuKhi(VuKhi* vk) {
        vuKhiDangDung = vk;
    }

    void hienThiThongTin() const {
        cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
        cout << "Cap bac: " << capBac << ", Don vi: " << donVi << endl;
        cout << "Que quan: " << queQuan << ", Nam sinh: " << namSinh << endl;

        if (vuKhiDangDung != nullptr) {
            cout << "Dang su dung: ";
            vuKhiDangDung->hienThiThongTin();
            cout << endl;
        } else {
            cout << "Chua duoc cap vu khi.\n";
        }
    }

    string getHoTen() const { return hoTen; }
    string getCapBac() const { return capBac; }
    string getDonVi() const { return donVi; }
    string getQueQuan() const { return queQuan; }
    int getMaSo() const { return maSo; }
    int getNamSinh() const { return namSinh; }

    void khaiHoa(){
        vuKhiDangDung->khaiHoa();
    }
};

class DSVK {
    vector<VuKhi*> danhSachVuKhi;

public:
    void themVuKhi(VuKhi* vk) {
        danhSachVuKhi.push_back(vk);
    }

    void Duyet() const {
        cout << "\n--- Danh sach vu khi ---\n";
        for (const VuKhi *vk : danhSachVuKhi) {
            vk->hienThiThongTin();
            cout << "\n----------------------\n";
        }
    }

    VuKhi* timVuKhiTheoTen(const string& ten) const {
        for (VuKhi *vk : danhSachVuKhi) {
            if (vk->getTen() == ten)
                return vk;
        }
        return nullptr;
    }

    ~DSVK() {
        for (VuKhi *vk : danhSachVuKhi)
            delete vk;
        danhSachVuKhi.clear();
    }
};

class DanhSachQuanNhan {
    vector<QuanNhan> danhSach;

public:
    void themQuanNhan(const QuanNhan& qn) {
        danhSach.push_back(qn);
    }

    void Duyet() const {
        cout << "\n--- Danh sach quan nhan ---\n";
        for (const QuanNhan& qn : danhSach) {
            qn.hienThiThongTin();
            cout << "-------------------------\n";
        }
    }

    QuanNhan* getQuanNhan(int maSo) {
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
                << "," << qn.getDonVi() << "," << qn.getQueQuan() << "," << qn.getNamSinh() << "\n";
        }
        out.close();
    }

    void docFile(const string& tenFile) {
        ifstream in(tenFile);
        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string ma_str, ten, capBac, donVi, queQuan, namSinh_str;
            if (line.empty()) {
                continue;
            }
            getline(ss, ma_str, ',');
            getline(ss, ten, ',');
            getline(ss, capBac, ',');
            getline(ss, donVi, ',');
            getline(ss, queQuan, ',');
            getline(ss, namSinh_str, ',');

            int maSo = stoi(ma_str);
            int namSinh = stoi(namSinh_str);

            danhSach.emplace_back(ten, capBac, donVi, queQuan, maSo, namSinh);
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
    DSVK qlVK;
    QuanNhan *ptr;
    VuKhi* AK = new Sung("AK-47", 400.0, 70, 4.3, "San sang", 10);
    VuKhi* M16 = new Sung("M16", 500.0, 65, 3.8, "San sang", 12);
    VuKhi* AWP = new Sung("AWP", 3000.0, 200, 6.5, "San sang", 1);
    VuKhi* M107  = new Sung("Barrett M107", 500.0, 65, 12.9, "San sang", 1);
    qlVK.themVuKhi(AK);
    qlVK.themVuKhi(M16);
    qlVK.themVuKhi(AWP);
    qlVK.themVuKhi(M107);
    //qlQN.thongKeTheoCapBac();
    // qlQN.Duyet();
    DSQN.docFile("quannhan.txt");
    DSQN.duyetDonVi("Tieu doan 5");
    ptr = DSQN.getQuanNhan(6325);
    ptr->capPhatVuKhi(AK);
    ptr = DSQN.getQuanNhan(7613);
    ptr->capPhatVuKhi(M16);
    ptr->khaiHoa();
    ptr = DSQN.getQuanNhan(6325);
    ptr->khaiHoa();
    ptr = DSQN.getQuanNhan(7613);
    ptr->khaiHoa();
    DSQN.ghiFile("output.txt");

    return 0;
}