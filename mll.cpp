#include <iostream>
#include "mll.h"
#include <cstdlib>
#include <limits>
#include <thread>
#include <chrono>

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

bool cekgudangnull(adr_gudang x){
    return x==nullptr;
}
bool cekbarangnull(adr_barang x){
    return x==nullptr;
}

adr_gudang searchGudang(list_gudang LG, string idGudang) {
    adr_gudang p = LG.first;
    while(p!=nullptr){
        if(p->info.id_gudang==idGudang){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adr_barang searchBarang(adr_gudang G, string idBarang) {
    adr_barang p = G->firstChild;
    while(p!=nullptr){
        if(p->info.id_barang == idBarang){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteBarang(list_gudang &LG, string idGudang, string idBarang) {
    adr_gudang p;
    adr_barang q,z;
    if (LG.first == nullptr) {
        cout << "Data Gudang kosong" << endl;
    }else {
        p = searchGudang(LG, idGudang);
        if (cekgudangnull(p)) {
            cout << "Data tidak ditemukan" << endl;
        }else {
            q = p->firstChild;
            if (q == nullptr) {
                cout << "Gudang tidak memiliki barang" << endl;
            }else {
                if (q->info.id_barang == idBarang) {
                    p->firstChild = q->next;
                    q->next = nullptr;
                }
                else {
                    while (q->next != nullptr) {
                        if (q->next->info.id_barang == idBarang) {
                            z = q->next;
                            q->next = z->next;
                            z->next = nullptr;
                        }
                        else {
                            q = q->next;
                        }
                    }
                }
            }
        }
    }
}

void deleteGudang(list_gudang &LG, string idGudang) {
    adr_gudang p,q;
    p = searchGudang(LG,idGudang);
    if(LG.first==nullptr){
        cout << "Data Barang sudah kosong" << endl;
    }else if(cekgudangnull(p)){
        cout << "Data tidak ditemukan" << endl;
    }else{
        if (LG.first == p) {
            LG.first = p->next;
        }
        else {
            q = LG.first;
            while (q->next != p) {
                q = q->next;
            }
            q->next = p->next;
        }
        p->next = nullptr;
        p->firstChild = nullptr;
        cout << "Gudang berhasil dihapus" << endl;
    }
}

void showSemuaGudang(list_gudang LG) {
    adr_gudang p = LG.first;
    if(LG.first==nullptr){
        cout << "Gudang Kosong" << endl;
    }else{
        while(p!=nullptr){
            cout << "ID Gudang: " << p->info.id_gudang << endl;
            cout << "Nama Gudang: " << p->info.nama_gudang << endl << endl;
            p = p->next;
        }
    }
}

void showBarangGudang(list_gudang LG, string idGudang) {
    adr_gudang p;
    adr_barang q;
    p = searchGudang(LG, idGudang);
    if (p == nullptr) {
        cout << "Data tidak ditemukan" << endl;
    }else {
        q = p->firstChild;
        if (cekbarangnull(q)) {
            cout << "Barang Kosong" << endl;
        }else {
            while (q != nullptr) {
                cout << "ID Barang: " << q->info.id_barang << endl;
                cout << "Nama Barang: " << q->info.nama_barang << endl;
                cout << "Kuantitas: " << q->info.kuantitas << endl;
                cout << "Jenis Komoditas: " << q->info.jenis_komoditas << endl;
                cout << "Kondisi: " << q->info.kondisi << endl << endl;
                q = q->next;
            }
        }
    }
}

void showSemuaBarangUnik(list_gudang LG) {
    adr_gudang p = LG.first;
    adr_barang q;
    if(p==nullptr){
            cout << "Barang Kosong" << endl;
    }else{
        while(p!=nullptr){
                q = p->firstChild;
                while(q!=nullptr){
                    cout << "ID Barang: " << q->info.id_barang << endl;
                    cout << "Nama Barang: " << q->info.nama_barang << endl;
                    cout << "Kuantitas: " << q->info.kuantitas << endl;
                    cout << "Jenis Komoditas: " << q->info.jenis_komoditas << endl;
                    cout << "Kondisi: " << q->info.kondisi << endl << endl;
                    q = q->next;
            }
        p=p->next;
        }
    }
}

/* FITUR : hitung stok nya */
adr_barang stokTerbanyak(list_gudang LG) {
    adr_barang max;
    adr_gudang p;
    if (LG.first == nullptr) {
        return nullptr;
    }
    p = LG.first;
    max = nullptr;
    while (p != nullptr) {
        adr_barang x = stokTerbanyakPergudang(LG, p);
        if (x != nullptr) {
            if (max == nullptr || x->info.kuantitas > max->info.kuantitas) {
                max = x;
            }
        }
        p = p->next;
    }
    return max;

}
adr_barang stokTerbanyakPergudang(list_gudang LG,adr_gudang z){
    adr_barang max,p;
    if (z == nullptr || z->firstChild == nullptr) {
        return nullptr;
    }
    max = z->firstChild;
    p   = z->firstChild;
    while (p != nullptr) {
        if (p->info.kuantitas > max->info.kuantitas) {
            max = p;
        }
        p = p->next;
    }

    return max;
}


adr_barang stokTersedikit(list_gudang LG) {
    adr_barang min;
    adr_gudang p;
     if (LG.first == nullptr) {
        return nullptr;
    }
    p = LG.first;
    min = nullptr;
    while (p != nullptr) {
        adr_barang x = stokTersedikitPergudang(LG, p);
        if (x != nullptr) {
            if (min == nullptr || x->info.kuantitas < min->info.kuantitas) {
                min = x;
            }
        }
        p = p->next;
    }
    return min;
}
adr_barang stokTersedikitPergudang(list_gudang LG, adr_gudang z){
    adr_barang min,p;
    if (z == nullptr || z->firstChild == nullptr) {
        return nullptr;
    }
    min = z->firstChild;
    p   = z->firstChild;
    while (p != nullptr) {
        if (p->info.kuantitas < min->info.kuantitas) {
            min = p;
        }
        p = p->next;
    }

    return min;
}

int hitungTotalStokGudang(list_gudang LG, string idGudang) {
    adr_gudang p;
    adr_barang q;
    p = searchGudang(LG,idGudang);
    int total = 0;
    q = p->firstChild;
    while(q!=nullptr){
        total=total+q->info.kuantitas;
        q = q->next;
    }
    return total;
}

int hitungStokBarangTertentu(list_gudang LG, string idGudang, string idBarang) {
    adr_barang p;
    adr_gudang q;
    q = searchGudang(LG,idGudang);
    p = searchBarang(q,idBarang);
    return p->info.kuantitas;
}

/* FITUR : cari barang spesifik */
void cariBarangRusak(list_gudang LG) {
    adr_gudang p = LG.first;
    if(LG.first==nullptr){
        cout << "Data Kosong" << endl;
    }else{
        while (p != nullptr) {
            adr_barang q = p->firstChild;
            while (q != nullptr) {
                if (q->info.kondisi == "Rusak") {
                    showbarangtertentu(q);
                }
                q = q->next;
            }
            p = p->next;
        }
    }
}

void showbarangtertentu(adr_barang q){
    cout << "────────────────────────────\n";
    cout << "🆔 ID Barang   : " << q->info.id_barang << endl;
    cout << "📦 Nama        : " << q->info.nama_barang << endl;
    cout << "🔢 Kuantitas   : " << q->info.kuantitas << endl;
    cout << "🏷 Jenis       : " << q->info.jenis_komoditas << endl;
    cout << "⚠ Kondisi     : " << q->info.kondisi << endl;
    cout << "────────────────────────────\n\n";
}


void ui() {
    cout << endl;
    cout << "╔════════════════════════════════════╗\n";
    cout << "║   🏭 WAVESHOUSE INVENTORY SYSTEM   ║\n";
    cout << "╚════════════════════════════════════╝\n";
    cout << "1.  ➕ Tambah Gudang\n";
    cout << "2.  📦 Tambah Barang ke Gudang\n";
    cout << "3.  🗑 Hapus Gudang\n";
    cout << "4.  ❌ Hapus Barang\n";
    cout << "5.  📋 Semua Gudang\n";
    cout << "6.  🏭 Barang per Gudang\n";
    cout << "7.  📦 Semua Barang\n";
    cout << "8.  📈 Stok Terbanyak\n";
    cout << "9.  📉 Stok Tersedikit\n";
    cout << "10. 📊 Total Stok Gudang\n";
    cout << "11. 📦 Stok Barang Tertentu\n";
    cout << "12. 🚨 Barang Rusak\n";
    cout << "0.  🚪 Keluar\n";
    cout << "────────────────────────────────────\n";
}


