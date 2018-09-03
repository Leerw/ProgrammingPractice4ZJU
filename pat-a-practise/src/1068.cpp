#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

const int maxn = 10010, maxv = 110;
int n, m;
bool choose[maxn][maxv];
int dp[maxn], w[maxn];

int main() {
    fill(choose[0], choose[0] + maxn * maxv, false);
    scanf("%d %d", &n, &m);
    int temp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (temp > m) {
            i--;
            n--;
            continue;
        }
        w[i] = temp;
    }
    sort(w + 1, w + 1 + n, std::greater<int>());
    for (int i = 1; i <= n; i++) {
        for (int v = m; v >= w[i]; v--) {
            if (dp[v] <= dp[v - w[i]] + w[i]) {
                dp[v] = dp[v - w[i]] + w[i];
                choose[i][v] = true;
            }
        }
    }
    if (dp[m] != m) {
        printf("No Solution\n");
        return 0;
    }
    int v = m, index = n;
    while (v > 0) {
        if (choose[index][v] == true) {
            if (v != m) {
                printf(" ");
            }
            printf("%d", w[index]);
            v -= w[index];
        }
        index--;
    }
    return 0;
}