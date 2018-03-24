#include <stdio.h>

int main() {
    int a[10] = {3, 1, 4 ,5, 2};
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (a[j] > a[j + 1]) {
                a[j] ^= a[j+1];
                a[j+1] ^= a[j];
                a[j] ^= a[j+1];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}