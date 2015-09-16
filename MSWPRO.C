/***************************************************************************
SOURCE CODE
****************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


#define SIZE 20

char board[SIZE][SIZE];
char act_board[SIZE][SIZE];
int n;

struct node
{
   int info;
   struct node *next;
};

struct stack
{
   struct node *top;
}*s;

void print_board();
void print_act_board();
int check_mine(int,int);
int count_adj(int,int);
void fill_numbers();
void push_stack(int);
int pop_stack();
void disp_stack();
void rc();

int main()
{
  int i,j,ctr,index1,index2,r_no,c_no,ch,res_flag=1,count,tot_moves=0,ch2;
  int a,prev_y,prev_x,no_flags=0,s_no,score[17],choice,choice2,res,temp_score;

  FILE *fp;

  s=(struct stack *)malloc(sizeof(struct stack));
  s->top=NULL;

  clrscr();

  for(a=200;a<=1000;a+=10)
  {
	 sound(a);
	 delay(20);
  }
  nosound();
  textcolor(RED);
  cprintf("\n\t\t\t        ");
  for(a=75;a>=35;a--)
  {
	 gotoxy(a,1);
	 cprintf("\n\n\nWELCOME  TO");
	 delay(40);
	 if(a>=36)
	     clrscr();
	 else
	     getch();
   }
   textcolor(BLUE);

   for(a=80;a>=35;a--)
   {
	gotoxy(a,1);
	cprintf("\n\n\n\n\nMINESWEEPER PARADOX");
	delay(40);
	if(a>=36)
	     clrscr();
	else
	     getch();
   }
   textcolor(RED);

   for(a=65;a>=26;a--)
   {
	gotoxy(a,1);
	cprintf("\n\n\n\n\n\n\nDeveloped by- NAMAN SANCHETI & SAMEER BISHNOI");
	delay(40);
	if(a>=27)
	     clrscr();
	else
	     getch();
   }
   clrscr();
   textcolor(RED);
   cprintf("\n\n\n         WELCOME  TO");
   textcolor(BLUE);
   cprintf("\n\n\n       MINESWEEPER PARADOX");
   textcolor(RED);
   cprintf("\n\n\nDeveloped by-NAMAN SANCHETI &                                                                SAMEER BISHNOI");
   getch();

   clrscr();

 while(1)
 {
	clrscr();
	gotoxy(20,4);
	textcolor(WHITE);
	cprintf("\n\n\nMINESWEEPER PARADOX");
	textcolor(RED);
	gotoxy(20,8);
	cprintf("\n1.NEW GAME");
	gotoxy(20,11);
	cprintf("2.INSTRUCTIONS");
	gotoxy(20,13);
	cprintf("3.QUIT");
	gotoxy(20,18);
	cprintf("\nENTER YOUR CHOICE:- ");
	textcolor(RED);
	scanf("%d",&choice);

	switch(choice)
	{
		case 3: exit(0);

		case 2: clrscr();
			gotoxy(10,4);
			textcolor(BLUE);
			cprintf("* THE AIM OF THIS GAME IS TO UNRAVEL ALL THE TILES WITHOUT\n");
			gotoxy(10,5);
			cprintf("  TRIGGERING A SINGLE MINE.\n ");
			gotoxy(10,7);
			cprintf("* IN A SINGLE CHANCE, THE PLAYER CAN EITHER OPEN TILE BY\n");
			gotoxy(10,8);
			cprintf("  PRESSING 1 OR FLAG IT BY PRESSING 2.\n");
			gotoxy(10,10);
			cprintf("* THE GAME GETS OVER IF A SINGLE MINE IS TRIGGERED OR IF\n");
			gotoxy(10,11);
			cprintf("  A PLAYER FLAGS MORE NUMBER OF TILES THAN NUMBER OF MINES.\n");
			gotoxy(10,13);
			cprintf("* THERE IS NO OPTION TO UNFLAG A TILE IF IT IS BEEN FLAGGED.\n");
			gotoxy(10,20);
			cprintf("PRESS ANY KEY TO GO BACK ON PREVIOUS PAGE ");
			textcolor(RED);
			getch();
			break;

   case 1:
   tot_moves=0;
   no_flags=0;
   res_flag=1;
   clrscr();
   textcolor(RED);
   printf("Enter the value of n to setup board of nxn dimension\n");
   scanf("%d",&n);
   if(n>16 || n<2)
   {
     while(n>16 || n<2)
     {
	if(n>16)
	   printf("Please enter a smaller value of n...\n");
	else
	   printf("Please enter a greater value of n...\n");
	getch();
	clrscr();
	textcolor(RED);
	printf("Enter the value of n to setup board of nxn dimension\n");
	scanf("%d",&n);
     }
   }

   switch(n)
   {
	case 2:fp=fopen("scores2.txt","a");
	       break;
	case 3:fp=fopen("scores3.txt","a");
	       break;
	case 4:fp=fopen("scores4.txt","a");
	       break;
	case 5:fp=fopen("scores5.txt","a");
	       break;
	case 6:fp=fopen("scores6.txt","a");
	       break;
	case 7:fp=fopen("scores7.txt","a");
	       break;
	case 8:fp=fopen("scores8.txt","a");
	       break;
	case 9:fp=fopen("scores9.txt","a");
	       break;
	case 10:fp=fopen("scores10.txt","a");
	       break;
	case 11:fp=fopen("scores11.txt","a");
	       break;
	case 12:fp=fopen("scores12.txt","a");
	       break;
	case 13:fp=fopen("scores13.txt","a");
	       break;
	case 14:fp=fopen("scores14.txt","a");
	       break;
	case 15:fp=fopen("scores15.txt","a");
	       break;
	case 16:fp=fopen("scores16.txt","a");
	       break;
   }


   ctr=n;
   randomize();
   for(i=1;i<=16;i++)
	score[i]=INT_MAX;


   for(i=0;i<n;i++)
   {
	for(j=0;j<n;j++)
	{
	  board[i][j]=48;
	}
   }

  while(1)
  {
       index1=rand()%n;
       index2=rand()%n;
       if(check_mine(index1,index2)==0 && check_mine(index1,index2+1)==0
	   && check_mine(index1+1,index2)==0 )
       {
	    board[index1][index2]='*';
	    ctr--;
       }
       else
       {
	    index1=rand()%n;
	    index2=rand()%n;
       }

       if(ctr==0) //ctr becomes zero when n mines have been placed
	    break;

  }

  fill_numbers();

  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
		act_board[i][j]=' ';/*initialize all entries in act_board to
				     '-'*/
      }
  }

  count=0;

  while(1)
  {
     clrscr();
     textcolor(RED);

     print_act_board();
     rc();

     printf("\nEnter the row number and column number:-\n");
     scanf("%d %d",&r_no,&c_no);

     if(r_no>n || c_no>n || r_no<0 || c_no<0)
     {
		while(r_no>n || c_no>n || r_no<0 || c_no<0)
		{
			printf("\nInvalid input...Please re-enter:-\n");
			printf("Enter the row number and column number:-\n");
			scanf("%d %d",&r_no,&c_no);
		}
     }

     tot_moves++;

     push_stack(r_no);//Storing the moves made by the user in a stack
     push_stack(c_no);

     printf("\nEnter your choice:-");
     printf("\n1.Open");
     printf("\n2.Flag\n");
     printf("3.Exit\n");
     scanf("%d",&ch);

     switch(ch)
     {
	   case 1:if(act_board[r_no-1][c_no-1]!=' ')
		  {
		       if(act_board[r_no-1][c_no-1]=='F')
		       {
			   printf("\nYou have already flagged this cell...!!!\n");
			   getch();
			   tot_moves--;
			   pop_stack();/*As move is invalid we do not keep
					 track of it*/
			   pop_stack();
		       }

		       else
		       {
			  printf("\nYou have already opened this cell...!!!\n");
			  getch();
			  tot_moves--;
			  pop_stack();/*As move is invalid we do not keep
					 track of it */
			  pop_stack();
		      }
		  }

		  else if(check_mine(r_no-1,c_no-1)==0)
		  {
		      act_board[r_no-1][c_no-1]=board[r_no-1][c_no-1];
		      count++;
		      if(board[r_no-1][c_no-1]=='0')//Opening adjacent zeroes
		      {
			   if(board[r_no-1][c_no-2]=='0' && r_no-1>=0 && c_no-2>=0)
			   {
				act_board[r_no-1][c_no-2]=board[r_no-1][c_no-2];
				count++;
			    }

			   if(board[r_no-1][c_no]=='0' && r_no-1>0 && c_no>=0)
			   {
				act_board[r_no-1][c_no]=board[r_no-1][c_no];
				count++;
			   }

			   if(board[r_no-2][c_no-1]=='0' && r_no-2>=0 && c_no-1>=0)
			   {
				act_board[r_no-2][c_no-1]=board[r_no-2][c_no-1];
				count++;
			   }

			   if(board[r_no][c_no-1]=='0' && r_no>=0 && c_no-1>=0)
			   {
				act_board[r_no][c_no-1]=board[r_no][c_no-1];
				count++;
			   }
		     }
		  }

		  else
		      res_flag=0;/*Setting res_flag to zero when mine has
				   been triggered */
		  break;

	   case 2:act_board[r_no-1][c_no-1]='F';
		  no_flags++;
		  break;

	   case 3:fclose(fp);
		  exit(0);

	   default:printf("\nInvalid choice...!!!");
		   printf("\nPlease enter another choice:-\n");
		   tot_moves--;
		   getch();
     }

     if(no_flags==n+1)
     {
       textcolor(YELLOW+BLINK);
       cprintf("\nGame Over...!!!");
       getch();
       textcolor(RED);
       cprintf("\nYou have flagged more mines than actually present...\n");
       break;
     }

     if(res_flag==0)
     {
       textcolor(YELLOW+BLINK);
       cprintf("\nGame over...!!!");
       getch();
       textcolor(RED);
       printf("\nDo you want to try again from your previous move?(0/1)\n");
       scanf("%d",&ch2);

       if(ch2==1)
       {
	   prev_y=pop_stack();
	   prev_x=pop_stack();
	   printf("\nYour previous move was at %d %d",prev_x,prev_y);
	   getch();
	   res_flag=1;/*Setting res_flag to 1 in order to continue playing
			from last correct move*/
       }

       else
       {
	 break;
	}

     }

     else if(count==((n*n)-n))/*Checking if only mines are remaining as count
				stores number of tiles opened*/
	break;
  }

  if(res_flag==0)
  {
     clrscr();
     textcolor(YELLOW+BLINK);
     printf("\nThanks for playing...!!!\n");
     getch();
     textcolor(RED);
     print_board();
     printf("\nThe total no. of moves was %d",tot_moves);
  }

  else if(count==(n*n)-n)
  {
     clrscr();
     textcolor(YELLOW+BLINK);
     cprintf("\nYou won...!!!");
     getch();
     printf("\nThe total no. of moves was %d",tot_moves);
     print_board();
     clrscr();
     textcolor(YELLOW+BLINK);
     cprintf("\nThanks for playing...!!!\n");
  }

  getch();
  clrscr();
  textcolor(RED);
  s_no=1;
  if(res_flag!=0)
  {
	if(tot_moves<score[n])
	{
	score[n]=tot_moves;
	fprintf(fp,"%d ",tot_moves);
	}
  }
  else
  {}
  fclose(fp);
  switch(n)
  {
	case 2:fp=fopen("scores2.txt","r");
	       break;
	case 3:fp=fopen("scores3.txt","r");
	       break;
	case 4:fp=fopen("scores4.txt","r");
	       break;
	case 5:fp=fopen("scores5.txt","r");
	       break;
	case 6:fp=fopen("scores6.txt","r");
	       break;
	case 7:fp=fopen("scores7.txt","r");
	       break;
	case 8:fp=fopen("scores8.txt","r");
	       break;
	case 9:fp=fopen("scores9.txt","r");
	       break;
	case 10:fp=fopen("scores10.txt","r");
	       break;
	case 11:fp=fopen("scores11.txt","r");
	       break;
	case 12:fp=fopen("scores12.txt","r");
	       break;
	case 13:fp=fopen("scores13.txt","r");
	       break;
	case 14:fp=fopen("scores14.txt","r");
	       break;
	case 15:fp=fopen("scores15.txt","r");
	       break;
	case 16:fp=fopen("scores16.txt","r");
	       break;
   }

  printf("\nThe high score for %dx%d board is\n",n,n);
  res=fscanf(fp,"%d",&temp_score);
  while(res!=-1 || res!=EOF)
  {
	if(temp_score<score[n])
		score[n]=temp_score;
	res=fscanf(fp,"%d %d ",&s_no,&temp_score);
  }
  if(score[n]==INT_MAX)
	printf("No high score exists...!!!");
  else
	printf("%d",score[n]);
   getch();
  fclose(fp);
  break;

		default:  gotoxy(40,1);
			  cprintf("Invalid choice...\n");
			  cprintf("Please enter another choice\n");

      }
}


  getch();
  return 0;
}

/*****************************************************************************
FUNCTION TO PRINT THE MINESWEEPER BOARD
*****************************************************************************/

void print_board()
{
  int i,j;
  textcolor(RED);
  printf("\nThe complete board was:-");
  for(i=0;i<n;i++)
  {
	printf("\n");
	for(j=0;j<n;j++)
	{
	     if(board[i][j]=='*')
	     {
		textcolor(YELLOW+BLINK);
		cprintf("%c ",board[i][j]);
		getch();
	     }

	     else
	     {
		textcolor(RED);
		printf("%c ",board[i][j]);
	     }
	}
  }
}

/****************************************************************************
FUNCTION TO PRINT THE BOARD ON WHICH GAME IS PLAYED
****************************************************************************/

void print_act_board()
{
  int i,j;
  textcolor(RED);
  gotoxy(2,1);
  for(i=0;i<n;i++)
  {
	 printf("\n");
	for(j=0;j<n;j++)
	{
	    if(j==0)
			cprintf("   %c| ",act_board[i][j]);
		else
			cprintf("%c| ",act_board[i][j]);

	}
  }
}

/****************************************************************************
FUNCTION TO CHECK IF MINE IS PRESENT AT (index1,index2)
****************************************************************************/

int check_mine(int index1,int index2)
{
    if(board[index1][index2]=='*')
       return 1;
    else
       return 0;
}
/****************************************************************************
FUNCTION TO FILL NUMBERS ON THE BOARD
****************************************************************************/

void fill_numbers()
{
  int i,j;
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
	 if(check_mine(i,j)==0 )
	 {
	    board[i][j]=count_adj(i,j)+48;
	 }
     }
  }
}
/****************************************************************************
FUNCTION TO COUNT NUMBER OF ADJACENT MINES AT (i,j)
*****************************************************************************/

int count_adj(int i,int j)
{
   int count=0;
   if(board[i][j+1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i][j-1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i-1][j]=='*' && (i>=0 && j>=0 && i<n && j<n) )
     count++;

   if(board[i+1][j]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i-1][j-1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i+1][j+1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i-1][j+1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

   if(board[i+1][j-1]=='*' && (i>=0 && j>=0 && i<n && j<n))
     count++;

     return count;
}

/****************************************************************************
FUNCTION TO PUSH AN ELEMENT IN STACK
*****************************************************************************/

void push_stack(int data)
{
   struct node *new_node;
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->info=data;
   new_node->next=NULL;
   if(s->top==NULL)
       s->top=new_node;
   else
   {
       new_node->next=s->top;
       s->top=new_node;
   }
}
/****************************************************************************
FUNCTION TO POP AN ELEMENT FROM STACK
*****************************************************************************/

int pop_stack()
{
   int temp;
   if(s->top==NULL)
      return -1;
   else
   {
      temp=s->top->info;
      s->top=s->top->next;
      return temp;
   }
}

/****************************************************************************
FUNCTION TO DISPLAY STACK
****************************************************************************/

void disp_stack()
{
   struct node *ptr;
   ptr=s->top;
   textcolor(BLUE);
   while(ptr!=NULL)
   {
     cprintf("\n%d ",ptr->info);
     ptr=ptr->next;
   }
}

/****************************************************************************
FUNCTION TO PRINT THE ROW AND COLUMN NUMBERS
****************************************************************************/
void rc()
{
     int i;
     textcolor(RED);
     gotoxy(2,1);
     for(i=1;i<=n;i++)
     {
	 if(i==1)
	   printf("  %d  ",i);
	 else if(i==9)
	 {
		printf("%d ",i);
	 }
	 else
	 {
	   if(i<10)
		printf("%d  ",i);
	   else
		printf("%d ",i);
	 }
     }
     gotoxy(1,2);
     for(i=1;i<=n;i++)
     {
	printf("%d\n",i);
     }
}

