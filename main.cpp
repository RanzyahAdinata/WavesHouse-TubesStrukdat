#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "mll.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(int ms = 600) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void typeEffect(const string &text, int speed = 10) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

void loading(const string &text) {
    cout << text;
    for (int i = 0; i < 3; i++) {
        cout << "." << flush;
        pause(300);
    }
    cout << endl;
}

int main() {
    list_gudang LG;
    list_barang LB;
    adr_gudang g;
    adr_barang b;

    infotype_barang barang;
    infotype_gudang gudang;

    string idGudang, idBarang;
    string masukan, choice;

    createListGudang(LG);
    createListBarang(LB);

    while (masukan != "0") {
        clearScreen();
        ui();
        cout << "➜ Pilih Menu : ";
        cin >> masukan;
        clearScreen();

        if (masukan == "1") {
            typeEffect("➕ Menambah Gudang\n");
            cout << "ID Gudang   : "; cin >> gudang.id_gudang;
            cout << "Nama Gudang : "; cin >> gudang.nama_gudang;
            g = alokasiGudang(gudang);
            insertGudang(LG, g);
            loading("✔ Gudang berhasil ditambahkan");
        }
        else if (masukan == "2") {
            typeEffect("📦 Menambah Barang ke Gudang\n");
            cout << "ID Gudang        : "; cin >> idGudang;
            cout << "ID Barang        : "; cin >> barang.id_barang;
            cout << "Nama Barang      : "; cin >> barang.nama_barang;
            cout << "Kuantitas        : "; cin >> barang.kuantitas;
            cout << "Jenis Komoditas  : "; cin >> barang.jenis_komoditas;
            cout << "Kondisi          : "; cin >> barang.kondisi;
            b = alokasiBarang(barang);
            insertBarangKeGudang(LG, idGudang, b);
            loading("✔ Barang berhasil ditambahkan");
        }
        else if (masukan == "3") {
            typeEffect("🗑 Menghapus Gudang\n");
            cout << "ID Gudang : "; cin >> idGudang;
            deleteGudang(LG, idGudang);
            pause();
        }
        else if (masukan == "4") {
            typeEffect("❌ Menghapus Barang\n");
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "ID Barang : "; cin >> idBarang;
            deleteBarang(LG, idGudang, idBarang);
            pause();
        }
        else if (masukan == "5") {
            typeEffect("📋 Daftar Semua Gudang\n\n");
            showSemuaGudang(LG);
            pause(1200);
        }
        else if (masukan == "6") {
            cout << "ID Gudang : "; cin >> idGudang;
            showBarangGudang(LG, idGudang);
            pause(1200);
        }
        else if (masukan == "7") {
            typeEffect("📦 Semua Barang\n\n");
            showSemuaBarangUnik(LG);
            pause(1200);
        }
        else if (masukan == "8") {
            cout << "[a] Seluruh Gudang\n[b] Gudang Tertentu\n➜ ";
            cin >> choice;
            if (choice == "a") {
                b = stokTerbanyak(LG);
                if (!cekbarangnull(b)) showbarangtertentu(b);
            } else {
                cout << "ID Gudang : "; cin >> idGudang;
                g = searchGudang(LG, idGudang);
                if (!cekgudangnull(g))
                    showbarangtertentu(stokTerbanyakPergudang(LG, g));
            }
            pause(1200);
        }
        else if (masukan == "9") {
            cout << "[a] Seluruh Gudang\n[b] Gudang Tertentu\n➜ ";
            cin >> choice;
            if (choice == "a") {
                b = stokTersedikit(LG);
                if (!cekbarangnull(b)) showbarangtertentu(b);
            } else {
                cout << "ID Gudang : "; cin >> idGudang;
                g = searchGudang(LG, idGudang);
                if (!cekgudangnull(g))
                    showbarangtertentu(stokTersedikitPergudang(LG, g));
            }
            pause(1200);
        }
        else if (masukan == "10") {
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "📊 Total Stok : "
                 << hitungTotalStokGudang(LG, idGudang) << endl;
            pause();
        }
        else if (masukan == "11") {
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "ID Barang : "; cin >> idBarang;
            cout << "📦 Total Stok : "
                 << hitungStokBarangTertentu(LG, idGudang, idBarang) << endl;
            pause();
        }
        else if (masukan == "12") {
            typeEffect("🚨 Mencari Barang Rusak\n\n");
            cariBarangRusak(LG);
            pause(1200);
        }

        else if (masukan == "13") {
            sortGudangAsc(LG);
            typeEffect("🔤 Gudang diurutkan A - Z\n\n");
            showSemuaGudang(LG);
            pause(1200);
        }
        else if (masukan == "14") {
            sortGudangDesc(LG);
            typeEffect("🔤 Gudang diurutkan Z - A\n\n");
            showSemuaGudang(LG);
            pause(1200);
        }
        else if (masukan == "15") {
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) {
                sortBarangStokAsc(g);
                showBarangGudang(LG, idGudang);
            }
            pause(1200);
        }
        else if (masukan == "16") {
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) {
                sortBarangStokDesc(g);
                showBarangGudang(LG, idGudang);
            }
            pause(1200);
        }
        else if (masukan == "17") {
            sortBarangStokAscGlobal(LG);
            typeEffect("🌐 Semua Barang (Stok ASC)\n\n");
            showSemuaBarangUnik(LG);
            pause(1200);
        }
        else if (masukan == "18") {
            sortBarangStokDescGlobal(LG);
            typeEffect("🌐 Semua Barang (Stok DESC)\n\n");
            showSemuaBarangUnik(LG);
            pause(1200);
        }
    }

    clearScreen();
    typeEffect("👋 Terima kasih telah menggunakan sistem\n");
    return 0;
}
