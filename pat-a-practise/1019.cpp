#include <cstdio>
#include <string.h>

long long numbers[100];

int toDecimal(long long n, long long base) {
    memset(numbers, 0, sizeof numbers);
    int index = 0;
    do {
        numbers[index++] = n % base;
        n = n / base;
    } while (n != 0);
    return index;
}



int main() {
    bool isTrue = true;
    long long n, base;
    scanf("%lld %lld", &n, &base);
    int index = toDecimal(n, base);
    for (int left = 0, right = index - 1; left < right; left++, right--) {
        if (numbers[left] != numbers[right]) {
            isTrue = false;
            break;
        }
    }
    if (isTrue) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", numbers[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    return 0;
}
