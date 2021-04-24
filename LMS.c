#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

char catagories[][15]={"C Programming","Mechanics","Chemistry","Mathematics","English"};
void intro();
void returnfunc();
void mainmenu();
void addbooks();
void deletebooks();
void searchbooks();
void issuebooks();
void viewbooks();
int  getdata();
int  checkid();
int t();

FILE *fp,*ft,*fs;

int s;
char findbook;

struct books
{
	int id;
	char stname[20];
	char name[20];
	char Author[20];
	int quantity;
	int count;
	int rackno;
	char *cat;
};
struct books a;
void main()
{       system(“cls”);
	intro();
}
void intro()
{
	clrscr();
	printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\n");
	printf("\xB2          'C' Mini Project          \xB1\n");
	printf("\xB1                 on                 \xB2\n");
	printf("\xB2                                    \xB1\n");
	printf("\xB1  \xDB          \xDB\xDB      \xDB\xDB     \xDC\xDB\xDB\xDB\xDB\xDC  \xB2\n");
	printf("\xB2  \xDB          \xDB \xDB    \xDB \xDB     \xDD       \xB1\n");
	printf("\xB1  \xDB          \xDB  \xDB  \xDB  \xDB      \xDB\xDB\xDB\xDB   \xB2\n");
	printf("\xB2  \xDB          \xDB   \xDF\xDF   \xDB          \xDE  \xB1\n");
	printf("\xB1  \xDB\xDB\xDB\xDB\xDB\xDB\xDB    \xDB        \xDB     \xDF\xDB\xDB\xDB\xDF   \xB2\n");
	printf("\xB2  LIBRARY    MANAGEMENT    SYSTEM   \xB1\n");
	printf("\xB1                                    \xB2\n");
	printf("\xB2  Prepared by------                 \xB1\n");
	printf("\xB1        IFFAT PARVEZ                \xB2\n");
	printf("\xB2        JUWAIRIYA BAKHTEYAR         \xB1\n");
	printf("\xB1        MOHD GHAZI RAZA             \xB2\n");
	printf("\xB2        NISHAT WASI                 \xB1\n");
	printf("\xB1                                    \xB2\n");
	printf("\xB2  Submitted to------                \xB1\n");
	printf("\xB1        Mrs. KHALEDA AFROAZ ma'am   \xB2\n");
	printf("\xB2                                    \xB1\n");
	printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\n\n");
	printf("Press 'Enter' to start the programme");
	getch();
	mainmenu();
}
void mainmenu()
{
	int i;
	clrscr();
	printf("\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1 MAIN MENU \xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\n\n");
	printf("\xB1\xB2\xB1\xB2\xB1   1. Add Books   \n");
	printf("\xB2\xB1\xB2\xB1\xB2   2. Delete books\n");
	printf("\xB1\xB2\xB1\xB2\xB1   3. Search Books\n");
	printf("\xB2\xB1\xB2\xB1\xB2   4. Issue Books\n");
	printf("\xB1\xB2\xB1\xB2\xB1   5. View Book list\n");
	printf("\xB2\xB1\xB2\xB1\xB2   6. Close the Programme\n\n");
	printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\n");
	t();
	printf("Enter your choice:\n\n");
	switch(getch())
	{
		case '1':addbooks();
			 break;
		case '2':deletebooks();
			break;
		case '3':searchbooks();
			break;
		case '4':issuebooks();
			break;
		case '5':viewbooks();
			break;
		case '6':exit(0);
		default:{
				printf("\aWrong Entry!!\nPlease re-entered correct option");
				if(getch())
				mainmenu();
			}
	}
}
void addbooks(void)
{
	int i;
	clrscr();
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. C Programming\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. Mechanics\n");
	printf("\xDB\xDB\xDB\xDB\xB2 3. Chemistry\n");
	printf("\xDB\xDB\xDB\xDB\xB2 4. Mathematics\n");
	printf("\xDB\xDB\xDB\xDB\xB2 5. English\n");
	printf("\xDB\xDB\xDB\xDB\xB2 6. Back to main menu\n\n");
	printf("Enter your choice:");
	scanf("%d",&s);
	if(s==6)
		mainmenu() ;
	clrscr();
	fp=fopen("Books.txt","ab+");
	if(getdata()==1)
	{
		a.cat=catagories[s-1];
		fseek(fp,0,SEEK_END);
		fwrite(&a,sizeof(a),1,fp);
		fclose(fp);
		printf("\n\nThe record is sucessfully saved");
		printf("\n\nSave any more?(Y / N):\n");
		if(getch()=='n')
			mainmenu();
		else
			clrscr();
			addbooks();
	}
}
void deletebooks()
{
	int d;
	char another='y';
	clrscr();
	while(another=='y')  //infinite loop
	{
		clrscr();
		printf("Enter the Book ID to  delete:\n");
		scanf("%d",&d);
		fp=fopen("Books.txt","r");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(a.id==d)
			{
				printf("\nThe book record is available\n");
				printf("Book name is %s\n",a.name);
				printf("Rack No. is %d\n",a.rackno);
				findbook='t';
			}
		}
		if(findbook!='t')
		{
			printf("\nNo record was found. \nSearch again\n");
			if(getch())
				mainmenu();
		}
		if(findbook=='t' )
		{
			printf("\nDo you want to delete it?(Y/N):\n");
			if(getch()=='y')
			{
				ft=fopen("test.txt","w");
				rewind(fp);
				while(fread(&a,sizeof(a),1,fp)==1)
				{
					if(a.id!=d)
					{
						fseek(ft,0,SEEK_CUR);
						fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
					}                              //we want to delete
				}
				fclose(ft);
				fclose(fp);
				remove("Books.txt");
				rename("test.txt","Books.txt"); //copy all item from temporary file to fp except that
				fp=fopen("Books.txt","r");    //we want to delete
				if(findbook=='t')
				{
					printf("\nThe record is sucessfully deleted\n");
					printf("\nDelete another record?(Y/N)\n");
				}
			}
			else
				mainmenu();
				fflush(stdin);
				another=getch();
		}
	}
	mainmenu();
}
void searchbooks()
{
	int d=0;
	clrscr();
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	printf("\xDB\xDB\xDB\xB2 1. Search By Book ID\n");
	printf("\xDB\xDB\xDB\xB2 2. Search By Book Name\n");
	printf("\nEnter Your Choice\n");
	fp=fopen("Books.txt","r");
	rewind(fp);
	switch(getch())
	{
		case '1':
		{
			clrscr();
			printf("****Search Books By Id****");
			printf("\n\nEnter the book id:\n");
			scanf("%d",&d);
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(a.id==d)
				{
					printf("\nThe Book is available\n");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
					printf("\xB2 ID:%d\n",a.id);
					printf("\xB2 Name:%s\n",a.name);
					printf("\xB2 Author:%s \n",a.Author);
					printf("\xB2 Qantity:%d \n",a.quantity);
					printf("\xB2 Rack No:%d \n\n",a.rackno);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					findbook='t';
				}
			}
			if(findbook!='t')  //checks whether conditiion enters inside loop or not
			{
				printf("\n\nNo Book Found\n");
			}
			printf("\nTry another search?(Y/N)");
			if(getch()=='y')
				searchbooks();
			else
				mainmenu();
			break;
		}
		case '2':
		{
			char s[15];
			clrscr();
			printf("****Search Books By Name****");
			printf("\n\nEnter Book Name:\n");
			fflush(stdin);
			gets(s);
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
				{
					printf("\nThe Book is available\n");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
					printf("\xB2 ID:%d\n",a.id);
					printf("\xB2 Name:%s\n",a.name);
					printf("\xB2 Author:%s\n",a.Author);
					printf("\xB2 Qantity:%d\n",a.quantity);
					printf("\xB2 Rack No:%d \n",a.rackno);
					printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					d++;
				}
			}
			if(d==0)
			{
				printf("\n\nNo Book Found\n\n");
			}
			printf("Search another book?(Y/N)");
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
void issuebooks(void)
{
	int t,c=0,j=4,p,b;
	char another='y';
	FILE *fg;  //declaration of temporary file for delete
	clrscr();
	printf("********************************ISSUE SECTION**************************\n\n");
	printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book\n");
	printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book\n");
	printf("\xDB\xDB\xDB\xDb\xB2 3. Return Book\n\n");
	printf("Enter a Choice:\n");
	switch(getch())
	{
		case '1':
		{
			clrscr();
			while(another=='y')
			{
				clrscr();
				printf("***Issue Book ***\n\n");
				printf("Enter the Book Id:\n");
				scanf("%d",&t);
				fp=fopen("Books.txt","r");
				fs=fopen("Issue.txt","a");
				if(checkid(t)==0) //issues those which are present in library
				{
					printf("\nThe book record is available\n");
					printf("There are %d books left in the library \n",a.quantity);
					printf("The name of book is %s\n\n",a.name);
					printf("Enter student name:\n");
					fflush(stdin);
					gets(a.stname);
					printf("\nThe BOOK of ID %d has been issued",a.id);
					fseek(fs,sizeof(a),SEEK_END);
					fwrite(&a,sizeof(a),1,fs);
					fclose(fs);
					c=1;
				}
				if(c==0)
				{
					printf("\nNo record found");
				}
				printf("\n\n\nIssue any more(Y/N):");
				fflush(stdin);
				another=getch();
				fclose(fp);
			}
			break;
		}
		case '2':
		{
			clrscr();
			printf("*******************************Issued Books List*******************************\n\n");
			gotoxy(2,2);
			printf("STUDENT NAME       SUBJECT       ID       BOOK NAME");
			fs=fopen("Issue.txt","r");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				gotoxy(2,j);
				printf("%s",a.stname);
				gotoxy(21,j);
				printf("%s",a.cat);
				gotoxy(34,j);
				printf("%d",a.id);
				gotoxy(43,j);
				printf("%s",a.name);
				j++;

			}
			fclose(fs);
			returnfunc();
		}
		break;
		case '3':
		{
			clrscr();
			while(another=='y')
			{
				printf("\nEnter book id to return the book:\n");
				scanf("%d",&b);
				fs=fopen("Issue.txt","r");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==b)
					{
						findbook='t';
					}
					if(findbook=='t')
					{
						printf("\n\nDo you want to return this book?(Y/N)\n");
						if(getch()=='y')
						{
							fg=fopen("record.txt","w");
							rewind(fs);
							while(fread(&a,sizeof(a),1,fs)==1)
							{
								if(a.id!=b)
								{
									fseek(fs,0,SEEK_CUR);
									fwrite(&a,sizeof(a),1,fg);
								}
							}
							fclose(fs);
							fclose(fg);
							remove("Issue.txt");
							rename("record.txt","Issue.dat");
							printf("This book has been returned");
						}
					}
					if(findbook!='t')
					{
						printf("\n\nNo Record Found");
					}
				}
				printf("\n\nReturn more books?(Y/N)");
				another=getch();
			}
		}
		default:
		printf("\n\nError!!\n");
		getch();
		issuebooks();
		break;
	}
	returnfunc();
}
void viewbooks(void)
{
	int i=0,j;
	clrscr();
	gotoxy(1,1);
	printf("*********************************Book List*****************************");
	gotoxy(2,2);
	printf(" CATEGORY      ID      BOOK NAME        AUTHOR           QTY  ");
	j=4;
	fp=fopen("Books.txt","r");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		gotoxy(3,j);
		printf("%s",a.cat);
		gotoxy(16,j);
		printf("%d",a.id);
		gotoxy(24,j);
		printf("%s",a.name);
		gotoxy(40,j);
		printf("%s",a.Author);
		gotoxy(59,j);
		printf("%d",a.quantity);
		gotoxy(57,j);
		j++;
		i=i+a.quantity;
	}
	gotoxy(2,22);
	printf("Total Books =%d\n",i);
	fclose(fp);
	returnfunc();
}
void returnfunc(void)
{
	{
		printf(" Press ENTER to return to main menu");
	}
	a:
	if(getch()==13) //acsii value of enter is 13
		mainmenu();
	else
	goto a;
}
int getdata()
{
	int t;
	clrscr();
	printf("Enter the BOOK details:\n\n");
	printf("Category:\n");
	printf("%s\n\n",catagories[s-1]);
	printf("Book ID:\t\n");
	scanf("%d\n\n",&t);
	if(checkid(t) == 0)
	{
		printf("The book id already exists\n");
		getch();
		mainmenu();
		return 0;
	}
	a.id=t;
	printf("Book Name:  \n");
	fflush(stdin);
	gets(a.name);
	printf("\nAuthor:\n");
	fflush(stdin);
	gets(a.Author);
	printf("Quantity:\n");
	scanf("%d",&a.quantity);
	printf("Rack No:\n");
	scanf("%d\n",&a.rackno);
	return 1;
}
int checkid(int t)
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;
	return 1;
}
int t(void)
{
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
	return 0;
}
