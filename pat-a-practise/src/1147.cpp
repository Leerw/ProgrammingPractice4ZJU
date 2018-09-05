#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void postOrder(int index) {
    if (index >= n) return;
    postOrder(index * 2 + 1);
    postOrder(index * 2 + 2);
    printf("%d%s", v[index], index == 0 ? "\n" : " ");
}
int main() {
    scanf("%d %d", &m, &n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        int flag = v[0] > v[1] ? 1 : -1;
        for (int index = 0; index <= (n - 1) / 2; index++) {
            int left = index * 2 + 1, right = index * 2 + 2;
            if (flag == 1 && (v[index] < v[left] || (right < n && v[index] < v[right]))) {
                flag = 0; break;
            }
            if (flag == -1 && (v[index] > v[left] || (right < n && v[index] > v[right]))) {
                flag = 0; break;
            }
        }
        if (flag == 0) {
            printf("Not Heap\n");
        } else if (flag == 1) {
            printf("Max Heap\n");
        } else {
            printf("Min Heap\n");
        }
        postOrder(0);
    }
    return 0;
}