#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int ans[110];

string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void myAdd(int adder) {
    for (int i = 109; i > 0; i--) {
        int temp;
        temp = (adder + ans[i]) % 10;
        adder = (adder + ans[i]) / 10;
        ans[i] = temp;
    }
}

int main() {
    string N;
    cin >> N;
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < N.length(); i++) {
        myAdd((int) (N[i] - '0'));
    }
    int counter = 0;
    while (counter < 110 && ans[counter] == 0) {
        counter = counter + 1;
    }
    for (int i = counter; i < 109; i++) {
        cout << numbers[ans[i]] << " ";
    }
    cout << numbers[ans[109]];
    return 0;
}