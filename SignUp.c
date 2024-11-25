#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Path "c:\\Sign In Sign Up\\database.txt"

void SignUp();
void SignIn();
int cekemail();
int cekpassword();
char email[50]; // var global
char password[10]; // var global

int main() {
    int pilihan;

    do
    {

    printf("-----------------------------------------------------------\n");
    printf("                       SELAMAT DATANG DI                             \n");
    printf("                       BIOSKOP SUKA SUKA                        \n");
    printf("KETIK 1 : SIGN UP\n");
    printf("KETIK 2 : SIGN IN\n");
    printf("-----------------------------------------------------------\n");
    printf("MASUKKAN PILIHANMU : ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1 : SignUp();
        break;
        case 2 : SignIn();
        break;
        default : printf("ANGKA YANG ANDA MASUKKAN TIDAK VALID\n");
        break;
    }
    }while(pilihan != 2);
    return 0;
} 

void SignUp(){
     while(getchar() !='\n');
     cek1:
     printf("MASUKKAN EMAIL ANDA : ");
     fgets(email, sizeof(email), stdin);
     if(cekemail() == 0){
        goto cek1;
     }else{
        cek2:
        printf("MASUKKAN PASSWORD ANDA : ");
        fgets(password, sizeof(password), stdin);
        if(cekpassword() == 0){
            goto cek2;
        }else{
            FILE *fptr = NULL;
            fptr = fopen(Path, "a");
            if(fptr == NULL){
                system("cls");
                printf("Coba Lagi");
            }else{
                fprintf(fptr, "%s %s\n", email, password);
                printf("Sign Up Anda Berhasil\n");
                fclose(fptr);
                exit(0);
            }
        }
     }
}

int cekemail(){
    int panjang = strlen(email);

     if(panjang < 12){
        system("cls");
        printf("EMAIL TIDAK BOLEH KURANG DARI 12 HURUF\n");
        return 0;
     }
     int i = 0;
     while(email[i] != '\0'){
        if(email[i] == ' '){
            system("cls");
            printf("EMAIL TIDAK BOLEH ADA SPASI\n");
            return 0;
        }
        i++;
     }
     FILE *fptr = NULL;
     fptr = fopen(Path, "r");
     if(fptr == NULL){
        system("cls");
     }else{
        while(fscanf(fptr,"%s", email) == 1){
            if(email == 0){
                system("cls");
                printf("Email Telah Terdaftar. Masukkan Email Lain\n");
                return 0;
            }
        }
     }
     return 1;
}

int cekpassword(){
    int panjang = strlen(password);

    if(panjang < 8){
        system("cls");
        printf("PASSWORD TIDAK BOLEH KURANG DARI 8 KARAKTER\n");
        return 0;
    }
    int i = 0;
    while(password[i] != '\0'){
        if(password[i] == ' '){
            system("cls");
            printf("PASSWORD TIDAK BOLEH ADA SPASI\n");
            return 0;
        }
        i++;
    }
    return 1;
}

void SignIn(){
    while(getchar() != '\n');
    printf("MASUKKAN EMAIL ANDA: ");
    fgets(email, sizeof(email), stdin);
    printf("MASUKKAN PASSWORD ANDA: ");
    fgets(password, sizeof(password), stdin);

    FILE *fptr = NULL;
    fptr = fopen(Path, "r");
    if(fptr == NULL){
        system("cls");
    }else{
        while(fscanf(fptr,"%s", email) == 0){
            if(strcmp(email, "1") == 0){
                fscanf(fptr,"%s", password);
                if(strcmp(password, "1") == 0){
                    system("cls");
                    printf("Sign In Anda Berhasil \n");
                    exit(0);
                }
            }
        }
        system("cls");
        printf("EMAIL DAN PASSWORD ANDA SALAH. COBA SEKALI LAGI ATAU PERGI KE MENU Sign Up\n");
    }
}