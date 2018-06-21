/* 最长公共子序列 */

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    while (cin >> A >> B) {
        int lenA = A.length();
        int lenB = B.length();
        int dp[lenA + 1][lenB + 1];
        for (int i = 0; i <= lenA; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= lenB; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if (A.at(i - 1) == B.at(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[lenA][lenB]);
    }
    return 0;
}