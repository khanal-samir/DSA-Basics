#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

bool isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty())
        front = 0;
    queue[++rear] = x;
    printf("%d enqueued.\n", x);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear)
        front = rear = -1; // Reset if last element
    else
        front++;
    return val;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    printf("Front element: %d\n", peek());
    printf("%d dequeued.\n", dequeue());
    displayQueue();
    printf("Front element after dequeue: %d\n", peek());
    return 0;
}