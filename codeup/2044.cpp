#include <cstdio>
using namespace std;

int P[21] = {0};

int pick(int num, int n) {
    if (num == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    return pick(num, n - 1) + pick(num - P[n], n - 1);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &P[i]);
        }
        printf("%d\n", pick(40, n));
    }
    return 0;
}