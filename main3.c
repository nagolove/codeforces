#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void task(int a, int b, int c, int d) {
    int t;

    if (c < b && c > a && d > a && d < b)
        printf("YES\n");
    else
        printf("NO\n");
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input3.txt", "rt", stdin); 
    freopen("output3.txt", "wt", stdout); 
#endif

    size_t max_line_len = 128;
    char line1[max_line_len], line2[max_line_len];
    int num = 0;
    scanf("%d", &num);
    fgets(line1, max_line_len, stdin);
//#ifndef ONLINE_JUDGE
    fprintf(stderr, "num %d\n", num);
//#endif
    for (int i = 0; i < num; ++i) {
        /*fgets(line1, max_line_len, stdin);*/
        /*line1[strlen(line1) - 1] = 0;*/
        /*fprintf(E, "line1: '%s'\n", line1);*/
        int a = 0, b = 0, c = 0, d = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        task(a, b, c, d);
    }

    return EXIT_SUCCESS;
}
