/* 最长不下降子序列 LIS */
/*****************************************************************
一个数列ai如果满足条件a1 < a2 < ... < aN，那么它是一个有序的上升数列。我们取
数列(a1, a2, ..., aN)的任一子序列(ai1, ai2, ..., aiK)使得1 <= i1 < i2 
< ... < iK <= N。例如，数列(1, 7, 3, 5, 9, 4, 8)的有序上升子序列，像(1, 
7)， (3, 4, 8)和许多其他的子序列。在所有的子序列中，最长的上升子序列的长度是4
，如(1, 3, 5, 8)。
*****************************************************************/


#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;
int A[N], dp[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}