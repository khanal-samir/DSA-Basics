//dynamic memory== heap memory persits unitl free is called
// static memory == stack memory persits inside a function only
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node NodeType;// alternative name
NodeType *head;

//insertion
void insertAtBeg(int item){
    NodeType *newNode;
    newNode= (NodeType*)malloc(sizeof(NodeType));
    newNode->data=item;
    newNode->next=NULL;
    if(head==NULL)
    head= newNode;
    else {
        newNode->next=head;
        head= newNode;
    }
}

void insertAtEnd(int item){
   NodeType *newNode = (NodeType*) malloc (sizeof(NodeType));
   NodeType *temp;
   newNode->data=item;
   newNode->next=NULL;
   if(head == NULL){
    head = newNode;
   }else{
    temp=head;
    while (temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= newNode;
   }
}

void insertAtPos(int item , int pos){
    NodeType *newNode = (NodeType *) malloc(sizeof(NodeType));
    newNode->data=item;
    newNode->next=NULL;
    if(pos<1){
        printf("Invalid position \n");
        return;
    }else if(pos==1){
        if(head==NULL){
            head= newNode;
        }else{
            newNode->next= head;
            head= newNode;
        }
    }else{
        NodeType *temp= head;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp = temp->next;
        }
        if(temp==NULL){
            printf("Invalid position \n");
            return;
        }
        newNode->next= temp->next;
        temp->next=newNode;
    }

}

//deletion
void deleteAtBeg(){
    if(head==NULL){
        printf("Empty list \n");
      
    }else if(head->next==NULL){//single node
        free(head);
        head=NULL;
      
        
    }else{
       NodeType * temp=head;
        head= head->next;
        free(temp);
    }
}

void deleteAtEnd(){
    if(head==NULL){
        printf("Empty list \n");
    }else if(head->next==NULL){
        free(head);// free the memory
        head=NULL;
    }else{
        NodeType *temp= head;
        NodeType *prev= NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}


void deleteAtPos(int pos){
    if(pos<1){
        printf("Invalid postion\n");
    }else if(pos==1){
        if(head==NULL){
            printf("Empty list \n");
        }else if(head->next==NULL){
            free(head);
            head=NULL;
        }else{
            NodeType *temp=head;
            head= head->next;
            free(temp);
        }
    }else {
        NodeType *temp=head;
        NodeType *prev=NULL;
        for(int i=1; i<pos && temp!=NULL; i++){
            prev=temp;
            temp= temp->next;
        }
        prev->next=temp->next;//point element after pos
        free(temp);
    }
}

//traverse
void displayList (){
    struct node *temp;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }else{
        temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp= temp->next;
        }
        printf("\n");
    }
}

int main(){
    insertAtPos(1,1);
    insertAtBeg(5);
    insertAtEnd(100);
    insertAtPos(3,2);
    displayList();
    deleteAtBeg();
    displayList();
    deleteAtEnd();
    displayList();
    deleteAtPos(2);
    displayList();
    return 0;
}