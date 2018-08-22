#include <cstdio>
#include <map>
using namespace std;
int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    int pixel;
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &pixel);
            if (ans.count(pixel) <= 0) {
                ans[pixel] = 1;
            } else {
                ans[pixel] += 1;
            }
        }
    }
    int max = 0;
    int index = 0;
    for (map<int, int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        if (it->second > max) {
            max = it->second;
            index = it->first;
        }
    }
    printf("%d", index);
    return 0;
}