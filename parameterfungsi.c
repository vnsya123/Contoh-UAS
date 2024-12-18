#include <stdio.h>
#include <string.h>

// Struktur data untuk tiket
typedef struct {
    char Tipe[10];
    int Harga;
} Tiket;

// Struktur data untuk lokasi
typedef struct {
    char Nama[20];
    int BiayaTransportasi;
    int BiayaHarian;
    int BiayaPerJam;
} Lokasi;

// Fungsi untuk menghitung biaya penginapan
int hitungBiayaPenginapan(const Lokasi *lokasi, int waktuPenginapan) {
    if (waktuPenginapan < 24) {
        return 0; // Refund biaya penginapan
    } else if (waktuPenginapan == 24) {
        return lokasi->BiayaHarian; // Biaya satu hari
    } else { // waktuPenginapan > 24
        int kelebihanJam = waktuPenginapan - 24;
        return lokasi->BiayaHarian + (kelebihanJam * lokasi->BiayaPerJam);
    }
}

// Fungsi utama
int main() {
    // Daftar tiket
    Tiket tiketA = {"A", 350000};
    Tiket tiketB = {"B", 270000};
    Tiket tiketC = {"C", 150000};

    // Daftar lokasi
    Lokasi jakarta = {"Jakarta", 400000, 250000, 40000};
    Lokasi bandung = {"Bandung", 390000, 200000, 30000};
    Lokasi surabaya = {"Surabaya", 360000, 220000, 35000};
    Lokasi yogyakarta = {"Yogyakarta", 0, 0, 0};

    // Input pengguna
    char pilihanTiket[10];
    char pilihanLokasi[20];
    int waktuPenginapan;

    printf("=== Pemesanan Tiket Konser ===\n");
    printf("Pilih tipe tiket (A/B/C): ");
    scanf("%s", pilihanTiket);
    printf("Pilih lokasi konser (Jakarta/Bandung/Surabaya/Yogyakarta): ");
    scanf("%s", pilihanLokasi);
    printf("Masukkan waktu penginapan (dalam jam): ");
    scanf("%d", &waktuPenginapan);

    // Menentukan tiket
    Tiket *tiket;
    if (strcmp(pilihanTiket, "A") == 0) {
        tiket = &tiketA;
    } else if (strcmp(pilihanTiket, "B") == 0) {
        tiket = &tiketB;
    } else {
        tiket = &tiketC;
    }

    // Menentukan lokasi
    Lokasi *lokasi;
    if (strcmp(pilihanLokasi, "Jakarta") == 0) {
        lokasi = &jakarta;
    } else if (strcmp(pilihanLokasi, "Bandung") == 0) {
        lokasi = &bandung;
    } else if (strcmp(pilihanLokasi, "Surabaya") == 0) {
        lokasi = &surabaya;
    } else {
        lokasi = &yogyakarta;
    }

    // Menghitung biaya
    int biayaTransportasi = lokasi->BiayaTransportasi;
    int biayaPenginapan = hitungBiayaPenginapan(lokasi, waktuPenginapan);
    int totalBiaya = tiket->Harga + biayaTransportasi + biayaPenginapan;

    // Output hasil
    printf("\n=== Total Biaya ===\n");
    printf("Tiket: %s (%d IDR)\n", tiket->Tipe, tiket->Harga);
    printf("Lokasi: %s (Transportasi: %d IDR)\n", lokasi->Nama, biayaTransportasi);
    printf("Biaya Penginapan: %d IDR\n", biayaPenginapan);
    printf("Total Biaya: %d IDR\n", totalBiaya);

    return 0;
}
