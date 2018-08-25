#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
bool visit[maxn];
int n, k, maxlevel = 1;
int level[maxn];
int G[maxn][maxn];

void DFS(int node, int lev) {
    visit[node] = true;
    level[lev] += 1;
    if (level[lev] > level[maxlevel]) {
        maxlevel = lev;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && G[node][i] == 1) {
            DFS(i, lev + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    fill(visit, visit + maxn, false);
    memset(level, maxn, 0);
    memset(G, maxn * maxn, 0);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int father, nchild, child;
        scanf("%d %d", &father, &nchild);
        for (int i = 0; i < nchild; i++) {
            scanf("%d", &child);
            G[father][child] = 1;
        }
    }
    DFS(1, 1);
    printf("%d %d\n", level[maxlevel], maxlevel);
    return 0;
}
