/**
 * int kruskal() {
 *      令最小生成树的边权之和为ans，最小生成树的当前边数为Num_Edge
 *      讲所有边按边权从小到大排序
 *      for (从小到大枚举所有边) {
 *          if (当前测试边的两个顶点在不同的连通块中) {
 *              将该测试边加入到最小生成树中
 *              ans += 测试边的边权
 *              最小生成树的当前边数加一
 *              当前边数等于顶点数时结束循环
 *          }
 *      }
 *      return ans;
 * }
 **/

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 110;
const int MAXE = 10010;
int n, m;
struct edge {
    int u, v;
    int cost;
}E[MAXE];
bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

int father[MAXV];
int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int kruskal() {
    int ans = 0, Num_Edge = 0;
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for (int i = 0; i < m; i++) {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV) {
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++;
            if (Num_Edge == n - 1) break;
        }
    }
    if (Num_Edge != n - 1) return -1;
    else return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].cost);
    }
    int ans = kruskal();
    printf("%d\n", ans);
    return 0;
}