#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct mice {
    int weight;
    string hat;
};

bool cmp(mice m1, mice m2) {
    return m1.weight > m2.weight;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        vector<mice> m;
        for (int i = 0; i < N; i++) {
            mice temp;
            cin >> temp.weight >> temp.hat;
            m.push_back(temp);
        }
        sort(m.begin(), m.end());
        for (vector<mice>::iterator iter = m.begin(); iter != m.end(); iter++) {
            cout << iter->hat << endl;
        }
    }
    return 0;
}