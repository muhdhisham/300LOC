// C program that demonstrates
// the use of remove() function
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char ch, source_file[20], destin_file[20];
   FILE *source, *target;
 
   printf("Enter name of file to move\n");
   gets(source_file);
 
   source = fopen(source_file, "r");
 
   if( source == NULL )
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   printf("Enter name of target file\n");
   gets(destin_file);
 
   target = fopen(destin_file, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
 
   printf("File copied successfully.\n");
fclose(source);
int ret = remove(source_file);

   if(ret == 0) {
      printf("File deleted successfully");
   } else {
      printf("Error: unable to delete the file");
   }
 
   
   fclose(target);
 
   return 0;
}



