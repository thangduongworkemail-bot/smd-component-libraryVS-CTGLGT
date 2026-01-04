#include<iostream>
#include"../include/menu.h"
using namespace std;
void menu(){
    cout<<"==========MENU QUAN LY LINH KIEN DIEN TU=========="<<endl;
    cout<<"1. Nhap linh kien"<<endl;
    cout<<"2. Xuat danh sach linh kien"<<endl;
    cout<<"3. Sua linh kien"<<endl;
    cout<<"4. Xoa linh kien"<<endl;
    cout<<"5. Tim kiem linh kien"<<endl;
    cout<<"6. Thoat"<<endl;
    cout<<"==============================================="<<endl;
    cout<<"Nhap lua chon cua ban: ";
    void luuutru_linhkien();
}
void option1(){
    nhaplinhkien();
}
void option2(){
    xuatlinhkien();
}
bool isname(std::string name){
    for (char & c : name) {
        int lower=c;
        if(lower>=65 && lower<=90){
            c=lower+32;
        }
    }
    if(name=="capacitor" || name=="resistor" || name=="inductor"){
        return true;
    }
    return false;

}
void opton5(){

    std::string key;
    cout << "Nhap ten linh kien can tim: "<< endl;
    cin >> key;
    int count=0;;
    for (char c:key){
        if (c==' '){
            count++;
        }
    }
    if(count ==0){
        if(isname(key)){
        Llist * temp = map_linhkien.search_key(key);
        }
        else{
             Llist * temp1 = map_linhkien.search_key(key);
              Llist * temp2 = map_linhkien.search_key(key);

        }
        
        
    }
    else if(count >1){


    }
        

    
    
}