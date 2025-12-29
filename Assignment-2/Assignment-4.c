#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char dirname[100];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("Cannot open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%-20s : ", entry->d_name);

        switch (entry->d_type) {
            case DT_REG:
                printf("Regular File");
                break;
            case DT_DIR:
                printf("Directory");
                break;
            case DT_LNK:
                printf("Symbolic Link");
                break;
            case DT_FIFO:
                printf("FIFO");
                break;
            case DT_SOCK:
                printf("Socket");
                break;
            case DT_CHR:
                printf("Character Device");
                break;
            case DT_BLK:
                printf("Block Device");
                break;
            default:
                printf("Unknown");
        }
        printf("\n");
    }

    closedir(dir);
    return 0;
}
