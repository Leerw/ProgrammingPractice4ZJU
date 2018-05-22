#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N) {
        int array[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
        sort(array, array + N);
        printf("%d\n", N % 2 == 0 ? (int)floor((array[N / 2 - 1] + array[N / 2])/2) : array[N / 2]);
    }
    return 0;
}