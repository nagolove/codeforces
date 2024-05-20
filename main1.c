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

static int test_num = 0;

void task(int a1, int b2) {
    test_num++;

    int cells = 0;
    fprintf(E, "%d task: %d %d\n", test_num, a1, b2);

    /*
    На экране - два больших и 7 малых значков
    или 15 малых значков
     */
    int ans = 0;

    int k = b2 / 2 + (b2 % 2);

    if (a1 == 0 && b2 == 0) {
        printf("0\n");
        return;
    }

    if (b2 == 1 || b2 == 2 || b2 == 0)
        k = 1;

    fprintf(E, "k %d\n", k);
    cells = k * 15 - b2 * 4; // количество свободных еденичных ячеек

    fprintf(E, "cells %d\n", cells);

    if (a1 > cells) {
        fprintf(E, "needed %d\n", a1 - cells);
        int d1 = (a1 - cells) / 15;
        if (d1 == 0)
            d1 = 1;
        int d2 = 15 % (a1 - cells);
        fprintf(E, "d1 %d, d2 %d\n", d1, d2);
        ans += d1 + d2;
    }

    ans += k;

    printf("%d\n", ans);
    fprintf(E, "ans %d\n", ans);
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
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        task(a, b);
    }

    return EXIT_SUCCESS;
}
