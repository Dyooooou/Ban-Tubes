#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SignUp.h"

void SignUp();
void SignIn();
int cekemail();
int cekpassword();
User user; 

void HomeScreen () {
    int pilihan;
    
    do
    { 

    printf("-----------------------------------------------------------\n");
    printf("                       SELAMAT DATANG DI                             \n");
    printf("                       BIOSKOP SUKA SUKA                        \n");
    printf("KETIK 1 : SIGN UP\n");
    printf("KETIK 2 : SIGN IN\n");
    printf("KETIK 3 : EXIT\n");
    printf("-----------------------------------------------------------\n");
    printf("MASUKKAN PILIHANMU : ");

    if(scanf("%d", &pilihan) !=1 ){
        printf("Input tidak valid. Harapakan input kembali angka 1, 2, atau 3 \n ");
        while (getchar() != '\n');  
        continue;
    }

    switch (pilihan) {
        case 1 : 
            SignUp(&user);
            SignIn();
        break;
        case 2 : 
            SignIn();
        break;
        case 3 : 
            printf("TERIMA KASIH TELAH BERKUNJUNG.\n");
        break;
        default : 
            printf("ANGKA YANG ANDA MASUKKAN TIDAK VALID\n");
        break;
    }
    }while(pilihan != 3);
} 

void SignUp(User *user){

     while(getchar() !='\n');
     printf("MASUKKAN USERNAME ANDA : "); 
     fgets(user->username, sizeof(user->username), stdin);
     strtok(user->username, "\n");
     do{
        printf("MASUKKAN EMAIL ANDA : ");
        fgets(user->email, sizeof(user->email), stdin);
        strtok(user->email, "\n");
        }while(!cekemail(user->email));
    do{
        printf("MASUKKAN PASSWORD ANDA : ");
        fgets(user->password, sizeof(user->password), stdin);
        strtok(user->password, "\n");
        }while(!cekpassword(user->password));
        FILE *fptr = NULL;
        fptr = fopen("isi.txt", "a");
        if(fptr == NULL){
            system("cls");
            printf("Coba Lagi");
        }else{
            fprintf(fptr, "%s,%s,%s\n", user->username, user->email, user->password);
            printf("Sign Up Anda Berhasil\n");
            fclose(fptr);
            }
}
     
// cek email yang di masukkan user
int cekemail(const char *email){
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
     fptr = fopen("isi.txt", "r");
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

// untuk cek password yang dimasukkan user
int cekpassword(const char *password){
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
    char inputemail[50];
    char inputpassword[50];
    char storedemail[50];
    char storedpassword[50];
    char storedusername[50];
    int found = 0;

    while(getchar() != '\n');
    printf("MASUKKAN EMAIL ANDA: ");
    fgets(inputemail, sizeof(inputemail), stdin);
    strtok(inputemail, "\n");
    printf("MASUKKAN PASSWORD ANDA: ");
    fgets(inputpassword, sizeof(inputpassword), stdin);
    strtok(inputpassword, "\n");

    FILE *fptr = fopen("isi.txt", "r");
    while(fscanf(fptr, "%s,%s,%s\n", storedusername, storedemail, storedpassword) != EOF){
        if(strcmp(inputemail, storedemail) == 0 && strcmp(inputpassword, storedpassword) == 0){
            found = 1;
            break;
        }
    }
    fclose(fptr);
    if(found){
        printf("SELAMAT LOGIN ANDA BERHASIL.\n");
    }else{
        printf("EMAIL ATAU PASSWORD ANDA SALAH. SILAHKAN COBA LAGI.\n");
    }
}
