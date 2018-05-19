#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    while (cin >> num) {
        int length = num.size();
        int n[length];
        for (int i = 0; i < length; i++) {
            n[i] = num[i] - '0';
        }
        int carry, count = 0, j = 0;
        char ans[200];
        while (j < length) {
            ans[count++] = n[length - 1] % 2 + '0';
            // 模拟除法
            for (int i = j, carry = 0; i < length; i++) {
                int sum = (carry * 10 + n[i]) / 2;
                carry = n[i] % 2;
                n[i] = sum;
            }
            if (n[j] == 0)
                j++;
        }
        for (int i = count - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
    return 0;
}