#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int n, m, l;
int color[maxn], dp[maxn];
int fav_index[maxn];

int main() {
    int temp, num = 0;
    scanf("%d%d", &n, &m);
    fill(fav_index, fav_index + maxn, -1);    
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        fav_index[temp] = i;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &temp);
        if (fav_index[temp] >= 0) {
            color[num++] = temp;
        }
    }
    int ans = 0;
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (fav_index[color[j]] <= fav_index[color[i]] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(dp[i], ans);
    }
    printf("%d", ans);
    return 0;
}