#include <iostream>
#include "mll.h"

using namespace std;

/* create list gudang n barang */
void createListGudang(list_gudang &LG) {
    LG.first = NULL;
}

void createListBarang(list_barang &LB) {
    LB.first = NULL;
}

/* alokasi infotype ke list */
adr_gudang alokasiGudang(infotype_gudang x) {
    adr_gudang G = new elm_gudang;
    G->info = x;
    G->next = NULL;
    G->firstRelasi = NULL;
    return G;
}

adr_barang alokasiBarang(infotype_barang x) {
    adr_barang B = new elm_barang;
    B->info = x;
    B->next = NULL;
    return B;
}

adr_relasi alokasiRelasi(adr_barang B) {
    adr_relasi R = new elm_relasi;
    R->barang = B;
    R->next = NULL;
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

void insertRelasi(list_gudang &LG, string idGudang, adr_barang B) {
    adr_gudang G = searchGudang(LG, idGudang);
    if (G != NULL) {
        adr_relasi R = alokasiRelasi(B);
        R->next = G->firstRelasi;
        G->firstRelasi = R;
    }
}

/* search */
adr_gudang searchGudang(list_gudang LG, string idGudang) {
    // I.S : List gudang tersedia
    // F.S : Alamat gudang dikembalikan jika ada, NULL jika tidak
}

adr_barang searchBarangByID(list_barang LB, string idBarang) {
    // I.S : List barang tersedia
    // F.S : Alamat barang dikembalikan sesuai ID
}

adr_barang searchBarangByNama(list_barang LB, string namaBarang) {
    // I.S : List barang tersedia
    // F.S : Alamat barang dikembalikan sesuai nama
}

/* edit / update data gudang or barang or relasi di list */
void editGudang(list_gudang &LG, string idGudang) {
    // I.S : Gudang dengan ID tertentu mungkin ada
    // F.S : Data gudang diperbarui
}

void editBarang(list_barang &LB, string idBarang) {
    // I.S : Barang dengan ID tertentu mungkin ada
    // F.S : Data barang diperbarui
}

/* hapus data gudang, barang, ato relasi dari list*/
void deleteGudang(list_gudang &LG, string idGudang) {
    // I.S : List gudang mungkin kosong
    // F.S : Gudang dengan ID tertentu terhapus
}

void deleteBarang(list_barang &LB, string idBarang) {
    // I.S : List barang mungkin kosong
    // F.S : Barang dengan ID tertentu terhapus
}

void deleteRelasi(list_gudang &LG, string idGudang, string idBarang) {
    // I.S : Relasi mungkin ada
    // F.S : Relasi gudang–barang terhapus
}

/* tampilin data gudang, barang, atau barang di gudang yang available */
void showGudang(list_gudang LG) {
    // I.S : List gudang tersedia
    // F.S : Seluruh data gudang ditampilkan
}

void showBarang(list_barang LB) {
    // I.S : List barang tersedia
    // F.S : Seluruh data barang ditampilkan
}

void showBarangGudang(list_gudang LG, string idGudang) {
    // I.S : Gudang tersedia
    // F.S : Barang pada gudang ditampilkan
}

/* fitur gimmick */
int hitungTotalBarangPerKomoditas(list_barang LB, string komoditas) {
    // I.S : List barang tersedia
    // F.S : Total kuantitas per komoditas dikembalikan
}

void tampilBarangRusak(list_barang LB) {
    // I.S : List barang tersedia
    // F.S : Barang dengan kondisi rusak ditampilkan
}

adr_barang stokTerbanyak(list_barang LB) {
    // I.S : List barang tidak kosong
    // F.S : Alamat barang dengan stok terbesar dikembalikan
}

adr_barang stokTersedikit(list_barang LB) {
    // I.S : List barang tidak kosong
    // F.S : Alamat barang dengan stok terkecil dikembalikan
}
