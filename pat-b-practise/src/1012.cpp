#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    bool Aexists[5] = {0};
    int N = 0;
    int flag = 1;
    scanf("%d", &N);
    int A1 = 0, A2 = 0, A3 = 0, A4temp = 0, A5 = 0;
    int A4counter = 0;
    double A4 = 0.0;
    for (int i = 0; i != N; i++) {
        int temp = 0;
        scanf("%d", &temp);
        if (temp % 10 == 0) {
            A1 += temp;
            Aexists[0] = 1;
        }
        if (temp % 5 == 1) {
            A2 += temp * flag;
            flag = -flag;
            Aexists[1] = 1;
        }
        if (temp % 5 == 2) {
            A3 += 1;
            Aexists[2] = 1;            
        }
        if (temp % 5 == 3) {
            A4temp += temp;
            A4counter += 1;
            Aexists[3] = 1;                        
        }
        if (temp % 5 == 4 && temp > A5) {
            A5 = temp;
            Aexists[4] = 1;
        }
    }
    if (A4counter) {
        A4 = (double)A4temp / A4counter;
    }
    if (Aexists[0] == 0) {
        printf("N ");
    } else {
        printf("%d ", A1);
    }
    if (Aexists[1] == 0) {
        printf("N ");
    } else {
        printf("%d ", A2);
    }
    if (Aexists[2] == 0) {
        printf("N ");
    } else {
        printf("%d ", A3);
    }
    if (Aexists[3] == 0) {
        printf("N ");
    } else {
        printf("%.1f ", A4);
    }
    if (Aexists[4] == 0) {
        printf("N");
    } else {
        printf("%d", A5);
    }
    return 0;
}