#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, u, v;
bool visit[10010];
vector<vector<int> > G;

int maxheight = 0;
vector<int> temp;
set<int> s;

void dfs(int node, int height) {
    visit[node] = true;
    if (height > maxheight) {
        maxheight = height;
        temp.clear();
        temp.push_back(node);
    } else if (height == maxheight) {
        temp.push_back(node);
    }
    for (int i = 0; i < G[node].size(); i++) {
        if (visit[G[node][i]] == false) {
            dfs(G[node][i], height + 1);
        }
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
    int cnt = 0, s1 = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0) {
                    s1 = temp[0];
                }
                for (int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }
    if (cnt > 1) {
        printf("Error: %d components\n", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for (int i = 0; i < temp.size(); i++) {
            s.insert(temp[i]);
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            printf("%d\n", *it);
        }
    }
    return 0;
}