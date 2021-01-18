#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flesh.h"

userdata *createUser(char *nama, char *sandi)
{
    userdata *var=(userdata*)malloc(sizeof(userdata));
    strcpy(var->nama, nama);
    strcpy(var->sandi, sandi);

    var->next=var->prev=NULL;
    var->fren=NULL;

    return var;
}

void pushuser(char *nama, char *sandi)
{
    userdata *var=createUser(nama,sandi);

    if(!headofuser)
    {
        tailofuser=var;
        headofuser=tailofuser;
    }else{
        headofuser->prev=var;
        var->next=headofuser;
        headofuser=var;
    }
}

userdata *login(char *nama, char *sandi)
{
    userdata *curr=headofuser;
    while(curr)
    {
        if(strcmp(curr->nama, nama) == 0 && strcmp(curr->sandi, sandi) == 0)
        {
            return curr;
        }
        curr=curr->next;
    }
    puts("Username atau Password salah!");
    return NULL;
}

void printUser()
{
    userdata *curr=headofuser;
    int a=1;
    while (curr){
        printf("\t%d.%s\n", a, curr->nama);
        a++;
        curr = curr->next;
    }
    if(a != 1) puts("");
}

void printFriend(userdata *curr) {

    system("cls || clear");
    printf("Daftar teman dari %s\n", curr->nama);

    if (!curr->fren)
    {
        puts("Anda masih tidak memiliki teman");
        return;
    }else{
        int a=1;
        while (curr->fren) {
            printf("\t%d.%s\n\n", a, curr->fren);
            a++;
            curr->fren = curr->fren->next;
        }
    }
    puts("");
}

bool lenghtValidator(char *kata) {

    int leng=strlen(kata);
    if (leng<0 || leng>25)
    {
        puts("Panjang karakter harus 1-24 karakter");
        getchar();
        return false;
    }else{
        for (int i = 0; kata[i] != '\0'; i++) {
            if (kata[i]==' ' || (kata[i]>='A' && kata[i]<='Z'))
            {
                puts("Dilarang menggunakan spasi, dan dimohon untuk menggunakan huruf kecil");
                getchar();
                return false;
            }
        }
    }
    return true;
}

bool userlistValidator(char *kata) {

    userdata *curr = headofuser;

    while(curr)
    {
        if(strcmp(curr->nama,kata) == 0)
        {
            puts("Nama sudah tersedia!");getchar();
            return false;
        }
        curr = curr->next;
    }
    return true;
}
