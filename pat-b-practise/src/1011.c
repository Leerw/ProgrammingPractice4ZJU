#include <stdio.h>

int main() {
    long a = 0, b = 0;
    int T = 0;
    int counter = 0;
    long long c = 0;
    scanf("%d", &T);
    while (T--) {
        counter += 1;
        scanf("%ld%ld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", counter, a + b > c ? "true" : "false");
    }
    return 0;
}