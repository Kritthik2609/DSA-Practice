#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("0\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node *addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            result = insertNode(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insertNode(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertNode(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

void main() {
    struct Node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int n,m, coeff, exp, i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d%d", &coeff, &exp);
        p1 = insertNode(p1, coeff, exp);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d%d", &coeff, &exp);
        p2 = insertNode(p2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = addPolynomials(p1, p2);

    printf("\nSum of Polynomials: ");
    display(sum);
}
