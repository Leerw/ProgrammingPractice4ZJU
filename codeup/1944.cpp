#include <cstdio>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int ans[100], num  = 0;
        do {
            ans[num++] = n % 8;
            n = n / 8;
        } while (n != 0);
        for (int i = num - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}