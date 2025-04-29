#include <stdio.h>

#define MAX 100

int queue[MAX];
int size = 0;

// Insert an element into the queue
void insert(int value) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }
    
    int i = size - 1;
    while (i >= 0 && queue[i] < value) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = value;
    size++;
}

// Find the maximum value (highest priority)
int find_max() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[0];
}

// Remove the highest priority element
int remove_highest() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    int highest = find_max();
    for (int i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
    }
    size--;
    return highest;
}

// Display the queue
void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(5);
    insert(30);
    insert(20);
    
    display();
    
    printf("Max value: %d\n", find_max());
    printf("Removed: %d\n", remove_highest());
    display();
    
    printf("Max value: %d\n", find_max());
    printf("Removed: %d\n", remove_highest());
    display();
    
    return 0;
}
