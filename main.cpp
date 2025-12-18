#include <iostream>
#include <cstdlib>
#include "mll.h"

using namespace std;

int main()
{
    list_gudang LG;
    list_barang LB;
    adr_gudang g;
    adr_barang b;
    string idGudang, idBarang;
    infotype_barang barang;
    infotype_gudang gudang;
    string masukan, choice;

    createListGudang(LG);
    createListBarang(LB);

    while (masukan != "0") {
        ui();
        cout << "Pilih Menu: ";
        cin >> masukan;

        if (masukan == "1") {
            system("clear");
            g = alokasiGudang(gudang);
            cout << "ID Gudang: ";
            cin >> g->info.id_gudang;
            cout << "Nama Gudang: ";
            cin >> g->info.nama_gudang;
            insertGudang(LG, g);
            system("clear");
        }
        else if (masukan == "2") {
            system("clear");
            cout << "Masukkan ID Gudang nya: ";
            cin >> idGudang;
            b = alokasiBarang(barang);
            cout << "ID Barang: ";
            cin >> b->info.id_barang;
            cout << "Nama Barang: ";
            cin >> b->info.nama_barang;
            cout << "Kuantitas: ";
            cin >> b->info.kuantitas;
            cout << "Jenis Komoditas: ";
            cin >> b->info.jenis_komoditas;
            cout << "Kondisi: ";
            cin >> b->info.kondisi;
            g = searchGudang(LG, idGudang);
            insertBarangKeGudang(LG, idGudang, b);
            system("clear");
        }
        else if (masukan == "3") {
            system("cls");
            cout << "Masukkan ID Gudang yang ingin dihapus: ";
            cin >> idGudang;
            deleteGudang(LG, idGudang);
            system("clear");
        }
        else if (masukan == "4") {
            system("clear");
            cout << "Masukkan ID Gudang yang ingin dihapus: ";
            cin >> idGudang;
            cout << "Masukkan ID Barang yang ingin dihapus: ";
            cin >> idBarang;
            deleteBarang(LG, idGudang, idBarang);
            system("clear");
        }
        else if (masukan == "5") {
            system("clear");
            showSemuaGudang(LG);
        }
        else if (masukan == "6") {
            system("clear");
            cout << "Masukkan ID Gudang yang ingin dilihat barangnya: ";
            cin >> idGudang;
            showBarangGudang(LG, idGudang);
        }
        else if (masukan == "7") {
            system("clear");
            cout << "Data Semua Barang" << endl << endl;
            showSemuaBarangUnik(LG);
        }
        else if (masukan == "8") {
            system("clear");
            cout << "a. Stok terbanyak dari seluruh gudang" << endl;
            cout << "b. Stok terbanyak dari gudang tertentu" << endl;
            cout << "Pilih (a/b): ";
            cin >> choice;

            if (choice == "a") {
                b = stokTerbanyak(LG);
                if (cekbarangnull(b)) {
                    cout << "Data Barang Kosong" << endl;
                } else {
                    showbarangtertentu(b);
                }
            }
            else if (choice == "b") {
                cout << "Masukkan ID Gudang yang ingin dilihat barangnya: ";
                cin >> idGudang;
                g = searchGudang(LG, idGudang);
                if (cekgudangnull(g)) {
                    cout << "Gudang tidak ditemukan" << endl;
                } else {
                    b = stokTerbanyakPergudang(LG, g);
                    showbarangtertentu(b);
                }
            }
        }
        else if (masukan == "9") {
            system("clear");
            cout << "a. Stok tersedikit dari seluruh gudang" << endl;
            cout << "b. Stok tersedikit dari gudang tertentu" << endl;
            cout << "Pilih (a/b): ";
            cin >> choice;

            if (choice == "a") {
                b = stokTersedikit(LG);
                if (cekbarangnull(b)) {
                    cout << "Data Barang Kosong" << endl;
                } else {
                    showbarangtertentu(b);
                }
            }
            else if (choice == "b") {
                cout << "Masukkan ID Gudang yang ingin dilihat barangnya: ";
                cin >> idGudang;
                g = searchGudang(LG, idGudang);
                if (cekgudangnull(g)) {
                    cout << "Gudang tidak ditemukan" << endl;
                } else {
                    b = stokTersedikitPergudang(LG, g);
                    showbarangtertentu(b);
                }
            }
        }
        else if (masukan == "10") {
            system("clear");
            if (LG.first == nullptr) {
                cout << "Data Kosong" << endl;
            } else {
                cout << "Masukkan ID Gudang: ";
                cin >> idGudang;
                cout << "Total Stok : "
                     << hitungTotalStokGudang(LG, idGudang) << endl;
            }
        }
        else if (masukan == "11") {
            system("clear");
            if (LG.first == nullptr) {
                cout << "Data Kosong" << endl;
            } else {
                cout << "Masukkan ID Gudang: ";
                cin >> idGudang;
                cout << "Masukkan ID Barang: ";
                cin >> idBarang;
                cout << "Total Stok : "
                     << hitungStokBarangTertentu(LG, idGudang, idBarang) << endl;
            }
        }
        else if (masukan == "12") {
            system("clear");
            cariBarangRusak(LG);
        }
    }

    system("clear");
    return 0;
}
