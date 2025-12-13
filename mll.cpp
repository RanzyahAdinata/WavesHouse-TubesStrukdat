#include <iostream>
#include "mll.h"

using namespace std;

/* create list gudang n barang */
void createListGudang(list_gudang &LG) {
    LG.first = nullptr;
}

void createListBarang(list_barang &LB) {
    LB.first = nullptr;
}

void createListRelasi(list_relasi &LR) {
    LR.first = nullptr;
}

/* alokasi infotype ke list */
adr_gudang alokasiGudang(infotype_gudang x) {
    adr_gudang G = new elm_gudang;
    G->info = x;
    G->next = nullptr;
    return G;
}

adr_barang alokasiBarang(infotype_barang x) {
    adr_barang B = new elm_barang;
    B->info = x;
    B->next = nullptr;
    return B;
}

adr_relasi alokasiRelasi(adr_gudang G, adr_barang B) {
    adr_relasi R = new elm_relasi;
    R->gudang = G;
    R->barang = B;
    R->next = nullptr;
    return R;
}

/* tambah gudang, barang dan relasi baru ke list */
void insertGudang(list_gudang &LG, adr_gudang G) {
    G->next = LG.first;
    LG.first = G;
}

void insertBarang(list_barang &LB, adr_barang B) {
    B->next = LB.first;
    LB.first = B;
}

void insertRelasi(list_relasi &LR, adr_gudang G, adr_barang B) {
    adr_relasi R = alokasiRelasi(G, B);
    R->next = LR.first;
    LR.first = R;
}

/* search */
adr_gudang searchGudang(list_gudang LG, string idGudang) {
    // I.S : List gudang tersedia
    // F.S : Alamat gudang ditemukan atau nullptr
}

adr_barang searchBarangByID(list_barang LB, string idBarang) {
    // I.S : List barang tersedia
    // F.S : Alamat barang ditemukan atau nullptr
}

adr_barang searchBarangByNama(list_barang LB, string namaBarang) {
    // I.S : List barang tersedia
    // F.S : Alamat barang ditemukan atau nullptr
}

/* edit / update data gudang or barang or relasi di list */
void editGudang(list_gudang &LG, string idGudang) {
    // I.S : Gudang mungkin ada
    // F.S : Data gudang diperbarui
}

void editBarang(list_barang &LB, string idBarang) {
    // I.S : Barang mungkin ada
    // F.S : Data barang diperbarui
}

void editRelasi(list_relasi &LR, list_gudang LG, string idGudangLama, string idGudangBaru, string idBarang) {
    // I.S : Relasi lama mungkin ada
    // F.S : Relasi menunjuk gudang baru
}

/* hapus data gudang, barang, ato relasi dari list*/
void deleteGudang(list_gudang &LG, string idGudang) {
    // I.S : List gudang mungkin kosong
    // F.S : Gudang terhapus dari list
}

void deleteBarang(list_barang &LB, string idBarang) {
    // I.S : List barang mungkin kosong
    // F.S : Barang terhapus dari list
}

void deleteRelasi(list_relasi &LR, string idGudang, string idBarang) {
    // I.S : Relasi mungkin ada
    // F.S : Relasi terhapus dari list
}

/* tampilin data gudang, barang, atau barang di gudang yang available */
void showGudang(list_gudang LG) {
    // I.S : List gudang tersedia
    // F.S : Data gudang ditampilkan
}

void showBarang(list_barang LB) {
    // I.S : List barang tersedia
    // F.S : Data barang ditampilkan
}

void showBarangGudang(list_relasi LR, string idGudang) {
    // I.S : List relasi tersedia
    // F.S : Barang pada gudang ditampilkan
}

/* fitur gimmick */
int hitungTotalBarangPerKomoditas(list_barang LB, string komoditas) {
    // I.S : List barang tersedia
    // F.S : Total kuantitas barang dikembalikan
}

void tampilBarangRusak(list_barang LB) {
    // I.S : List barang tersedia
    // F.S : Barang rusak ditampilkan
}

adr_barang stokTerbanyak(list_barang LB) {
    // I.S : List barang tidak kosong
    // F.S : Barang dengan stok terbesar dikembalikan
}

adr_barang stokTersedikit(list_barang LB) {
    // I.S : List barang tidak kosong
    // F.S : Barang dengan stok terkecil dikembalikan
}
