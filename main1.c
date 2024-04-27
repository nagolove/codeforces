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

void task(char *line1, char *line2) {
    fprintf(E, "'%s', '%s'\n", line1, line2);
    int n = 0, k = 0;
    sscanf(line1, "%d %d\n", &n, &k);
    int nums[n + 1];
    memset(nums, 0, sizeof(nums));

    if (k > n) {
        printf("1\n");
        return;
    }

    char *token = strtok(line2, " ");
    int i = 0;
    while(token) {
        //puts(token);

        sscanf(token, "%d", &nums[i++]);

        token = strtok(NULL, " ");
    }

    //fprintf(stderr, "n %d, k %d\n", n, k);
    fprintf(stderr, "nums:\n");
    for (int i = 0; i < n; i++) {
        fprintf(stderr, "%d ", nums[i]);
    }
    fprintf(stderr, "\n");
 //   */

    struct S map[100 + 2];
    struct S *order = &map[n + 1];

    int N = n;

    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; i++) {
        //fprintf(E, "%d\n", nums[i]);
        map[nums[i]].val = nums[i];
        map[nums[i]].rep++;
    }

    int total_cur = 0, total_prev = 0;

    for (int i = 0; i < n; i++) {
        total_prev += map[i].rep;
    }

    while (1) {
        qsort(map, n, sizeof(map[0]), _cmp_map);

        if (map[0].rep < k) {
            fprintf(E, "map[0].rep < %d\n", k);
            printf("%d\n", total_prev);
            return;
        }

        if (map[0].rep >= k) {
            map[0].rep -= k;

            int i = 1;
            while (i < n) {
                if (map[i].rep < k) 
                    break;
                i++;
            }

            order->val = map[i].val;
            order->rep = k - 1;
        }

        fprintf(E, "map:\n");
        for (int i = 0; i < n; i++) {
            fprintf(E, "val %d, rep %d\n", map[i].val, map[i].rep);
        }
        fprintf(E, "\n");

        total_cur = 0;
        for (int i = 0; i < n; i++) {
            total_cur += map[i].rep;
        }

        if (total_cur == total_prev) {
            fprintf(E, "break, total_cur %d\n", total_cur);
            break;
        }

        total_prev = total_cur;
    }

    /*
    for (int i = 0; i < n; i++) {
        fprintf(E, "val %d, rep %d\n", map[i].val, map[i].rep);
    }
    fprintf(E, "\n");
    */
    printf("%d", total_cur);
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input1.txt", "rt", stdin); 
    freopen("output1.txt", "wt", stdout); 
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
        fgets(line1, max_line_len, stdin);
        fgets(line2, max_line_len, stdin);
        size_t len = strlen(line1);
        line1[len - 1] = 0;
        len = strlen(line2);
        line2[len - 1] = 0;
        //printf("%s\n", line);
        task(line1, line2);
    }

    return EXIT_SUCCESS;
}
