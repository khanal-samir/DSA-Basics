#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NodeType;
struct node *head=NULL;

//insertion
void insertAtBeg(int data){
    NodeType * newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
    head=newNode;
    }else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }

}

void insertAtEnd(int item){
    NodeType * newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data=item;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        NodeType *temp=head;
        while (temp->next!=NULL)
        {
           temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void insertAtPos(int item, int pos) {
    NodeType *newNode = (NodeType *) malloc(sizeof(NodeType));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (pos < 1) {
        printf("Invalid position\n");
        free(newNode);  
        return;
    } else if (pos == 1) {
        // Insert at beginning
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    } else {
        NodeType *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode); 
            return;
        }
        
       
        newNode->next = temp->next;
        
       
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        
       
        temp->next = newNode;
        newNode->prev = temp;
    }
}

//deletion
void deleteAtBeg(){
    if(head==NULL){
        printf("Empty list \n");
    }else if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        NodeType *temp= head->next;
        head->next=NULL;
        free(head);
        head=temp;
        head->prev=NULL; 
    }
}

void deleteAtEnd(){
    if(head==NULL){
        printf("Empty list \n");
    }else if(head->next==NULL){
        head=NULL;
    }else{
        NodeType *temp;
        NodeType *prev;
        while(temp->next!=NULL){
            prev=temp;//second last
            temp=temp->next;//last
        }
        prev->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}
void deleteAtPos(int pos){
    if(pos < 1){
        printf("Invalid position\n");
    }else if(pos == 1){
        if(head == NULL){
            printf("Empty list\n");
        }else if(head->next == NULL){
            free(head);
            head = NULL;
        }else{
            NodeType *temp = head;
            head = head->next;
            head->prev = NULL;  // Update prev pointer for new head
            free(temp);
        }
    }else{
        NodeType *temp = head;
        NodeType *prev = NULL;
        
        for(int i = 1; i < pos && temp != NULL; i++){
            prev = temp;
            temp = temp->next;
        }
        
        if(temp == NULL){
            printf("Invalid position\n");
            return;
        }
        
        prev->next = temp->next;  // Point element after pos
        
        // Update prev pointer of the next node (if exists)
        if(temp->next != NULL){
            temp->next->prev = prev;
        }
        
        free(temp);
    }
}

//traverse 
void display(){
    if(head==NULL){
        printf("Empty list \n");
    }else {
        NodeType *temp=head;
        while (temp!=NULL)
        {
           printf("%d\t",temp->data);
           temp= temp->next;
        }
        printf("\n");
        
    }
}

int main(){
    insertAtBeg(5);
    insertAtEnd(10);
    insertAtBeg(2);
    insertAtEnd(15);
    insertAtPos(3,2);
    display();
    deleteAtBeg();
    deleteAtEnd();
    deleteAtPos(2);
    display();
}