#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define maxsize 5
int front = -1, rear = -1,i;
void insert();
void delete();
void display();
queue[maxsize];
void main()
{
	int choice;
	clrscr();
	printf("\n\t --- Queue Opertion using array ---\t\n");
	while(choice!=4)
	{
	printf("\n1.Insert \n2.Delete  \n3.Display \n4.Exit\n");
	printf("\n Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		  insert();
		  break;
		case 2:
		  delete();
		  break;
		case 3:
		  display();
		  break;
		case 4:
		  exit(0);
		  break;
		default:
		  printf("\n Please enter valid choice");
		  break;
	}
	}
getch();
}
void insert()
{
     int item;
     printf("\n Enter your element");
     scanf("%d",&item);
	if(rear==maxsize-1)
	{
	  printf("\n Queue is Overflow");
	}
	else
	{
	 if(front==-1&&rear==-1)
	{
	 front =0;
	 rear =0;
	}
	else
	{
	  rear++;
	}
	}
	queue[rear] = item;
	printf("\n Element inserted");
}
void delete()
{
int item;
   if(front==-1||front>rear)
   {
     printf("\n\t -- Queue is underflow --\t\n ");
   }
   else{
	if(front == rear)
	{
	 front=-1;
	 rear=-1;
	}
	else{
	 front++;
	 }
       }
       printf("\n  %d Element is Deleted",queue[front]);
       item = queue[front];
}
void display()
{
    if(front==-1&&rear==-1)
    {
      printf("\n\t --- Queue is Empty ---\t\n");
    }
    else
    {
    printf("\n\t Elements are in queue\t\n");
     for (i=front;i<=rear;i++)
     {
      if(i==front)
      {
      printf("\n\t %d -->Front",queue[front]);
      }
      else if(i==rear)
      {
      printf("\n\t %d -->Rear",queue[rear]);
      }
      else{
       printf("\n\t %d",queue[i]);
       }
     }
}
}


