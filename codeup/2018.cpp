#include <cstdio>

int Fibonaci[20] = {0};

int F(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        if (Fibonaci[n - 1] == 0) Fibonaci[n - 1] = F(n - 1);
        if (Fibonaci[n - 2] == 0) Fibonaci[n - 2] = F(n - 2);
        Fibonaci[n] = Fibonaci[n - 1] + Fibonaci[n - 2];
        return Fibonaci[n];
    }
}

int main() {
    int m;
    F(19);
    scanf("%d", &m);
    while (m--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2 * (n - i); j++) {
                printf(" ");
            }
            printf("0");
            if (i != 1) printf(" ");
            for (int j = 0; j < 2 * (i - 1); j++) {
                printf("%d", Fibonaci[j]);
                if (j != 2 * (n - 1) - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}