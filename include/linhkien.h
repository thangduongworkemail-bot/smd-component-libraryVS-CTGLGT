#ifndef LINHKIEN_H
#define LINHKIEN_H
#include <iostream>
using namespace std;
class LinhKien {
  string maLK;
    string tenLK;
    string nhacungcap;
    float gia;
    int soLuong;
    double thongso;
    double giatri;
    bool trangthai;
    public:
    void nhap(string mlk,string tlk,string ncc,float g,int sl,float ts);
    void nhap(LinhKien lk);
    void setMaLK(string mlk);
    void setTenLK(string tlk);
    void setNhaCungCap(string ncc);
    void setGia(float g);
    void setThongSo(double ts);
    void setSoLuong(int sl);
    void setTrangThai(bool tt);
    void setGiaTri(double gt);
    string getNhaCungCap();
   string getMaLK();
    string getTenLK();
    float getGia();
    float getThongSo();
    int getSoLuong();
    bool getTrangThai();
   
    double getGiatri();
};
#endif // LINHKIEN_H