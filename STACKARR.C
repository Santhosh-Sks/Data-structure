#include<stdio.h>
int stack[50],choice,n,i,top;
void push();
void pop();
void show();
void main()
{       clrscr();
	printf("\n\t -----Stack using array----\t\n");
	printf("Enter the number of stack");
	scanf("%d",&n);
	while(choice!=4)
	{
	  printf("\n 1.push\n 2.pop\n 3.show\n 4.Exit");
	  printf("\nEnter your choice :");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	   case 1:
	   {
	     push();
	     break;
	   }
	   case 2:
	   {
	     pop();
	     break;
	   }
	   case 3:
	   {
	    show();
	    break;
	   }
	   case 4:
	   {
	    exit(0);
	    printf("\n Exiting.....");
	    break;
	   }
	   default:
	   {
	    printf("\nEnter valid choices");
	    break;
	   }
	  }
	};
getch();
}
void push()
{
 int val;
 if(top==n)
 {
  printf("\n\t --- Stack Overflow ---\t\n");

 }
 else
 {
  printf("\n Enter your value");
  scanf("%d",&val);
  top +=1;
  stack[top] = val;
 }
}
void pop()
{
 if(top == -1)
 {
  printf("\n\t --- Stack underflow ---\t\n");
 }
 else
 {
 top = top-1;
 printf("\n\t Element is poped");
 printf("\n\t Top--> %d",stack[top]);
 }
}
void show()
{
printf("\nThe Element of Stack:");
 for(i=top;i>0;i--)
 {
  if(i==top)
  {
   printf("\n\t%d --> Top",stack[i]);
  }
  else{
  printf("\n\t%d",stack[i]);
  }
 }
 if(top ==-1)
  {
  printf("\n Stack is empty");
  }
}



