#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

queue<string> q;

void splitStr(string s) {
    string temp;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while (i < s.size() && s[i] != ' ') {
            i++;
        }
        if (j != i) {
            temp = s.substr(j, i - j);
            q.push(temp);
            i = i - 1;
        }
    }
}

int main() {
    string s, a, b;
    while (getline(cin, s)) {
        getline(cin, a);
        getline(cin, b);
        splitStr(s);
        while (!q.empty()) {
            if (q.front() == a) {
                cout << b;
                q.pop();
            } else {
                cout << q.front();
                q.pop();
            }
            if (! q.empty()) {
                printf(" ");
            }
        }
        printf("\n");
    }
}