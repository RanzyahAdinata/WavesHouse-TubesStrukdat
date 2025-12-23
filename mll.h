#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/* INFOTYPE gudang n barang*/

struct infotype_barang {
    string id_barang;
    string nama_barang;
    int kuantitas;
    string jenis_komoditas;
    string kondisi;
};

struct infotype_gudang {
    string id_gudang;
    string nama_gudang;
};

/* ELEMEN gudang n barang */

struct elm_barang {
    infotype_barang info;
    elm_barang *next;
};

struct elm_gudang {
    infotype_gudang info;
    elm_gudang *next;
    elm_barang *firstChild;   // pointer ke list barang
};

/*  POINTER gudang n barang */

typedef elm_barang* adr_barang;
typedef elm_gudang* adr_gudang;

/* LIST gudang n barang */

struct list_barang {
    adr_barang first;
};

struct list_gudang {
    adr_gudang first;
};

/* CRUD disini */

void createListGudang(list_gudang &LG);
void createListBarang(list_barang &LB);

adr_gudang alokasiGudang(infotype_gudang x);
adr_barang alokasiBarang(infotype_barang x);

void insertGudang(list_gudang &LG, adr_gudang G);
void insertBarangKeGudang(list_gudang &LG, string idGudang, adr_barang B);

void deleteGudang(list_gudang &LG, string idGudang);
void deleteBarang(list_gudang &LG, string idGudang, string idBarang);

bool cekgudangnull(adr_gudang x);
bool cekbarangnull(adr_barang x);
adr_gudang searchGudang(list_gudang LG, string idGudang);
adr_barang searchBarang(adr_gudang G, string idBarang);

void showSemuaGudang(list_gudang LG);
void showBarangGudang(list_gudang LG, string idGudang);
void showSemuaBarangUnik(list_gudang LG);
void showbarangtertentu(adr_barang q);

/* FITUR : hitung stok nya */

adr_barang stokTerbanyak(list_gudang LG);
adr_barang stokTerbanyakPergudang(list_gudang LG, adr_gudang z);
adr_barang stokTersedikit(list_gudang LG);
adr_barang stokTersedikitPergudang(list_gudang LG, adr_gudang z);
int hitungTotalStokGudang(list_gudang LG, string idGudang);
int hitungStokBarangTertentu(list_gudang LG, string idGudang, string idBarang);

/* FITUR : cari barang spesifik */

void cariBarangRusak(list_gudang LG);

/*FITUR : MENU*/
void ui();
#endif


