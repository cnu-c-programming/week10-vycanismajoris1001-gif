#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char name[20];
  int score;
  struct Point *next;
} Node;

Node* head = NULL;

void add(char* name, int score) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->score = score;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* curr = head;
    while (curr->next != NULL)
      curr = curr->next;
      curr->next = newNode;
  }
}

void delete(char* name) {
  Node* curr = head;
  Node* prev = NULL;

  while (curr != NULL) {
    if(strcmp(curr->name, name) == 0) {
      if(prev == NULL)
        head = curr->next;
      else prev->next = curr-> next;
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}
void print() {
  Node* curr = head;
  while (curr != NULL) {
    printf("%s %d\n", curr->name, curr->score);
    curr = curr->next;
  }
}

int main() {
  char command[10], name[20];
  int score;
  
  while (1) {
    scanf("%s", command);
    if (strcmp(command, "add") == 0) {
      scanf("%s %d", name, &score);
      add(name, score);
    } else if (strcmp(command, "delete") == 0) {
      scanf("%s", name);
      delete(name);
    } else if (strcmp(command, "print") == 0) {
      print();
    } else if (strcmp(command, "quit") == 0) {
      break;
    }
  }
  return 0;
}
}


  
};
