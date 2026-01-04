#ifndef IO_LINHKIEN_H
#define IO_LINHKIEN_H
#include"linhkien.h"
#include"../include/structure.h"


extern STR_Map map_linhkien(100,djb2Hash);
    extern STR_Map map_maLK(600,djb2Hash);
extern LinhKien lk[5000];
extern int sizelk;
void xuatlinhkien();
void luutru_linhkien();
void nhaplinhkien();
void sualinhkien();
void xoalinhkien();
void timkiemlinhkien();
 

#endif // IO_LINHKIEN_H