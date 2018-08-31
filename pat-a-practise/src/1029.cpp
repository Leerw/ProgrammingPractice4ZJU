#include <cstdio>
int k[200010];
int main() {
    int n, m, count = 0;
    int temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
    k[n + 1] = (1 << 30) - 1;
    scanf("%d", &m);
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == midpos) printf("%d", k[i]);
            i++;
        }
        count++;
        if (count == midpos) printf("%d", temp);
    }
    while (i <= n) {
        count++;
        if (count == midpos) printf("%d", k[i]);
        i++;
    }
    return 0;
}