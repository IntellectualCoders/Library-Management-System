#include<windows.h>               //for sleep() used in int password()
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//#include<bios.h>

#define RETURNTIME 15

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void returnbooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findbook;
char password[10]={"teghdeep"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};


struct books
{
char nameb[25];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;
};
struct books a;


struct user
{
int id;
char name[25];
struct books book;
struct meroDate issued;
struct meroDate duedate;
};
struct user u;


int main()
{
char datamate[25]="DATAMATE";
int j,i,z,d;
gotoxy(20,5);
for(j=0;j<10;j++)
{
Sleep(50);
printf("$");
}
for(j=0;j<9;j++)
{
Sleep(50);
printf("%c",datamate[j]);
}
for(j=0;j<10;j++)
{
Sleep(50);
printf("$");
}
gotoxy(10,7);
printf("\n\nYou want to access which profile?\n1.Librarnian\t2.Student\n");
scanf("%d",&i);

if(i==1)                          //calling libranian section
{
printf("Welcome to Libranian Section\n");
Password();
}

else                               //calling student section
{
    system("cls");
  printf("Welcome to Student User\n\n\n\n");
  printf("Enter the option \n1.Search A record\n2.Exit\n");
  scanf("%d",&z);
  switch(z)
  {
   case 1:
       tegh:
       system("cls");
       gotoxy(25,4);
       printf("****Search Books By Id****");
       gotoxy(20,5);
       printf("Enter the Student id:");
       scanf("%d",&d);
       gotoxy(20,7);
       printf("Searching........");
       while(fread(&u,sizeof(u),1,fp)==1)
       {
         if(u.id==d)
         {
           Sleep(2);
           gotoxy(20,7);
           printf("The Book is available");
           gotoxy(20,8);
           printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
           gotoxy(20,9);
           printf("\xB2 ID:%d",u.id);gotoxy(47,9);
           printf("\xB2");
           gotoxy(20,10);
           printf("\xB2 Name:%s",u.name);
           gotoxy(47,10);
           printf("\xB2");
           gotoxy(20,11);
           printf("\xB2 Author:%s ",u.book.Author);gotoxy(47,11);printf("\xB2");
           gotoxy(20,12);
           printf("\xB2 Qantity:%d ",u.book.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
           gotoxy(20,13);
           printf("\xB2 Price:Rs.%.2f",u.book.Price);gotoxy(47,13);printf("\xB2");
           gotoxy(20,14);
           printf("\xB2 Rack No:%d ",u.book.rackno);gotoxy(47,14);printf("\xB2");
           gotoxy(20,15);
           printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
           findbook='t';
        }

   }
   if(findbook!='t')  //checks whether conditiion enters inside loop or not
   {
      gotoxy(20,8);
      printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
      gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
      gotoxy(20,10);
      printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
      gotoxy(22,9);printf("\aNo Record Found");
   }
   gotoxy(20,17);
   printf("Try another search?(Y/N)");
   if(getch()=='y')
     goto tegh;
   else
     goto tanya;
   break;
   case 2:
    tanya:
    system("cls");
    gotoxy(16,3);
    printf("\tLibrary Management System");
    gotoxy(10,4);
    printf("\tJaypee Institute Of Information Technology");
    gotoxy(20,5);
    printf("\tBatch B12\n");
    printf("Team:\n1.Teghdeep Kapoor:18104050\n2.Tanya Pandhi:18104064\n3.Damyanti Singh:18104032\n4.Mayuri Sahai:18104039");
    gotoxy(16,12);
    printf("******************************************");
    gotoxy(16,14);
    printf("*******************************************");
    gotoxy(16,15);
    printf("*******************************************");
    gotoxy(16,17);
    printf("********************************************");
    gotoxy(10,21);
    printf("Exiting in 3 second...........>");
    //flushall();
    Sleep(10000);
    exit(0);
  }
}
getch();
return 0;

}
void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
//textbackground(WHITE);
//textcolor(RED);
gotoxy(10,4);
for(j=0;j<10;j++)
{
Sleep(50);
printf(":)");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<10;j++)
{
Sleep(50);
printf("(:");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
void mainmenu()
{
//loaderanim();
system("cls");
//    textbackground(13);
int i;
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//    show_mouse();
gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Issue Books");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. Return Books");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 7. Search Book");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 8. Close Application");
gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,22);
t();
gotoxy(20,23);
printf("Enter your choice:");
switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
issuebooks();
break;
case '4':
returnbooks();
break;
case '5':
viewbooks();
break;
case '6':
editbooks();
break;
case '7':
searchbooks();
break;
case '8':
{
system("cls");
gotoxy(16,3);
printf("\tLibrary Management System");
gotoxy(10,4);
printf("\tJaypee Institute Of Information Technology");
gotoxy(20,5);
printf("\tBatch B12\n");
printf("Team:\n1.Teghdeep Kapoor:18104050\n2.Tanya Pandhi:18104064\n3.Damyanti Singh:18104032\n4.Mayuri Sahai:18104039");
gotoxy(16,12);
printf("******************************************");
gotoxy(16,14);
printf("*******************************************");
gotoxy(16,15);
printf("*******************************************");
gotoxy(16,17);
printf("********************************************");
gotoxy(10,21);
printf("Exiting in 3 second...........>");
//flushall();
Sleep(3000);
getch();
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

void addbooks(void)    //funtion that add books
{
system("cls");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGORIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. Back to main menu");
gotoxy(20,19);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,20);
printf("Enter your choice:");
scanf("%d",&s);
if(s==6)
mainmenu();
system("cls");
fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
{
u.book.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&u,sizeof(u),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n'|| getch()=='N')
mainmenu();
else
system("cls");
addbooks();
}
}

void deletebooks()    //function that delete items from file fp
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
rewind(fp);          //to set the file pointer at beginning
while(fread(&u,sizeof(u),1,fp)==1) //changed
{
if(u.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",u.name);
gotoxy(10,9);
printf("Rack No. is %d",u.book.rackno);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found modify the search");
if(getch())
mainmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&u,sizeof(u),1,fp)==1)
{
if(u.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&u,sizeof(u),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("Bibek.dat");
rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
fp=fopen("Bibek.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}


void searchbooks()
{
system("cls");
int d;
printf("*****************************Search Books*********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("Bibek.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Books By Id****");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&u,sizeof(u),1,fp)==1)
{
if(u.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",u.id);gotoxy(47,9);
printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",u.name);
gotoxy(47,10);
printf("\xB2");
gotoxy(20,11);
printf("\xB2 Author:%s ",u.book.Author);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Qantity:%d ",u.book.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",u.book.Price);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Rack No:%d ",u.book.rackno);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search Books By Name****");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&u,sizeof(u),1,fp)==1)
{
if(strcmp(u.book.nameb,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",u.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",u.book.nameb);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Author:%s",u.book.Author);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Qantity:%d",u.book.quantity);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",u.book.Price);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Rack No:%d ",u.book.rackno);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}


void issuebooks(void)  //function that issue books from library
{
int t;

system("cls");
printf("********************************ISSUE SECTION**************************");
gotoxy(10,5);
printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
gotoxy(10,7);
printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
gotoxy(10,9);
printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
gotoxy(10,11);
printf("Enter a Choice:");
switch(getch())
{
case '1':  //issue book
{
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("***Issue Book section***");
gotoxy(10,6);
printf("Enter the Book Id:");
scanf("%d",&t);
fp=fopen("Bibek.dat","rb");
fs=fopen("Issue.dat","ab+");
if(checkid(t)==0) //issues those which are present in library
{
gotoxy(10,8);
printf("The book record is available");
gotoxy(10,9);
printf("There are %d unissued books in library ",u.book.quantity);
gotoxy(10,10);
printf("The name of book is %s",u.book.nameb);
gotoxy(10,11);
printf("Enter student name:");
scanf("%s",u.name);
//struct dosdate_t d; //for current date
//_dos_getdate(&d);
//a.issued.dd=d.day;
//a.issued.mm=d.month;
//a.issued.yy=d.year;
gotoxy(10,12);
printf("Issued date=%d-%d-%d",u.issued.dd,u.issued.mm,u.issued.yy);
gotoxy(10,13);
printf("The BOOK of ID %d is issued",u.id);
u.duedate.dd=u.issued.dd+RETURNTIME;   //for return date
u.duedate.mm=u.issued.mm;
u.duedate.yy=u.issued.yy;
if(u.duedate.dd>30)
{
u.duedate.mm+=u.duedate.dd/30;
u.duedate.dd-=30;

}
if(u.duedate.mm>12)
{
u.duedate.yy+=u.duedate.mm/12;
u.duedate.mm-=12;

}
gotoxy(10,14);
printf("To be return:%d-%d-%d",u.duedate.dd,u.duedate.mm,u.duedate.yy);
fseek(fs,sizeof(u),SEEK_END);
fwrite(&u,sizeof(u),1,fs);
fclose(fs);
c=1;
}
if(c==0)
{
gotoxy(10,11);
printf("No record found");
}
gotoxy(10,15);
printf("Issue any more(Y/N):");
fflush(stdin);
another=getche();
fclose(fp);
}

break;
}
case '2':  //show issued book list
{
system("cls");
int j=4;
printf("*******************************Issued book list*******************************\n");
gotoxy(2,2);
printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
fs=fopen("Issue.dat","rb");
while(fread(&u,sizeof(u),1,fs)==1)
{

gotoxy(2,j);
printf("%s",u.name);
gotoxy(18,j);
printf("%s",u.book.cat);
gotoxy(30,j);
printf("%d",u.id);
gotoxy(36,j);
printf("%s",u.book.nameb);
gotoxy(51,j);
printf("%d-%d-%d",u.issued.dd,u.issued.mm,u.issued.yy );
gotoxy(65,j);
printf("%d-%d-%d",u.duedate.dd,u.duedate.mm,u.duedate.yy);
//struct dosdate_t d;
//_dos_getdate(&d);
gotoxy(50,25);
//            printf("Current date=%d-%d-%d",d.day,d.month,d.year);
j++;

}
fclose(fs);
gotoxy(1,25);
returnfunc();
}
break;
case '3':   //search issued books by id
{
system("cls");
gotoxy(10,6);
printf("Enter Book ID:");
int p,c=0;
char another='y';
while(another=='y')
{

scanf("%d",&p);
fs=fopen("Issue.dat","rb");
while(fread(&u,sizeof(u),1,fs)==1)
{
if(u.id==p)
{
issuerecord();
gotoxy(10,12);
printf("Press any key.......");
getch();
issuerecord();
c=1;
}

}
fflush(stdin);
fclose(fs);
if(c==0)
{
gotoxy(10,8);
printf("No Record Found");
}
gotoxy(10,13);
printf("Try Another Search?(Y/N)");
another=getch();
}
}
break;

default:
gotoxy(10,18);
printf("\aWrong Entry!!");
getch();
issuebooks();
break;
}
gotoxy(1,30);
returnfunc();
}


void returnbooks()
{
system("cls");
int b;
FILE *fg;  //declaration of temporary file for delete
char another='y';
while(another=='y')
{
gotoxy(10,5);
printf("Enter book id to remove:");
scanf("%d",&b);
fs=fopen("Issue.dat","rb+");
while(fread(&u,sizeof(u),1,fs)==1)
{
if(u.id==b)
{
issuerecord();
findbook='t';
}
if(findbook=='t')
{
gotoxy(10,12);
printf("Do You Want to Remove it?(Y/N)");
if(getch()=='y')
{
fg=fopen("record.dat","wb+");
rewind(fs);
while(fread(&u,sizeof(u),1,fs)==1)
{
if(u.id!=b)
{
fseek(fs,0,SEEK_CUR);
fwrite(&u,sizeof(u),1,fg);
}
}
fclose(fs);
fclose(fg);
remove("Issue.dat");
rename("record.dat","Issue.dat");
gotoxy(10,14);
printf("The issued book is removed from list");

}

}
if(findbook!='t')
{
gotoxy(10,15);
printf("No Record Found");
}
}
gotoxy(10,16);
printf("Delete any more?(Y/N)");
another=getch();
}
}
void viewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************");
gotoxy(2,2);
printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
j=4;
fp=fopen("Bibek.dat","rb");
while(fread(&u,sizeof(u),1,fp)==1)
{
gotoxy(3,j);
printf("%s",u.book.cat);
gotoxy(16,j);
printf("%d",u.id);
gotoxy(22,j);
printf("%s",u.book.nameb);
gotoxy(36,j);
printf("%s",u.book.Author);
gotoxy(50,j);
printf("%d",u.book.quantity);
gotoxy(57,j);
printf("%.2f",u.book.Price);
gotoxy(69,j);
printf("%d",u.book.rackno);
printf("\n\n");
j++;
i=i+u.book.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}


void editbooks(void)  //edit information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("****Edit Books Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be edited:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
while(fread(&u,sizeof(u),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The book is availble");
gotoxy(15,8);
printf("The Book ID:%d",u.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",u.book.nameb);
gotoxy(15,10);
printf("Enter new Author:");scanf("%s",u.book.Author);
gotoxy(15,11);
printf("Enter new quantity:");scanf("%d",&u.book.quantity);
gotoxy(15,12);
printf("Enter new price:");scanf("%f",&u.book.Price);
gotoxy(15,13);
printf("Enter new rackno:");scanf("%d",&u.book.rackno);
gotoxy(15,14);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(u),0);
fwrite(&u,sizeof(u),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}

void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a");
getch();
mainmenu();
return 0;
}
u.id=t;
gotoxy(21,7);
printf("Book Name:");gotoxy(33,7);
scanf("%s",u.book.nameb);
gotoxy(21,8);
printf("Author:");gotoxy(30,8);
scanf("%s",u.book.Author);
gotoxy(21,9);
printf("Quantity:");gotoxy(31,9);
scanf("%d",&u.book.quantity);
gotoxy(21,10);
printf("Price:");gotoxy(28,10);
scanf("%f",&u.book.Price);
gotoxy(21,11);
printf("Rack No:");gotoxy(30,11);
scanf("%d",&u.book.rackno);
return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&u,sizeof(u),1,fp)==1)
if(u.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

void issuerecord()  //display issued book's information
{
system("cls");
gotoxy(10,8);
printf("The Book has taken by Mr. %s",u.name);
gotoxy(10,9);
printf("Issued Date:%d-%d-%d",u.issued.dd,u.issued.mm,u.issued.yy);
gotoxy(10,10);
printf("Returning Date:%d-%d-%d",u.duedate.dd,u.duedate.mm,u.duedate.yy);
}
/*void loaderanim()
{
int loader;
system("cls");
gotoxy(20,10);
printf("LOADING........");
printf("\n\n");
gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
Sleep(100);printf("%c",219);}
}*/
//End of program