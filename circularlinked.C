
#include<stdio.h>
#include<stdlib.h>


struct lnode{//define node
    int data;
    struct lnode* next; //self referential str
};


typedef struct lnode node;

node* last = NULL;

void insertAtBeginning(int val){
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    if(last==NULL){ //list is empty
        newNode->next = newNode;
        last = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("\nInserted %d at the beginning",val);
}

void display(){
	node* temp = last->next;
    if(last==NULL){
	printf("List is empty");
	return;
    }
    printf("\nElements in the list are: ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=last->next);

}

void insertAtEnd(int val){
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    if(last==NULL){ //list is empty
        newNode->next = newNode;
        last = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("\nInserted %d at the beginning",val);
}

void deleteAtBeginning(){
	node* del;
    if(last==NULL){
	printf("List is empty");
	return;
    }



    if(last->next == last){ //only one element in list
        del = last;
        last = NULL;
    }
    else{
        del= last->next;
        last->next = last->next->next;
    }
    printf("\ndeleted %d",del->data);
    free(del);

}

void deleteAtEnd(){
	node *del,*temp;
    if(last==NULL){
	printf("List is empty");
	return;
    }


    if(last->next == last){ //only one element in list
        del = last;
        last = NULL;
    }
    else{
        temp = last->next;
        while(temp->next!=last){
            temp = temp->next;
        }
        del = last;
	temp->next = last->next;
	last = temp;

    }
    printf("\ndeleted %d",del->data);
    free(del);
}
int main(){
    int val,iab,iae;
    do{
    printf("\n\n---circular in linkedlist---");
    printf("\n1.Insert At Beginning\n2.Insert at End\n3.Delete At Beginning\n4.delete At End\n5.Exit\n6.Display on circular List\n");
    printf("Enter a choice : ");
    scanf("%d",&val);
    switch(val){
	case 1:
	    printf("Enter a value : ");
	    scanf("%d",&iab);
	    insertAtBeginning(iab);
	    break;
	case 2:
	    printf("Enter a value : ");
	    scanf("%d",&iae);
	    insertAtEnd(iae);
	    break;
	case 3:
	     deleteAtBeginning();
	     break;

	case 4:
	     deleteAtEnd();
	     break;
	case 5:
            printf("Exiting...");
            break;
        case 6:
            display();
            break;
        default:
            printf("\nInvalid choice...\n");
            break;
    }
    }while(val!=5);

    return 0;
}

/*
try
insertAfter(val)
insertBefore(val)
delete(val)
doubly circular linkedlist
*/