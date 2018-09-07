#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };
int prim() {
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0;
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
        ans += d[u];
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

struct Node {
    int v, dis;
};
vector<Node> Adj[MAXV];
int n, d[MAXV];
bool vis[MAXV] = { false };
int Prim() {
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0;
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
        ans += d[u];
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis[v] == false && Adj[u][j].dis < d[v]) {
                d[v] = Adj[u][j].dis;
            }
        }
    }
    return ans;
}