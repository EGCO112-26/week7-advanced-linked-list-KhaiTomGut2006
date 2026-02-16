#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  setbuf(stdout, NULL);
  LLPtr startPtr = NULL;
  unsigned int choice;
  int id;
  char name[50];

  instructions();
  printf("? ");
  if (scanf("%u", &choice) != 1)
    choice = 3;
  while (choice != 3) {
    switch (choice) {
    case 1:
      printf("Enter id and name: ");
      scanf("%d", &id);
      scanf("%s", name);
      insert(&startPtr, id, name);
      printList(startPtr);
      break;
    case 2:
      if (!isEmpty(startPtr)) {
        printf("Enter number to be deleted: ");
        scanf("%d", &id);
        if (deletes(&startPtr, id)) {
          printf("%d deleted.\n", id);
          printList(startPtr);
        } else {
          printf("%d not found.\n\n", id);
        }
      } else {
        puts("List is empty.\n");
      }
      break;
    default:
      puts("Invalid choice.\n");
      instructions();
      break;
    }
    printf("? ");
    if (scanf("%u", &choice) != 1)
      break;
  }
  clearList(&startPtr);
  puts("End of run.");
}
