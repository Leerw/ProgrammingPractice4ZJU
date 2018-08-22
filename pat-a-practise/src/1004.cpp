#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    vector<int> children;
};
vector<node> nodes(100);
int leafs[100];
int maxlevel = 0;

void DFS(int id, int level) {
    if (level > maxlevel) {
        maxlevel = level;
    }
    if (nodes[id].children.size() == 0) {
        leafs[level]++;
        return;
    }
    for (vector<int>::iterator it = nodes[id].children.begin(); it != nodes[id].children.end(); ++it) {
        DFS(*it, level+1);
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int id, k, child;
    for (int i = 0; i < m; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> child;
            nodes[id].children.push_back(child);
        }
    }
    fill(leafs, leafs + 100, 0);
    DFS(1, 0);

    cout << leafs[0];
    for (int i = 1; i <= maxlevel; i++) {
        cout << " " << leafs[i];
    }
    return 0;
}