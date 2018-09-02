#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int ans = 1;
string s;
int dp[maxn][maxn];
int main() {
    getline(cin, s);
    fill(dp[0], dp[0] + maxn * maxn, 0);
    for (int i = 0; i < s.length(); i++) {
        dp[i][i] = 1;
        if (i < s.length() - 1) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for (int L = 3; L <= s.length(); L++) {
        for (int i = 0; i + L - 1 < s.length(); i++) {
            int j = i + L - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans;
    return 0;
}