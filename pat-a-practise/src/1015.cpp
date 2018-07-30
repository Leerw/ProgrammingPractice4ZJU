#include <cstdio>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}



int main() {
    int N, D;
    while (scanf("%d", &N), N >= 0) {
        scanf("%d", &D);
        if (!isPrime(N)) {
            printf("No\n");
            continue;
        }
        int z[40], num = 0;
        do {
            z[num++] = N % D;
            N = N / D;
        } while (N != 0);
        int Nreversed = 0;
        for (int i = 0; i < num; i++) {
            Nreversed = Nreversed * D + z[i];
        }
        if (isPrime(Nreversed)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
