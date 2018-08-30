#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 110;

int n[maxn];
int r[maxn];
int bakn[maxn];

void add() {
    int out = 0;
    for (int i = 0; i < maxn; i++) {
        n[i] = (r[i] + bakn[i] + out) % 10;
        out = (r[i] + bakn[i] + out) / 10;
    }
    for (int i = 0; i < maxn; i++) {
        bakn[i] = n[i];
    }
}

bool ispalindromic() {
    int cnt = maxn - 1;
    while (n[cnt] == 0) {
        cnt--;
    }
    for (int i = 0, j = cnt; i <= cnt / 2; i++, j--) {
        if (n[i] != n[j]) return false;
    }
    return true;
}

void print() {
    int i = maxn - 1;
    while (n[i] == 0) {
        i--;
    }
    while (i >= 0) {
        printf("%d", n[i--]);
    }
}

void reverse() {
    int cnt = maxn - 1;
    while (n[cnt] == 0) {
        cnt--;
    }
    for (int i = 0; i <= cnt; i++) {
        r[i] = n[cnt - i];
    }
}

int main() {
    int k;
    long long temp;
    cin >> temp >> k;
    if (temp < 10) {
        cout << temp << endl << 0;
        return 0;
    }
    int x, cnt = 0;
    do {
        x = temp % 10;
        temp = temp / 10;
        n[cnt] = x;
        bakn[cnt] = x;
        cnt++;
    } while (temp);
    for (int i = 0; i <= cnt; i++) {
        r[i] = n[cnt - 1 - i];
    }
    if (ispalindromic()) {
        print();
        cout << endl << 0;
        return 0;
    }
    int step = 1;
    while (step <= k) {
        add();
        if (ispalindromic()) {
            print();
            cout << endl << step;
            return 0;
        }
        reverse();
        step++;
    }
    print();
    cout << endl << k;
    return 0;
}