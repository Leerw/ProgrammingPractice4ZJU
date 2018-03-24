#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int main() {
    int L = 0;
    int M = 0;
    int left = 0, right = 0;
    int counter = 0;
    while (scanf("%d %d", &L, &M) && L != 0 && M != 0) {
        int* tree = (int *)calloc(L + 1, sizeof(int));
        //memset(tree, -1, L * sizeof(int));
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &left, &right);
            for (int j = left; j <= right; j++) {
                *(tree + j) = 1;
            }
        }
        counter = 0;
        for (int i = 0; i <= L; i++) {
            if (*(tree + i) == 0) {
                counter += 1;
            }
        }
        printf("%d", counter);
        free(tree);
        tree = NULL;
    }
    return 0;
}