#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
#define COMPUTER 1
#define HUMAN 2

#define SIDE 3 
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'
int chec=0,flag=0;
void menu();
void uwrite();
void entry();
void signin();
void check();
void fun();
void mr2();
class user
{
  private:
	 char username[100];
	 char pas[100];
  public:
	 void signup()
  {

     cout<<"Sign Up:";
     cout<<"\nEnter your User Name (No Spaces): ";
     cin>>username;
     char temp[100];
     strcpy(temp,username);
     check();
     if(chec==0)
  {
     cout<<"\nEnter your Password (No Spaces):";
     cin>>pas;
     strcpy(username,temp);
     uwrite();
  }
     else
  {
     getch();
     system("cls");
     signin();
  }
  }
  char* nameret()
 {
  return username;
 }
  char* pasret()
 {
  return pas;
 }
 }u;

void viewacc();
void startup();

void adminmenu()
{   system("cls");
	int choice1;
	cout<<"\n1. View All Account(s)";
	cout<<"\n2. Log Out";
	cout<<"\n\nEnter Choice: ";
	here120:
	cin>>choice1;
	if(choice1==1)
	viewacc();
	else if(choice1==2)
	{
	system("cls");
	startup();
	}
	else
	{
	cout<<"Invalid Choice. Enter again: ";
	goto here120;
	}
}

void viewacc()
{
	system("cls");
	ifstream fin;
	fin.open("user.dat",ios::in|ios::binary);
	while(fin.read((char*)&u,sizeof(u)))
	{
	cout<<"User Name: ";
	cout<<u.nameret()<<"\n";
	cout<<"Password: ";
	cout<<u.pasret()<<"\n";
	cout<<endl;
	}
	fin.close();
	getch();
}

//Admin code ends

void check()
{
	char temp[100];
	strcpy(temp,u.nameret());
	ifstream use;
	use.open("user.dat",ios::in|ios::binary);
	while(use.read((char*)&u,sizeof(u)))
	{
	use.read((char*)&u,sizeof(u));
	if(strcmp(u.nameret(),temp)==0)
	{
	cout<<"User already exist. Proceed to SignIn.\n";
	chec=1;
	goto here1;
	}
	else chec=0;
	}
	here1:;
	use.close();
}

void uwrite()
{
	char temp[100];
	strcpy(temp,u.nameret());
	ofstream users;
	ofstream puser1,puser2,puser3,puser4,puser5;
	users.open("user.dat",ios::app|ios::binary);
	puser1.open(strcat(temp,"c"),ios::out|ios::binary);
	strcpy(temp,u.nameret());
	puser2.open(strcat(temp,"mn"),ios::out|ios::binary);
	strcpy(temp,u.nameret());
	puser3.open(strcat(temp,"n"),ios::out|ios::binary);
	strcpy(temp,u.nameret());
	puser4.open(strcat(temp,"s"),ios::out|ios::binary);
	strcpy(temp,u.nameret());
	puser5.open(strcat(temp,"mo"),ios::out|ios::binary);
	users.write((char*)&u,sizeof(u));
	cout<<"\nSign Up Successful! Proceed to SignIn.\n";
	getch();
	system("cls");
	users.close();
	puser1.close();
	puser2.close();
	puser3.close();
	puser4.close();
	puser5.close();
	signin();
}

int choice2;
char mobi[100];
char pass[100];

void authenticate()
{
	ifstream users;
	users.open("user.dat",ios::in|ios::binary);
	while(!users.eof())
	{
	users.read((char*)&u,sizeof(u));
	if(strcmp(mobi,u.nameret())==0 && strcmp(u.pasret(),pass)==0)
	{
	cout<<"Login Successful! ";
	flag=1;
	goto here;
	}
	if(strcmp(mobi,"admin")==0 && strcmp(pass,"admin")==0)
	adminmenu();
	}
	int choice;
	cout<<"Login Failed! Please check the User Name or Password\n";
	cout<<"1. Try Again\n";
	cout<<"2. Sign Up\n";
	cout<<"Enter Choice: ";
	here5:
	cin>>choice;
	if(choice==1)
	{
	system("cls");
	signin();
	}
	else if(choice==2)
	{
	system("cls");
	u.signup();
	}
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here5;
	}
	here:;
	getch();
	entry();
}

void signin()
{
	cout<<"Sign In:";
	cout<<"\nUser Name: ";
	cin>>mobi;
	cout<<"\nPassword:";
	cin>>pass;
	authenticate();
}

void entry()
{
	if(flag==1)
	menu();
	else
	signin();
}



void startup()
{    system("color 0B");
	cout<<("\t\t\t\t\t\tWelcome");
	cout<<"\n1. Sign In";
	cout<<"\n2. Sign Up";
	cout<<"\n3. Exit";
	cout<<"\nEnter your choice:";
	here8:
	cin>>choice2;
	if(choice2==1)
	{
	system("cls");
	signin();
	}
	else if(choice2==2)
	{
	system("cls");
	u.signup();
	}
	else if(choice2==3)
	{
	getch();
	    }
	     else	{
	cout<<"Invalid Choice! Enter Again: ";
	goto here8;
	}
}




//Game 2 Code Starts
bool isSafe(int mat[][9],int i,int j,int no,int n){
    //Row or col
    for(int x=0;x<n;x++){
        if(mat[i][x]==no || mat[x][j]==no ){
            return false;
        }
    }
    //Subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    int x,y;
    
    for(x=sx;x<sx+3;x++){
        for(y=sy;y<sy+3;y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    //Base case
    if(i==n){
        //Print the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
                if((j+1)%3==0){
                    cout<<"   ";
                }
                
            }
            if((i+1)%3==0){
                cout<<endl;
            }
            cout<<endl;
        }
        
        return true;
    }
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    //Blue cell
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    //White cell
    for(int no=1;no<=9;no++){
        if(isSafe(mat,i,j,no,n)){
            
            mat[i][j] = no;
            bool solveAaageKa = solveSudoku(mat,i,j+1,n);
            if(solveAaageKa==true){
                return true;
            }
            //backtrack
            mat[i][j] = 0;
            
        }
        
    }
    return false;
}
void showBoard(char board[][SIDE])
{
	printf("\n\n");
	
	printf("\t\t\t %c | %c | %c \n", board[0][0],
							board[0][1], board[0][2]);
	printf("\t\t\t--------------\n");
	printf("\t\t\t %c | %c | %c \n", board[1][0],
							board[1][1], board[1][2]);
	printf("\t\t\t--------------\n");
	printf("\t\t\t %c | %c | %c \n\n", board[2][0],
							board[2][1], board[2][2]);

	return;
}


void showInstructions()
{
	printf("\t\t\t Tic-Tac-Toe\n\n");
	printf("Choose a cell numbered from 1 to 9 as below"
			" and play\n\n");
	
	printf("\t\t\t 1 | 2 | 3 \n");
	printf("\t\t\t--------------\n");
	printf("\t\t\t 4 | 5 | 6 \n");
	printf("\t\t\t--------------\n");
	printf("\t\t\t 7 | 8 | 9 \n\n");
	
	printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");

	return;
}


// A function to initialise the game 
void initialise(char board[][SIDE], int moves[])
{
	// Initiate the random number generator so that 
	// the same configuration doesn't arises
	srand(time(NULL)); 
	
	// Initially the board is empty
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			board[i][j] = ' ';
	}
	
	// Fill the moves with numbers
	for (int i=0; i<SIDE*SIDE; i++)
		moves[i] = i;

	// randomise the moves
	random_shuffle(moves, moves + SIDE*SIDE);
	
	return;
}


void declareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER)
		printf("COMPUTER has won\n");
	else
		printf("HUMAN has won\n");
	return;
}


bool rowCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] && 
			board[i][0] != ' ')
			return (true);
	}
	return(false);
}

bool columnCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] && 
			board[0][i] != ' ')
			return (true);
	}
	return(false);
}


bool diagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] && 
		board[0][0] != ' ')
		return(true);
		
	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[0][2] != ' ')
		return(true);

	return(false);
}


bool gameOver(char board[][SIDE])
{
	return(rowCrossed(board) || columnCrossed(board)
			|| diagonalCrossed(board) );
}

void playTicTacToe(int whoseTurn)
{
	
	char board[SIDE][SIDE];
	
	int moves[SIDE*SIDE];
	
	// Initialise the game
	initialise(board, moves);
	

	showInstructions();
	
	int moveIndex = 0, x, y;
	
	// Keep playing till the game is over or it is a draw
	while (gameOver(board) == false && 
			moveIndex != SIDE*SIDE)
	{
		if (whoseTurn == COMPUTER)
		{
			x = moves[moveIndex] / SIDE;
			y = moves[moveIndex] % SIDE;
			board[x][y] = COMPUTERMOVE;
			printf("COMPUTER has put a %c in cell %d\n",
					COMPUTERMOVE, moves[moveIndex]+1);
			showBoard(board);
			moveIndex ++;
			whoseTurn = HUMAN;
		}
		
		else if (whoseTurn == HUMAN)
		{
			x = moves[moveIndex] / SIDE;
			y = moves[moveIndex] % SIDE;
			board[x][y] = HUMANMOVE;
			printf ("HUMAN has put a %c in cell %d\n",
					HUMANMOVE, moves[moveIndex]+1);
			showBoard(board);
			moveIndex ++;
			whoseTurn = COMPUTER;
		}
	}

	
	if (gameOver(board) == false && 
			moveIndex == SIDE * SIDE)
		printf("It's a draw\n");
	else
	{
		
		if (whoseTurn == COMPUTER)
			whoseTurn = HUMAN;
		else if (whoseTurn == HUMAN)
			whoseTurn = COMPUTER;
		
		
		declareWinner(whoseTurn);
	}
	return;
}


void fun()
{
	system("cls");
	int choice1;
	cout<<"1. GAME I";
	cout<<"\n2. GAME II";
	cout<<"\n3. Exit";
	cout<<"\n\nEnter choice: ";
	here10:
	cin>>choice1;
	if(choice1==1)
	{
		playTicTacToe(COMPUTER);
	}
	else if (choice1==2)
	{  int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
        
    int n=9;
    //Print the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
                if((j+1)%3==0){
                    cout<<"   ";
                }
                
            }
            if((i+1)%3==0){
                cout<<endl;
            }
            cout<<endl;
        }
        
        cout<<endl;
        
    //Solve 
    cout<<endl;
    cout<<"Solution - "<<endl;
    solveSudoku(mat,0,0,9);
    
	  getch();
    fun();
	}
else if(choice1==3)
	menu();
	else
	cout<<"Invalid Choice. Enter Again: ";
	goto here10;
}

void calc()
{
	double num1,num2;
    char operation,redo;
    cout<<"Calculator"<<endl;
    do
    {
	cout<<" Please enter an operation which you like to calculate (+,-,*,/) \nOr Press 0 to go Back: ";
	cin>>operation ;
	if(operation=='0')
	menu();
	cout<<endl<<endl;
	cout<<" Please enter two numbers to apply your requested operation(";
	cout<<operation<<"):"<<endl<<"1st num:";
	cin>>num1;
	cout<<"2nd num:" ;
	cin>>num2;
	cout<<endl;
	switch (operation)
	{
	case'+':
	cout<<"The addition of two numbers ("<<num1<<","<<num2<<"):";
	cout<<num1+num2<<endl;
	break;
	case'-':
	cout<<"The substraction of two numbers ("<<num1<<","<<num2<<"):";
	cout<<num1-num2<<endl;
	break;
	case'*':
	cout<<"The multiplication of two numbers ("<<num1<<","<<num2<<"):";
	cout<<num1*num2<<endl;
	break;
	case'/':
	cout<<"The division of two numbers ("<<num1<<","<<num2<<"):";
	if(num2==0)
	cout<<"not valid"<<endl;
	cout<<(num1/num2)<<endl;
	break;
	default:
	cout<<"unknown command"<<endl;
	}
	cout<<"enter y or Y to continue:";
	cin>>redo;
	cout<<endl<<endl;
    }
    while(redo=='y'||redo=='Y');
    menu();
}

void cont();
void note();
void msg();
void appoint();

void menu()
{
	system("cls");
	int choice1;
	cout<<"\t\t\t\t\t\t    >>ESSENTIALS<<\n\n";
	cout<<"Welcome: "<<mobi<<"\t\t\t\t\t\t\t\t\t";
	cout<<"\n1. Calculator";
	cout<<"\n2. Contacts";
	cout<<"\n3. FunBox";
	cout<<"\n4. Messages";
	cout<<"\n5. Notes";
	cout<<"\n6. Log Out";
	cout<<"\n\nEnter Choice: ";
	here12:
	cin>>choice1;
       if(choice1==1)
	{
	system("cls");
	calc();
	}
	else if(choice1==2)
	cont();
	else if(choice1==3)
	fun();
	else if(choice1==4)
	msg();
	else if(choice1==5)
	note();
	else if(choice1==6)
	{
	system("cls");
	startup();
	}
	else
	{
	cout<<"Invalid Choice. Enter again: ";
	goto here12;
	}
}
//Contacts Code Start
class contact{
	private:
	char name[100];
	char phone[100];
	char other[256];
	public:
	void input()
	{
	cout<<"Enter Contact Name: ";
	cin.ignore();
	gets(name);
	cout<<"Enter Contact Number: ";
	gets(phone);
	cout<<"Enter any other detail you want to add: ";
	gets(other);
	}
	char* nameret()
	{
	return name;
	}
	char* phoneret()
	{
	return phone;
	}
	char* otherret()
	{
	return other;
	}
}c;

void contadd();
void contedit();
void contdel();
void contsearch();
void contview();

void cont()
{
	system("cls");
	cout<<"1. Add New Contact";
	cout<<"\n2. Edit Existing Contact";
	cout<<"\n3. Delete Existing Contact";
	cout<<"\n4. Search Contact";
	cout<<"\n5. View All Contact(s)";
	cout<<"\n6. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here890:
	cin>>choice;
	if(choice==1)
	contadd();
	else if(choice==2)
	contedit();
	else if(choice==3)
	contdel();
	else if(choice==4)
	contsearch();
	else if(choice==5)
	contview();
	else if(choice==6)
	menu();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here890;
	}
}


void contadd()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	c.input();
	char tempn[100];
	strcpy(tempn,c.nameret());
	char tempp[100];
	strcpy(tempp,c.phoneret());
	char tempo[256];
	strcpy(tempo,c.otherret());
	ofstream fout;
	fout.open(temp,ios::app);
	ifstream fin;
	fin.open(temp,ios::in);
	int flag=0;
	while(fin.read((char*)&c,sizeof(c)))
	{
	if(strcmp(tempn,c.nameret())==0)
	{
	cout<<"A contact with same name already exist. Please check: ";
	cout<<"\nName: ";
	puts(c.nameret());
	cout<<"Phone Number: ";
	puts(c.phoneret());
	cout<<"Other Details:";
	puts(c.otherret());
	flag=1;
	}
	else if(strcmp(tempp,c.phoneret())==0)
	{
	cout<<"\n\nA contact with same number already exist. Please check: ";
	cout<<"\n\nName: ";
	puts(c.nameret());
	cout<<"Phone Number: ";
	puts(c.phoneret());
	cout<<"Other Details:";
	puts(c.otherret());
	flag=1;
	}
	}
	fin.close();
	strcpy(c.nameret(),tempn);
	strcpy(c.phoneret(),tempp);
	strcpy(c.otherret(),tempo);
	if(flag==0)
	{
	fout.write((char*)&c,sizeof(c));
	cout<<"\nContact Successfully Added.\n";
	fout.close();
	}
	getch();
	cont();
}

void contedit()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	here102:
	cout<<"Enter name of contact to be edited: ";
	cin.ignore();
	gets(name);
	fstream fp;
	int found=0;
	fp.open(temp,ios::in|ios::out);
	while(!fp.eof() && found==0)
	{
	fp.read((char*)&c,sizeof(c));
	if(strcmp(c.nameret(),name)==0)
	{
	cout<<"\nEnter The New Details: \n";
	c.input();
	int pos=(-1)*sizeof(c);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&c,sizeof(c));
	found=1;
	}
	}
	if(found==0)
	{
	cout<<"\nNo Such Contact Found. Press 1 to Try Again or Press 0 to Go Back.";
	int choice;
	here101:
	cin>>choice;
	if(choice==1)
	goto here102;
	else if(choice==0)
	cont();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here101;
	}
	}
	fp.close();
	cout<<"\n\nContact Successfully Edited.";
	getch();
	cont();
}

void contdel()
{
	system("cls");
	char temp[100];
	int flag=0;
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	here104:
	cout<<"Enter name of contact to be deleted: ";
	cin.ignore();
	gets(name);
	ifstream fp1;
	fp1.open(temp,ios::in);
	while(fp1.read((char*)&c,sizeof(c)))
	if(strcmp(name,c.nameret())==0)
	flag=1;
	fp1.close();
	ifstream fp3;
	fp3.open(temp,ios::in);
	ofstream fp2;
	fp2.open("Temp",ios::out);
	while(fp3.read((char*)&c,sizeof(c)))
	if(strcmp(name,c.nameret())!=0)
	fp2.write((char*)&c,sizeof(c));
	if(flag==1)
	cout<<"\nContact Successfully Deleted.\n";
	fp3.close();
	fp2.close();
	remove(temp);
	rename("Temp",temp);
	if(flag==0)
	{
	cout<<"No Such Contact Found. Press 1 to Try Again or Press 0 to Go Back.";
	int choice;
	here103:
	cin>>choice;
	if(choice==1)
	goto here104;
	else if(choice==0)
	cont();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here103;
	}
	}
	getch();
	cont();
}

void contsearch()
{
	system("cls");
	char temp[100];
	int flag=0;
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	char phone[100];
	int choice;
	here567:
	cout<<"\n1. Search by Name";
	cout<<"\n2. Search by Number";
	cout<<"\nEnter Choice: ";
	here568:
	cin>>choice;
	if(choice==1)
	{
	char name[100];
	cout<<"Enter the Name of the Contact: ";
	cin.ignore();
	gets(name);
	ifstream fp1;
	fp1.open(temp,ios::in);
	int flag=0;
	while(fp1.read((char*)&c,sizeof(c)))
	{
	if(strcmp(name,c.nameret())==0)
	{
	cout<<"Name: ";
	puts(c.nameret());
	cout<<"\nPhone Number: ";
	puts(c.phoneret());
	cout<<"\nOther Details:";
	puts(c.otherret());
	flag=1;
	}

	}
	fp1.close();
	if(flag==0)
	{
	cout<<"No such contact found. Press 1 to try again or Press 0 to go back: ";
	here678:
	int choice;
	cin>>choice;
	if(choice==1)
	{
	goto here567;
	}
	else if(choice==0)
	{
	cont();
	}
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here678;
	}
	}
	getch();
	cont();
	}
	else if(choice==2)
	{
	char phone[100];
	cout<<"Enter the Phone Number of the Contact: ";
	cin.ignore();
	gets(phone);
	ifstream fp1;
	fp1.open(temp,ios::in);
	int flag=0;
	while(fp1.read((char*)&c,sizeof(c)))
	{
	if(strcmp(phone,c.phoneret())==0)
	{
	cout<<"Name: ";
	puts(c.nameret());
	cout<<"\nPhone Number: ";
	puts(c.phoneret());
	cout<<"\nOther Details:";
	puts(c.otherret());
	flag=1;
	}

	}
	fp1.close();
	if(flag==0)
	{
	cout<<"No such contact found. Press 1 to try again or Press 0 to go back: ";
	here679:
	int choice;
	cin>>choice;
	if(choice==1)
	{
	goto here567;
	}
	else if(choice==0)
	{
	cont();
	}
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here679;
	}
	}
	}
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here568;
	}
}

void contview()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	ifstream fp1;
	fp1.open(temp,ios::in);
	while(fp1.read((char*)&c,sizeof(c)))
	{
	cout<<"Name: ";
	puts(c.nameret());
	cout<<"Phone Number: ";
	puts(c.phoneret());
	cout<<"Other Details:";
	puts(c.otherret());
	cout<<endl;
	}
	getch();
	cont();
}

//Contacts code ends

//Notes code starts

class notes
{
	private:
	char note[1000];
	public:
	void input()
	{
	cout<<"Enter Note: "<<endl;
	cin.ignore();
	gets(note);
	}
	char* noteret()
	{
	return note;
	}
}n;

void noteadd();
void noteedit();
void notedel();
void noteview();

void note()
{
	system("cls");
	cout<<"1. Add New Note";
	cout<<"\n2. Edit Existing Note";
	cout<<"\n3. Delete Existing Note";
	cout<<"\n4. View All Note(s)";
	cout<<"\n5. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here899:
	cin>>choice;
	if(choice==1)
	noteadd();
	else if(choice==2)
	noteedit();
	else if(choice==3)
	notedel();
	else if(choice==4)
	noteview();
	else if(choice==5)
	menu();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here899;
	}
}

void noteadd()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	n.input();
	ofstream fout;
	fout.open(temp,ios::app);
	fout.write((char*)&n,sizeof(n));
	cout<<"\nNote Successfully Added.\n";
	fout.close();
	getch();
	note();
}

void noteedit()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	fstream fp;
	fp.open(temp,ios::in|ios::out);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
	cout<<count<<". ";
	puts(n.noteret());
	count++;
	}
	fp.close();
	cout<<"Enter note number for the note to be edited: ";
	int choice;
	here111:
	cin>>choice;
	if(choice>=count)
	{
	cout<<"Invalid number. Enter again: ";
	goto here111;
	}
	else
	{
	fstream fp1;
	fp1.open(temp,ios::in|ios::out);
	cout<<"Enter New Note:\n";
	n.input();
	int pos=(1*(choice-1)*sizeof(n));
	fp1.seekp(pos,ios::beg);
	fp1.write((char*)&n,sizeof(n));
	cout<<"Note Successfully Edited\n";
	fp1.close();
	}
	getch();
	note();
}

void notedel()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
	cout<<count<<". ";
	puts(n.noteret());
	count++;
	}
	fp.close();
	cout<<"Enter note number for the note to be deleted: ";
	int choice;
	here121:
	cin>>choice;
	if(choice>=count)
	{
	cout<<"Invalid number. Enter again: ";
	goto here121;
	}
	else
	{
	ofstream fout;
	fout.open("Temp",ios::out);
	ifstream fin;
	fin.open(temp,ios::in);
	long int pos=(choice*sizeof(n));
	while(fin.read((char*)&n,sizeof(n)))
	{
	int p=fin.tellg();
	if(p!=pos)
	fout.write((char*)&n,sizeof(n));
	}
	fin.close();
	fout.close();
	remove(temp);
	rename("Temp",temp);
	cout<<"Note Successfully Deleted.\n";
	}
	getch();
	note();
}

void noteview()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
	cout<<count<<". ";
	puts(n.noteret());
	count++;
	}
	fp.close();
	getch();
	note();
}

//Note code Ends

//Messaging code starts

class message{
	private:
	char message[256];
	char sender[100];
	public:
	char* messageret()
	{
	return message;
	}
	char* senderret()
	{
	return sender;
	}
}m;

void msgnew();
void msgchk();
void msgold();
void msgdel();

void msg()
{
	system("cls");
	cout<<"1. Send New Message";
	cout<<"\n2. Check For New Message(s)";
	cout<<"\n3. View Old Message(s)";
	cout<<"\n4. Delete Old Message(s)";
	cout<<"\n5. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here897:
	cin>>choice;
	if(choice==1)
	msgnew();
	else if(choice==2)
	msgchk();
	else if(choice==3)
	msgold();
	else if(choice==4)
	msgdel();
	else if(choice==5)
	menu();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here897;
	}
}

void msgnew()
{
	system("cls");
	char name[100];
	cout<<"Enter Recepient User Name: ";
	here1234:
	cin.ignore();
	gets(name);
	ifstream fin;
	fin.open("user1234.dat",ios::in);
	int flag=0;
	while(fin.read((char*)&u,sizeof(u)))
	{
	if(strcmp(name,u.nameret())==0)
	flag=1;
	}
	fin.close();
	if(flag==0)
	{
	cout<<"No Such User Exist. Press 1 to Try Again or Press 0 to Go Back: ";
	int choice;
	here4321:
	cin>>choice;
	if(choice==1)
	goto here1234;
	else if(choice==0)
	msg();
	else
	{
	cout<<"Invalid Choice. Enter Again: ";
	goto here4321;
	}
	}
	else
	{
	strcat(name,"mn");
	cout<<"Enter Message: ";
	gets(m.messageret());
	ofstream fout;
	fout.open(name,ios::app);
	strcpy(m.senderret(),mobi);
	fout.write((char*)&m,sizeof(m));
	fout.close();
	cout<<"Message Successfully Sent.\n";
	}
	getch();
	msg();
}

void msgchk()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mn");
	ifstream fp;
	fp.open(temp,ios::in);
	cout<<"You have the following new message(s): \n"<<endl;
	while(fp.read((char*)&m,sizeof(m)))
	{
	cout<<"From: ";
	puts(m.senderret());
	puts(m.messageret());
	cout<<endl;
	}
	fp.close();
	char tempo[100];
	strcpy(tempo,mobi);
	strcat(tempo,"mo");
	ofstream fout;
	fout.open(tempo,ios::app);
	ifstream fin;
	fin.open(temp,ios::in);
	while(fin.read((char*)&m,sizeof(m)))
	fout.write((char*)&m,sizeof(m));
	fin.close();
	fout.close();
	ofstream newn;
	newn.open(temp,ios::out);
	newn.close();
	getch();
	msg();
}

void msgold()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mo");
	ifstream fp;
	fp.open(temp,ios::in);
	cout<<"You have the following old message(s): \n"<<endl;
	while(fp.read((char*)&m,sizeof(m)))
	{
	cout<<"From: ";
	puts(m.senderret());
	puts(m.messageret());
	cout<<endl;
	}
	fp.close();
	getch();
	msg();
}

void msgdel()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mo");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&m,sizeof(m)))
	{
	cout<<count<<". ";
	puts(m.senderret());
	puts(m.messageret());
	cout<<endl;
	count++;
	}
	fp.close();
	cout<<"Enter message number for the message to be deleted: ";
	int choice;
	here127:
	cin>>choice;
	if(choice>=count)
	{
	cout<<"Invalid number. Enter again: ";
	goto here127;
	}
	else
	{
	ofstream fout;
	fout.open("Temp",ios::out);
	ifstream fin;
	fin.open(temp,ios::in);
	long int pos=(choice*sizeof(m));
	while(fin.read((char*)&m,sizeof(m)))
	{
	int p=fin.tellg();
	if(p!=pos)
	fout.write((char*)&m,sizeof(m));
	}
	fin.close();
	fout.close();
	remove(temp);
	rename("Temp",temp);
	cout<<"Message Successfully Deleted.\n";
	}
	getch();
	msg();
}

//Messaging code ends
int main()
{
	startup();
return 0;}
