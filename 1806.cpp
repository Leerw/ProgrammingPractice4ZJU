#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < str.size(); i++) {
            if (i == 0) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = str[i] - 32;
                } 
            }
            int flag = 0;
            while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n') {
                i = i + 1;
                flag = 1;
            }
            if (flag) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = str[i] - 32;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}