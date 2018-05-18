#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    char str[2][120];
    while (scanf("%s%s", str[0], str[1]) == 2) {
        char newStr[300];
        int count = 0;
        int i = 0;
        while (str[0][i] != '\0') {
            newStr[count++] = str[0][i++];
        }
        i = 0;
        while (str[1][i] != '\0') {
            newStr[count++] = str[1][i++];
        }
        for (i = 0; i < count; i++) {
            printf("%c", newStr[i]);
        }
        printf("\n");
    }
    return 0;
}