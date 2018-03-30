#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int N = 0;
    scanf("%d", &N);
    int ADrunk = 0;
    int BDrunk = 0;
    int A1 = 0, A2 = 0, B1 = 0, B2 = 0;
    while (N--) {
        scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
        if (A2 == B2) {
            continue;
        }
        if (A2 == A1 + B1) {
            BDrunk += 1;
        } else if (B2 == A1 + B1) {
            ADrunk += 1;
        }
    }
    printf("%d %d", ADrunk, BDrunk);
    return 0;
}