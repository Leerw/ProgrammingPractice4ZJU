/**
 * n条直线将平面分为n*(n+1)/2+1
 * n条折线将平面分为2n^2-n+1
 * n条封闭曲线将平面分为n^2-n+2
 * n个平面将空间分为(n^3+5n)/6+1
 */

#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int M;
        scanf("%d", &M);
        printf("%lld\n", (long long) (2 * M * M - M + 1));
    }
    return 0;
}