#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define MAXC 4    /* maximun seperate lines for a long input line */
#define NCOLUMN 20   /* Fold at the n-th point */     
#define IN 1
#define OUT 0

int fold(char *to[], char from[]);
int getlinex(char line[], int maxline);

/* replace strings of blanks by the minimum number of tabs and blanks. */
int main(void) {
    int len;    /* current line length */
    int nl, i;
    char line[MAXLINE];   /* current input line */
    char line_r[MAXC][MAXLINE];  /* the reversed input line */


    while ((len = getlinex(line, MAXLINE)) > 0) {
        nl = fold(**line_r, line);
        for (i = 0; i < nl; ++i)
            printf("%s", line_r[i]);
    }
}

int fold(char *to[], char from[])
{
    int i, j, p;
    int m;
    int nl;
    int state;
    
    j = p = 0;
    nl = 0;
    state = OUT;

    for (i = 0; i < MAXLINE && from[i] != '\n'; ++i) {
        if ((from[i] == ' ' || from[i] == '\t') && (i - j) < NCOLUMN) {
            p = i;
        }
        if (p == j)
            p = i;
        for (m = 0; m < (p - j); ++m) {
            to[nl][m] = from[j + m];
        }
        to[nl][m + 1] = '\n';
        to[nl][m + 2] = '\0';
        i = j = p;
        ++nl;
    }    
    if (from[i] == '\n' && i != j) {
        for (m = 0; m < (i - j); ++m) {
            to[nl][m] = from[j + m];
        }
        to[nl][m + 1] = '\0';
    }
    
    return nl;
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


