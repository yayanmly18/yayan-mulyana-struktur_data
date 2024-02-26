#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Deklarasi variabel
    string input = "aaabbbccccd"; // input
    string output;                // Array output
    int outputIndex = 0;          // Indeks untuk array output
    char currentChar;             // Karakter yang sedang diproses
    int count = 1;                // Jumlah karakter berurutan

    currentChar = input[0];

    // Perulangan buat karakter dalam array input
    for (int i = 1; i < input.length(); i++)
    {
        // Jika karakter sama dengan karakter sebelumnya
        if (input[i] == currentChar)
        {
            count++;
        }
        else
        {
            // Jika karakter berbeda dengan karakter sebelumnya,
            // simpan karakter dan count sebelumnya ke dalam array output
            outputIndex += 2; // ruang buat karakter dan count
            if (outputIndex >= input.length())
            {
                // Memperbesar ukuran array
                output.resize(outputIndex + 1);
            }
            output[outputIndex - 1] = currentChar;
            output[outputIndex] = '0' + count;

            // Update karakter dan reset count
            currentChar = input[i];
            count = 1;
        }
    }

    // Menambahkan karakter dan count terakhir ke dalam array output
    outputIndex += 2;
    if (outputIndex >= input.length())
    {
        output.resize(outputIndex + 1);
    }
    output[outputIndex - 1] = currentChar;
    output[outputIndex] = '0' + count;

    // cetak array terkompresi
    cout << "input: " << input << endl;
    cout << "Array setelah kompresi: ";
    for (int i = 0; i < outputIndex + 1; i++)
    {
        cout << output[i];
    }
    cout << endl;
    cout << "========================" << endl;
    cout << " Nama  :Yayan Mulyana " << endl;
    cout << " Kelas :2C Informatika " << endl;
    cout << " NPM   :2310631170057" << endl;
    cout << "========================" << endl;

    return 0;
}
