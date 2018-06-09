#include <cstdio>
#include <cstring>
int main() {
    int n;
    int hash[10010];
    while (scanf("%d", &n) != EOF) {
        int arr[n];
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            hash[arr[i]] += 1;
        }
        int i = 0;
        for (i = 0; i < n; i++) {
            if (hash[arr[i]] == 1) {
                printf("%d\n", arr[i]);
                break;
            }
        }
        if (i == n) {
            printf("None\n");
        }
    }
    return 0;
}