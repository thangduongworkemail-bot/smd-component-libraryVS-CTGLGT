#include<iostream>
#include<cstring>
#include"../include/linhkien.h"
void LinhKien::nhap(string mlk,string tlk,string ncc,float g,double sl,double ts){
    maLK=mlk;
    tenLK=tlk;
    nhacungcap=ncc;
    gia=g;
    soLuong=sl;
    thongso=ts;                                         
    
    if(soLuong>0) trangthai=true;
    else
    trangthai=false;
}
void LinhKien::nhap(LinhKien lk){
    maLK=lk.maLK;
    tenLK=lk.tenLK;
    nhacungcap=lk.nhacungcap;
    gia=lk.gia;
    soLuong=lk.soLuong;
    thongso=lk.thongso;                                         
    
    if(soLuong>0) trangthai=true;
    else
    trangthai=false;
}
void LinhKien::setMaLK(std::string mlk){
    maLK=mlk;
}
void LinhKien::setTenLK(std::string tlk){
    tenLK=tlk;
}
void LinhKien::setNhaCungCap(std::string ncc){
    nhacungcap=ncc;
}
void LinhKien::setGia(float g){
    gia=g;
}
void LinhKien::setSoLuong(double sl){
    soLuong=sl;
    if(soLuong>0) trangthai=true;
    else
    trangthai=false;
}
void LinhKien::setThongSo(double ts){
    thongso=ts;
}
void LinhKien::setTrangThai(bool tt){
    trangthai=tt;
}
void LinhKien::setGiaTri(string gt){
    giatri=gt;
}
string LinhKien::getNhaCungCap(){
    return nhacungcap;
}
string LinhKien::getMaLK(){
    return maLK;
}
string LinhKien::getTenLK(){
    return tenLK;
}
float LinhKien::getGia(){
    return gia;
}
double LinhKien::getThongSo(){
    return thongso;
}
double LinhKien::getSoLuong(){
    return soLuong;
}
bool LinhKien::getTrangThai(){
    return trangthai;
}
string LinhKien::getGiatri(){
    return giatri;
}
