#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */
#define MAXNUM 10
#define OUT 0
#define IN 1

int getlinex(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void) {
    int len;    /* current line length */
    int i;
    int idx_line;
    char line[MAXLINE];   /* current input line */
    char lines[MAXNUM][MAXLINE]; /* longest line saved here */

    idx_line = 0;

    while ((len = getlinex(line, MAXLINE)) > 0)
        if (len == 1 && line[0] == '\n') {
            continue;
        }
        else {
            if (idx_line < MAXNUM) {
                copy(lines[idx_line], line);
                ++idx_line;
            }
            else
                break;
        }
    printf("The processes lines:\n");
    for (i = 0; i < idx_line; ++i)
        printf("%s", lines[i]); 
    return 0;
}

/* getline: get a line into s, return length */
int getlinex(char s[], int lim)
{
    int c, j;
    int state;
    state = OUT;

    j = 0;
    while (j < lim - 1 && (c=getchar()) != EOF && c != '\n') {
        if (c == ' ' || c == '\t') {
            if (state == IN) {
                s[j] = ' ';
                ++j;
            }
            state = OUT;
        }
        else {
            state = IN;
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n') {
        s[j] = c;
        ++j;
    }
    s[j] = '\0';
    return j;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
