#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[10];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9]) {
        int odd[10];
        int even[10];
        int p1 = 0, p2 = 0;
        for (int i = 0; i < 10; i++) {
            if (a[i] % 2 == 0) {
                odd[p1++] = a[i];
            } else {
                even[p2++] = a[i];
            }
        }
        sort(odd, odd + p1);
        sort(even, even + p2, std::greater<int>());
        for (int i = 0; i < p2; i++) {
            printf("%d ", even[i]);
        }
        for (int i = 0; i < p1; i++) {
            printf("%d", odd[i]);
            if (i < p1 - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}