#include <cstdio>
using namespace std;
const int MAX_N = 1010;
inline int max(int a, int b) {return a>b?a:b;}
int dp1[MAX_N][MAX_N], dp2[MAX_N][MAX_N], dp3[MAX_N][MAX_N], dp4[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp2[i][j] = a[i][j] + max(dp2[i][j+1], dp2[i+1][j]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i][j-1], dp3[i+1][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
    int ans = 0;
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j) {
            ans = max(ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]); // 对应情况1)
            ans = max(ans, dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]); // 对应情况2)
        }
    printf("%d\n", ans);
    return 0;
}