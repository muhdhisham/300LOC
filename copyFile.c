#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(char []);

int main()
{
   char ch, source_file[20], destin_file[20];
   
   copyFile("Data3.txt");
 
   return 0;
}


void copyFile(char fileName[20]){
   char ch, source_file[20], destin_file[100] = "C:\\Users\\muhdh\\Downloads\\300LOC-main-20230808T170351Z-001\\300LOC-main\\Halo\\";
   FILE *source, *dest;
 
   source = fopen(fileName, "r");
 
   if( source == NULL )
   {
      printf("Press any key to exit.......\n");
      exit(EXIT_FAILURE);
   }
 
   strcpy(source_file, fileName);
   // printf("%s", source_file);
 
   dest = fopen(strcat(destin_file, source_file), "w");
   printf("%s", destin_file);

 
   if( dest == NULL )
   {
      perror("Error");
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, dest);
 
   printf("File copied successfully.\n");
 
   fclose(source);
   fclose(dest);
}