#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int hashtable[maxn] = { 0 };
int main() {
    int n, temp;
    fill(hashtable, hashtable + maxn, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp > 0 && temp < maxn) {
            hashtable[temp]++;
        }
    }
    
    for (int i = 1; i < __INT_MAX__; i++) {
        if (hashtable[i] == 0) {
            printf("%d", i);
            return 0;
        }    
    }
}