#include <stdio.h>

int main(void)
{
    long nb, nt, nl;  /* the count of blanks, tabs, and newlines. */
    int c;
    nb = 0;
    nt = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("# of blanks: %ld.\n", nb);
    printf("# of tabs: %ld.\n", nt);
    printf("# of lines: %ld.\n", nl);

    return 0;
}
