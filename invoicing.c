#include <stdio.h> 
#include <unistd.h>
#include "film.h" // include isi info const punya jul
#include "Pembayaran.h" // include extern saldo jadwal punya han
#include "invoicing.h"

int harga;

void invoice_film (int pil_film, int pil_lokasi, int pil_jadwal, int pil_kursi, char* atasnama) {
    char place, schedule; 
    if (pil_lokasi == 0) {
        place = *(NamaLokasi[0]);  
    } else if (pil_lokasi == 1) {
        place = *(NamaLokasi[1]);
    }
    if (pil_film == 1) {
        switch (pil_jadwal) {
        case 0: schedule = *(JadwalFilm[0][0]);
        break;
        case 1: schedule = *(JadwalFilm[0][1]);
        break;
        case 2: schedule = *(JadwalFilm[0][2]);
        break;
        case 3: schedule = *(JadwalFilm[0][3]);
        break;
        }
    } else if (pil_film == 2) {
        switch (pil_jadwal) {
        case 0: schedule = *(JadwalFilm[1][0]);
        break;
        case 1: schedule = *(JadwalFilm[1][1]);
        break;
        case 2: schedule = *(JadwalFilm[1][2]);
        break;
        case 3: schedule = *(JadwalFilm[1][3]);
        break;
        }
    }
    printf("Sudah siap untuk menonton?\n\n");
    printf("Kamu akan memesan kursi 0%02d atas nama %s untuk menonton:", pil_kursi, atasnama);
    if (pil_film == 1) {
        printf("\n\nHSR\n\nJam: %s \n Di: %s \n\n\n\n", schedule, place);
        if (pil_lokasi == 0) {
            printf("Harga: 25000");
        } else if (pil_lokasi == 1) {
            printf("Harga: 30000");
        }
    }
    if (pil_film == 2) {
        printf("\n\nZZZ\n\nJam: %s \n Di: %s \n\n\n\n", schedule, place);
        if (pil_lokasi == 0) {
            printf("Harga: 30000");
        } else if (pil_lokasi == 1) {
            printf("Harga: 25000");
        }
    }
}

int confirmpembayaran () {
    int lanjuttidak;
    printf("\n\nKonfirmasi Pembayaran?\n");
    printf("(1) Lanjutkan\n(2) Batalkan");
    printf("\n\nMembatalkan akan mengembalikan anda ke halaman daftar tayang.");
    printf("\nPilihan: ");
    scanf("%d", &lanjuttidak);
    return lanjuttidak;
}

int proses_bayar (int pil_film, int pil_lokasi) {
    int balik = 0;
    int isiSaldo = Saldo;
    if (pil_film == 1) {
        if (pil_lokasi == 0) {
            harga = 25000;
        } else if (pil_lokasi == 1) {
            harga = 30000;
        }
    } else if (pil_film == 2) {
        if (pil_lokasi == 0) {
            harga = 30000;
        } else if (pil_lokasi == 1) {
            harga = 25000;
        }
    }
    printf("Melanjutkan ke proses pembayaran.\n\nSaldo anda: %d \nHarga: Rp. %d", Saldo, harga);
    if (isiSaldo < harga) {
        printf("Maaf, saldo anda tidak mencukupi.\n");
        printf("Anda akan dikembalikan ke halaman invoice. Silahkan bila ingin mengganti bank.");
        balik = 1;
    } else if (isiSaldo > harga) {
        printf("\n\nSaldo anda mencukupi untuk melakukan pembayaran.\n");
        printf("Memproses pembayaran. Mohon menunggu sebentar...");
        sleep(5);
        printf("\n\nPembayaran berhasil.");
        int sisaSaldo = isiSaldo - harga; 
        printf("\nSisa saldo anda: Rp. %d", sisaSaldo);
    }
    return balik;
}


void tiket_film (int pil_film, int pil_lokasi, int pil_jadwal, int pil_kursi, char* atasnama) {
    char place, schedule;
    if (pil_lokasi == 0) {
        place = *(NamaLokasi[0]);
    } else if (pil_lokasi == 1) {
        place = *(NamaLokasi[1]);
    }
    if (pil_film == 1) {
        switch (pil_jadwal) {
            case 0: schedule = *(JadwalFilm[0][0]);
            break;
            case 1: schedule = *(JadwalFilm[0][1]);
            break;
            case 2: schedule = *(JadwalFilm[0][2]);
            break;
            case 3: schedule = *(JadwalFilm[0][3]);
            break;
            }
    } else if (pil_film == 2) {
            switch (pil_jadwal) {
            case 0: schedule = *(JadwalFilm[1][0]);
            break;
            case 1: schedule = *(JadwalFilm[1][1]);
            break;
            case 2: schedule = *(JadwalFilm[1][2]);
            break;
            case 3: schedule = *(JadwalFilm[1][3]);
            break;
            }
    }
    if (pil_film == 1) {
        printf("Terima kasih sudah menggunakan layanan Bioskop Suka Suka, %s.\n", atasnama);
        printf("Berikut ini tiketmu:\n\n");
        printf("----------------------------------\n");
        printf(" TICKET OF     Honkai Star Rail   \n");
        printf(" Location: %s \n", place); 
        printf(" Schedule: %s \n", schedule);
        printf(" Seat: 0%02d \n", pil_kursi);
        printf("              PAID                \n");
        printf("----------------------------------\n");
    } else if (pil_film == 2) {
        printf("Terima kasih sudah menggunakan layanan Bioskop Suka Suka, %s.\n", atasnama);
        printf("Berikut ini tiketmu:\n\n");
        printf("----------------------------------\n");
        printf(" TICKET OF     Zenless Zone Zero  \n");
        printf(" Location: %s \n", place);
        printf(" Schedule: %s \n", schedule);
        printf(" Seat: 0%02d \n", pil_kursi);
        printf("              PAID                \n");
        printf("----------------------------------\n");
    }
}
