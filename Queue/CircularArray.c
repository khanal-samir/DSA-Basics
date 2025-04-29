#include <stdio.h>
#include <stdbool.h>

#define MAX 5

// Global variables for circular queue
int queue[MAX];
int front = -1;
int rear = -1;

// Function prototypes
void initQueue();
bool isEmpty();
bool isFull();
void enqueue(int x);
int dequeue();
int peek();
void display();

int main()
{
  initQueue();

  enqueue(10);
  enqueue(20);
  enqueue(30);
  display(); // Queue: 10 20 30

  dequeue(); // 10 dequeued
  display(); // Queue: 20 30

  enqueue(40);
  enqueue(50);
  enqueue(60); // Queue Overflow! (MAX=5)
  display();   // Queue: 20 30 40 50

  printf("Front element: %d\n", peek()); // Front element: 20
  printf("%d , %d\n", front, rear);

  return 0;
}

void initQueue()
{
  front = rear = -1;
}

bool isEmpty()
{
  return (front == -1 && rear == -1);
}

bool isFull()
{
  return ((rear + 1) % MAX == front);
}

void enqueue(int x)
{
  if (isFull())
  {
    printf("Queue Overflow!\n");
    return;
  }
  if (isEmpty())
  {
    front = rear = 0;
  }
  else
  {
    rear = (rear + 1) % MAX;
  }
  queue[rear] = x;
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
  {
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % MAX;
  }
  printf("%d dequeued.\n", val);
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

void display()
{
  if (isEmpty())
  {
    printf("Queue is empty.\n");
    return;
  }
  printf("Queue: ");
  int i = front;
  do
  {
    printf("%d ", queue[i]);
    i = (i + 1) % MAX;
  } while (i != (rear + 1) % MAX);
  printf("\n");
}