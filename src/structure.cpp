#include"../include/structure.h"

void Llist::initList(LlistNode* hed){ 
    if(hed==nullptr){
    head = hed;
size=1;
    }
    else{
    insertAtEnd(hed->data);
    size++;
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
        return;
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
    LlistNode* temp=head;
    while(temp!=nullptr){
        cout<<temp->data.getMaLK()<<" "<<temp->data.getTenLK()<<" "<<temp->data.getSoLuong()<<endl;
        temp=temp->next;
    }
}
 int djb2Hash( std::string& key, int size){
     int hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % size;
}
STR_Map::STR_Map(int s, STRING_HASH_FUNC func)
    : size(s), hashFunc(func)
{
    table = new Llist[size];
     for(int i=0;i<size;i++){
        table[i]=Llist();
    }
}
void STR_Map::initMap(int s, STRING_HASH_FUNC func){
    size=s;
    hashFunc=func;
    table=new Llist[size];
    for(int i=0;i<size;i++){
        table[i]=Llist();
    }
}
void STR_Map::insert(string key, LinhKien* value){
    int index=hashFunc(key,size);
    table[index].insertAtEnd(*value);
}
STR_Map::~STR_Map(){
    for(int i=0;i<size;i++){
        table[i].deleteList();
    }
    delete[] table;
}