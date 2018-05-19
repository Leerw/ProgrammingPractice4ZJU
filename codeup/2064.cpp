#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

stack<string> stk;
stack<string> temp;

void print() {
    int count = 1;
    temp = stk;    
    while (!stk.empty() && count <= 4) {
        printf("%d=", count);
        cout << stk.top();
        count = count + 1;
        stk.pop();
        if (! stk.empty()) {
            printf(" ");
        }
    }
    printf("\n");
    stk = temp;
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        stk.push(str);
        print();
    }
    return 0;
}