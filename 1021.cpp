#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int n, u, v;
bool visit[10010];
vector<vector<int>> G;

void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
}

int main () {
    scanf("%d", &n);
    G.resize(n+1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(visit, visit + 10010, false);
    int cnt = 0;
    visit[1] = true;
    for (int i = 2; i <= n; i++) {
        if (visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt > 1) {
        printf("Error: %d components\n", cnt);
    }
    
}