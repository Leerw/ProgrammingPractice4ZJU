#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int m;
    while (scanf("%d", &m) == 1) {
        int matrix[m][m];
        int sum[2 * m + 2];
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
                sum[i] += matrix[i][j];
                sum[m + j] += matrix[i][j];
                if (i == j) {
                    sum[2 * m] += matrix[i][j];
                }
                if (i + j == m - 1) {
                    sum[2 * m + 1] += matrix[i][j];
                }
            }
        }
        sort(sum, sum + 2 * m + 2, std::greater<int>());
        for (int i = 0; i < 2 * m + 2; i++) {
            printf("%d", sum[i]);
            if (i != 2 * m + 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}