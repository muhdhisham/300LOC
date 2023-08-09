#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void listFilesRecursively(const char *basePath, const char *targetExtension) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    
    if (!(dir = opendir(basePath))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);

        if (stat(path, &fileStat) == -1) {
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            listFilesRecursively(path, targetExtension);
        } else {
            // Check if the file has the desired extension
            const char *fileExtension = strrchr(entry->d_name, '.');
            if (fileExtension && strcmp(fileExtension, targetExtension) == 0) {
                printf("%s\n", path);
            }
        }
    }
    closedir(dir);
}

int main() {
    const char *directoryPath = "."; // Change this to your target directory
    const char *targetExtension = ".c"; // Change this to the desired extension
    
    printf("Files with extension %s in directory %s:\n", targetExtension, directoryPath);
    listFilesRecursively(directoryPath, targetExtension);

    return 0;
}