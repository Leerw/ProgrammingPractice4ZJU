#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool flag = false;
int n, m, k;
int main() {
    scanf("%d%d", &n, &m);
    vector<int> G[n + 1];
    int inDegree[n + 1];
    fill(inDegree, inDegree + n + 1, 0);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        inDegree[v]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int judge = 1;
        vector<int> in(inDegree, inDegree + n + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &u);
            if (in[u] != 0) judge = 0;
            for (int it : G[u]) in[it]--;
        }
        if (judge == 1) continue;
        printf("%s%d", flag == false ? "" : " ", i);
        flag = true;
    }
    return 0;
}