#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main( void )
{
   LLPtr startPtr = NULL;
   unsigned int choice;
   int id;
   char name[50];

   instructions();
   printf("? ");
   scanf("%u", &choice);
   while (choice != 3) {
      switch (choice) {
         case 1:
            printf("Enter id and name: ");
            scanf("%d", &id);
            getchar(); // consume whitespace/newline
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
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
      scanf("%u", &choice);
   }
   clearList(&startPtr);
   puts("End of run.");
}
