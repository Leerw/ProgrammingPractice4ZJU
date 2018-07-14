#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main() {
    map<int, double> a;
    map<int, double> b;
    map<int, double> ans;
    int N;
    int exp;
    double coeff;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> exp >> coeff;
        if (coeff == 0) { continue; }
        a.insert(make_pair(exp, coeff));
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> exp >> coeff;
        if (coeff == 0) { continue; }
        b.insert(make_pair(exp, coeff));
    }

    for (auto ita = a.begin(); ita != a.end(); ita++) {
        for (auto itb = b.begin(); itb != b.end(); itb++) {
            exp = ita->first + itb->first;
            coeff = ita->second * itb->second;
            auto temp = ans.find(exp);
            if (temp != ans.end()) {
                coeff += temp->second;
                ans.erase(exp);
                if (coeff == 0) { continue; }
                ans.insert(make_pair(exp, coeff));
            } else {
                if (coeff == 0) { continue; }
                ans.insert(make_pair(exp, coeff));
            }
        }
    }

    cout << ans.size();
    int i = 0;
    for (auto it = ans.rbegin(); it != ans.rend() && fabs(it->second) != 0; it++, i++) {
        printf(" %d %.1lf", it->first, it->second);
    }

    return 0;
}