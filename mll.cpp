#include <iostream>
#include "mll.h"
using namespace std;

/* CREATE */
void createListGudang(list_gudang &LG) {
    LG.first = nullptr;
}

void createListBarang(list_barang &LB) {
    LB.first = nullptr;
}

/* ALOKASI */
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

/* INSERT */
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

/* UPDATE GUDANG */
void updateGudang(list_gudang &LG, string idGudang, string namaBaru) {
    adr_gudang g = searchGudang(LG, idGudang);
    if (g == nullptr) {
        cout << "Gudang tidak ditemukan" << endl;
    } else {
        g->info.nama_gudang = namaBaru;
        cout << "Data gudang berhasil diperbarui" << endl;
    }
}

/* UPDATE BARANG */
void updateBarang(
    list_gudang &LG,
    string idGudang,
    string idBarang,
    string namaBaru,
    int stokBaru,
    string jenisBaru,
    string kondisiBaru
) {
    adr_gudang g = searchGudang(LG, idGudang);
    if (g == nullptr) {
        cout << "Gudang tidak ditemukan" << endl;
        return;
    }

    adr_barang b = searchBarang(g, idBarang);
    if (b == nullptr) {
        cout << "Barang tidak ditemukan" << endl;
    } else {
        b->info.nama_barang = namaBaru;
        b->info.kuantitas = stokBaru;
        b->info.jenis_komoditas = jenisBaru;
        b->info.kondisi = kondisiBaru;
        cout << "Data barang berhasil diperbarui" << endl;
    }
}


/* CEK */
bool cekgudangnull(adr_gudang x) {
    return x == nullptr;
}

bool cekbarangnull(adr_barang x) {
    return x == nullptr;
}

/* SEARCH */
adr_gudang searchGudang(list_gudang LG, string idGudang) {
    adr_gudang p = LG.first;
    while (p != nullptr) {
        if (p->info.id_gudang == idGudang)
            return p;
        p = p->next;
    }
    return nullptr;
}

adr_barang searchBarang(adr_gudang G, string idBarang) {
    if (G == nullptr) return nullptr;
    adr_barang p = G->firstChild;
    while (p != nullptr) {
        if (p->info.id_barang == idBarang)
            return p;
        p = p->next;
    }
    return nullptr;
}

/* DELETE */
void deleteBarang(list_gudang &LG, string idGudang, string idBarang) {
    adr_gudang p;
    adr_barang q, z;

    if (LG.first == nullptr) {
        cout << "Data Gudang kosong" << endl;
    }
    else {
        p = searchGudang(LG, idGudang);
        if (cekgudangnull(p)) {
            cout << "Data Gudang tidak ditemukan" << endl;
        }
        else {
            q = p->firstChild;
            if (q == nullptr) {
                cout << "Gudang tidak memiliki barang" << endl;
            }
            else {
                if (q->info.id_barang == idBarang) {
                    p->firstChild = q->next;
                    q->next = nullptr;
                    cout << "Barang berhasil dihapus" << endl;
                }
                else {
                    while (q->next != nullptr) {
                        if (q->next->info.id_barang == idBarang) {
                            z = q->next;
                            q->next = z->next;
                            z->next = nullptr;
                            cout << "Barang berhasil dihapus" << endl;
                            return;
                        }
                        q = q->next;
                    }
                    cout << "Barang tidak ditemukan" << endl;
                }
            }
        }
    }
}


void deleteGudang(list_gudang &LG, string idGudang) {
    adr_gudang p, q;
    p = searchGudang(LG, idGudang);

    if (LG.first == nullptr) {
        cout << "Data Gudang sudah kosong" << endl;
    }
    else if (cekgudangnull(p)) {
        cout << "Data Gudang tidak ditemukan" << endl;
    }
    else {
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

/* SHOW */
void showSemuaGudang(list_gudang LG) {
    for (adr_gudang p = LG.first; p != nullptr; p = p->next) {
        cout << "ID Gudang   : " << p->info.id_gudang << endl;
        cout << "Nama Gudang : " << p->info.nama_gudang << endl << endl;
    }
}

void showBarangGudang(list_gudang LG, string idGudang) {
    adr_gudang g = searchGudang(LG, idGudang);
    if (g == nullptr) return;

    for (adr_barang b = g->firstChild; b != nullptr; b = b->next)
        showbarangtertentu(b);
}

void showSemuaBarangUnik(list_gudang LG) {
    for (adr_gudang g = LG.first; g != nullptr; g = g->next)
        for (adr_barang b = g->firstChild; b != nullptr; b = b->next)
            showbarangtertentu(b);
}

/* HITUNG STOK */
adr_barang stokTerbanyakPergudang(list_gudang, adr_gudang g) {
    if (g == nullptr || g->firstChild == nullptr) return nullptr;

    adr_barang max = g->firstChild;
    for (adr_barang p = g->firstChild; p != nullptr; p = p->next)
        if (p->info.kuantitas > max->info.kuantitas)
            max = p;
    return max;
}

adr_barang stokTersedikitPergudang(list_gudang, adr_gudang g) {
    if (g == nullptr || g->firstChild == nullptr) return nullptr;

    adr_barang min = g->firstChild;
    for (adr_barang p = g->firstChild; p != nullptr; p = p->next)
        if (p->info.kuantitas < min->info.kuantitas)
            min = p;
    return min;
}

adr_barang stokTerbanyak(list_gudang LG) {
    adr_barang max = nullptr;
    for (adr_gudang g = LG.first; g != nullptr; g = g->next) {
        adr_barang x = stokTerbanyakPergudang(LG, g);
        if (x && (!max || x->info.kuantitas > max->info.kuantitas))
            max = x;
    }
    return max;
}

adr_barang stokTersedikit(list_gudang LG) {
    adr_barang min = nullptr;
    for (adr_gudang g = LG.first; g != nullptr; g = g->next) {
        adr_barang x = stokTersedikitPergudang(LG, g);
        if (x && (!min || x->info.kuantitas < min->info.kuantitas))
            min = x;
    }
    return min;
}

int hitungTotalStokGudang(list_gudang LG, string idGudang) {
    int total = 0;
    adr_gudang g = searchGudang(LG, idGudang);
    if (!g) return 0;

    for (adr_barang b = g->firstChild; b != nullptr; b = b->next)
        total += b->info.kuantitas;
    return total;
}

int hitungStokBarangTertentu(list_gudang LG, string idGudang, string idBarang) {
    adr_barang b = searchBarang(searchGudang(LG, idGudang), idBarang);
    return b ? b->info.kuantitas : 0;
}

/* SORT GUDANG */
void sortGudangAsc(list_gudang &LG) {
    for (adr_gudang i = LG.first; i != nullptr; i = i->next)
        for (adr_gudang j = i->next; j != nullptr; j = j->next)
            if (i->info.nama_gudang > j->info.nama_gudang) {
                swap(i->info, j->info);
                swap(i->firstChild, j->firstChild);
            }
}

void sortGudangDesc(list_gudang &LG) {
    for (adr_gudang i = LG.first; i != nullptr; i = i->next)
        for (adr_gudang j = i->next; j != nullptr; j = j->next)
            if (i->info.nama_gudang < j->info.nama_gudang) {
                swap(i->info, j->info);
                swap(i->firstChild, j->firstChild);
            }
}

/* SORT BARANG STOK */
void sortBarangStokAsc(adr_gudang G) {
    if (!G) return;
    for (adr_barang i = G->firstChild; i != nullptr; i = i->next)
        for (adr_barang j = i->next; j != nullptr; j = j->next)
            if (i->info.kuantitas > j->info.kuantitas)
                swap(i->info, j->info);
}

void sortBarangStokDesc(adr_gudang G) {
    if (!G) return;
    for (adr_barang i = G->firstChild; i != nullptr; i = i->next)
        for (adr_barang j = i->next; j != nullptr; j = j->next)
            if (i->info.kuantitas < j->info.kuantitas)
                swap(i->info, j->info);
}

void sortBarangStokAscGlobal(list_gudang &LG) {
    for (adr_gudang g = LG.first; g != nullptr; g = g->next)
        sortBarangStokAsc(g);
}

void sortBarangStokDescGlobal(list_gudang &LG) {
    for (adr_gudang g = LG.first; g != nullptr; g = g->next)
        sortBarangStokDesc(g);
}

/* SORT BARANG ALFABET */
void sortBarangNamaAsc(adr_gudang G) {
    if (!G) return;
    for (adr_barang i = G->firstChild; i != nullptr; i = i->next)
        for (adr_barang j = i->next; j != nullptr; j = j->next)
            if (i->info.nama_barang > j->info.nama_barang)
                swap(i->info, j->info);
}

void sortBarangNamaDesc(adr_gudang G) {
    if (!G) return;
    for (adr_barang i = G->firstChild; i != nullptr; i = i->next)
        for (adr_barang j = i->next; j != nullptr; j = j->next)
            if (i->info.nama_barang < j->info.nama_barang)
                swap(i->info, j->info);
}

void sortBarangNamaAscGlobal(list_gudang &L) {
    adr_gudang g = L.first;
    while (g != NULL) {
        sortBarangNamaAsc(g);
        g = g->next;
    }
}

void sortBarangNamaDescGlobal(list_gudang &L) {
    adr_gudang g = L.first;
    while (g != NULL) {
        sortBarangNamaDesc(g);
        g = g->next;
    }
}

/* BARANG RUSAK */
void cariBarangRusak(list_gudang LG) {
    for (adr_gudang g = LG.first; g != nullptr; g = g->next)
        for (adr_barang b = g->firstChild; b != nullptr; b = b->next)
            if (b->info.kondisi == "Rusak")
                showbarangtertentu(b);
}

/* TAMPIL BARANG */
void showbarangtertentu(adr_barang q) {
    cout << "────────────────────────────\n";
    cout << "🆔 ID Barang   : " << q->info.id_barang << endl;
    cout << "📦 Nama        : " << q->info.nama_barang << endl;
    cout << "🔢 Kuantitas   : " << q->info.kuantitas << endl;
    cout << "🏷 Jenis       : " << q->info.jenis_komoditas << endl;
    cout << "⚠ Kondisi     : " << q->info.kondisi << endl;
    cout << "────────────────────────────\n\n";
}

/* UI */
void ui() {
    cout << endl;
    cout << "╔════════════════════════════════════╗\n";
    cout << "║   🏭 WAVESHOUSE INVENTORY SYSTEM   ║\n";
    cout << "╚════════════════════════════════════╝\n";
    cout << "1.  ➕🏭 Tambah Gudang\n";
    cout << "2.  ➕📦 Tambah Barang ke Gudang\n";
    cout << "3.  ✏️🏭 Update Data Gudang\n";
    cout << "4.  ✏️📦 Update Data Barang\n";
    cout << "5.  ❌🏭 Hapus Gudang\n";
    cout << "6.  ❌📦 Hapus Barang\n";
    cout << "7.  📋🏭 Tampilkan Semua Gudang\n";
    cout << "8.  📦🏭 Tampilkan Barang per Gudang\n";
    cout << "9.  📋📦 Tampilkan Semua Barang\n";
    cout << "10. 📈📦 Tampilkan Barang dengan Stok Terbanyak\n";
    cout << "11. 📉📦 Tampilkan Barang dengan Stok Tersedikit\n";
    cout << "12. 📊📦🏭 Hitung Total Stok Gudang\n";
    cout << "13. 📦 Hitung Total Stok Barang Tertentu\n";
    cout << "14. 🚨📦 Cari Barang Rusak\n";
    cout << "────────────────────────────────────\n";
    cout << "15. 🔤🏭 Urutkan Gudang (A - Z)\n";
    cout << "16. 🔤🏭 Urutkan Gudang (Z - A)\n";
    cout << "────────────────────────────────────\n";
    cout << "17. 🔢📦📈 Urutkan Barang per Gudang (Stok Asc)\n";
    cout << "18. 🔢📦📉 Urutkan Barang per Gudang (Stok Desc)\n";
    cout << "19. 🔢🌐📦📈 Urutkan Semua Barang (Stok Asc)\n";
    cout << "20. 🔢🌐📦📉 Urutkan Semua Barang (Stok Desc)\n";
    cout << "21. 🔤📦 Urutkan Barang per Gudang (Nama A - Z)\n";
    cout << "22. 🔤📦 Urutkan Barang per Gudang (Nama Z - A)\n";
    cout << "23. 🔤🌐📦 Urutkan Semua Barang (Nama A - Z)\n";
    cout << "24. 🔤🌐📦 Urutkan Semua Barang (Nama Z - A)\n";
    cout << "0.  🚪 Keluar\n";
    cout << "────────────────────────────────────\n";
}
