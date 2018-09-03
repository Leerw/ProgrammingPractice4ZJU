#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int m, n, k, temp, push_index;
    stack<int> s;
    scanf("%d %d %d", &m, &n, &k);
    while (k--) {
        push_index = 1;
        bool flag = true;
        while (!s.empty()) s.pop();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            while (s.empty() || s.top() < temp) {
                if (s.size() < m) {
                    s.push(push_index++);
                } else {
                    flag = false;
                    break;
                }
            }
            if (s.top() == temp) {
                s.pop();
            }
        }
        if (flag && s.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
