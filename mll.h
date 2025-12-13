#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/* INFOTYPE */

struct infotype_gudang {
    string id_gudang;
    string nama_gudang;
};

struct infotype_barang {
    string id_barang;
    string nama_barang;
    int kuantitas;
    string jenis_komoditas;
    string kondisi;
};

/* ELEMEN */

struct elm_gudang {
    infotype_gudang info;
    elm_gudang *next;
    struct elm_relasi *firstRelasi;
};

struct elm_barang {
    infotype_barang info;
    elm_barang *next;
};

struct elm_relasi {
    elm_barang *barang;
    elm_relasi *next;
};

/* POINTER */

typedef elm_gudang* adr_gudang;
typedef elm_barang* adr_barang;
typedef elm_relasi* adr_relasi;

/* LIST */

struct list_gudang {
    adr_gudang first;
};

struct list_barang {
    adr_barang first;
};

/* PROTOTYPE */

void createListGudang(list_gudang &LG);
void createListBarang(list_barang &LB);

adr_gudang alokasiGudang(infotype_gudang x);
adr_barang alokasiBarang(infotype_barang x);
adr_relasi alokasiRelasi(adr_barang B);

void insertGudang(list_gudang &LG, adr_gudang G);
void insertBarang(list_barang &LB, adr_barang B);
void insertRelasi(list_gudang &LG, string idGudang, adr_barang B);

adr_gudang searchGudang(list_gudang LG, string idGudang);
adr_barang searchBarangByID(list_barang LB, string idBarang);
adr_barang searchBarangByNama(list_barang LB, string namaBarang);

void deleteGudang(list_gudang &LG, string idGudang);
void deleteBarang(list_barang &LB, string idBarang);
void deleteRelasi(list_gudang &LG, string idGudang, string idBarang);

void showGudang(list_gudang LG);
void showBarang(list_barang LB);
void showBarangGudang(list_gudang LG, string idGudang);

int hitungTotalBarangPerKomoditas(list_barang LB, string komoditas);
void tampilBarangRusak(list_barang LB);
adr_barang stokTerbanyak(list_barang LB);
adr_barang stokTersedikit(list_barang LB);

#endif
