#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100010;
string s;
int countP[maxn] = {0};
int countPA[maxn] = {0};
long long count = 0;

void P() {
    for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == 'P') {
            countP[i] = countP[i-1] + 1;
        } else {
            countP[i] = countP[i-1];
        }
    }
}

void PA() {
    for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == 'A') {
            countPA[i] = countPA[i-1] + countP[i];
        } else {
            countPA[i] = countPA[i-1];
        }
    }
}

int main() {
    memset(countP, maxn, 0);
    memset(countPA, maxn, 0);
    cin >> s;
    P();
    PA();
    int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            count += countPA[i+1];
        }
    }
    printf("%lld\n", count % 1000000007);
    return 0;
}