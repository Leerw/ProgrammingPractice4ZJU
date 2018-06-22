#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 101;

int f[maxn][maxn];
int dp[maxn][maxn];

int main() {
    int C;
    int N;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        memset(f, 0, sizeof f);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                scanf("%d", &f[i][j]);
            }
        }
        for (int j = 1; j <= N; j++) {
            dp[N][j] = f[N][j];
        }
        for (int i = N - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = f[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        printf("%d\n", dp[1][1]);
    }
    return 0;
}