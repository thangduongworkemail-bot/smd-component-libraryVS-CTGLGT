#include"../include/structure.h"

void Llist::initList(LlistNode* hed){ 
    
    head = hed;
    if (head == nullptr) {
        size = 0;
    } else {
        size = 1;
        LlistNode* temp = head;
        while (temp->next != nullptr) {
            size++;
            temp = temp->next;
        }
}
}
void Llist::insertAtEnd(LinhKien lk)
{
    LlistNode *newNode=new LlistNode;
    newNode->data=lk;
    newNode->next=nullptr;
    if(head==nullptr)
{
    head=newNode;
}
else{
    LlistNode *temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
size++;
}
void Llist::insertAtBeginning( LinhKien lk) {
    LlistNode* newNode = new LlistNode;
    newNode->data = lk;
    newNode->next = head;
    head = newNode;
    size++;
}
void Llist:: deleteList()
{
    if (head == nullptr) return;
    LlistNode* current = head;
    LlistNode* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    size = 0;
    head = nullptr;
}
LlistNode* Llist:: getlast(){
    LlistNode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    return temp;
}
void Llist:: deleteNode(LinhKien lk){
    if(head==nullptr) return;
    LlistNode* temp=head;
    LlistNode* prev=nullptr;
    while(temp!=nullptr && temp->data.getMaLK()!=lk.getMaLK()){
        prev=temp;
        temp=temp->next;
    }
    if(temp==nullptr) return;
    if(prev==nullptr){
        head=temp->next;
    }
    else{
        prev->next=temp->next;
    }
    delete temp;
    size--;
}

void Llist:: printList(){
    cout<<"Danh sach linh kien trong danh muc:"<<endl;
    LlistNode* temp=head;
    while(temp!=nullptr){
        
       
    cout<<"Ten linh kien: "<<temp->data.getTenLK()<<endl;
    cout<<"Ma linh kien: "<<temp->data.getMaLK()<<endl;
    cout<<"So luong: "<<temp->data.getSoLuong()<<endl;
    cout<<"Trang thai: "<<(temp->data.getTrangThai() ? "Con hang" : "Het hang")<<endl;
    cout<<"Thong so: "<<temp->data.getThongSo()<<" "<<temp->data.getGiatri()<<endl;
    cout<<"Nha cung cap: "<<temp->data.getNhaCungCap()<<endl;
    temp=temp->next;
    cout<<"-------------------------------------"<<endl;
    }
}
 int djb2Hash( std::string& key, int size){
     unsigned  long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % size;
}
STR_Map::STR_Map(int s, STRING_HASH_FUNC func)
    : size(s), hashFunc(func)
{
    sl=0;
    table = new Llist[size];
     for(int i=0;i<size;i++){
        table[i]=Llist();
    }
}
void STR_Map::initMap(int s, STRING_HASH_FUNC func){
    size=s;
    hashFunc=func;
    sl=0;
    table=new Llist[size];
    for(int i=0;i<size;i++){
        table[i]=Llist();
    }
}
void STR_Map::insert(string key, LinhKien value){
    int index=hashFunc(key,size);
    
    LlistNode* temp=table[index].getHead();
    while (temp!=nullptr)
    {
        if (temp->data.getMaLK() == value.getMaLK()) {
            // Cập nhật giá trị nếu khóa đã tồn tại
            cout<<"Chu Y!Da ton tai ma linh kien "<<value.getMaLK()<<", cap nhat thong tin!"<<endl;
             sl++;
            temp->data = value;
            return;
        }
        temp=temp->next;
    }
     sl++;
    table[index].insertAtBeginning(value);
      
}
Llist* STR_Map::search_key(string key){
    int index=hashFunc(key,size);
    return &table[index];
}
void STR_Map::deletemap(){
    for(int i=0;i<size;i++){
        table[i].deleteList();
    }
    delete[] table;
}
int partition(LinhKien a[], int low, int high) {
    double pivot = a[high].getThongSo();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j].getThongSo() < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(LinhKien a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}