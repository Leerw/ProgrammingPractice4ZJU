#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<string> segs;

int main() {
    cin >> n;
    segs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i];
    }
    sort(segs.begin(), segs.end(), [](string a, string b) {
        return a + b < b + a;
    });
    string s;
    for (int i = 0; i < segs.size(); i++) {
        s += segs[i];
    }
    int i = 0;
    while (s[i] == '0') { i++; }
    if (i == s.length()) {
        cout << 0;
    } else {
        while (i < s.length()) {
            printf("%c", s[i++]);
        }
    }
    return 0;
}