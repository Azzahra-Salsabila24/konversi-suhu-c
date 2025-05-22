#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100

// Struktur untuk menyimpan riwayat konversi
typedef struct {
    char dari_satuan[10];
    char ke_satuan[10];
    float nilai_awal;
    float hasil;
} Konversi;

// Fungsi-fungsi konversi suhu
float celsius_ke_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float celsius_ke_kelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheit_ke_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float fahrenheit_ke_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvin_ke_celsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvin_ke_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Fungsi untuk menambahkan konversi ke riwayat
void tambah_riwayat(Konversi *riwayat, int *jumlah_riwayat, char *dari, char *ke, float nilai_awal, float hasil) {
    if (*jumlah_riwayat < MAX_HISTORY) {
        strcpy(riwayat[*jumlah_riwayat].dari_satuan, dari);
        strcpy(riwayat[*jumlah_riwayat].ke_satuan, ke);
        riwayat[*jumlah_riwayat].nilai_awal = nilai_awal;
        riwayat[*jumlah_riwayat].hasil = hasil;
        (*jumlah_riwayat)++;
    } else {
        printf("Peringatan: Riwayat sudah penuh!\n");
    }
}

// Fungsi untuk menampilkan riwayat
void tampilkan_riwayat(Konversi *riwayat, int jumlah_riwayat) {
    if (jumlah_riwayat == 0) {
        printf("\n=== RIWAYAT KONVERSI ===\n");
        printf("Belum ada riwayat konversi.\n");
        return;
    }
    
    printf("\n=== RIWAYAT KONVERSI ===\n");
    printf("No. | Dari      | Nilai Awal | Ke        | Hasil\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < jumlah_riwayat; i++) {
        printf("%-3d | %-9s | %-10.2f | %-9s | %.2f\n", 
               i + 1, 
               riwayat[i].dari_satuan, 
               riwayat[i].nilai_awal, 
               riwayat[i].ke_satuan, 
               riwayat[i].hasil);
    }
    
    printf("\nTekan Enter untuk kembali ke menu...");
    getchar();
    getchar();
}

// Fungsi untuk menampilkan tabel konversi suhu
void tampilkan_tabel_konversi() {
    printf("\n=== TABEL KONVERSI SUHU ===\n");
    printf("| Celsius | Fahrenheit | Kelvin |\n");
    printf("|---------|------------|--------|\n");
    
    for (int c = 0; c <= 100; c += 10) {
        float f = celsius_ke_fahrenheit(c);
        float k = celsius_ke_kelvin(c);
        printf("| %-7d | %-10.2f | %-6.2f |\n", c, f, k);
    }
    
    printf("\nTekan Enter untuk kembali ke menu...");
    getchar();
    getchar();
}

// Fungsi utama
int main() {
    int pilihan;
    float suhu, hasil;
    Konversi riwayat[MAX_HISTORY];
    int jumlah_riwayat = 0;
    char dari_satuan[10], ke_satuan[10];
    
    do {
        system("clear || cls"); // Membersihkan layar (cross-platform)
        
        printf("\n==== PROGRAM KONVERSI SUHU ====\n");
        printf("1. Celsius ke Fahrenheit\n");
        printf("2. Fahrenheit ke Kelvin\n");
        printf("3. Kelvin ke Celsius\n");
        printf("4. Fahrenheit ke Celsius\n");
        printf("5. Kelvin ke Fahrenheit\n");
        printf("6. Celsius ke Kelvin\n");
        printf("7. Lihat Riwayat Konversi\n");
        printf("8. Tampilkan Tabel Konversi\n");
        printf("0. Keluar\n");
        printf("================================\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1: // Celsius ke Fahrenheit
                printf("\nMasukkan suhu dalam Celsius: ");
                scanf("%f", &suhu);
                hasil = celsius_ke_fahrenheit(suhu);
                strcpy(dari_satuan, "Celsius");
                strcpy(ke_satuan, "Fahrenheit");
                printf("%.2f °C = %.2f °F\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 2: // Fahrenheit ke Kelvin
                printf("\nMasukkan suhu dalam Fahrenheit: ");
                scanf("%f", &suhu);
                hasil = fahrenheit_ke_kelvin(suhu);
                strcpy(dari_satuan, "Fahrenheit");
                strcpy(ke_satuan, "Kelvin");
                printf("%.2f °F = %.2f K\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 3: // Kelvin ke Celsius
                printf("\nMasukkan suhu dalam Kelvin: ");
                scanf("%f", &suhu);
                hasil = kelvin_ke_celsius(suhu);
                strcpy(dari_satuan, "Kelvin");
                strcpy(ke_satuan, "Celsius");
                printf("%.2f K = %.2f °C\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 4: // Fahrenheit ke Celsius
                printf("\nMasukkan suhu dalam Fahrenheit: ");
                scanf("%f", &suhu);
                hasil = fahrenheit_ke_celsius(suhu);
                strcpy(dari_satuan, "Fahrenheit");
                strcpy(ke_satuan, "Celsius");
                printf("%.2f °F = %.2f °C\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 5: // Kelvin ke Fahrenheit
                printf("\nMasukkan suhu dalam Kelvin: ");
                scanf("%f", &suhu);
                hasil = kelvin_ke_fahrenheit(suhu);
                strcpy(dari_satuan, "Kelvin");
                strcpy(ke_satuan, "Fahrenheit");
                printf("%.2f K = %.2f °F\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 6: // Celsius ke Kelvin
                printf("\nMasukkan suhu dalam Celsius: ");
                scanf("%f", &suhu);
                hasil = celsius_ke_kelvin(suhu);
                strcpy(dari_satuan, "Celsius");
                strcpy(ke_satuan, "Kelvin");
                printf("%.2f °C = %.2f K\n", suhu, hasil);
                tambah_riwayat(riwayat, &jumlah_riwayat, dari_satuan, ke_satuan, suhu, hasil);
                break;
                
            case 7: // Lihat Riwayat
                tampilkan_riwayat(riwayat, jumlah_riwayat);
                break;
                
            case 8: // Tampilkan Tabel Konversi
                tampilkan_tabel_konversi();
                break;
                
            case 0: // Keluar
                printf("\nTerima kasih telah menggunakan program konversi suhu!\n");
                break;
                
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
                printf("\nTekan Enter untuk melanjutkan...");
                getchar();
                getchar();
        }
        
        if (pilihan != 0 && pilihan != 7 && pilihan != 8) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar();
            getchar();
        }
        
    } while (pilihan != 0);
    
    return 0;
}