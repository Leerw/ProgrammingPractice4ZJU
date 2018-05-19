#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
    return x < y;
}

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        int array[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &array[i]);
        }
        if (m == 1) {
            printf("%d\n-1", array[0]);
        } else {
            sort(array, &array[m], cmp);
            int max = array[m - 1];
            printf("%d\n", max);
            /*
            int count = 1;
            for (int i = m - 2; i >= 0; i--) {
                if (array[i] == max) {
                    count = count + 1;
                } else {
                    break;
                }
            }
            for (int i = 0; i < m - count; i++) {
                printf("%d", array[i]);
                if (i != m - count - 1) {
                    printf(" ");
                }
            }
            */
            for (int i = 0; i < m - 1; i++) {
                printf("%d", array[i]);
                if (i != m - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
