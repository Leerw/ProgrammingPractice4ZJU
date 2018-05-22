#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int N, M, G;
    while (scanf("%d%d%d", &N, &M, &G) == 3 && N) {
        int passline[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &passline[i]);
        }
        char numbers[N][20];
        vector<int> passed;
        int sum[N];
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < N; i++) {
            int m;
            scanf("%s%d", numbers[i], &m);
            for (int j = 0; j < m; j++) {
                int temp = 0;
                scanf("%d", &temp);
                sum[i] += passline[temp - 1];
            }
            if (sum[i] >= G) {
                passed.push_back(i);
            }
        }
        printf("%d\n", (int)passed.size());
        for (int i = 0; i < (int)passed.size(); i++) {
            printf("%s %d\n", numbers[passed[i]], sum[passed[i]]);
        }
    }
    return 0;
}