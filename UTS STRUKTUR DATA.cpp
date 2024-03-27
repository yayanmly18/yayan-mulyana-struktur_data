#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk data barang
struct Barang {
    string kode;
    string nama;
    int stok;
    double harga;
};

// Fungsi untuk menambahkan data barang ke dalam array dengan pointer
void tambahBarangArray(Barang* arrayBarang, int& jumlahBarang) {
    Barang barangBaru;

    cout << "Masukkan kode barang: ";
    cin >> barangBaru.kode;
    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, barangBaru.nama);
    cout << "Masukkan stok barang: ";
    cin >> barangBaru.stok;
    cout << "Masukkan harga barang: ";
    cin >> barangBaru.harga;

    // Menambahkan data barang baru ke dalam array dengan pointer
    *(arrayBarang + jumlahBarang) = barangBaru;
    jumlahBarang++;
}

// Fungsi untuk menampilkan data barang dari array
void tampilkanBarangArray(const Barang* arrayBarang, int jumlahBarang) {
    cout << "\nDaftar Barang:\n";
    cout << "No.\tKode\tNama\tStok\tHarga\n";

    for (int i = 0; i < jumlahBarang; i++) {
        cout << i + 1 << "\t" << (arrayBarang + i)->kode << "\t" << (arrayBarang + i)->nama << "\t" << (arrayBarang + i)->stok << "\t" << (arrayBarang + i)->harga << endl;
    }
}

int main() {
    const int MAX_BARANG = 100; // Batas maksimum barang dalam array
    Barang arrayBarang[MAX_BARANG]; // Array untuk menyimpan data barang
    int jumlahBarang = 0; // Jumlah barang yang sudah dimasukkan

    int pilihan;

    do {
        cout << "\nNama : Yayan Mulyana\n";
        cout << "Kelas: 2C\n";
        cout << "NPM  : 2310631170057\n";
        cout << "\nPilih menu:\n";
        cout << "1. Tambah barang\n";
        cout << "2. Tampilkan daftar barang\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarangArray(arrayBarang, jumlahBarang); // Panggil fungsi tambahBarangArray
                break;
            case 2:
                tampilkanBarangArray(arrayBarang, jumlahBarang); // Panggil fungsi tampilkanBarangArray
                break;
            case 3:
                cout << "Terima kasih! Sampai jumpa!\n";
                break;
            default:
                cout << "Menu tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 3);

    return 0;
}
