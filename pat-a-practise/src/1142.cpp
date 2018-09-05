#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];
int main() {
	int nv, ne, m, k, u, v;
	scanf("%d %d", &nv, &ne);
	fill(G[0], G[0] + maxn * maxn, 0);
	for (int i = 0; i < ne; i++) {
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		bool isclique = true;
		bool ismax = true;
		int hash[210];
		fill(hash, hash + 210, 0);
		vector<int> testset(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &testset[j]);
			hash[testset[j]] = 1;
		}
		for (int j = 0; j < k; j++) {
			if (isclique == false) break;
			for (int l = j + 1; l < k; l++) {
				if (G[testset[j]][testset[l]] == 0) {
					isclique = false;
					printf("Not a Clique\n");
					break;
				}
			}
		}
		if (isclique == false) continue;
		for (int j = 1; j <= nv; j++) {
			if (hash[j] == 0) {
				for (int l = 0; l < k; l++) {
					if (G[j][testset[l]] == 0) break;
					if (l == k - 1) ismax = false;
				}
			}
			if (ismax == false) {
				printf("Not Maximal\n");
				break;
			}
		}
		if (ismax == true) printf("Yes\n");
	}
	return 0;
}