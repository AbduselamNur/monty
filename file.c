#include "monty.h"

void openFile(char *name)
{
        FILE *fd = fopen(name, "r");

        if (name == NULL || fd == NULL)
                err(2, name);

        readFile(fd);
        fclose(fd);
}
void readFile(FILE *name)
{
        int leng;
        int fo = 0;
        char *buf = NULL;
        size_t len = 0;

        for (leng = 1; getline(&buf, &len, name) != -1; leng++)
        {
                fo = p_line(buf, leng, fo);
        }
        free(buf);
}
