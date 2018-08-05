#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int indexes[12];
int numbers[25];
int doubledNumbers[25];
int doubledIndexes[12];

int main() {
    string input;
    cin >> input;
    memset(indexes, 0, sizeof indexes);
    memset(doubledIndexes, 0, sizeof doubledIndexes);
    int i;
    for (i = 0; i < input.size(); i++) {
        indexes[input[i] - '0']++;
        numbers[i + 1] = input[i] - '0';
    }
    int Cin = 0;
    for (; i > 0; i--) {
        doubledNumbers[i] = (numbers[i] * 2 + Cin) % 10;
        Cin = (numbers[i] * 2 + Cin) / 10;
        doubledIndexes[doubledNumbers[i]]++;
    }
    doubledNumbers[i] = Cin;
    if (Cin != 0)
        doubledIndexes[doubledNumbers[i]]++;
    bool flag = true;
    int j;
    for (j = 0; j < 12; j++) {
        if (indexes[j] != doubledIndexes[j]) {
            flag = false;
        }
    }
    if (flag == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    if (doubledNumbers[0] != 0) {
        cout << doubledNumbers[0];
    }
    for (j = 1; j <= input.size(); j++) {
        cout << doubledNumbers[j];
    }
    return 0;
}
