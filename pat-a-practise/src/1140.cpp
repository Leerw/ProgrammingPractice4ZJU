#include <iostream>
#include <string>
using namespace std;
int d, n;
int main() {
    cin >> d >> n;
    n--;
    string s = std::to_string(d);
    while (n--) {
        string ans;
        int i = 0, j, cnt = 0;
        char c;
        while (i < s.length()) {
            c = s[i];
            ans += c;
            j = i;
            while (s[i] == s[i + 1] && i + 1 < s.length()) { i++; }
            int len = i - j + 1;
            ans += std::to_string(len);
            i++;
        }
        s = ans;
    }
    s.replace(0, 1, std::to_string(d));
    cout << s;
    return 0;
}