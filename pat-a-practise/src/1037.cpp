#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int c[maxn], p[maxn];
int np = 0, nc = 0, pc = 0, pp = 0;
long long ans = 0;
int main() {
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }
    sort(c, c + nc, std::greater<int>());
    sort(p, p + np, std::greater<int>());
    while (c[pc] > 0 && p[pp] > 0 && pc < np && pp < np) {
        ans += c[pc++] * p[pp++];
    }
    pc = nc - 1; pp = np - 1;
    while (c[pc] < 0 && p[pp] < 0 && pc < nc && pp < np) {
        ans += c[pc--] * p[pp--];
    }
    if (ans <= 0) {
        printf("0");
    } else {
        printf("%lld", ans);
    }
    return 0;
}