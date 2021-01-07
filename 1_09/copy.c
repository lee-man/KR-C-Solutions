#include <stdio.h>

int main(void) {
    int c, c_last;

    while ((c = getchar()) != EOF) {
        if ((c == ' ') && (c_last == ' '))
            ;
        else
            putchar(c);
            c_last = c;
    }
}
