#include <iostream>
#include "mll.h"

using namespace std;

/* CREATE list gudang n barang , kemudian allocate ke list*/
void createListGudang(list_gudang &LG) {
    LG.first = nullptr;
}

void createListBarang(list_barang &LB) {
    LB.first = nullptr;
}

adr_gudang alokasiGudang(infotype_gudang x) {
    adr_gudang G = new elm_gudang;
    G->info = x;
    G->next = nullptr;
    G->firstChild = nullptr;
    return G;
}

adr_barang alokasiBarang(infotype_barang x) {
    adr_barang B = new elm_barang;
    B->info = x;
    B->next = nullptr;
    return B;
}

/* CRUD disini */
void insertGudang(list_gudang &LG, adr_gudang G) {
    G->next = LG.first;
    LG.first = G;
}

void insertBarangKeGudang(list_gudang &LG, string idGudang, adr_barang B) {
    adr_gudang G = searchGudang(LG, idGudang);
    if (G != nullptr) {
        B->next = G->firstChild;
        G->firstChild = B;
    }
}

adr_gudang searchGudang(list_gudang LG, string idGudang) {
    /* I.S : List gudang berisi data */
    /* F.S : Alamat gudang dikembalikan atau NULL */
    return nullptr;
}

adr_barang searchBarang(adr_gudang G, string idBarang) {
    /* I.S : Gudang memiliki list barang */
    /* F.S : Alamat barang dikembalikan atau NULL */
    return nullptr;
}

void deleteBarang(list_gudang &LG, string idGudang, string idBarang) {
    /* I.S : Barang mungkin ada di gudang */
    /* F.S : Barang dihapus dari gudang */
}

void deleteGudang(list_gudang &LG, string idGudang) {
    /* I.S : Gudang mungkin ada di list */
    /* F.S : Gudang dihapus dari list */
}

void showSemuaGudang(list_gudang LG) {
    /* I.S : List gudang berisi data */
    /* F.S : Data gudang ditampilkan */
}

void showBarangGudang(list_gudang LG, string idGudang) {
    /* I.S : Gudang memiliki barang */
    /* F.S : Barang gudang ditampilkan */
}

void showSemuaBarangUnik(list_gudang LG) {
    /* I.S : List gudang dan barang berisi data */
    /* F.S : Seluruh barang ditampilkan */
}

/* FITUR : hitung stok nya */
adr_barang stokTerbanyak(list_gudang LG) {
    /* I.S : List gudang dan barang berisi data */
    /* F.S : Barang dengan stok terbanyak dikembalikan */
}

adr_barang stokTersedikit(list_gudang LG) {
    /* I.S : List gudang dan barang berisi data */
    /* F.S : Barang dengan stok tersedikit dikembalikan */
}

int hitungTotalStokGudang(list_gudang LG, string idGudang) {
    /* I.S : Gudang memiliki barang */
    /* F.S : Total stok gudang dikembalikan */
}

int hitungStokBarangTertentu(list_gudang LG, string idGudang, string namaBarang) {
    /* I.S : Gudang dan nama barang diketahui */
    /* F.S : Total stok barang tertentu dikembalikan */
}

/* FITUR : cari barang spesifik */
void cariBarangRusak(list_gudang LG) {
    /* I.S : List gudang dan barang berisi data */
    /* F.S : Barang rusak ditampilkan */
}
