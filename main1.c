#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef ONLINE_JUDGE 
#endif

void task(char *line) {
    int a, b, c;
    fprintf(stderr, "line '%s'\n", line);
    sscanf(line, "%d %d %d", &a, &b, &c);
    if (c > b && b > a)
        printf("STAIR\n");
    else if (b > a && b > c) 
        printf("PEAK\n");
    else
        printf("NONE\n");
}


int main(int argc, char **argv) {

#ifndef ONLINE_JUDGE 
    freopen("input1.txt", "rt", stdin); 
    freopen("output.txt", "wt", stdout); 
#endif

    size_t max_line_len = 128;
    char line[max_line_len];
    int num = 0;
    scanf("%d", &num);
//#ifndef ONLINE_JUDGE
    fprintf(stderr, "num %d\n", num);
//#endif
    fgets(line, max_line_len, stdin);
    while (fgets(line, max_line_len, stdin)) {
        size_t len = strlen(line);
        line[len - 1] = 0;
        //printf("%s\n", line);
        task(line);
    }

    return EXIT_SUCCESS;
}
