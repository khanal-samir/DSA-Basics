#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node NodeType;
NodeType *head;

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
    }
}


int main(){
    insertAtBeg(24);
    insertAtBeg(12);
    displayList();
    return 0;
}