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

void task(const char *line, int len) {
    fprintf(E, "line '%s', len %d\n", line, len);

    int map[26] = {};
    char r[26] = {};
    char buf[(int)(2 * pow(10, 5)) + 1], *pbuf = buf;
    memset(buf, 0, sizeof(r));

    for (int i = 0; i < len; i++) {
        int idx = line[i] - 'a' ;
        /*fprintf(E, "line[%d] = %c, idx %d\n", i, line[i], idx);*/
        map[idx]++;
    }

    char *pr = r;
    for (int i = 0; i < 26; i++) {
        if (map[i])
            *pr++ = i + 'a';
    }

    char cipher[26] = {0};

    fprintf(E, "r '%s'\n", r);
    size_t r_len = strlen(r);

    for (int i = 0; i < r_len / 2; i++) {
        cipher[(int)r[i] - 'a'] = r[r_len - i - 1] - 'a';
    }
    for (int i = r_len / 2 + 1; i < r_len; i++) {
        cipher[(int)r[i] - 'a'] = r[i - 1 - r_len / 2] - 'a';
    }
    /*if (r_len % 2)*/
        /*cipher[(int)r[r_len / 2 + 1] - 'a'] = r[r_len / 2 + 1] - 'a';*/

    fprintf(E, "cipher ");
    for (int i = 0; i < 26; i++) {
        fprintf(E, "'%c' ", cipher[i] + 'a');
    }
    fprintf(E, "\n");

    for (int i = 0; i < len; i++) {
        *pbuf++ = cipher[line[i] - 'a'] + 'a';
    }

    fprintf(E, "buf %s\n", buf);
    printf("%s\n", buf);
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input2.txt", "rt", stdin); 
    freopen("output2.txt", "wt", stdout); 
#endif

    size_t max_line_len = 2. * pow(10, 5) + 1;
    char line1[max_line_len];
    int num = 0;
    scanf("%d", &num);
    fgets(line1, max_line_len, stdin);
//#ifndef ONLINE_JUDGE
    fprintf(stderr, "num %d\n", num);
//#endif
    for (int i = 0; i < num; ++i) {
        /*line1[strlen(line1) - 1] = 0;*/
        /*fprintf(E, "line1: '%s'\n", line1);*/
        int len = 0;
        scanf("%d\n", &len);
        fgets(line1, max_line_len, stdin);
        line1[len - 0] = 0;
        task(line1, len);
    }

    return EXIT_SUCCESS;
}
