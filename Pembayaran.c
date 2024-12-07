#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pembayaran.h"

int Saldo;
void rekeningbri();
void rekeningmandiri();

void tampilbank () {
    int pilihan;
    do{
    printf("==========PEMBAYARAN============\n");
    printf("KETIK 1 : BANK BRI\n");
    printf("KETIK 2 : BANK MANDIRI\n");
    printf("================================\n");
    printf("MASUKKAN PILIHAN ANDA : ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1 : rekeningbri();
        break;
        case 2 : rekeningmandiri();
        break;
        default : printf("ANGKA YANG ANDA MASUKKAN TIDAK VALID\n");
        break;
    }
    }while(pilihan != 2);
}

void rekeningbri(){
    char RekeningInput[50];
    char RekeningFile[50];
    int found = 0;

    printf("MASUKKAN NOMOR REKENING ANDA : ");
    scanf("%s", RekeningInput);

    FILE *rekening = fopen("rekeningbri.txt", "r");
    if(rekening == NULL){
        printf("REKENING ANDA TIDAK DITEMUKAN.\n");
        return;
    }

    while(fscanf(rekening, "%s %d", RekeningFile, &Saldo) != EOF){
        if(strcmp(RekeningInput, RekeningFile) == 0){
            printf("Saldo Anda : Rp %d\n", Saldo);
            found = 1;
            break;
        }
    }
    fclose(rekening);
    if(!found){
        printf("REKENING ANDA TIDAK DITEMUKAN!\n");
    }   
}

void rekeningmandiri() {
    char RekeningInput[50];
    char RekeningFile[50];
    int found = 0;

    printf("MASUKKAN NOMOR REKENING ANDA : ");
    scanf("%s", RekeningInput);

    FILE *rekening = fopen("rekeningmandiri.txt", "r");
    if(rekening == NULL){
        printf("REKENING ANDA TIDAK DITEMUKAN.\n");
        return;
    }

    while(fscanf(rekening, "%s %d", RekeningFile, &Saldo) != EOF){
        if(strcmp(RekeningInput, RekeningFile) == 0){
            printf("Saldo Anda : Rp %d\n", Saldo);
            found = 1;
            break;
        }
    }
    fclose(rekening);
    if(!found){
        printf("REKENING ANDA TIDAK DITEMUKAN!\n");
    }   
}
