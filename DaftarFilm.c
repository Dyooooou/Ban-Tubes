#include<stdio.h>



const char* NamaFilm[2] = {"HSR", "ZZZ"
};

const char* NamaLokasi[2] = {"CGV", "XXI"
};

const char* JadwalFilm[2][4] = {
    {"9.30 WIB", "12.00 WIB", "16.20 WIB", "19.45 WIB"},
    {"10.20 WIB", "14.10 WIB", "18.30 WIB", "21.40 WIB"}
};

void MenampilkanFilm(){
    printf("Daftar film yang dapat anda tonton \n");
    printf("1. %s.\n", NamaFilm[0]);
    printf("2. %s.\n", NamaFilm[1]);
}

void MenampilkanLokasi(){
    printf("Pilih lokasi bioskop\n");
    printf("1. %s.\n", NamaLokasi[0]);
    printf("2. %s.\n", NamaLokasi[1]);
}

void PilihLokasi(){
    
    int Lokasi;
    printf("Masukan lokasi bioskop (1-2) ");
    scanf("%d", &Lokasi);

    if (Lokasi < 1 || Lokasi > 2){
        printf("Pilihan tidak valid. Silahkan isi lagi. \n");
        MenampilkanLokasi();
        PilihLokasi();
        
    } else {
        printf("Kamu memilih menonton di %s.\n", NamaLokasi[Lokasi - 1]);
    }
}

void MenampilkanJadwal(int Film){
    printf("Pilih jadwal menonton film %s.\n", NamaFilm[Film - 1]);
    for (int i = 0; i < 4; i++){
        printf("%d. %s\n", i + 1, JadwalFilm[Film - 1][i]);
    }
}

void PilihJadwal(int Film){ //input Film dari atasssh
    int Jadwal;
    printf("Masukan pilihan jam tayang (1-4): ");
    scanf("%d", &Jadwal);

    if (Jadwal < 1 || Jadwal > 4){
        printf("Jam Tayang tidak ada. Silahkan coba lagi\n");
    } else {
        printf("Anda memilih Jadwal: %s untuk Film %s.\n", JadwalFilm[Film - 1][Jadwal - 1], NamaFilm[Film - 1]);
    }
    if (Jadwal < 1 || Jadwal > 4){
        MenampilkanJadwal(Film);
        PilihJadwal(Film);
    }
}

void FilmPertama(){
    printf("Anda memilih film %s.\n", NamaFilm[0]);
    printf("Deskripsi Film\n");
    printf("HSR adalah film dimana kamu menjadi tokoh utama yang menjelajahi dunia menggunakan kereta\n");
}
void FilmKedua(){
    printf("Anda memilih film %s.\n", NamaFilm[1]);
    printf("Deskripsi Film \n");
    printf("ZZZ adalah film yang bercerita tentang seorang hacker jenius yang kehilangan akun miliknya\n");
}

int main(){
    int PilihanFilm;
    MenampilkanFilm();
    printf("Film apa yang ingin anda tonton (1/2): ");
    scanf("%d", &PilihanFilm);
    switch (PilihanFilm){
        case 1:
            FilmPertama();
            MenampilkanLokasi();
            PilihLokasi();
            MenampilkanJadwal(1);
            PilihJadwal(1);
            //MenampilkanTiket();
            break;
        case 2:
            FilmKedua();
            MenampilkanLokasi();
            PilihLokasi();
            MenampilkanJadwal(2);
            PilihJadwal(2);
            //MenampilkanTiket();
            break;
        default:
            printf("Pilihan tidak valid. Silahkan coba lagi");
            break;
        }

return 0;
}

// void MenampilkanTiket(int Film, int Lokasi, int Jadwal){
//     if (Lokasi == 1){
//         printf("            ___");
//         printf("           // \\");
//         printf("          //");
//         printf("         ||")
//         printf("         ||")
//         printf("         ||")
//         printf("         ||")
//         printf("         ||")
//         printf("         ||")
//         printf("")
//         printf()
//         printf()
//         printf()
//         printf()
//         printf("           ")
//     printf()
//     }
//     printf();
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
//     printf()
// }