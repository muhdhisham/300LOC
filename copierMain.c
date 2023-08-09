#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "listFiles.h"

int main() {
    char input[100];
    char cwd[1024];
    char *dest = "", *src="";
    


    while (1) {
        getcwd(cwd, sizeof(cwd));
        printf("copier %s",cwd);
        printf(" > ");
        scanf("%s",input);

        if ((strcmp(input, "quit")) == 0) {
            break;
        } 
        
        else if (strcmp(input, "help") == 0){

            printf("ls\n");
            printf("lls\n");
            printf("src \t %s \n",strlen(src) > 0 ? src : src);
            printf("dest \t %s \n",strlen(dest) > 0 ? dest : dest);
            printf("copy\n");
            printf("move\n");
        }

        else if (strcmp(input, "ls")){
            listFilesInFolder(src);

        }

        else if (strcmp(input, "src") == 0) {
            // Read the command following "src" and allocate memory for it
            scanf("%s", input);
            if (strlen(input) == 0 && (strlen(src) !=0)){
                printf("%s",src);
            } 
            src = (char *)malloc(strlen(input) + 1);
            if (src == NULL) {
                perror("Memory allocation error");
                return 1;
            }
            strcpy(src, input);
        }

        else if (strcmp(input, "dest") == 0) {
            // Read the command following "dest" and allocate memory for it
            scanf("%s", input);
            dest = (char *)malloc(strlen(input) + 1);
            if (dest == NULL) {
                perror("Memory allocation error");
                return 1;
            }
            strcpy(dest, input);
        }



        
    }
    

    return 0;
}


void listFilesInFolder(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Files in directory '%s':\n", path);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}
