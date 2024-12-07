#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#include "invoicing.h"
#include "rekap.h"

void CatatTransaksi(int PilihanFilm, int Lokasi, int Jadwal, int Harga){
    FILE *file = fopen("DaftarTransaksi.txt", "a");
    if (file == NULL){
        printf("Coba lagi");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char WaktuTransaksi[50];
    strftime(WaktuTransaksi, sizeof(WaktuTransaksi), "%H:%M, %d/%m/%Y", t);

    fprintf(file, "Film: %s\n Lokasi: %s\n Jadwal: %s \n Waktu Transaksi: %s\n Total Harga: %d \n \n", NamaFilm[PilihanFilm - 1], NamaLokasi[Lokasi - 1], JadwalFilm[PilihanFilm - 1][Jadwal - 1], WaktuTransaksi, Harga);
    fclose(file);
    printf("Transaksi di simpan\n");
}

// int TransaksiBerhasil(int pil_Film, int pil_Lokasi, int pil_Jadwal){

// }
void Rekapitulasi(){
    char PeriodeAwal[20], PeriodeAkhir[20];
    InputPeriode(PeriodeAwal, PeriodeAkhir);

    FILE *file = fopen("DaftarTransaksi.txt", "r");
    if (file == NULL){
        printf("Coba lagi\n");
        exit(1);
    }
    struct tm waktu;
    time_t start, end;

    memset(&waktu, 0, sizeof(struct tm));
    if (sscanf(PeriodeAwal, "%d/%d/%d", &waktu.tm_mday, &waktu.tm_mon, &waktu.tm_year) != 3) {
        printf("Format tanggal awal tidak valid.\n");
        fclose(file);
        return;
    }
    waktu.tm_mon -= 1;
    waktu.tm_year -= 1900;
    start = mktime(&waktu);

    memset(&waktu, 0, sizeof(struct tm));
    if (sscanf(PeriodeAkhir, "%d/%d/%d", &waktu.tm_mday, &waktu.tm_mon, &waktu.tm_year) != 3){
        printf("Format tanggal awal tidak valid.\n");
        fclose(file);
        return;
    }
    waktu.tm_mon -= 1;
    waktu.tm_year -= 1900;
    end = mktime(&waktu);
    
    char line[200], WaktuTransaksi[50];
    int TotalTransaksi = 0;
    int TotalPendapatan = 0;

    printf("Rekapitulasi data penjualan dari %s sampai %s: \n", PeriodeAwal, PeriodeAkhir);
    while (fgets(line, sizeof(line), file)){
        if (strncmp(line, "Film: ", 6) == 0) {
            char Film[50], Lokasi[50], Jadwal[50];
            int Harga;

            sscanf(line, "Film: %[^\n]", Film);
            fgets(line, sizeof(line), file);
            sscanf(line, "Lokasi: %[^\n]", Lokasi);
            fgets(line, sizeof(line), file);
            sscanf(line, "Jadwal: %[^\n]", Jadwal);
            fgets(line, sizeof(line), file);
            sscanf(line, "Waktu Transaksi: %[^\n]", WaktuTransaksi);
            fgets(line, sizeof(line), file);
            sscanf(line, "Total Harga: %d\n", &Harga);

            memset(&waktu, 0, sizeof(struct tm));
            if (sscanf(WaktuTransaksi + 6, "%d/%d/%d", &waktu.tm_mday, &waktu.tm_mon, &waktu.tm_year) != 3){
                printf("Format waktu transaksi tidak valid.\n");
                continue;
            }
            waktu.tm_mon -= 1;
            waktu.tm_year -= 1900;
            time_t WaktuFile = mktime(&waktu);

            if (difftime(WaktuFile, start) >= 0 && difftime(end, WaktuFile) >= 0){
                printf("Film: %s\n Lokasi: %s\n Jadwal: %s\n Waktu Transaksi: %s\n Total Harga: %d\n\n", Film, Lokasi, Jadwal, WaktuTransaksi, Harga);
                TotalTransaksi++;
                TotalPendapatan += Harga;
            }
        }
    }
    printf("Total Transaksi: %d\n", TotalTransaksi);
    printf("Total Pendapatan: %d\n", TotalPendapatan);
    fclose(file);
}   

int ValidasiTgl(const char* Tanggal){
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));

    if (sscanf(Tanggal, "%d/%d/%d",  &tm.tm_mday, &tm.tm_mon, &tm.tm_year) != 3){ 
        return 0;
    }
    tm.tm_mon -= 1; 
    tm.tm_year -= 1900;
    time_t t = mktime(&tm);
    return t != -1;

}

void InputPeriode(char* PeriodeAwal, char* PeriodeAkhir){
    while (1){
        printf("Masukan periode (tanggal) awal (dd/mm/yyyy): \n");
        scanf("%s", PeriodeAwal);

        if (!ValidasiTgl(PeriodeAwal)){
            printf("Tanggal awal salah. Coba lagi dalam format dd/mm/yyyy\n");
            continue;
        }
        printf("Masukan periode (tanggal) akhir (dd/mm/yyyy): \n");
        scanf("%s", PeriodeAkhir);
        if (!ValidasiTgl(PeriodeAkhir)){
            printf("Tanggal akhir salah. Coba lagi dalam format dd/mm/yyyy\n");
            continue;
        }
        break;
    }
}
