#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

typedef struct node NodeType;


NodeType *top = NULL;


int isEmpty() {
    return (top == NULL);
}


void push(int item) {
    
    NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
    
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push %d\n", item);
        return;
    }
    newNode->data=item;
    newNode->next=top;
    top = newNode;

}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return;  
    }
    if(top->next==NULL){
        free(top);
        top=NULL;
        return;
    }
    NodeType *temp= top;
    top= top->next;
    free(temp);    
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty! Nothing to peek\n");
        return -1;  // Return an error value
    }
    
    return top->data;
}


void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements (top to bottom): ");
    NodeType *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void freeStack() {
    NodeType *temp;
    
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}