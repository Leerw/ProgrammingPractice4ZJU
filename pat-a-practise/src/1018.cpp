#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int maxn = 510;
const int INF = 0x3fffffff;
int cmax, n, sp, m, si, sj, t;
int c[maxn];
int G[maxn][maxn];

bool vis[maxn];
int d[maxn];
vector<int> pre[maxn];

void Dijkstra() {
    fill(d, d + maxn, INF);
    d[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int minSend = INF;
int minBack = INF;
vector<int> path, tempPath;
void DFS(int v) {
    if (0 == v) {
        tempPath.push_back(v);
        int in = 0;
        int out = 0;
        for (int i = tempPath.size() - 2; i >= 0; i--) {
            if (c[tempPath[i]] > cmax / 2) {
                out += c[tempPath[i]] - cmax / 2;
            } else {
                if (out + c[tempPath[i]] >= cmax / 2) {
                    out = out + c[tempPath[i]] - cmax / 2;
                } else {
                    in += cmax / 2 - out - c[tempPath[i]];
                    out = 0;
                }
            }
        }
        if (in < minSend) {
            minSend = in;
            minBack = out;
            path = tempPath;
        } else if (in == minSend && out < minBack) {
            minBack = out;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}


int main() {
    fill(c, c + maxn, 0);
    fill(vis, vis + maxn, 0);
    fill(G[0], G[0] + maxn * maxn, INF);
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &si, &sj, &t);
        G[si][sj] = t;
        G[sj][si] = t;
    }
    Dijkstra();
    DFS(sp);
    printf("%d ", minSend);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i == 0) {
            printf(" ");
        } else {
            printf("->");
        }
    }
    printf("%d", minBack);
    return 0;
}
