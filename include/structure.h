#ifndef STRUCTURE_H
#define STRUCTURE_H
#include"linhkien.h"
typedef  int (*STRING_HASH_FUNC)(string& key, int size);



 struct LlistNode {
    LinhKien data;
    struct LlistNode* next;
};
typedef struct LlistNode LlistNode;

class Llist{
    LlistNode* head;
    int size;
public:
Llist(){
    head=nullptr;
    size=0;
}
void initList(LlistNode* hed);
void insertAtEnd( LinhKien lk);
void insertAtBeginning(LinhKien lk);
void deleteNode(LinhKien lk);
void deleteList();
void printList();
LlistNode* getHead(){
    return head;
    }
     LlistNode* getlast();
};
class STR_Map{
    public:
    int size;
    STRING_HASH_FUNC hashFunc;
    Llist* table;

    STR_Map(int s, STRING_HASH_FUNC func);
    void initMap(int s, STRING_HASH_FUNC func);
    void insert(string key, LinhKien* value);
    Llist* search_key(string key);
    void remove(string key);
  ~STR_Map();
};

 int djb2Hash( std::string& key, int size);

#endif // STRUCTURE_H