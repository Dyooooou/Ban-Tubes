// HEADER SIGNUP //

#ifndef SIGNUP_H
#define SIGNUP_H

typedef struct{
    char username[50];
    char email[50];
    char password[50];
}User;

void SignUp(User *user);
void SignIn();
int cekemail(const char *email);
int cekpassword(const char *password);
void HomeScreen();

#endif
