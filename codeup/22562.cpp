#include <cstdio>
#include <cstring>
#include <iostream>
const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];

int main() {
    std::cin >> S;
    int len = strlen(S), cur_len = 1;
    memset(dp, 0, sizeof(dp));
    // 边界
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if (i < len - 1) {
            if (S[i] == S[i + 1]) {
                dp[i][i + 1] = 1;
                cur_len = 2;
            }
        }
    }
    // 状态转移方程
    for (int L = 3; L <= len; L++) {
        for (int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;
            if (S[i] == S[j] && S[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                cur_len = L;
            }
        }
    }
    printf("%d\n", cur_len);
    return 0;
}