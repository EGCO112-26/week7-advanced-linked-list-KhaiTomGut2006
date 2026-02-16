#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int id;
  char name[50];
  struct Node *nextPtr;
  struct Node *prevPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

int deletes(LLPtr *sPtr, int id);
int isEmpty(LLPtr sPtr);
void insert(LLPtr *sPtr, int id, char *name);
void printList(LLPtr currentPtr);
void instructions(void);
void clearList(LLPtr *sPtr);

void instructions(void) {
  puts("Enter your choice:\n"
       "   1 to insert an element into the list.\n"
       "   2 to delete an element from the list.\n"
       "   3 to end.");
}

void insert(LLPtr *sPtr, int id, char *name) {
  LLPtr newPtr;
  LLPtr previousPtr;
  LLPtr currentPtr;

  newPtr = (LLPtr)malloc(sizeof(LLnode));

  if (newPtr != NULL) {
    newPtr->id = id;
    strcpy(newPtr->name, name);
    newPtr->nextPtr = NULL;
    newPtr->prevPtr = NULL;

    previousPtr = NULL;
    currentPtr = *sPtr;

    while (currentPtr != NULL && id > currentPtr->id) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) {
      newPtr->nextPtr = *sPtr;
      if (*sPtr != NULL) {
        (*sPtr)->prevPtr = newPtr;
      }
      *sPtr = newPtr;
    } else {
      previousPtr->nextPtr = newPtr;
      newPtr->prevPtr = previousPtr;
      newPtr->nextPtr = currentPtr;
      if (currentPtr != NULL) {
        currentPtr->prevPtr = newPtr;
      }
    }
  } else {
    printf("%d not inserted. No memory available.\n", id);
  }
}

int deletes(LLPtr *sPtr, int id) {
  LLPtr previousPtr;
  LLPtr currentPtr;
  LLPtr tempPtr;

  if ((*sPtr) != NULL && id == (*sPtr)->id) {
    tempPtr = *sPtr;
    *sPtr = (*sPtr)->nextPtr;
    if (*sPtr != NULL) {
      (*sPtr)->prevPtr = NULL;
    }
    free(tempPtr);
    return id;
  } else if (*sPtr != NULL) {
    previousPtr = *sPtr;
    currentPtr = (*sPtr)->nextPtr;

    while (currentPtr != NULL && currentPtr->id != id) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      if (currentPtr->nextPtr != NULL) {
        currentPtr->nextPtr->prevPtr = previousPtr;
      }
      free(tempPtr);
      return id;
    }
  }

  return 0;
}

int isEmpty(LLPtr sPtr) { return sPtr == NULL; }

void printList(LLPtr currentPtr) {
  LLPtr lastPtr;
  LLPtr tempPtr;

  if (isEmpty(currentPtr)) {
    puts("List is empty.");
  } else {
    puts("The list is:");

    lastPtr = currentPtr;
    while (lastPtr->nextPtr != NULL) {
      lastPtr = lastPtr->nextPtr;
    }

    tempPtr = currentPtr;
    while (tempPtr != NULL) {
      printf("%d %s", tempPtr->id, tempPtr->name);
      if (tempPtr->nextPtr != NULL) {
        printf(" -->");
      } else {
        printf(" -->NULL");
      }
      tempPtr = tempPtr->nextPtr;
    }
    printf("\n");

    tempPtr = lastPtr;
    while (tempPtr != NULL) {
      printf("%d %s", tempPtr->id, tempPtr->name);
      if (tempPtr->prevPtr != NULL) {
        printf(" -->");
      } else {
        printf(" -->NULL");
      }
      tempPtr = tempPtr->prevPtr;
    }
    printf("\n");
  }
}

void clearList(LLPtr *sPtr) {
  LLPtr tempPtr;

  if (*sPtr != NULL) {
    puts("Clear all nodes");
    while (*sPtr != NULL) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->nextPtr;
      printf("delete %d\n", tempPtr->id);
      free(tempPtr);
    }
  }
}