#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

//untuk menuAwal, dan menuUtama hanya tampilan sementara, silahkan jka ingin memperindah lagi
void menuAwal()
{
    system("cls||clear");
    printUser();
    printf("1.Sign Up\n");
    printf("2.Login\n");
    printf("3.Exit\n");
    printf(">> ");
}

void menuUtama()
{
    printf("1.Add Friend\n");
    printf("2.Remove Friend\n");
    printf("3.View Inbox\n");
    printf("4.View sent Request\n");
    printf("5.Add, Edit, Announce, Delete Note\n");
    printf("6.Log out\n");
    printf(">> ");
}
int main()
{
    bool program_run=true;

    while(program_run)
    {
        bool validator=false;
        userdata *registereduser=NULL;
        int opsi=-1;
        menuAwal();

        do
        {
            scanf("%d",&opsi);
            getchar();
        }while(opsi<1 && opsi>3);

        if(opsi==1)
        {
            char newName[30];
            char newPassword[30];
            do
            {
                printf("Nama (1-24): ");
                scanf("%[^\n]", newName);
                getchar();

            }while(!lenghtValidator(newName));
            do{
                printf("Password (1-24): ");
                scanf("%[^\n]", newPassword);
                getchar();
            }while(!lenghtValidator(newName));
            if(userlistValidator(newName))
            {
                pushuser(newName,newPassword);
            }

        }else if(opsi==2){
            char newName[30];
            char newPassword[30];

            int end = 0;
            do{
                printf("Nama : ");
                scanf("%[^\n]", newName);
                getchar();

                if (strlen(newName)==1 && newName[0]=='0')
                {
                    break;
                }

                printf("Password : ");
                scanf("%[^\n]", newPassword);
                getchar();

                registereduser = login(newName,newPassword);
                if (registereduser != NULL)
                {
                    validator=true;
                    end = 1;
                }
            } while (!end);

            while(validator)
            {
              printFriend(registereduser);
              menuUtama();

              int opsiutama=-1;

              do {
                scanf("%d", &opsiutama);
              } while (opsiutama<1 && opsiutama>6);

              if (opsiutama == 1)
              {

              }else if (opsiutama == 2) {

              }else if (opsiutama == 3) {

              }else if (opsiutama == 4) {

              }else if (opsiutama == 5) {

              }else if (opsiutama == 6) {
                validator=false;
                registereduser=NULL;
              }
            }
        }else if(opsi==3){
            program_run=false;
        }
    }
}
