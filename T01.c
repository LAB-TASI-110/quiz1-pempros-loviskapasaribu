#include <stdio.h>
#include <string.h>

int main() {

    char kode[10];
    int porsi_butet;
    int harga = 0;
    int total = 0;

    int berat_ucok = 100;
    int berat_butet = 50;
    int rasio = berat_ucok / berat_butet;

    while (1) {

        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            break;
        }

        scanf("%d", &porsi_butet);

        if (strcmp(kode, "NGS") == 0) harga = 15000;
        else if (strcmp(kode, "AP") == 0) harga = 20000;
        else if (strcmp(kode, "SA") == 0) harga = 25000;
        else if (strcmp(kode, "BU") == 0) harga = 18000;
        else if (strcmp(kode, "MAP") == 0) harga = 15000;
        else if (strcmp(kode, "GG") == 0) harga = 15000;
        else if (strcmp(kode, "SAM") == 0) harga = 17000;
        else if (strcmp(kode, "RD") == 0) harga = 25000;
        else if (strcmp(kode, "IB") == 0) harga = 35000;
        else if (strcmp(kode, "NUK") == 0) harga = 20000;
        else {
            printf("Kode tidak valid\n");
            continue;
        }

        int porsi_ucok = rasio * porsi_butet;
        int total_porsi = porsi_ucok + porsi_butet;
        int subtotal = harga * total_porsi;

        total += subtotal;
    }

    float diskon = 0;

    if (total >= 400000) diskon = 0.25;
    else if (total >= 300000) diskon = 0.20;
    else if (total >= 200000) diskon = 0.15;
    else if (total >= 100000) diskon = 0.10;

    float potongan = total * diskon;
    float bayar = total - potongan;

    printf("Total Belanja : %d\n", total);
    printf("Diskon        : %.0f\n", potongan);
    printf("Total Bayar   : %.0f\n", bayar);

    return 0;
}