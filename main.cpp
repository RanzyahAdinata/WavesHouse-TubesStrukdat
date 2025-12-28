#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <limits>
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

void waitEnterAndClear() {
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearScreen();
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

        if (masukan == "1") {
            clearScreen();
            typeEffect("➕ Menambah Gudang\n");
            cout << "ID Gudang   : "; cin >> gudang.id_gudang;
            cout << "Nama Gudang : "; cin >> gudang.nama_gudang;
            insertGudang(LG, alokasiGudang(gudang));
            loading("✔ Gudang berhasil ditambahkan");
        }
        else if (masukan == "2") {
            clearScreen();
            typeEffect("📦 Menambah Barang ke Gudang\n");
            cout << "ID Gudang        : "; cin >> idGudang;
            cout << "ID Barang        : "; cin >> barang.id_barang;
            cout << "Nama Barang      : "; cin >> barang.nama_barang;
            cout << "Kuantitas        : "; cin >> barang.kuantitas;
            cout << "Jenis Komoditas  : "; cin >> barang.jenis_komoditas;
            cout << "Kondisi          : "; cin >> barang.kondisi;
            insertBarangKeGudang(LG, idGudang, alokasiBarang(barang));
            loading("✔ Barang berhasil ditambahkan");
        }

        /* UPDATE */
        else if (masukan == "3") {
            clearScreen();
            typeEffect("✏️ Memperbarui Data Gudang\n");
            cout << "ID Gudang   : "; cin >> idGudang;
            cout << "Nama Baru   : "; cin >> gudang.nama_gudang;
            updateGudang(LG, idGudang, gudang.nama_gudang);
            waitEnterAndClear();
        }
        else if (masukan == "4") {
            clearScreen();
            typeEffect("✏️ Memperbarui Data Barang\n");
            cout << "ID Gudang       : "; cin >> idGudang;
            cout << "ID Barang       : "; cin >> idBarang;
            cout << "Nama Baru       : "; cin >> barang.nama_barang;
            cout << "Kuantitas Baru  : "; cin >> barang.kuantitas;
            cout << "Jenis Komoditas : "; cin >> barang.jenis_komoditas;
            cout << "Kondisi         : "; cin >> barang.kondisi;

            updateBarang(
                LG,
                idGudang,
                idBarang,
                barang.nama_barang,
                barang.kuantitas,
                barang.jenis_komoditas,
                barang.kondisi
            );
            waitEnterAndClear();
        }

        /* DELETE */
        else if (masukan == "5") {
            clearScreen();
            typeEffect("🗑 Menghapus Gudang\n");
            cout << "ID Gudang : "; cin >> idGudang;
            deleteGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "6") {
            clearScreen();
            typeEffect("❌ Menghapus Barang\n");
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "ID Barang : "; cin >> idBarang;
            deleteBarang(LG, idGudang, idBarang);
            waitEnterAndClear();
        }

        /* SHOW */
        else if (masukan == "7") {
            clearScreen();
            typeEffect("📋 Daftar Semua Gudang\n\n");
            showSemuaGudang(LG);
            waitEnterAndClear();
        }
        else if (masukan == "8") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            showBarangGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "9") {
            clearScreen();
            typeEffect("📦 Semua Barang\n\n");
            showSemuaBarangUnik(LG);
            waitEnterAndClear();
        }

        /* STOK */
        else if (masukan == "10") {
            clearScreen();
            b = stokTerbanyak(LG);
            if (!cekbarangnull(b)) showbarangtertentu(b);
            waitEnterAndClear();
        }
        else if (masukan == "11") {
            clearScreen();
            b = stokTersedikit(LG);
            if (!cekbarangnull(b)) showbarangtertentu(b);
            waitEnterAndClear();
        }
        else if (masukan == "12") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "📊 Total Stok : " << hitungTotalStokGudang(LG, idGudang) << endl;
            waitEnterAndClear();
        }
        else if (masukan == "13") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            cout << "ID Barang : "; cin >> idBarang;
            cout << "📦 Total Stok : "
                 << hitungStokBarangTertentu(LG, idGudang, idBarang) << endl;
            waitEnterAndClear();
        }
        else if (masukan == "14") {
            clearScreen();
            typeEffect("🚨 Mencari Barang Rusak\n\n");
            cariBarangRusak(LG);
            waitEnterAndClear();
        }

        /* SORTING */
        else if (masukan == "15") {
            clearScreen();
            sortGudangAsc(LG);
            showSemuaGudang(LG);
            waitEnterAndClear();
        }
        else if (masukan == "16") {
            clearScreen();
            sortGudangDesc(LG);
            showSemuaGudang(LG);
            waitEnterAndClear();
        }
        else if (masukan == "17") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) sortBarangStokAsc(g);
            showBarangGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "18") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) sortBarangStokDesc(g);
            showBarangGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "19") {
            clearScreen();
            sortBarangStokAscGlobal(LG);
            showSemuaBarangUnik(LG);
            waitEnterAndClear();
        }
        else if (masukan == "20") {
            clearScreen();
            sortBarangStokDescGlobal(LG);
            showSemuaBarangUnik(LG);
            waitEnterAndClear();
        }
        else if (masukan == "21") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) sortBarangNamaAsc(g);
            showBarangGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "22") {
            clearScreen();
            cout << "ID Gudang : "; cin >> idGudang;
            g = searchGudang(LG, idGudang);
            if (!cekgudangnull(g)) sortBarangNamaDesc(g);
            showBarangGudang(LG, idGudang);
            waitEnterAndClear();
        }
        else if (masukan == "23") {
            clearScreen();
            sortBarangNamaAscGlobal(LG);
            showSemuaBarangUnik(LG);
            waitEnterAndClear();
        }
        else if (masukan == "24") {
            clearScreen();
            sortBarangNamaDescGlobal(LG);
            showSemuaBarangUnik(LG);
            waitEnterAndClear();
        }
    }

    clearScreen();
    typeEffect("👋 Terima kasih telah menggunakan sistem\n");
    return 0;
}
