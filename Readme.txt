Chương trình được xây dựng nhằm quản lý thư viện linh kiện điện tử (điện trở, tụ điện, cuộn cảm, jumper, …).
Hệ thống cho phép lưu trữ, tìm kiếm, sắp xếp và xuất dữ liệu linh kiện phục vụ cho việc quản lý và tra cứu nhanh.
nguồn: https://github.com/thangduongworkemail-bot/smd-component-libraryVS-CTGLGT.git
có thể lấy trên git
Chương trình được cài đặt bằng ngôn ngữ C++, sử dụng cấu trúc dữ liệu bảng băm (Hash Table) kết hợp danh sách liên kết để xử lý va chạm.

2. Cấu trúc thư mục
electronic_library/
│
___src/
│   ├
│   ├── linhkien.cpp          // Cài đặt lớp LinhKien
│   ├── menu.cpp         // Cài đặt bảng băm
│   ├── structure.cpp        // Danh sách liên kết
│   └── io_linhkien.cpp       // Đọc / ghi dữ liệu
│
├── include/
│   ├── linhkien.h 
│   ├── IO_linhkien.h
│   |── structure.h
│   |__menu.h
|   
|
|
├── data/
│   ├── INPUT/
│   │   └── linhkien.xlsx     // Dữ liệu đầu vào dùng để thử nghiệm
│   └── OUTPUT/
│       └── linhkien.txt      // File xuất kết quả
│── main.cpp              // Hàm main, menu chương trình
├── CMakeLists.txt
├── README.txt
└── build/main.exe

3. Dữ liệu sử dụng để thử nghiệm

Dữ liệu linh kiện được lưu trong file Excel (.xlsx)
lấy thông tin ở file linhkien copy để lấy dữ liệu test


Mỗi linh kiện gồm các thông tin:

Tên linh kiện

Mã linh kiện

Số lượng

Trạng thái

Thông số kỹ thuật (giá trị R, C, L…)

Nhà cung cấp

Số lượng linh kiện thử nghiệm: khoảng 1200 linh kiện

4. Cấu trúc dữ liệu và thuật toán sử dụng
4.1 Cấu trúc dữ liệu

Hash Table với kích thước là số nguyên tố gần 2 lần số linh kiện

Xử lý va chạm bằng Separate Chaining (Danh sách liên kết)

4.2 Hàm băm

Sử dụng hàm băm chuỗi dựa trên thuật toán djb2

Khóa băm có thể là:

Mã linh kiện

Tên linh kiện

4.3 Thuật toán

Sắp xếp: QuickSort / std::sort theo tham số (giá trị linh kiện)

Tìm kiếm:

Tìm theo mã / tên bằng bảng băm

Tìm theo khoảng giá trị bằng:

Sắp xếp trước


5. Các chức năng chính

Thêm linh kiện mới

Cập nhật thông tin linh kiện

Tìm kiếm linh kiện theo:

Mã linh kiện

Tên linh kiện

Khoảng giá trị tham số

Xuất toàn bộ danh sách linh kiện ra file .txt

Hiển thị danh sách linh kiện ra màn hình

6. Cách biên dịch và chạy chương trình
6.1 Biên dịch bằng CMake
mkdir build
cd build
cmake ..
cmake --build .

6.2 Chạy chương trình
./main


(hoặc main.exe trên Windows)

7. Kết quả cho trường hợp đơn giản(bổ xung trên báo cáo)

Chương trình đọc thành công dữ liệu từ file Excel

Thêm và lưu trữ linh kiện vào bảng băm

Tìm kiếm nhanh theo mã và tên 

Xuất đầy đủ danh sách linh kiện ra file linhkien.txt