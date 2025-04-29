#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NodeType;


NodeType *front = NULL;
NodeType *rear = NULL;

// Check if queue is empty
int isEmpty() {
    return (front == NULL);
}

// Enqueue operation: Add element to the rear
void enqueue(int item) {
    // Create a new node
    NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot enqueue %d\n", item);
        return;
    }
    
    
    newNode->data = item;
    newNode->next = NULL;
    
   
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        // Link the new node at the rear
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation: Remove and return front element
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot dequeue from empty queue\n");
        return -1;  // Return an error value
    }
    
    // Save the front node and its data
    NodeType *temp = front;
    int item = temp->data;
    
    // Update front pointer
    front = front->next;
    
    // If this was the last node, update rear to NULL
    if (front == NULL) {
        rear = NULL;
    }
    
    // Free the memory of the dequeued node
    free(temp);
    
    return item;
}


int peek() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;  // Return an error value
    }
    
    return front->data;
}


void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements (front to rear): ");
    NodeType *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void freeQueue() {
    NodeType *temp;
    
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
    
    rear = NULL;
}