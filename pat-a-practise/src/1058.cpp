#include <cstdio>
using namespace std;
int main() {
    int a1, a2, a3, b1, b2, b3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    a3 += b3;
    a2 += a3 / 29;
    a3 %= 29;
    a2 += b2;
    a1 += a2 / 17;
    a2 %= 17;
    a1 += b1;
    printf("%d.%d.%d", a1, a2, a3);
    return 0;
}