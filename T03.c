#include <stdio.h>
#include <string.h>

#define MAX 100

// ===== STRUCT =====
struct Mahasiswa {  
    int nim;
    char nama[50];
};

struct Transaksi {
    int id;
    int nim;
    char bulan[20];
    char layanan[20];
    float berat;
    float total;
};

// ===== DATA GLOBAL =====
struct Mahasiswa mahasiswa[MAX];
struct Transaksi transaksi[MAX];

int jumlahMahasiswa = 0; 
int jumlahTransaksi = 0;

// ===== CEK NIM =====
int nimTerdaftar(int nim) {
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (mahasiswa[i].nim == nim) {
            return 1;
        }
    }
    return 0;
}

// ===== INPUT MAHASISWA =====
void inputMahasiswa() {
    if (jumlahMahasiswa >= MAX) {
        printf("Data mahasiswa penuh!\n");
        return;
    }

    printf("\n=== INPUT DATA MAHASISWA ===\n");
    printf("Masukkan NIM  : ");
    scanf("%d", &mahasiswa[jumlahMahasiswa].nim);

    printf("Masukkan Nama : ");
    scanf(" %[^\n]", mahasiswa[jumlahMahasiswa].nama);

    jumlahMahasiswa++;
    printf(">> Data mahasiswa berhasil disimpan.\n");
}

// ===== INPUT TRANSAKSI =====
void inputTransaksi() {
    if (jumlahTransaksi >= MAX) {
        printf("Data transaksi penuh!\n");
        return;
    }

    int nim, pilihan;
    float hargaPerKg;

    printf("\n=== INPUT TRANSAKSI LAUNDRY ===\n");
    printf("Masukkan NIM Mahasiswa : ");
    scanf("%d", &nim);

    if (!nimTerdaftar(nim)) {
        printf(">> ERROR: NIM tidak terdaftar!\n");
        return;
    }

    transaksi[jumlahTransaksi].id = jumlahTransaksi + 1;
    transaksi[jumlahTransaksi].nim = nim;

    printf("Masukkan Bulan (contoh: Januari) : ");
    scanf(" %[^\n]", transaksi[jumlahTransaksi].bulan);

    printf("\nPilih Layanan:\n");
    printf("1. Cuci Kering   (Rp 5000/kg)\n");
    printf("2. Cuci Setrika  (Rp 7000/kg)\n");
    printf("3. Setrika Saja  (Rp 4000/kg)\n");
    printf("Pilihan Anda : ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        strcpy(transaksi[jumlahTransaksi].layanan, "Cuci Kering");
        hargaPerKg = 5000;
    } else if (pilihan == 2) {
        strcpy(transaksi[jumlahTransaksi].layanan, "Cuci Setrika");
        hargaPerKg = 7000;
    } else if (pilihan == 3) {
        strcpy(transaksi[jumlahTransaksi].layanan, "Setrika Saja");
        hargaPerKg = 4000;
    } else {
        printf(">> Pilihan layanan tidak valid!\n");
        return;
    }

    printf("Masukkan Berat (kg) : ");
    scanf("%f", &transaksi[jumlahTransaksi].berat);

    transaksi[jumlahTransaksi].total =
        transaksi[jumlahTransaksi].berat * hargaPerKg;

    jumlahTransaksi++;

    printf("\n>> Transaksi berhasil dicatat.\n");
    printf(">> Tagihan akan direkap akhir bulan dan dikirim ke Bursar (CIS Del).\n");
}

// ===== REKAP PER MAHASISWA =====
void rekapMahasiswa() {
    int nim;
    char bulan[20];
    float totalTagihan = 0;

    printf("\n=== REKAP TAGIHAN MAHASISWA ===\n");
    printf("Masukkan NIM   : ");
    scanf("%d", &nim);

    printf("Masukkan Bulan : ");
    scanf(" %[^\n]", bulan);

    for (int i = 0; i < jumlahTransaksi; i++) {
        if (transaksi[i].nim == nim &&
            strcmp(transaksi[i].bulan, bulan) == 0) {
            totalTagihan += transaksi[i].total;
        }
    }

    printf("\n--- HASIL REKAP ---\n");
    printf("NIM          : %d\n", nim);
    printf("Bulan        : %s\n", bulan);
    printf("Total Tagihan: Rp %.2f\n", totalTagihan);
    printf(">> Data dikirim ke Bursar untuk diinput ke CIS Del.\n");
}

// ===== LAPORAN BULANAN =====
void laporanBulanan() {
    char bulan[20];
    float totalSemua = 0;

    printf("\n=== LAPORAN BULANAN LAUNDRY DEL ===\n");
    printf("Masukkan Bulan : ");
    scanf(" %[^\n]", bulan);

    printf("\nDaftar Transaksi Bulan %s:\n", bulan);

    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(transaksi[i].bulan, bulan) == 0) {
            printf("ID:%d | NIM:%d | Layanan:%s | Total: Rp %.2f\n",
                   transaksi[i].id,
                   transaksi[i].nim,
                   transaksi[i].layanan,
                   transaksi[i].total);

            totalSemua += transaksi[i].total;
        }
    }

    printf("\nTotal Seluruh Tagihan Bulan %s : Rp %.2f\n",
           bulan, totalSemua);
    printf(">> Laporan siap dikirim ke Bursar.\n");
}

// ===== MAIN =====
int main() {
    int menu;

    do {
        printf("\n====================================\n");
        printf("   SISTEM LAUNDRY DEL - CIS DEL\n");
        printf("====================================\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Input Transaksi Laundry\n");
        printf("3. Rekap Tagihan Mahasiswa\n");
        printf("4. Laporan Bulanan\n");
        printf("0. Keluar\n");
        printf("Pilih Menu : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: inputMahasiswa(); break;
            case 2: inputTransaksi(); break;
            case 3: rekapMahasiswa(); break;
            case 4: laporanBulanan(); break;
            case 0: printf("Program selesai.\n"); break;
            default: printf("Menu tidak tersedia!\n");
        }

    } while (menu != 0);

    return 0;
}