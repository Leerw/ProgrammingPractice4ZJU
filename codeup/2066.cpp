#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        int n, max = 0, maxnum = ~0x0;
        int numbers[n];
        int groups[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
            if (numbers[i] > maxnum) {
                maxnum = numbers[i];
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &groups[i]);
            if (groups[i] > max) {
                max = groups[i];
            }
        }
        int matrix[max + 1][maxnum + 1];
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < n; i++) {
            matrix[groups[i]][numbers[i]] += 1;
        }
        sort(groups, groups + n);
        int before = groups[0];
        for (int i = 0; i < n; i++) {
            
        }
    }
}