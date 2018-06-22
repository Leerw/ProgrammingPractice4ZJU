#include <cstdio>
#include <cstring>

const int maxn = 55;
int dp[maxn];

int ans(int n) {
    if (n <= 4) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = ans(n-1) + ans(n-3);
}

int main(int argc, char const *argv[])
{
    int n;
    memset(dp, 0, sizeof dp);
    while (scanf("%d", &n) == 1 && n != 0) {
        printf("%d\n", ans(n));
    }
    return 0;
}
