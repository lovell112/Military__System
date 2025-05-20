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

//nhập vào mã số muốn sửa, nếu tồn tại thì cho phép sửa thông tin một quân nhân, chỉ sửa nếu tìm thấy, còn không thì in ra báo lỗi
void QuanLiQuanDoi::sua(string _maso){
    int pos = timKiem(_maso);
    if (pos == -1) {
        cout << "Khong ton tai quan nhan nay!" << endl;
        return;
    }

    string hoTenMoi, capBacMoi, donViMoi, queQuanMoi, ngaySinhMoi, ngayNhapNguMoi, trachNhiemMoi;

    cout << "Nhap ho ten moi: ";
    getline(cin >> ws, hoTenMoi);

    cout << "Nhap cap bac moi: ";
    getline(cin >> ws, capBacMoi);

    cout << "Nhap don vi moi: ";
    getline(cin >> ws, donViMoi);

    cout << "Nhap que quan moi: ";
    getline(cin >> ws, queQuanMoi);

    cout << "Nhap ngay sinh moi: ";
    getline(cin >> ws, ngaySinhMoi);

    cout << "Nhap ngay nhap ngu moi: ";
    getline(cin >> ws, ngayNhapNguMoi);

    cout << "Nhap trach nhiem moi (chuc vu hoac nhiem vu): ";
    getline(cin >> ws, trachNhiemMoi);

    // Tạo lại đối tượng với dữ liệu mới, giữ nguyên mã số & loại (S hoặc B)
    QuanNhan* old = danhSach[pos];
    string loai = old->getLoai();

    QuanNhan* moi = nullptr;
    if (loai == "Binh Si") {
        moi = new BinhSi(_maso, hoTenMoi, capBacMoi, donViMoi, queQuanMoi, ngaySinhMoi, ngayNhapNguMoi, trachNhiemMoi);
    } else if (loai == "Si Quan") {
        moi = new SiQuan(_maso, hoTenMoi, capBacMoi, donViMoi, queQuanMoi, ngaySinhMoi, ngayNhapNguMoi, trachNhiemMoi);
    }

    // Giải phóng bộ nhớ cũ và gán lại
    delete danhSach[pos];
    danhSach[pos] = moi;

    capNhatDuLieu();
}

//Thống kê các cấp bậc có trong danh sách
int QuanLiQuanDoi::thongKeCapBac(string _capBac) {
    int dem = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getCapBac() == _capBac)
            dem++;
    }
    return dem;
}

//Thống kê số lượng sĩ quan có trong danh sách
int QuanLiQuanDoi::thongKeSiQuan(){
    int dem = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getLoai() == "Si Quan")
            dem++;
    }
    return dem;
}

//Thống kê số lượng binh sĩ có trong danh sách
int QuanLiQuanDoi::thongKeBinhSi(){
    int dem = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getLoai() == "Binh Si")
            dem++;
    }
    return dem;
}

//Thống kê lương được nhận rồi trả về ngân sách tối thiểu cần có trong 1 năm
long long QuanLiQuanDoi::NganSachToiThieu(){
    long long tongLuong = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getLoai() == "Si Quan") {
            
            string chucVu = danhSach[i]->getTrachNhiem();
            long long luong = 0;

            if (chucVu == "Dai tuong") luong = 24336000;
            else if (chucVu == "Thuong tuong") luong = 22932000;
            else if (chucVu == "Trung tuong") luong = 21528000;
            else if (chucVu == "Thieu tuong") luong = 20124000;
            else if (chucVu == "Dai ta") luong = 18720000;
            else if (chucVu == "Thuong ta") luong = 17082000;
            else if (chucVu == "Trung ta") luong = 15444000;
            else if (chucVu == "Thieu ta") luong = 14040000;
            else if (chucVu == "Dai uy") luong = 12636000;
            else if (chucVu == "Thuong uy") luong = 11700000;
            else if (chucVu == "Trung uy") luong = 10764000;
            else if (chucVu == "Thieu uy") luong = 9828000;
            else luong = 0;

            tongLuong += luong * 12; // lương theo năm của từng sĩ quan
        } else if (danhSach[i]->getLoai() == "Binh Si") {
            tongLuong += 9000000; // Binh sĩ: mặc định 9 triệu/năm
        }
    }
    return tongLuong;
}
