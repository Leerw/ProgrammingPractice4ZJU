#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int n, m, st, ed;
bool vis[maxn] = {false};
int d[maxn], c[maxn], pre[maxn];
int G[maxn][maxn], cost[maxn][maxn];

void Dijsktra(int s) {
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == st) {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    int u, v, dis, cos;
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &u, &v, &dis, &cos);
        G[u][v] = G[v][u] = dis;
        cost[u][v] = cost[v][u] = cos;
    }
    Dijsktra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}