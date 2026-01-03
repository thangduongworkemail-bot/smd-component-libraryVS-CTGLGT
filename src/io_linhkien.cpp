#include<iostream>
#include<cstring>
#include"../include/io_linhkien.h"
#include<OpenXLSX.hpp>
using namespace std;
using namespace OpenXLSX;
void xuatlinhkien(){
    XLDocument doc;
    doc.open("../data/linhkien.xlsx");
auto wbs = doc.workbook().worksheet("Sheet1");
XLCellValue a[10];
int i=2;
cout<<"-------------------------------Bang Linh Kien----------------------------------"<<endl;
while(wbs.cell("F" + std::to_string(i)).value().type() != XLValueType::Empty) {
    a[1]=wbs.cell("A" + std::to_string(i)).value();
    cout<<"\nten linh kien: "<<a[1];
     a[2]=wbs.cell("B" + std::to_string(i)).value();
    cout<<"\tma linh kien: "<<a[2];
        a[3]=wbs.cell("C" + std::to_string(i)).value();
    cout<<"\tso luong: "<<a[3];
        a[4]=wbs.cell("D" + std::to_string(i)).value();
    cout<<"\ttrang thai:"<<a[4];
        a[5]=wbs.cell("E" + std::to_string(i)).value();
    cout<<"\t thong so:"<<a[5];
        a[6]=wbs.cell("F" + std::to_string(i)).value();
    cout<<"\t nha cung cap:"<<a[6];i++;
}
   doc.close();
}
void luutru_linhkien(){
    STR_Map map_linhkien(100,djb2Hash);
    XLDocument doc;
    doc.open("../data/linhkien.xlsx");
    auto wbs=doc.workbook().worksheet("Sheet1");
    int i=2;
    cout<<"-----------------Hash Table Linh Kien-----------------"<<endl;
    while(wbs.cell("A" + std::to_string(i)).value().type() != XLValueType::Empty) 
    {
        LinhKien lk;
        lk.setTenLK(wbs.cell("A" + std::to_string(i)).value());
        lk.setMaLK(wbs.cell("B" + std::to_string(i)).value());
        lk.setSoLuong((wbs.cell("C" + std::to_string(i)).value()));
        if(lk.getSoLuong()>0) lk.setTrangThai(true);
        lk.setThongSo((wbs.cell("E" + std::to_string(i)).value()));
        lk.setNhaCungCap(wbs.cell("F" + std::to_string(i)).value());
        map_linhkien.insert(lk.getMaLK(),&lk);
        i++;
    }
     for(int j=0;j<map_linhkien.size;j++){
        cout<<"Bucket "<<j<<": ";
        map_linhkien.table[j].printList();
    }
    
}


    