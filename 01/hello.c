#include "hello.h"

#include <stdio.h>
#include <stdlib.h>

int hello_loop(int *i) {
    for (int j = 0; j < 10; j++) {
        printf("Go %d\n", *i);
        (*i)++;
    }
    return *i;
}

#ifndef TESTING
int main(void) {
    int i = 0;
    printf("Hello, world!\n");
    return hello_loop(&i);
}
#endif
