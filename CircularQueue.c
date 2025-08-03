#include <stdio.h>

#define SIZE 5  // You can change this as needed

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return item;
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to demonstrate circular queue
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(50);
    enqueue(60);  // Should show overflow if queue is full
    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(70);
    enqueue(80);
    display();

    return 0;
}
