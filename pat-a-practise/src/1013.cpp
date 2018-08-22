#include <cstdio>
#include <algorithm>

using namespace std;

int n;

bool visit[1010];
int G[1010][1010];

void dfs(int node) {
  visit[node] = true;
  for (int i = 1; i <= n; i++) {
    if (visit[i] == false && G[node][i] == 1) {
      dfs(i);
    }
  }
}

int main() {
  int m, k;
  scanf("%d%d%d", &n, &m, &k);
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    G[u][v] = 1;
    G[v][u] = 1;
  }
  int count;
  for (int i = 0; i < k; i++) {
    fill(visit, visit+1010, false);
    count = 0;
    scanf("%d", &u);
    visit[u] = true;
    for (int j = 1; j <= n; j++) {
      if (visit[j] == false) {
        dfs(j);
        count++;
      }
    }
    printf("%d\n", count - 1);
  }
  return 0;
}