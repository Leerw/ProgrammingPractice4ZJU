#include <cstdio>
using namespace std;

int n, m, count;

void dfs(int i) {
    if (i <= n) {
        count++;
        dfs(i*2);
        dfs(i*2+1);
    }
}

int main () {
    while (scanf("%d %d", &m, &n) && n && m) {
        count = 0;
        dfs(m);
        printf("%d\n", count);
    }
    return 0;
}