#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define TAB_SIZE 8   /* the size of each tab */     
#define IN 1
#define OUT 0

void replacetabs(char to[], char from[]);
int getlinex(char line[], int maxline);

/* replace strings of blanks by the minimum number of tabs and blanks. */
int main(void) {
    int len;    /* current line length */
    int i;
    char line[MAXLINE];   /* current input line */
    char line_r[MAXLINE];  /* the reversed input line */

    while ((len = getlinex(line, MAXLINE)) > 0) {
        replacetabs(line_r, line);
        printf("%s", line_r);
    }
}

void replacetabs(char to[], char from[])
{
    int i, j, p;
    int state;
    int nblank;

    state = OUT;
    i = 0;
    j = 0;
    p = 0;
    nblank = 0;

    while (from[i] != '\n') {
        if (from[i] == ' ' || from[i] == '\t') {
            state = OUT;
            ++i;
            if (from[i] == ' ')
                nblank++;
            else
                nblank = nblank + TAB_SIZE;
        }
        else {
            if (state == OUT) {
                state = IN;
                printf("nblank, %d\n", nblank);
                printf("ntabs, %d\n", nblank/TAB_SIZE);
                printf("nblank, %d\n", nblank%TAB_SIZE);
                for (p = 0; p < (nblank / TAB_SIZE); ++p) {
                    to[j] = '\t';
                    ++j;
                }
                for (p = 0; p < (nblank % TAB_SIZE); ++p) {
                    to[j] = ' ';
                    ++j;
                }
                nblank = 0;
            }
            to[j] = from[i];
            ++i;
            ++j;
        }
    }
    if (from[i] == '\n') {
        to[j] = '\n';
        ++j;
    }
    to[j] = '\0';
    
}

/* getline: get a line into s, return length */
int getlinex(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


