#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef ONLINE_JUDGE 
#endif

static FILE *E;

struct S {
    int val, rep;
};

int _cmp_map(const void *a, const void *b) {
    const struct S *_a = a, *_b = b;
    return _b->rep - _a->rep;
}

void task(int a, int b) {
    printf("%d %d\n", a < b ? a : b, a > b ? a : b);
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input1.txt", "rt", stdin); 
    freopen("output1.txt", "wt", stdout); 
#endif

    size_t max_line_len = 128;
    char line1[max_line_len];
    int num = 0;
    scanf("%d", &num);
    fgets(line1, max_line_len, stdin);
//#ifndef ONLINE_JUDGE
    fprintf(stderr, "num %d\n", num);
//#endif
    for (int i = 0; i < num; ++i) {
        fgets(line1, max_line_len, stdin);
        size_t len = strlen(line1);
        fprintf(E, "%s\n", line1);
        int a = 0, b = 0;
        sscanf(line1, "%d %d", &a, &b);
        task(a, b);
    }

    return EXIT_SUCCESS;
}
