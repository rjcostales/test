/* C Program To Sort page in ascending order using bubble sort. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAXSIZE 40000

typedef char * str;

int main(int argc, char *argv[])
{
    int  i, size;
    char line[MAXLINE];
    str  temp, page[MAXSIZE];

    for (i = 0; fgets(line, MAXLINE, stdin); i++) {
        page[i] = calloc(strlen(line) + 1, sizeof(char));
        strcpy(page[i], line);
    }

    size = i;

    for (int step = 0; step < size - 1; ++step)
        for (int i = 0; i < size - step - 1; ++i) {
            if (strcmp(page[i], page[i + 1]) > 0) {
                temp = page[i];
                page[i] = page[i + 1];
                page[i + 1] = temp;
            }
        }

    for (int i = 0; page[i] != NULL; i++)
        fputs(page[i], stdout);

    return 0;
}
