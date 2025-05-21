#include "QuanLiQuanDoi.h"
#include "SiQuan.h"
#include "BinhSi.h"
#include <fstream>
#include <iostream>



vector<QuanNhan*> QuanLiQuanDoi::getDanhsach(){
  	return danhSach;
}

void QuanLiQuanDoi::docFile() {
    ifstream inFile("../data/solider__list.txt");
    if (!inFile){
        cout << "File khong ton tai!";
        return;
    }
    string line;
    while (getline(inFile, line)) {
		char x; cin >> x;
        QuanNhan *temp = nullptr;
    	if (x == 'S'){
        	temp = new SiQuan(); cin >> *temp;
		}
    	else if (x =='B'){
        	temp = new BinhSi(); cin >> *temp;
		}
		danhSach.push_back(temp);

    }
    inFile.close();
}
void QuanLiQuanDoi::ghiFile() {
    ofstream outFile("../data/solider__list.txt");
    bool flag = false;
    for (int i = 0; i < danhSach.size(); i++) {
        if (flag)
            outFile << endl;
        string line;
        line = danhSach[i]->getMaSo() + ",";
        line += danhSach[i]->getHoTen() + ",";
        line += capBacToString(danhSach[i]->getCapBac()) + ",";
        line += danhSach[i]->getDonVi() + ",";
        line += danhSach[i]->getQueQuan() + ",";
        line += danhSach[i]->getNgaySinh() + ",";
        line += danhSach[i]->getNgayNhapNgu() + ",";
        outFile << line;
        flag = true;
    }
}
QuanLiQuanDoi::QuanLiQuanDoi(){
    ghiFile();
}

QuanLiQuanDoi::~QuanLiQuanDoi() {
    for (int i = 0; i < danhSach.size(); i++)
        delete danhSach[i];
}