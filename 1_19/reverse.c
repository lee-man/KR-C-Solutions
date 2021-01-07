#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

void reversex(char to[], char from[], int len);
int getlinex(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void) {
    int len;    /* current line length */
    int i;
    char line[MAXLINE];   /* current input line */
    char line_r[MAXLINE];  /* the reversed input line */

    while ((len = getlinex(line, MAXLINE)) > 0) {
        reversex(line_r, line, len);
        printf("%s", line_r);
    }
}

void reversex(char to[], char from[], int len)
{
    int i;
    if (from[len - 1] == '\n') {
        to[len - 1] = '\n';   
        to[len] = '\0';
        --len;
    }
    else {
        to[len] = '\0';
    }
    for (i = 0; i < len; i++) {
        to[i] = from[len - i - 1];
    }
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
