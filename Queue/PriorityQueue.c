#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global arrays to store elements and their priorities
int queue[MAX_SIZE];
int priority[MAX_SIZE];
int size = 0;

// Function to insert an element with its priority
void enqueue(int data, int p) {
    if (size >= MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    queue[size] = data;
    priority[size] = p;
    size++;
}

// Function to find the index of the element with the highest priority
int findHighestPriorityIndex() {
    if (size == 0) {
        return -1; // Queue is empty
    }
    int highestPriority = priority[0];
    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (priority[i] > highestPriority) {
            highestPriority = priority[i];
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

// Function to remove and return the element with the highest priority
int dequeue() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return -1; // Or some other indicator of an empty queue
    }

    int highestPriorityIndex = findHighestPriorityIndex();
    int highestPriorityElement = queue[highestPriorityIndex];

    // Shift elements to fill the gap
    for (int i = highestPriorityIndex; i < size - 1; i++) {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
    return highestPriorityElement;
}

// Function to check if the queue is empty
int isEmpty() {
    return size == 0;
}

// Function to display the queue (for debugging purposes)
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", queue[i], priority[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 1);

    display(); // Output: Queue: (10, 2) (20, 1) (30, 3) (40, 1)

    printf("Dequeued: %d\n", dequeue()); // Output: Dequeued: 30
    display(); // Output: Queue: (10, 2) (20, 1) (40, 1)

    printf("Dequeued: %d\n", dequeue()); // Output: Dequeued: 10
    display(); // Output: Queue: (20, 1) (40, 1)

    return 0;
}