struct menu
{
    char material[200];
    int fav;
    int kind;
    menu* prev, *next;

}headofmenu, *tailofmenu;

struct friendship
{
    char nama[100];
    char sandi[100];
    friendship* prev, *next;
    
}*headoffriendship, *tailoffriendship;

struct userdata
{
    char nama[100];
    char sandi[100];
    friendship* fren;
    userdata* prev, *next;
    menu* menus;
}*headofuser, *tailofuser;

