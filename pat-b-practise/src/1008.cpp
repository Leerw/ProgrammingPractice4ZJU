#include <cstdio>

int main() {
    int N = 0, M = 0;
    scanf("%d%d", &N, &M);
    M = M % N;
    int array[N];
    int* p = array;
    int i = 0;
    for (i = 0; i != N; i++) {
        scanf("%d", &array[i]);
    }
    i = N - M;
    while (i != N) {
        printf("%d ", *(p + i));
        i += 1;
    }
    i = 0;
    p = array;
    while (i != N - M - 1) {
        printf("%d ", *(p + i));
        i += 1;
    }
    printf("%d", *(p + i));
    return 0;
}