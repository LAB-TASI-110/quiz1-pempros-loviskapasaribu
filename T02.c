#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int nilai[100];   // kapasitas maksimum 100 data

    // input nilai
    for(int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    int kode;
    scanf("%d", &kode);   // kode kelompok (1, 2, atau 3)

    int total = 0;  

    // proses penjumlahan berdasarkan pola selang 3
    for(int i = 0; i < N; i++) {
        if((i % 3) + 1 == kode) {
            total += nilai[i];
        }
    }

    printf("%d\n", total);

    return 0;
}