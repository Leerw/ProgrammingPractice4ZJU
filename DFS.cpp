const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u, int depth) {
    vis[u] = true;
    for (int v = 0; v < n; v++) {
        if (vis[v] == false && G[u][v] != INF) {
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (vis[u] == false) {
            DFS(u, 1);
        }
    }
}

vector<int> Adj[MAXV];
int n;
bool vis[MAXV] = {false};

void DFS(int u, int depth) {
    vis[u] = true;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (vis[i] == false) {
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (vis[u] == false) {
            DFS(u, 1);
        }
    }
}
