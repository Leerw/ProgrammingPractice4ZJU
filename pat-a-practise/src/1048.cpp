#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n, m, temp;
int hashtable[maxn];

int main() {
    fill(hashtable, hashtable + maxn, 0);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        hashtable[temp]++;
    }
    for (int i = 0; i < maxn; i++) {
        if (hashtable[i]) {
            hashtable[i]--;
            if (m > i && hashtable[m - i]) {
                printf("%d %d", i, m - i);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}