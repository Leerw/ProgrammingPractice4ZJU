#include <cstdio>
#include <cstring>

int fibo[100];

int F(int n) {
    if (n == 0) {
        return 0;
    }
    if (fibo[n] != -1) {
        return fibo[n];
    }
    fibo[n] = F(n - 1) + F(n - 2);
    return fibo[n];
}

int main() {
    int n;
    memset(fibo, -1, sizeof(fibo));
    fibo[0] = 0;
    fibo[1] = 1;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", F(n));
    }
    return 0;
}