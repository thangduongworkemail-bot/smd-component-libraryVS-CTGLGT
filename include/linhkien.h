#ifndef LINHKIEN_H
#define LINHKIEN_H
#include <iostream>
#include <fstream>
using namespace std;
class LinhKien {
  string maLK;
    string tenLK;
    string nhacungcap;
    float gia;
     double soLuong;
    double thongso;
    string giatri;
    bool trangthai;
    public:
    void nhap(string mlk,string tlk,string ncc,float g,double sl,double ts);
    void nhap(LinhKien lk);
    void setMaLK(string mlk);
    void setTenLK(string tlk);
    void setNhaCungCap(string ncc);
    void setGia(float g);
    void setThongSo(double ts);
    void setSoLuong(double sl);
    void setTrangThai(bool tt);
    void setGiaTri(string gt);
    string getNhaCungCap();
   string getMaLK();
    string getTenLK();
    float getGia();
    double getThongSo();
    double getSoLuong();
    bool getTrangThai();
   
    string getGiatri();
};
#endif // LINHKIEN_H