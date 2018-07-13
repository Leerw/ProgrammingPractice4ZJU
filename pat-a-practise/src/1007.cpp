#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    int leftIndex = 0, rightIndex = N - 1, sum = -1, temp = 0, tempIndex = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempIndex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftIndex = tempIndex;
            rightIndex = i;
        }
    }
    if (sum < 0) { sum = 0; }
    cout << sum << " " << v[leftIndex] << " " << v[rightIndex];
    return 0;
}