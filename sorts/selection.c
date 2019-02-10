#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAXLINE 1024
#define MAXSIZE 50000

typedef char *str;

int read(str strings[])
{
    int  size;
    char line[MAXLINE];

    for (size = 0; fgets(line, MAXLINE, stdin); size++) {
        strings[size] = calloc(strlen(line) + 1, sizeof(char));
        strcpy(strings[size], line);
    }
    return size;
}

void print(str strings[])
{
    for (int i = 0; strings[i] != NULL; i++)
        fputs(strings[i], stdout);
}

int main(int argc, char *argv[])
{
    str  tmp, page[MAXSIZE];
    int  min, size = read(page);
    fprintf(stderr, "%s %d records\n", argv[0], size);

    // selection sort
    clock_t start, end;
    start = clock();
    for (int i = 0; i < size; i++) {

        min = i;
        for (int j = i; j < size; j++) {
            if (strcmp(page[min], page[j]) > 0)
                min = j;
        }

        tmp = page[i];
        page[i] = page[min];
        page[min] = tmp;
    }
    end = clock();
    setlocale(LC_NUMERIC, "");
    fprintf(stderr, "execution time: %0.6f secs.\n",
           (float) (end - start) / (float) CLOCKS_PER_SEC);

    print(page);

    return 0;
}
