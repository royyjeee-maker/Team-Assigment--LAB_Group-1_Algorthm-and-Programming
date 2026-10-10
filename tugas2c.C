#include <stdio.h>

int main() {
    int totalPembelian;
    int kupon;
    float diskon = 0, totalBayar;
    
    printf("Input total belanja: ");
    scanf("%d", &totalPembelian);
    
    kupon = totalPembelian / 100000;
    
    if (totalPembelian >= 100000) {
        diskon = 0.05 * totalPembelian;
    }
    
    totalBayar = totalPembelian - diskon;
    
    printf("\n=== Hasil Perhitungan ===\n");
    printf("Total Pembelian: Rp %d\n", totalPembelian);
    printf("Jumlah Kupon Undian: %d lembar \n", kupon);
    printf("Diskon: Rp %.0f\n", diskon);
    printf("Total Dibayar: Rp %.0f\n", totalBayar);
    
    return 0;
}