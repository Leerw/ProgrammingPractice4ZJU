#include <cstdio>
#include <cstring>

char s1[10010];
char s2[10010];
int statistic[1000];

int main() {
    while (fgets(s1, 10010, stdin) != NULL) {
        fgets(s2, 10010, stdin);
        // 把s2散列化
        for (int i = 0; i < sizeof(s2); ++i) {
            statistic[s2[i]]++;
        }
        for (int i = 0; i < sizeof(s1); ++i) {
            if (statistic[s1[i]] == 0) {
                printf("%c", s1[i]);
            }
        }
        printf("\n");
        memset(statistic, 0, sizeof(statistic));
    }
    return 0;
}