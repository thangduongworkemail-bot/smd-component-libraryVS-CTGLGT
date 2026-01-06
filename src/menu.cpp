#include<iostream>
#include"../include/menu.h"
using namespace std;
void displayMenu(){
    cout<<"--------------------------------------MENU-------------------------------"<<endl;
    cout<<"\t1. Nhap linh kien moi vao thu vien"<<endl;
    cout<<"\t2. Xuat toan bo danh sach linh kien trong thu vien"<<endl;
    cout<<"\t3. Xuat Linh kien ra file txt"<<endl;
    cout<<"\t4. Tim kiem theo gia tri cho truoc"<<endl;
    cout<<"\t5. Tim kiem linh kien theo ma hoac ten linh kien"<<endl;
    cout<<"\t6. Thoat chuong trinh"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Vui long nhap so de lua chon chuc nang: \n";
}
void menu(){
  displayMenu();
     luutru_linhkien();
     int k=10;
    string key;
    while(k!=6){
          
        cin>>key;
        if(isdigit(key[0])==false){
            cout<<"Vui long nhap so de lua chon!"<<endl;
            key.clear();
            continue;
        }
        double value = stod(key.substr(0, 1));
        k = static_cast<int>(value);
        switch(k){
            case 1:
                option1();
                displayMenu();
                break;
            case 2:
                option2();
                cout<<"Nhan phim bat ky de tiep tuc..."<<endl;
                cin.ignore();
                displayMenu();
                break;
            case 3:
                option3();
                cout<<"Da luu linh kien ra file txt thanh cong!"<<endl;
                cout<<" nhan phim bat ky de tiep tuc..."<<endl;
                cin.ignore();
                displayMenu();
                break;
            case 4:
                //option4();
                //displayMenu();
                break;
            case 5:
                option5();
                displayMenu();
                break;
            case 6:
                option6();
                break;
            default:
                cout<<"Lua chon khong hop le, vui long chon lai!"<<endl;
        }
    }
}
void option1(){
    nhaplinhkien();
}
void option2(){
  cout<<"Danh sach linh kien hien co trong thu vien:"<< sizelk<<endl;
    xuatlinhkien();
   
}

bool isCode(const string& s) {
    for (char c : s)
        if (isdigit(c)) return true;
    return false;
}
   void option5() {
    int temp=1;
    while(temp){
    string key;
    
    cout << "Nhap tu khoa can tim: ";
    cin.ignore(1000, '\n');
getline(cin, key);
    // chuẩn hóa về lowercase
    Llist* result1 = nullptr;

Llist* result2 = nullptr;
 result1 = map_maLK.search_key(key);
   result2 = map_linhkien.search_key(key);
    if (result1 != nullptr && result1->getHead() != nullptr) {
    
        while (result1->getHead() != nullptr) {
            if (result1->getHead()->data.getMaLK() == key) {
                cout << "Linh kien tim thay:\n";
                cout << "Ten linh kien: " << result1->getHead()->data.getTenLK() << endl;
                cout << "Ma linh kien: " << result1->getHead()->data.getMaLK() << endl;
                cout << "So luong: " << result1->getHead()->data.getSoLuong() << endl;
                cout << "Trang thai: " << (result1->getHead()->data.getTrangThai() ? "Con hang" : "Het hang") << endl;
                cout << "Thong so: " << result1->getHead()->data.getThongSo() << " " << result1->getHead()->data.getGiatri() << endl;
                cout << "Nha cung cap: " << result1->getHead()->data.getNhaCungCap() << endl;
                cout << "-------------------------------------" << endl;
                temp=1;
                break;
            } 
            result1->initList(result1->getHead()->next);
        }
     }
       if (result2 != nullptr && result2->getHead() != nullptr) {
        while (result2->getHead() != nullptr) {
            if (result2->getHead()->data.getTenLK() == key ) {
                cout << "Linh kien tim thay:\n";
                cout << "Ten linh kien: " << result2->getHead()->data.getTenLK() << endl;
                cout << "Ma linh kien: " << result2->getHead()->data.getMaLK() << endl;
                cout << "So luong: " << result2->getHead()->data.getSoLuong() << endl;
                cout << "Trang thai: " << (result2->getHead()->data.getTrangThai() ? "Con hang" : "Het hang") << endl;
                cout << "Thong so: " << result2->getHead()->data.getThongSo() << " " << result2->getHead()->data.getGiatri() << endl;
                cout << "Nha cung cap: " << result2->getHead()->data.getNhaCungCap() << endl;
                cout << "-------------------------------------" << endl;
                temp=1;
                break;
             } 
            result2->initList(result2->getHead()->next);
            
           }
        }
        if (temp!=1)
        cout << "Khong tim thay linh kien!\n";
cout<<"Nhan 1 de tiep tuc tim kiem, 0 de thoat chuc nang tim kiem!"<<endl;
cin>>temp;
    }
}
void option6(){
    cout<<"Thoat chuong trinh!"<<endl;
}
   void option3(){
   luu_LK_txt();
   }
        

    
    
