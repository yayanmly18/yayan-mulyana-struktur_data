#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Nama pembuat program
string namaPembuat = "Yayan Mulyana";
string npmPembuat = "2310631170057";


// Structure untuk data Mahasiswa
struct Mahasiswa {
    string NPM;
    string Nama;
};

// Structure untuk data Nilai
struct Nilai {
    float Absen;
    float Tugas;
    float UTS;
    float UAS;
    float NilaiAkhir;
    char IndexHuruf;
};

// Fungsi-fungsi prototipe
void inputData(Mahasiswa[], Nilai[], int&);
void tampilkanData(const Mahasiswa[], const Nilai[], int);
void editData(Mahasiswa[], Nilai[], int);
void hapusData(Mahasiswa[], Nilai[], int&);
void hitungNilai(Nilai&);
void tampilkanHeader();
void tampilkanGarisPemisah();

int main() {
    // Deklarasi array untuk menyimpan data mahasiswa dan nilai
    Mahasiswa dataMahasiswa[20];
    Nilai dataNilai[20];
    int jumlahMahasiswa = 0;
    char opsi;

    // Loop menu
    do {
        cout << "\nMenu:\n";
        cout << "C. Input data mahasiswa\n";
        cout << "R. Tampilkan data mahasiswa\n";
        cout << "U. Edit data mahasiswa\n";
        cout << "D. Hapus data mahasiswa\n";
        cout << "X. Keluar\n";
        cout << "Pilih operasi: ";
        cin >> opsi;

        switch (toupper(opsi)) {
            case 'C':
                inputData(dataMahasiswa, dataNilai, jumlahMahasiswa);
                break;
            case 'R':
                tampilkanHeader();
                tampilkanGarisPemisah();
                tampilkanData(dataMahasiswa, dataNilai, jumlahMahasiswa);
                break;
            case 'U':
                editData(dataMahasiswa, dataNilai, jumlahMahasiswa);
                break;
            case 'D':
                hapusData(dataMahasiswa, dataNilai, jumlahMahasiswa);
                break;
            case 'X':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Operasi tidak valid.\n";
        }
    } while (toupper(opsi) != 'X');

    // Tampilkan nama pembuat program setelah keluar dari loop menu
    cout << "Program dibuat oleh : " << namaPembuat << endl;
    cout << "NPM                 : " << npmPembuat << endl;

    return 0;
}

// Fungsi untuk menampilkan header tabel
void tampilkanHeader() {
    cout << left << setw(5) << "No" << setw(15) << "NPM" << setw(20) << "Nama" << setw(25) << "Nilai Akhir" << setw(10) << "Index\n";
}

// Fungsi untuk menampilkan garis pemisah antara header dan data
void tampilkanGarisPemisah() {
    cout << setfill('-') << setw( 5 + 15 + 20 + 25 + 10) << "-" << endl;
    cout << setfill(' ');
}

// Fungsi untuk input data mahasiswa
void inputData(Mahasiswa dataMahasiswa[], Nilai dataNilai[], int &jumlah) {
    // Memeriksa apakah sudah mencapai batas maksimal mahasiswa
    if (jumlah < 20) {
        cout << "Masukkan NPM mahasiswa: ";
        cin >> dataMahasiswa[jumlah].NPM;
        cout << "Masukkan Nama mahasiswa: ";
        cin.ignore();
        getline(cin, dataMahasiswa[jumlah].Nama);
        cout << "Masukkan Absen: ";
        cin >> dataNilai[jumlah].Absen;
        cout << "Masukkan Nilai Tugas: ";
        cin >> dataNilai[jumlah].Tugas;
        cout << "Masukkan Nilai UTS: ";
        cin >> dataNilai[jumlah].UTS;
        cout << "Masukkan Nilai UAS: ";
        cin >> dataNilai[jumlah].UAS;

        // Menghitung nilai akhir dan indeks huruf
        hitungNilai(dataNilai[jumlah]);

        jumlah++;
        cout << "Data mahasiswa berhasil ditambahkan.\n";
    } else {
        cout << "Batas maksimal mahasiswa telah tercapai.\n";
    }
}

// Fungsi untuk menghitung nilai akhir dan indeks huruf
void hitungNilai(Nilai &nilai) {
    nilai.NilaiAkhir = (nilai.Absen * 0.1) + (nilai.Tugas * 0.2) + (nilai.UTS * 0.3) + (nilai.UAS * 0.4);

    if (nilai.NilaiAkhir > 80)
        nilai.IndexHuruf = 'A';
    else if (nilai.NilaiAkhir > 70)
        nilai.IndexHuruf = 'B';
    else if (nilai.NilaiAkhir > 60)
        nilai.IndexHuruf = 'C';
    else
        nilai.IndexHuruf = 'D';
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const Mahasiswa dataMahasiswa[], const Nilai dataNilai[], int jumlah) {
    if (jumlah > 0) {
        for (int i = 0; i < jumlah; ++i) {
            cout << left << setw(5) << i + 1 << setw(15) << dataMahasiswa[i].NPM << setw(20) << dataMahasiswa[i].Nama
                 << setw(25) << fixed << setprecision(2) << dataNilai[i].NilaiAkhir
                 << "  " << setw(10) << dataNilai[i].IndexHuruf << endl;
        }
    } else {
        cout << "Belum ada data mahasiswa.\n";
    }
}

// Fungsi untuk mengedit data mahasiswa
void editData(Mahasiswa dataMahasiswa[], Nilai dataNilai[], int jumlah) {
    if (jumlah > 0) {
        string cariNPM;
        cout << "Masukkan NPM mahasiswa yang ingin diubah: ";
        cin >> cariNPM;
        bool ditemukan = false;
        for (int i = 0; i < jumlah; ++i) {
            if (dataMahasiswa[i].NPM == cariNPM) {
                cout << "Masukkan nilai Absen: ";
                cin >> dataNilai[i].Absen;
                cout << "Masukkan nilai Tugas: ";
                cin >> dataNilai[i].Tugas;
                cout << "Masukkan nilai UTS: ";
                cin >> dataNilai[i].UTS;
                cout << "Masukkan nilai UAS: ";
                cin >> dataNilai[i].UAS;

                // Menghitung kembali nilai akhir dan indeks huruf
                hitungNilai(dataNilai[i]);

                cout << "Data mahasiswa berhasil diubah.\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "NPM tidak ditemukan.\n";
        }
    } else
        cout << "Belum ada data mahasiswa.\n";
}

// Fungsi untuk menghapus data mahasiswa
void hapusData(Mahasiswa dataMahasiswa[], Nilai dataNilai[], int &jumlah) {
    if (jumlah > 0) {
        string cariNPM;
        cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
        cin >> cariNPM;
        bool ditemukan = false;
        for (int i = 0; i < jumlah; ++i) {
            if (dataMahasiswa[i].NPM == cariNPM) {
                // Menggeser data untuk menutupi data yang dihapus
                for (int j = i; j < jumlah - 1; ++j) {
                    dataMahasiswa[j] = dataMahasiswa[j + 1];
                    dataNilai[j] = dataNilai[j + 1];
                }
                jumlah--;
                cout << "Data mahasiswa berhasil dihapus.\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "NPM tidak ditemukan.\n";
        }
    } else
        cout << "Belum ada data mahasiswa.\n";
}
