#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum untuk jenis kelamin
typedef enum {
    Laki_laki,
    Perempuan
} Gender;

// Struct untuk menyimpan informasi mahasiswa
typedef struct {
    char NIM[15];
    char Nama[100];
    char Prodi[50];
    int Semester;
    char Kampus[50];
    Gender JenisKelamin;
} InfoMahasiswa;

// Fungsi untuk mengisi data mahasiswa
void isiDataMahasiswa(InfoMahasiswa *mhs, char nim[], char nama[], char prodi[], 
                      char kampus[], int semester, Gender jenisKelamin) {
    strcpy(mhs->NIM, nim);
    strcpy(mhs->Nama, nama);
    strcpy(mhs->Prodi, prodi);
    strcpy(mhs->Kampus, kampus);
    mhs->Semester = semester;
    mhs->JenisKelamin = jenisKelamin;
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(const InfoMahasiswa *mhs) {
    printf("=== Data Mahasiswa ===\n");
    printf("NIM          : %s\n", mhs->NIM);
    printf("Nama         : %s\n", mhs->Nama);
    printf("Prodi        : %s\n", mhs->Prodi);
    printf("Semester     : %d\n", mhs->Semester);
    printf("Kampus       : %s\n", mhs->Kampus);
    printf("Jenis Kelamin: %s\n", mhs->JenisKelamin == Laki_laki ? "Laki-laki" : "Perempuan");
    printf("======================\n");
}

// Fungsi utama
int main() {
    // Alokasi memori untuk InfoMahasiswa
    InfoMahasiswa *mahasiswa = (InfoMahasiswa *)malloc(sizeof(InfoMahasiswa));
    if (mahasiswa == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    // Mengisi data mahasiswa
    isiDataMahasiswa(mahasiswa, "71231057", "Vensya Motuti", "Teknik Informatika", 
                     "Universitas Kristen Duta Wacana", 3, Perempuan);

    // Menampilkan data mahasiswa
    tampilkanDataMahasiswa(mahasiswa);

    // Membebaskan memori
    free(mahasiswa);

    return 0;
}
