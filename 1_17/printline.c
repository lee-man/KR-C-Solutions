#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define MAXNUM 10
#define UPPER 20   /* set to be 20 for better testing */

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
        if (len > UPPER) {
            if (idx_line < MAXNUM) {
                copy(lines[idx_line], line);
                ++idx_line;
            }
            else
                break;
        }
    printf("The lines that are longer than 80 characters:\n");
    for (i = 0; i < idx_line; ++i)
        printf("%s", lines[i]); 
    return 0;
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
