/**
 * 1. 定义一个队列Q，并把所有入度为0的结点加入队列
 * 2. 取队首结点，输出。然后删去所有从它出发的边，并令这些边到达的顶点的入度减一，如果某个顶点的入度减为0，则将其加入队列
 * 3. 反复执行2，直到队列为空。如果队列为空时入过队的结点数目恰好为N，说明拓扑排序成功，图G为有向无环图；否则，拓扑排序失败，图G中有环。
 * 可使用领接表实现拓扑排序，显然，由于需要记录结点的入度，因此需要额外建立一个数组inDegree[MAXV]，并在程序开始读入图时就记录好每个结点的入度
 **/

#include <vector>
#include <queue>
using namespace std;
const int MAXV = 10010;
vector<int> G[MAXV];
int n, m, inDegree[MAXV];
bool topologicalSort() {
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
        G[u].clear();
        num++;
    }
    if (num == n) return true;
    else return false;
}

