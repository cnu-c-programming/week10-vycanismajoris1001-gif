
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char name[20];
    int score;
    struct Node *next;
} Node;

Node *head = NULL;

void add(char *name, int score) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}


int main() {

    return 0;
} 
