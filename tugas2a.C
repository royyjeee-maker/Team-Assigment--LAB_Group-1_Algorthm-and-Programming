#include <stdio.h>
#include <string.h>

// Membuat struct untuk menyimpan data pegawai
struct Pegawai {
    char nip[20];
    char nama[50];
    char alamat[100];
    char noHP[20];
    char jabatan[50];
    char golongan[5];
    long long gajiPokok;
};

int main() {
    // Membuat variabel pegawai
    struct Pegawai pegawai;

    // Input data pegawai
    printf("Masukkan NIP       : ");
    fgets(pegawai.nip, sizeof(pegawai.nip), stdin);
    pegawai.nip[strcspn(pegawai.nip, "\n")] = '\0';

    printf("Masukkan Nama      : ");
    fgets(pegawai.nama, sizeof(pegawai.nama), stdin);
    pegawai.nama[strcspn(pegawai.nama, "\n")] = '\0';

    printf("Masukkan Alamat    : ");
    fgets(pegawai.alamat, sizeof(pegawai.alamat), stdin);
    pegawai.alamat[strcspn(pegawai.alamat, "\n")] = '\0';

    printf("Masukkan No HP     : ");
    fgets(pegawai.noHP, sizeof(pegawai.noHP), stdin);
    pegawai.noHP[strcspn(pegawai.noHP, "\n")] = '\0';

    printf("Masukkan Jabatan   : ");
    fgets(pegawai.jabatan, sizeof(pegawai.jabatan), stdin);
    pegawai.jabatan[strcspn(pegawai.jabatan, "\n")] = '\0';

    printf("Masukkan Golongan  : ");
    fgets(pegawai.golongan, sizeof(pegawai.golongan), stdin);
    pegawai.golongan[strcspn(pegawai.golongan, "\n")] = '\0';

    // Menentukan gaji pokok berdasarkan golongan
    if (strcmp(pegawai.golongan, "D1") == 0) {
        pegawai.gajiPokok = 3000000;
    } 
    else if (strcmp(pegawai.golongan, "D2") == 0) {
        pegawai.gajiPokok = 2500000;
    } 
    else if (strcmp(pegawai.golongan, "D3") == 0) {
        pegawai.gajiPokok = 2000000;
    } 
    else {
        pegawai.gajiPokok = 0;
    }

    // Menampilkan data pegawai
    printf("\n======== DATA PEGAWAI ========\n");

    printf("NIP        : %s\n", pegawai.nip);
    printf("Nama       : %s\n", pegawai.nama);
    printf("Alamat     : %s\n", pegawai.alamat);
    printf("No HP      : %s\n", pegawai.noHP);
    printf("Jabatan    : %s\n", pegawai.jabatan);
    printf("Golongan   : %s\n", pegawai.golongan);

    if (pegawai.gajiPokok > 0) {
        printf("Gaji Pokok : Rp%lld\n", pegawai.gajiPokok);
    } else {
        printf("Gaji Pokok : Golongan tidak valid\n");
    }

    return 0;
}