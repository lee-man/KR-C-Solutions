#include <stdio.h>

#define IN 1
#define OUT 0

/* print a histogram of the lengths of words in its input */

int main(void)
{
    int c, i, j;
    int wc; /* word count */
    int state;
    int ncount[10]; /* from 1 to 9, and one elements for words that is larger than 9*/
    
    state = OUT;
    wc = 0;

    for (i=0; i < 10; ++i)
        ncount[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (wc > 9) {
                    ncount[9] += 1;
                } else {
                    ncount[wc-1] += 1;
                }
            }
            state = OUT;
            wc = 0;
        } else {
            state = IN;
            ++wc;
        }
    }
    
    printf("Histogram of lengths of words in its input:\n");
    for (i = 0; i < 9; ++i) {
        printf("length of %d: ", i+1);
        for (j = 0; j < ncount[i]; ++j)
            printf("#");
        printf("\n");
    }
    printf("length > 9: ");
    for (j = 0; j < ncount[9]; ++j)
        printf("#");
    printf("\n");

    return 0;
}
