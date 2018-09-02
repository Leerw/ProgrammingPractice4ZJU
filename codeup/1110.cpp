#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 30010;
int t, n, temp, i, j, Case = 1;
char cmd[10];
int block[maxn];
int main() {
    scanf("%d", &t);
    while (t--) {
        memset(block, 0, sizeof(block));
        printf("%d\n" ,Case++);
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &temp);
            block[i] += temp;
        }
        while (1) {
            scanf("%s", cmd);
            if (strcmp(cmd, "End")) {
                break;
            }
            if (strcmp(cmd, "Add")) {
                scanf("%d %d", &i, &j); 
                block[i] += j;
            } else if (strcmp(cmd, "Sub")) {
                scanf("%d %d", &i, &j);
                block[i] -= j;
            } else if (strcmp(cmd, "Query")) {
                scanf("%d %d", &i, &j);
                int sum = 0;
                while (i <= j) {
                    sum += block[i++];
                }
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}