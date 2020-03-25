#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define FILEPATH "/home/debian/.config/errno/errno.config"
#define MAXLINESIZE 100
#define MAXCODE 134

typedef struct {
    char err_name[MAXLINESIZE];
    char err_info[MAXLINESIZE];
} errentry;

int main(int argc, char **argv)
{
    if (!strcmp(argv[argc-1], "-h") || argc == 1) {
        printf("Usage: errno [errno code] | [errno name] | -a | -h \n");
        exit(0);
    }



    FILE* file = fopen(FILEPATH, "r");
    assert(file != NULL);

    errentry entries[MAXCODE];

    char *buf = malloc(sizeof(*buf)*MAXLINESIZE);
    char *token = malloc(sizeof(*token)*MAXLINESIZE);
    int err_code;

    while (fgets(buf, MAXLINESIZE, file) != NULL) {
        err_code = atoi(strtok(buf, "/\n"));
        strncpy(entries[err_code].err_name, strtok(NULL, "/\n"), MAXLINESIZE);
        strncpy(entries[err_code].err_info, strtok(NULL, "/\n"), MAXLINESIZE);
    }

    while (--argc > 0) {
        if (!strcmp(argv[argc], "-a")) {
            for (int i = 0; i < MAXCODE; ++i) {
                printf("%d:%s:%s\n", i, entries[i].err_name, entries[i].err_info);
            }
        } else if ((atoi(argv[argc]) > 0) && (atoi(argv[argc]) < MAXCODE)) {
            err_code = atoi(argv[argc]);
            printf("%d:%s:%s\n", err_code, entries[err_code].err_name, entries[err_code].err_info);
        } else {
            for (int i = 0; i < MAXCODE; ++i) {
                if (!strcmp(entries[i].err_name, argv[argc])) {
                    printf("%d:%s:%s\n", i, entries[i].err_name, entries[i].err_info);
                    exit(0);
                }
            }
            printf("invalid request...\n");
        }
    }

    return 0;
}
