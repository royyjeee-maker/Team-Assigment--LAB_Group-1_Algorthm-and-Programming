#include <stdio.h>
#include <string.h> //fungsi strcspn() dan strcmp()

// Struct untuk menyimpan data perhitungan gaji pegawai
struct Pegawai { //mengelompokan identitas pegawai dan data perhitungan gaji
    char nip[20]; //menyimpan NIP sbg teks agar angka nol di awal tetap dipertahankan
    char golongan[5];
    int jamLembur; //menyimpan jumlah jam lembur dlm bilangan bulat
    long long gajiPokok; 
    long long tarifLembur;
    long long upahLembur;
    long long totalGaji;
}; //long long untuk menyimpan nominal gaji dan upah dalam rupiah bulat

int main(void) { //fungsi utama program agak tidak menerima parameter 
    struct Pegawai pegawai; //variabel untuk menyimpan data satu pegawai

    // Input NIP pegawai
    printf("Masukkan NIP        : ");
    if (fgets(pegawai.nip, sizeof(pegawai.nip), stdin) == NULL) { 
        printf("Input NIP gagal.\n");
        return 1;
    } // fget(...,sizeoff(...), stdin) membaca teks dari keyboard dengan batas sesuai kapasitas array

    // Menghapus karakter Enter dari hasil fgets
    pegawai.nip[strcspn(pegawai.nip, "\n")] = '\0';

    // Input golongan pegawai
    printf("Masukkan Golongan   : ");
    if (fgets(pegawai.golongan,
              sizeof(pegawai.golongan), stdin) == NULL) {
        printf("Input golongan gagal.\n");
        return 1;
    } // fgets(..) == NULL u memeriksa apakah pembacaan teks gagal

    pegawai.golongan[strcspn(pegawai.golongan, "\n")] = '\0'; //find the posisi karakter Enter, kemudian karakter tsb diganti dengan '\0'

    // Menentukan gaji pokok dan tarif lembur berdasarkan golongan
    if (strcmp(pegawai.golongan, "D1") == 0) { //memeriksa apakah golongan sama dengan "D1"
        pegawai.gajiPokok = 3000000;
        pegawai.tarifLembur = 15000;
    }
    else if (strcmp(pegawai.golongan, "D2") == 0) {
        pegawai.gajiPokok = 2500000;
        pegawai.tarifLembur = 10000;
    }
    else if (strcmp(pegawai.golongan, "D3") == 0) {
        pegawai.gajiPokok = 2000000;
        pegawai.tarifLembur = 5000;
    }
    else {
        printf("Golongan tidak valid. Gunakan D1, D2, atau D3.\n");
        return 1;
    }

    // Input jumlah jam lembur dalam bilangan bulat
    printf("Masukkan Jam Lembur : ");
    if (scanf("%d", &pegawai.jamLembur) != 1) { //membaca jam lembur dan memeriksa apakah satu bilangan bulat berhaisl dibuka 
        printf("Jam lembur harus berupa bilangan bulat.\n");
        return 1;
    }

    // Jam lembur tidak boleh negatif
    if (pegawai.jamLembur < 0) { //memeriksa dan menolak jumlah jam lembur negatif
        printf("Jam lembur tidak boleh negatif.\n");
        return 1; //menghehntikan program dengan status kegagalan
    }

    // Menghitung upah lembur dan total gaji bulan berjalan
    pegawai.upahLembur =
        pegawai.jamLembur * pegawai.tarifLembur;

    pegawai.totalGaji =
        pegawai.gajiPokok + pegawai.upahLembur;

    // Menampilkan rincian gaji pegawai
    printf("\n======== GAJI BULANAN PEGAWAI ========\n");
    //%lld digunakan untuk menampilkan nilai bertipe long long, bilangan bulat dengan jangkauan lebih besar daripada int
    printf("NIP                  : %s\n", pegawai.nip);
    printf("Golongan             : %s\n", pegawai.golongan);
    printf("Jam Lembur           : %d\n", pegawai.jamLembur);
    printf("Gaji Pokok           : Rp%lld\n", pegawai.gajiPokok);
    printf("Tarif Lembur per Jam : Rp%lld\n", pegawai.tarifLembur);
    printf("Upah Lembur          : Rp%lld\n", pegawai.upahLembur);
    printf("Total Gaji Bulan Ini : Rp%lld\n", pegawai.totalGaji);

    return 0; //mengakhiri program dengan status berhasil
}