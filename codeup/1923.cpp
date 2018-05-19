#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b ? 1 : 0;
}

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        int array[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &array[i]);
        }
        sort(array, &array[m], cmp);
        for (int i = 0; i < m; i++) {
            printf("%d", array[i]);
            if (i < m - 1)
                printf(" ");
        }
        printf("\n");        
    }
}