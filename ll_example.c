
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
   printf( "%s", "? " );
   scanf( "%u", &choice );

   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter id and name: " );
            scanf( "%d %s", &id, name );
            insert( &startPtr, id, name );
            printList( startPtr );
            break;
         case 2: 
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &id );

               
               if ( deletes( &startPtr, id ) ) { 
                  printf( "%d deleted.\n", id );
                  printList( startPtr );
               } 
               else {
                  printf( "%d not found.\n\n", id );
               } 
            } 
            else {
               puts( "List is empty.\n" );
            } 

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } 

      printf( "%s", "? " );
      scanf( "%u", &choice );
   }
   
   clearList( &startPtr );
   puts( "End of run." );
} 
