#include <iostream>
#include <iomanip> // buat ngerapihkan table
using namespace std;

// definisikan struktur data Siswa
struct Siswa
{
    string nama;
};

// Fungsi buat menginput data nama siswa ke dalam array siswa
void inputSiswa(Siswa *siswa, int index)
{
    // Meminta pengguna buat masukin nama siswa
    cout << "Masukkan data nama siswa ke-" << index << ": ";

    // Pake getline() buat baca semua baris
    getline(cin, siswa[index - 1].nama); // Index dikurangi 1 buat menyesuaikan dengan indeks array
}

int main()
{
    // deklarasikan array siswa dengan maks 10
    Siswa siswa[10];

    // Meminta pengguna untuk memasukkan jumlah siswa
    cout << "Masukkan jumlah siswa: ";
    int jumlahSiswa;
    cin >> jumlahSiswa;

    // Pastikan siswa >10
    if (jumlahSiswa > 10)
    {
        // Pesan kalau siswa <10
        cout << "Jumlah siswa tidak boleh lebih dari 10" << endl;
        return 1; //Eror program di hentikan
    }

    cin.ignore(); // Kalau ga pake nanti pas masukin nama dimulai dari 2

    // Meminta input nama siswa sejumlah jumlahSiswa
    for (int i = 1; i <= jumlahSiswa; i++) // ubah indeks awal jadi 1
    {
        inputSiswa(siswa, i);
    }

    // Output tabel
    cout << "--------------------------------------------------------------\n";
    cout << "| No. |     Nama Mahasiswa        |   Alamat Memori          |\n";
    cout << "--------------------------------------------------------------\n";

    // Menampilkan nama mahasiswa dan alamat memori dalam bentuk tabel
    for (int i = 0; i < jumlahSiswa; ++i)
    {
        // Menampilkan nama mahasiswa dan alamat memori dalam bentuk tabel
        cout << "| " << setw(3) << left << i+1 << " | " << setw(25) << left << siswa[i].nama << " | " << setw(25) << &siswa[i] << "|\n";
    }

    cout << "--------------------------------------------------------------\n";


    cout << "\n========================\n";
    cout << " Nama  : Yayan Mulyana\n";
    cout << " Kelas : 2C Informatika\n";
    cout << " NPM   : 2310631170057\n";
    cout << "========================\n";

    return 0;
}
