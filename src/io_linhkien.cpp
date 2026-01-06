#include<iostream>
#include<cstring>
#include"../include/io_linhkien.h"
#include <cctype>
#include<OpenXLSX.hpp>

using namespace std;
using namespace OpenXLSX;
STR_Map map_linhkien(1501,djb2Hash);
STR_Map map_maLK(1501,djb2Hash);
LinhKien mang_lk[5000];
int sizelk=0;
void xuatlinhkien(){
    
for (int i=0;i<map_linhkien.size;i++){
if (map_linhkien.table[i].getHead()!=nullptr)
    map_linhkien.table[i].printList();
  
    }
}

double parseValue(const string& s, string &giatri)
{
    int i = 0;
    // Lấy phần số
    while (i < s.size() && (isdigit(s[i]) || s[i] == '.'))
        i++;

    double value = stod(s.substr(0, i));

    // Bỏ khoảng trắng
    while (i < s.size() && s[i] == ' ')
        i++;

    // Lấy phần đơn vị
    string unit = s.substr(i);
 
    // Xác định hệ số
    if (unit.find("p") == 0){  
        string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
return value * 1e-12;}
    if (unit.find("n") == 0) {
         string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
        return value * 1e-9;}
    if (unit.find("u") == 0 || unit.find("µ") == 0) 
    { 
         string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
        return value * 1e-6;}
    if (unit.find("m") == 0){
        string gt =s.substr(i+1); // phần giá trị không có tiền tố
      giatri=gt;
         return value * 1e-3;}
    if (unit.find("k") == 0){ 
        string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
        return value * 1e3;}
    if (unit.find("M") == 0) {
        string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
        return value * 1e6;}
    if (unit.find("G") == 0) {
        string gt =s.substr(i+1); // phần giá trị không có tiền tố
giatri=gt;
        return value * 1e9;}
   string gt =s.substr(i); // phần giá trị không có tiền tố
giatri=gt;
    return value; // không có tiền tố
}
 
void luutru_linhkien(){
    
    XLDocument doc;
    doc.open("../data/INPUT/linhkien1.xlsx");
    auto wbs=doc.workbook().worksheet("Sheet1");
    int i=2;
   
    while(wbs.cell("A" + std::to_string(i)).value().type() != XLValueType::Empty) 
    {
        LinhKien lk;
        
       lk.setTenLK(wbs.cell("A" + std::to_string(i)).value());
      lk.setMaLK(wbs.cell("B" + std::to_string(i)).value());
         lk.setSoLuong(wbs.cell("C" + std::to_string(i)).value());
         if(lk.getSoLuong()>0) lk.setTrangThai(true);
      string giatri;
       lk.setThongSo(parseValue(wbs.cell("D" + std::to_string(i)).value(), giatri));
         lk.setGiaTri(giatri);
        lk.setNhaCungCap(wbs.cell("E" + std::to_string(i)).value());
        mang_lk[sizelk]=lk;
        map_linhkien.insert(lk.getTenLK(),lk);
         map_maLK.insert(lk.getMaLK(),lk);
        sizelk++;
        i++;
    }
    doc.close();
}
void nhaplinhkien(){
    XLDocument doc;
    doc.open("../data/INPUT/linhkien1.xlsx");
    auto wbs=doc.workbook().worksheet("Sheet1");
    LinhKien lk;
    string mlk,tlk,ncc,ts_str;
    float g;
    double sl,ts;
    cout<<"Nhap ma linh kien: ";
    cin>>mlk;
    cout<<"Nhap ten linh kien: ";
    cin.ignore();
    getline(cin,tlk);
    cout<<"Nhap nha cung cap: ";
    getline(cin,ncc);
    cout<<"Nhap gia linh kien: ";
    cin>>g;
    cout<<"Nhap so luong linh kien: ";
    cin>>sl;
    cout<<"Nhap thong so linh kien (co don vi): ";
    cin.ignore();
    getline(cin,ts_str);
   ts=parseValue(ts_str, ts_str);
    lk.nhap(mlk,tlk,ncc,g,sl,ts);
     lk.setGiaTri(ts_str);
    map_linhkien.insert(lk.getTenLK(),lk);
     map_maLK.insert(lk.getMaLK(),lk);
    sizelk++;
   int row=wbs.lastCell().rowAsNumber("A")+1;
   wbs.cell("A" + std::to_string(row)).value()=lk.getTenLK();
   wbs.cell("B" + std::to_string(row)).value()=lk.getMaLK();
   wbs.cell("C" + std::to_string(row)).value()=lk.getSoLuong();
   wbs.cell("D" + std::to_string(row)).value()=to_string(lk.getThongSo())+" "+lk.getGiatri();
   wbs.cell("E" + std::to_string(row)).value()=lk.getNhaCungCap();
   doc.save();
   doc.close();
}

   void luu_LK_txt(){
   ofstream out("../data/OUTPUT/linhkien.txt");
if (!out.is_open()) {
    cout << "Khong mo duoc file!" << endl;
    return;
}
out << "Danh sach linh kien hien co trong thu vien: " << sizelk<<endl;

for (int i=0;i<map_linhkien.size;i++){
if (map_linhkien.table[i].getHead()!=nullptr)
    {
         LlistNode* temp=map_linhkien.table[i].getHead();
         while(temp!=nullptr)
         {
              out<< "Ten linh kien:" << temp->data.getTenLK() << "Ma linh kien " << temp->data.getMaLK() << "\t  " << temp->data.getSoLuong() << "\t"
                << (temp->data.getTrangThai() ? "Con hang" : "Het hang") << "  tThong so:  "
                << temp->data.getThongSo() << " " << temp->data.getGiatri() << " Nha cung cap: "
                << temp->data.getNhaCungCap() << endl;
              
               temp=temp->next;
         }
    }
   
   }
    out.close();
}
