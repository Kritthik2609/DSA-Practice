#include <stdio.h>

#define SIZE 100

int deque[SIZE];
int front = -1;
int rear = -1;

// Check if deque is empty
int isEmpty() {
    return front == -1;
}

// Check if deque is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow at rear! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear < SIZE - 1) {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted at rear: %d\n", value);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow at front! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front > 0) {
        front--;
    } else {
        printf("Cannot insert at front. No space at front.\n");
        return;
    }

    deque[front] = value;
    printf("Inserted at front: %d\n", value);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow at front! Cannot delete\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;  // Deque becomes empty
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow at rear! Cannot delete\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;  // Deque becomes empty
    } else {
        rear--;
    }
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

// Main to demonstrate the deque
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);
    display();

    deleteFront();
    deleteRear();
    display();

    insertFront(1);
    insertRear(25);
    display();

    return 0;
}
