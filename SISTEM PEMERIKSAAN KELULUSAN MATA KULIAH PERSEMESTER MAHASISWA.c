#include <stdio.h>

typedef enum {
    MENGULANG,
    LULUS
} StatusKelulusan;

int main() {
  
const char *mataKuliah[8] = {
    "Algoritma Pemrograman",
    "Kalkulus",
    "Matematika Diskrit",
    "Pengantar Teknologi Informasi",
    "Pancasila",
    "Bahasa Indonesia",
    "Bahasa Inggris",
    "Sistem Digital"
};

    int sks[8] = {3, 3, 3, 2, 2, 2, 2, 2};
    int nilai[8];
    StatusKelulusan status[8];

    int totalSKS = 0;
    int sksLulus = 0;
    int jumlahLulus = 0;
    int jumlahMengulang = 0;

    printf("========================================\n");
    printf(" SISTEM PEMERIKSAAN KELULUSAN MAHASISWA\n");
    printf("========================================\n");
    printf("Jumlah mata kuliah : 8\n");
    printf("Total SKS          : 19\n");
    printf("Batas kelulusan    : 80\n\n");

    for (int i = 0; i < 8; i++) {
        printf("Masukkan nilai %s (0-100): ",
               mataKuliah[i]);
        scanf("%d", &nilai[i]);

        while (nilai[i] < 0 || nilai[i] > 100) {
            printf("Nilai tidak valid! Masukkan 0-100: ");
            scanf("%d", &nilai[i]);
        }

        if (nilai[i] >= 80) {
            status[i] = LULUS;
        } else {
            status[i] = MENGULANG;
        }

        totalSKS += sks[i];
    }

    printf("\n========================================\n");
    printf("          HASIL PEMERIKSAAN\n");
    printf("========================================\n");

    for (int i = 0; i < 8; i++) {
        printf("\nMata kuliah : %s\n", mataKuliah[i]);
        printf("Nilai       : %d\n", nilai[i]);
        printf("SKS         : %d\n", sks[i]);
        printf("Status      : ");

        switch (status[i]) {
            case LULUS:
                printf("LULUS\n");
                jumlahLulus++;
                sksLulus += sks[i];
                break;

            case MENGULANG:
                printf("MENGULANG\n");
                jumlahMengulang++;
                break;
        }
    }

    printf("\n========================================\n");
    printf("             REKAP SEMESTER\n");
    printf("========================================\n");
    printf("Total mata kuliah         : 8\n");
    printf("Total SKS                 : %d\n", totalSKS);
    printf("Mata kuliah lulus         : %d\n", jumlahLulus);
    printf("Mata kuliah ulang         : %d\n", jumlahMengulang);
    printf("SKS mata kuliah lulus     : %d\n", sksLulus);

    if (jumlahMengulang == 0) {
        printf("\nHASIL SEMESTER: SEMUA MATA KULIAH LULUS!\n");
    } else {
        printf("\nHASIL SEMESTER: ADA MATA KULIAH YANG HARUS DIULANG.\n");
    }

    printf("========================================\n");

    return 0;
}