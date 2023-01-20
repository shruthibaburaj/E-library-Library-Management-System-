#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include<windows.h>

struct book{
    char name[30];
    char author[30];
    char genre[30];
    int rating;
    struct book *next;
};

struct tbr{
    char tname[30];
    char tauthor[30];
    struct tbr *next;
};

struct reading{
    char rname[30];
    char rauthor[30];
    struct reading *next;
};

struct completed{
    char cname[30];
    char cauthor[30];
    struct completed *next;
};

typedef struct book node;
node *head, *new_book, *temp, *pre, *cur;

typedef struct tbr node1;
node1 *thead, *tbook, *ttemp, *rptr, *rcur, *rpre;

typedef struct reading node2;
node2 *rhead, *rbook, *rtemp, *cptr, *ccur, *cpre;

typedef struct completed node3;
node3 *chead, *cbook, *ctemp, *ptr, *ur, *re;

struct book *head_book=NULL;
struct user *head_user=NULL;
void greetings();
void main_menu();
void addbook();
void deletebook();
void display();
void search();
void list();
void dlist();

COORD coord = {0, 0};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void main()
{
    greetings();
    getch();
}


void main_menu()
{
    int choice;
    system("COLOR 74");

        system("cls");
        printf("\n\n");
        printf("\n\t\t\t=================================================\n");
        printf("\n\t\t\t\t      What would you like to do? ");
        printf("\n\t\t\t\t     1.ADD NEW BOOK ");
        printf("\n\t\t\t\t     2.DELETE A BOOK ");
        printf("\n\t\t\t\t     3.DISPLAY BOOKS ");
        printf("\n\t\t\t\t     4.SEARCH FOR A BOOK  ");
        printf("\n\t\t\t\t     5.MY PERSONAL LIST  ");
        printf("\n\t\t\t\t     6.EXIT  ");
        printf("\n\t\t\t=================================================\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                addbook();
                break;
            }
        case 2:
            {
                deletebook();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                search();
                break;
            }
        case 5:
            {
                dlist();
                break;
            }
        case 6:
            {
                exit(1);
            }
        default:
            {
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press any key to try again: ");
                getch();
            }
    }
}

void greetings()
{
    system("COLOR F5");
    printf("\n\n");
    printf("\t\t\t      ====================================== \n");
    printf("\t\t\t     |                                      |\n");
    printf("\t\t\t     |                                      |\n");
    printf("\t\t\t     |     ----------------------------     |\n");
    printf("\t\t\t     |       E-Librarian Welcomes You!      |\n");
    printf("\t\t\t     |     ----------------------------     |\n");
    printf("\t\t\t     |                                      |\n");
    printf("\t\t\t     |                                      |\n");
    printf("\t\t\t      ====================================== \n");
    printf("\n\n");
    printf("\n\n\t\t\t         Press any key to continue ");
    getch();
    return main_menu();
}

void addbook()
{
    char c;
    new_book=(node*)malloc(sizeof(node));
    system("cls");


    do
    {


        printf("\n\t\t\t\t     =====ADD BOOK=====\n");
        printf("\n\t\t\t\t     ENTER BOOK NAME:  ");
        scanf("%s",new_book->name);
        printf("\n\t\t\t\t     ENTER AUTHOR NAME: ");
        scanf("%s",&new_book->author);
        printf("\n\t\t\t\t     ENTER BOOK GENRE: ");
        scanf("%s",&new_book->genre);
        printf("\n\t\t\t\t     ENTER YOUR RATING: ");
        scanf("%d",&new_book->rating);
        new_book->next=NULL;


    if(head==NULL)
    {
        head=new_book;
    }

    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new_book;
    }
    printf("\n\n\t\t\t\t     Book Added successfully!");

    }while(c=='y');

    printf("\n\t\t\t\t     Press Y to go to Main Menu: ");
    c=getch();
    return main_menu();
}

void deletebook()
{
    char del[20];
    char c;
    int value;
    system("cls");
    do
    {

    if(head!=NULL)
    {
        temp=head;
        pre=head;
        printf("\n\t\t\t\t     Which Book would you like to delete: ");
        scanf("%s",del);
        value=strcmp(temp->name,del);
        while(value!=0)
        {
            pre=temp;
            temp=temp->next;
        }

        if(temp==head)
            head=temp->next;
        else
            pre->next=temp->next;

        free(temp);
        printf("\n\t\t\t\t     Book: %s Successfully Deleted!\n",del);
    }

    else
        printf("\n\t\t\t\t     Your Bookshelf is Empty\n");

    }while(c=='y');

    printf("\n\t\t\t\t     Press Y to exit to Main Menu\n");
    c=getch();
    return main_menu();
}

void display()
{
    char c;
    system("cls");
    cur=head;
    if(cur!=NULL)
    {
        while(cur!=NULL)
        {


        printf("\n\t\t\t\t===============================");
        printf("\n\t\t\t\t     BOOK NAME  : %s",cur->name);
        printf("\n\t\t\t\t     AUTHOR     : %s",cur->author);
        printf("\n\t\t\t\t     GENRE      : %s",cur->genre);
        printf("\n\t\t\t\t     YOUR RATING: %d",cur->rating);
        printf("\n\t\t\t\t===============================");
        cur=cur->next;
        }
        printf("\n\t\t\t\t     Press any key to exit to Main Menu ");
        getch();
        return main_menu();
    }

    else
    {


        printf("\n\t\t\t\t     Your Bookshelf is empty :(");
        printf("\n\n\n\t\t\t\t     Press Y to add a book");
        printf("\n\t\t\t\t      OR");
        printf("\n\t\t\t\t     Press any key to go back to main menu");
        c=getch();

        if(c=='y')
            addbook();
        else
            return main_menu();

    }
}

void search()
{
    char key[20];
    char c;
    int value;
    system("cls");
    printf("\n\t\t\t\t     Enter name of Book: ");
    scanf("%s",key);
    temp=head;
    while(temp!=NULL)
    {
        value=strcmp(temp->name,key);
        if(value!=0)
            temp=temp->next;
        else
        {
            printf("\n\t\t\t\t     -BOOK FOUND!-");
            printf("\n\n\t\t\t\t     Book Name   : %s",temp->name);
            printf("\n\t\t\t\t     Book Author : %s",temp->author);
            printf("\n\t\t\t\t     Book Genre  : %s",temp->genre);
            printf("\n\t\t\t\t     Your Rating : %d",temp->rating);
            printf("\n\n\t\t\t\t     Press any button to exit to Main Menu");
            getch();
            return main_menu();

        }
    }
    printf("\n\t\t\t\t     Book Not found :(");
    printf("\n\t\t\t\t     Press any key to exit to Main menu");
    getch();
    return main_menu();
}



void list()
{
    int choice;
    char key[20];
    char fin[20];
    int value;
    int value1;
    system("cls");
    printf("\n\t\t\t\t     Which list would you like to edit?");
    printf("\n\t\t\t\t     1. To Be Read Pile");
    printf("\n\t\t\t\t     2. Reading Pile");
    printf("\n\t\t\t\t     3. Completed Pile");
    printf("\n\t\t\t\t     4. Back to List");
    printf("\n\n\t\t\t\t     Please enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:
        {
            tbook=(node1*)malloc(sizeof(node1));
            printf("\n\t\t\t\t     =====TO BE READ=====\n");
            printf("\n\t\t\t\t     ENTER BOOK NAME:  ");
            scanf("%s",tbook->tname);
            printf("\n\t\t\t\t     ENTER AUTHOR NAME: ");
            scanf("%s",&tbook->tauthor);
            tbook->next=NULL;

            if(thead==NULL)
                thead=tbook;

            else
            {
                ttemp=thead;
                while(ttemp->next!=NULL)
                    ttemp=ttemp->next;
                ttemp->next=tbook;
            }
            printf("\n\t\t\t\t     Press any key to go back");
            getch();
            return dlist();
            break;
        }


    case 2:
        {
            rptr=thead;
            if(rptr!=NULL)
            {
                while(rptr!=NULL)
                {


                printf("\n\t\t\t\t     BOOKS IN YOUR -TO BE READ-\n");
                printf("\n\t\t\t\t     BOOK NAME  : %s",rptr->tname);
                printf("\n\t\t\t\t     AUTHOR     : %s",rptr->tauthor);
                printf("\n\t\t\t\t===============================");
                rptr=rptr->next;
                }

            printf("\n\t\t\t\t     Which book would you like to add to your -READING PILE-?\n\t\t\t\t     ");
            scanf("%s",key);
            rcur=thead;
            while(rcur!=NULL)
            {
                value=strcmp(rcur->tname,key);
                while(value!=0)
                {
                    rpre=rcur;
                    rcur=rcur->next;
                }


                    rbook=(node2*)malloc(sizeof(node2));
                    strcpy(rbook->rname,rcur->tname);
                    strcpy(rbook->rauthor,rcur->tauthor);

                    rbook->next=NULL;

                    if(rhead==NULL)
                        rhead=rbook;

                    else
                    {
                        rtemp=rhead;
                        while(rtemp->next!=NULL)
                            rtemp=rtemp->next;
                        rtemp->next=rbook;
                    }


                    if(rcur==thead)
                        thead=rcur->next;
                    else
                    rpre->next=rcur->next;

                    free(rcur);
                    printf("\n\t\t\t\t     BOOK ADDED!");
                    getch();
                    return dlist();
            }
            printf("\n\t\t\t\t     Book Not found :(");
            printf("\n\t\t\t\t     Press any key to go back");
            getch();
            return dlist();


        }

            else
            {
                printf("\n\t\t\t\t     Your TBR list is empty :(");
                getch();
                return dlist();
            }

            break;
        }
    case 3:
        {
            cptr=rhead;
            if(cptr!=NULL)
            {
                while(cptr!=NULL)
                {


                printf("\n\t\t\t\t     BOOKS IN YOUR -READING PILE-\n");
                printf("\n\t\t\t\t     BOOK NAME  : %s",cptr->rname);
                printf("\n\t\t\t\t     AUTHOR     : %s",cptr->rauthor);
                printf("\n\t\t\t\t===============================");
                cptr=cptr->next;
                }

            printf("\n\t\t\t\t     Which book would you like to add to your -COMPLETED PILE-?\n\t\t\t\t     ");
            scanf("%s",fin);
            ccur=rhead;
            while(ccur!=NULL)
            {
                value1=strcmp(ccur->rname,fin);
                while(value1!=0)
                {
                    cpre=ccur;
                    ccur=ccur->next;
                }


                    cbook=(node3*)malloc(sizeof(node3));
                    strcpy(cbook->cname,ccur->rname);
                    strcpy(cbook->cauthor,ccur->rauthor);

                    cbook->next=NULL;

                    if(chead==NULL)
                        chead=cbook;

                    else
                    {
                        ctemp=chead;
                        while(ctemp->next!=NULL)
                            ctemp=ctemp->next;
                        ctemp->next=cbook;
                    }

                    if(ccur==rhead)
                        rhead=ccur->next;
                    else
                    cpre->next=ccur->next;

                    free(ccur);
                    printf("\n\t\t\t\t     BOOK ADDED!");
                    getch();
                    return dlist();


            }
            getch();
            return dlist();
        }

            else
            {
                printf("\n\t\t\t\t     Your READING list is empty :(");
                return dlist();
            }
            break;
        }
    case 4:
        {
            return dlist();
            break;
        }
    default:
        printf("Invalid option");
        getch();
        return dlist();
    }

getch();
}




void dlist()
{
    char c;
    int i,j;
    system("cls");
    //TBR PILE
    rcur=thead;
    gotoxy(30,3);
    printf("-TO BE READ-");
    j=5;
    if(rcur!=NULL)
    {
        while(rcur!=NULL)
        {
            gotoxy(30,j);
            printf("%s",rcur->tname);
            j++;
            rcur=rcur->next;
        }
    }

    else{
        gotoxy(30,5);
        printf("pile empty :(");
        }

    //READING PILE
    ccur=rhead;
    gotoxy(60,3);
    printf("-READING-");
    j=5;
    if(ccur!=NULL)
    {
        while(ccur!=NULL)
        {
            gotoxy(60,j);
            printf("%s",ccur->rname);
            j++;
            ccur=ccur->next;
        }
    }

    else{
        gotoxy(60,5);
        printf("pile empty :(");
        }

    //COMPLETED PILE
    ur=chead;
    gotoxy(90,3);
    printf("-COMPLETED-");
    j=5;
    if(ur!=NULL)
    {
        while(ur!=NULL)
        {
            gotoxy(90,j);
            printf("%s",ur->cname);
            j++;
            ur=ur->next;
        }
    }

    else{
        gotoxy(90,5);
        printf("pile empty :(");
        }

    gotoxy(5,20);
    printf("Press Y to EDIT LIST");
    gotoxy(5,22);
    printf("OR");
    gotoxy(5,24);
    printf("Press any button to exit to MAIN MENU");
    c=getch();
    if(c=='y')
    {
        return list();
    }

    else
    {
        getch();
        return main_menu();
    }
}

