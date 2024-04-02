#include <iostream>
using namespace std;

// struktur untuk data film bioskop
struct film {
    string judul;
    int harga;

};

// fungsi untung menampilkan menu film
void tampilkanMenu (film daftarFilm[], int jumlahFilm){
    cout << "Daftar film yang tersedia: \t" << endl;
    for (int i = 0; i < jumlahFilm; ++i){
        cout << i+1 << ". " << daftarFilm[i].judul << "- Rp" << daftarFilm[i].harga << endl;
    }
}

// fungsi untuk menghitung harga total harga film bioskop
int hitungTotalHarga(film daftarFilm[], int jumlahFilm, int beli[]){
    int totalHarga = 0;
    for (int i = 0; i < jumlahFilm; ++i){
        totalHarga += daftarFilm[i].harga * beli[i];
    }
    return totalHarga;
}

int main(){
    // inisialisasi daftar film
    const int JUMLAH_FILM = 5;
    film daftarFilm[JUMLAH_FILM] = {
        {"Inside Out 2", 45000},
        {"Agak Laen", 45000},
        {"Exhuma", 50000},
        {"Wonka", 50000},
        {"Barbie", 60000},
    };

    // inisialisasi jumlah tiket yang dibeli
    int beli[JUMLAH_FILM] = {0};

    // menampilkan menu film 
    tampilkanMenu(daftarFilm, JUMLAH_FILM);

    // meminta pengguna untuk memilih film
    int pilihan;
    do {
        cout << "\nMasukkan nomor film yang ingin di tonton (0 untuk selesai): ";
        cin >> pilihan;
        if (pilihan >= 1 && pilihan <= JUMLAH_FILM){
            int jumlah;
            cout << "Masukkan jumlah tiket untuk " << daftarFilm[pilihan-1].judul << ": ";
            cin >> jumlah;
            beli[pilihan-1] += jumlah;
        } else if (pilihan != 0){
            cout << "Nomor film tidak valid. Silahkan coba lagi." << endl;
        }
    } while (pilihan != 0);

    // menghitung total harga
    int totalHarga = hitungTotalHarga(daftarFilm, JUMLAH_FILM, beli);

    // meminta pengguna untuk memberikan uang
    int uang;
    cout <<"\nTotal harga: Rp" << totalHarga << endl;
    do {
        cout << "Masukkan uang Anda: Rp";
        cin >> uang;
        if (uang < totalHarga){
            cout << "Uang Anda kurang. Silahkan masukkan uang yang cukup. ";
        }
    } while (uang < totalHarga);

    // menghitung kembalian
    int kembalian = uang - totalHarga;
    cout << "Kembalian Anda: Rp" << kembalian << endl;

    return 0;
}