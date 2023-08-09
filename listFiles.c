#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

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

int main() {
    const char *folderPath = "C:\\Users\\muhdh\\Downloads\\300LOC-main-20230808T170351Z-001\\300LOC-main\\Halo"; // Replace with your folder path
    listFilesInFolder(folderPath);

    return 0;
}
