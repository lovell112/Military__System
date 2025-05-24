```markdown
# 🪖 Quản Lý Quân Nhân - C++ Project

Đây là đồ án môn học được xây dựng bằng ngôn ngữ **C++**, sử dụng các kiến thức về **lập trình hướng đối tượng** để mô phỏng hệ thống **quản lý quân nhân** gồm Sĩ Quan và Binh Sĩ.

---

## 🚀 Tính năng

- 📥 Đọc dữ liệu quân nhân từ file `solider__list.txt`
- ➕ Thêm mới sĩ quan hoặc binh sĩ
- ✏️ Sửa thông tin quân nhân theo mã số
- ❌ Xoá quân nhân khỏi danh sách
- 📊 Thống kê:
  - Tổng số sĩ quan / binh sĩ
  - Thống kê theo cấp bậc
  - Tính ngân sách tối thiểu cần thiết mỗi năm

---

## 🧱 Cấu trúc project
QuanLyQuanNhan/
├── CMakeLists.txt
├── data/
│   └── solider\_\_list.txt        # Dữ liệu quân nhân
├── src/
│   ├── main.cpp                 # Giao diện menu chính
│   ├── QuanNhan.cpp/.h         # Lớp cơ sở QuanNhan
│   ├── SiQuan.cpp/.h           # Lớp kế thừa Sĩ Quan
│   ├── BinhSi.cpp/.h           # Lớp kế thừa Binh Sĩ
│   └── QuanLiQuanDoi.cpp/.h    # Quản lý danh sách quân nhân
---

## 🛠 Cách chạy trong CLion

1. Mở CLion → **Open Folder** → chọn thư mục `QuanLyQuanNhan`
2. CLion sẽ nhận diện `CMakeLists.txt` tự động
3. Nhấn **Ctrl + F9** để build
4. Nhấn **Shift + F10** để chạy
5. Dữ liệu sẽ được đọc/ghi từ `data/solider__list.txt`

---

## 📂 Dữ liệu mẫu (`data/solider__list.txt`)

---

## 👨‍💻 Thành viên thực hiện

| MSSV          | Họ tên               |
| ------------- | -------------------- |
| 50.01.104.135 | Trần Nguyễn Xuân Sơn |
| 50.01.104.143 | Đổng Quốc Thái       |
| 50.01.104.085 | Nguyễn Hoàng Long    |
| 50.01.104.xxx | Dương Trung Nguyên   |
| 50.01.104.xxx | Nguyễn Đức Trọng     |
---

## 📌 Ghi chú

* Dự án sử dụng chuẩn C++.
* File dữ liệu nên giữ đúng định dạng CSV, mỗi dòng là thông tin 1 quân nhân.
* Các thao tác CRUD (Create, Read, Update, Delete) được thực hiện qua console menu.

---

## 📜 Bản quyền

Dự án thuộc về nhóm Ngũ Lão Tinh thuộc lớp 50.CNTT.A

```

---

Bạn chỉ cần copy toàn bộ nội dung trên, dán vào file `README.md` trong repo GitHub của bạn.

📦 Nếu bạn cần mình đính kèm README.md sẵn vào trong project `.zip` luôn thì mình có thể cập nhật nhé!
```
