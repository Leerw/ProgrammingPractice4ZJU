#include <cstdio>
#include <cstring>

const int maxn = 51;
long long dp[maxn];// 注意如果用int的话会上溢出,在我的机器上long是32位，但是在OJ上是16位，所以用long long


int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    memset(dp, 0, sizeof dp);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < maxn; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    while (N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", dp[1+b-a]);
    }
    return 0;
}
