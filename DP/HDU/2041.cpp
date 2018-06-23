#include <cstdio>
#include <cstring>

const int maxn = 40;
long long dp[maxn];

long long ans(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = ans(n-1) + ans(n-2);
}

int main() {
    int N;
    scanf("%d", &N);
    memset(dp, 0, sizeof dp);
    while (N--) {
        int M;
        scanf("%d", &M);
        printf("%lld\n", ans(M));
    }
    return 0;
}