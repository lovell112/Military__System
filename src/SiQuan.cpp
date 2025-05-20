#include "SiQuan.h"

SiQuan::SiQuan(): QuanNhan(), donViQuanLy(NULL) {}
SiQuan::SiQuan(string ms, string ht, string cb, string dv, string qq, string ns, string nnn,DSQN dvql)
    : QuanNhan(ms,ht,cb,dv,qq,ns,nnn), donViQuanLy(dvql) {}
SiQuan::SiQuan(const SiQuan& q): SiQuan(q.maSo, q.hoTen, q.capBac, q.donVi, q.queQuan, q.ngaySinh, q.ngayNhapNgu, q.donViQuanLy) {}

SiQuan::~SiQuan() {}

void SiQuan::getDonViQuanLy() {
    if (donViQuanLy != NULL) {
        cout << "Si Quan khong quan ly don vi nao" << endl;
        return;
    }
    for(string dv : donViQuanLy) {
      static int dem = 1;
      if(dem % 3 == 0) cout << endl;
      cout << dem++ << dv << '/';
    }
}

void SiQuan::hienThiThongTin() const {
    cout << "---Thong Tin Si Quan---" << endl;
    cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << endl;
    cout << "Cap bac: " << capBacToString(capBac) << ", Don vi: " << donVi << endl;
    cout << "Que quan: " << queQuan << ", ngay sinh: " << ngaySinh << endl;
    cout << "Ngay nhap ngu: " << ngayNhapNgu << endl;
    cout << "-----------------------" << endl;
}

void SiQuan::giaoNV(string MSQN, string nhiemVu) {
    bool flag = false;
    for (QuanNhan& qn : donViQuanLy) {
        if (qn.getMaSo() == MSQN) {
            flag = true;
            if (capBac <= qn.getCapBac()) {
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

void SiQuan::kiemTraNVQN(string MSQN) {
    bool flag = false;
    for (QuanNhan *qn : donViQuanLy) {
        if (qn->getMaSo() == MSQN) {
            flag = true;
            for (string NV : qn->getDSNhiemVu()) {
                cout << NV << ": ";
                if (qn->baoCaoNV(NV)) cout << "Da hoan thanh" << endl;
                else cout << "chua hoan thanh" << endl;
            }
        }
        cout << "Da giao nhiem vu cho quan nhan " << qn->getMaSo() <<'.' << endl;
    }
    if (!flag) {
        cout << "Si Quan khong co quyen kiem tra nhiem vu cua quan Nhan nay" << endl;
    }
}
istream& operator>>(istream& is , SiQuan& p){
    is >> dynamic_cast<QuanNhan&>(p);
    string temp;
    p.donViQuanLy.clear();
    is.ignore();
    while(getline(is, temp)) {
        p.donViQuanLy.push_back(temp);
    }
    return is;
}
ostream& operator<<(ostream& out , const SiQuan& p) {
      out << dynamic_cast<const QuanNhan&>(p);
      for(string dv : p.donViQuanLy) {
        out << dv << endl;
      }
      return out;
}