#include <stdio.h>

#define TABSTOP 4
#define MAXLINE 1000

int main(void)
{
    int c, i, j;
    char line[MAXLINE];
    
    i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (j = 0; j < TABSTOP; ++j)
                line[i + j] = ' ';
            i = i + TABSTOP;
        }
        else {
            line[i] = c;
            ++i;
        }
    }
    line[i] = '\0';
    printf("detab string: %s", line);
    
    return 0;
}
