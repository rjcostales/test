#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER  1024

int main(int argc, char *argv[])
{
    char buffer[BUFFER];

    memset(buffer, 0, sizeof(buffer));
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}
