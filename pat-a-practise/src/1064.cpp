#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> in, level;

void leveltrave(int start, int end, int index) {
    if (start > end) return;
    int n = end - start + 1;
    int l = log(n + 1) / log(2);
    int leave = n - pow(2, l) + 1;
    int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave);
    level[index] = in[root];
    leveltrave(start, root - 1, 2 * index + 1);
    leveltrave(root + 1, end, 2 * index + 2);
}

int main() {
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in.begin(), in.end());
    leveltrave(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        printf("%d", level[i]);
        if (i != n - 1) printf(" ");
    }
    return 0;
}