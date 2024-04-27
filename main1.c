#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef ONLINE_JUDGE 
#endif

static FILE *E;


void task(char *line1, char *line2) {
    fprintf(E, "'%s', '%s'\n", line1, line2);
    int n = 0, k = 0;
    sscanf(line1, "%d %d\n", &n, &k);
    int nums[n];
    memset(nums, 0, sizeof(nums));

    char *token = strtok(line2, " ");
    int i = 0;
    while(token) {
        //puts(token);

        sscanf(token, "%d", &nums[i++]);

        token = strtok(NULL, " ");
    }

    fprintf(stderr, "n %d, k %d\n", n, k);
    for (int i = 0; i < n; i++) {
        fprintf(stderr, "%d ", nums[i]);
    }
    fprintf(stderr, "\n");
}


int main(int argc, char **argv) {
    E = stderr;

#ifndef ONLINE_JUDGE 
    freopen("input1.txt", "rt", stdin); 
    freopen("output.txt", "wt", stdout); 
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
