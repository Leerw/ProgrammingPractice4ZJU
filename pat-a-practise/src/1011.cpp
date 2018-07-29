#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    char c[3] = {'W', 'T', 'L'};
    int i, j, index;
    double temp = 0.0, result = 1, odds[3][3];
    for (i = 0; i < 3; i++) {
        temp = 0.0;
        index = 0;
        for (j = 0; j <3; j++) {
            cin >> odds[i][j];
            if (odds[i][j] > temp) {
                temp = odds[i][j];
                index = j;
            }
        }
        result = result * temp;
        cout << c[index] << " ";
    }
    result = 2 * (result * 0.65 - 1);
    cout << fixed <<setprecision(2) <<result << endl;
    return 0;
}
