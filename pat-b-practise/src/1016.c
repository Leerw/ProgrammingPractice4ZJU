#include <stdio.h>

long long slave(long long A, int DA) {
    long long PA = 0;
    while (A != 0) {
        if (A % 10 == DA) {
            PA = PA * 10 + DA;
        }
        A = A / 10;
    }
    return PA;
}

int main() {
    int DA = 0, DB = 0;
    long long A = 0, B = 0;
    scanf("%lld%d%lld%d", &A, &DA, &B, &DB);
    printf("%lld", slave(A, DA) + slave(B, DB));
    return 0;
}