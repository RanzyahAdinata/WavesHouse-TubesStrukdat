#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/* INFOTYPE */

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

/* ELEMEN */

struct elm_barang {
    infotype_barang info;
    elm_barang *next;
};

struct elm_gudang {
    infotype_gudang info;
    elm_gudang *next;
    elm_barang *firstChild;
};

/* POINTER */

typedef elm_barang* adr_barang;
typedef elm_gudang* adr_gudang;

/* LIST */

struct list_barang {
    adr_barang first;
};

struct list_gudang {
    adr_gudang first;
};

/* CREATE */

void createListGudang(list_gudang &LG);
void createListBarang(list_barang &LB);

/* ALOKASI */

adr_gudang alokasiGudang(infotype_gudang x);
adr_barang alokasiBarang(infotype_barang x);

/* INSERT */

void insertGudang(list_gudang &LG, adr_gudang G);
void insertBarangKeGudang(list_gudang &LG, string idGudang, adr_barang B);

/* DELETE */

void deleteGudang(list_gudang &LG, string idGudang);
void deleteBarang(list_gudang &LG, string idGudang, string idBarang);

/* SEARCH & CEK */

bool cekgudangnull(adr_gudang x);
bool cekbarangnull(adr_barang x);
adr_gudang searchGudang(list_gudang LG, string idGudang);
adr_barang searchBarang(adr_gudang G, string idBarang);

/* SHOW */

void showSemuaGudang(list_gudang LG);
void showBarangGudang(list_gudang LG, string idGudang);
void showSemuaBarangUnik(list_gudang LG);
void showbarangtertentu(adr_barang q);

/* HITUNG STOK */

adr_barang stokTerbanyak(list_gudang LG);
adr_barang stokTersedikit(list_gudang LG);
adr_barang stokTerbanyakPergudang(list_gudang LG, adr_gudang z);
adr_barang stokTersedikitPergudang(list_gudang LG, adr_gudang z);

int hitungTotalStokGudang(list_gudang LG, string idGudang);
int hitungStokBarangTertentu(list_gudang LG, string idGudang, string idBarang);

/* CARI BARANG */

void cariBarangRusak(list_gudang LG);

/* SORTING GUDANG (ALFABET) */

void sortGudangAsc(list_gudang &LG);
void sortGudangDesc(list_gudang &LG);

/* SORTING BARANG PER GUDANG (STOK) */

void sortBarangStokAsc(adr_gudang G);   
void sortBarangStokDesc(adr_gudang G);

/* SORTING BARANG SEMUA GUDANG (STOK) */

void sortBarangStokAscGlobal(list_gudang &LG);
void sortBarangStokDescGlobal(list_gudang &LG);

/* MENU */

void ui();

#endif



