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

void task(int *t, int r, int c) {
    fprintf(E, "task\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            fprintf(E, "%c", t[i * r + c]);
        fprintf(E, "\n");
    }
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input2.txt", "rt", stdin); 
    freopen("output2.txt", "wt", stdout); 
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
        int r, c;

        scanf("%d %d\n", &r, &c);
        fprintf(E, "r %d, c %d\n", r, c);
        int *table = calloc(r * c * 2, sizeof(table[0]));

        size_t len;
        for (int i = 0; i < r; i++) {
            fgets(line2, max_line_len, stdin);

            len = strlen(line2);
            line2[len - 1] = 0;

            char *tmp = line2;
            int j = 0;
            while (*tmp) {
                table[i * r + j] = *tmp;
                tmp++, j++;
                /*fprintf(E, "read j %d, i %d\n", j, i);*/
            }

            /*fprintf(E, "'%s'\n", line2);*/

            //printf("%s\n", line);
        }
        
        task(table, r, c);
        free(table);
    }

    return EXIT_SUCCESS;
}
