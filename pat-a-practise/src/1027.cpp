#include <cstdio>

void toBase13(char& digit1, char& digit2, int decimal) {
    digit2 = decimal % 13;
    decimal = decimal / 13;
    digit1 = decimal % 13;
    digit2 = (digit2 > 9) ? digit2 - 10 + 'A' : digit2 + '0';
    digit1 = (digit1 > 9) ? digit1 - 10 + 'A' : digit1 + '0';
}

int main() {
    int R, G, B;
    scanf("%d%d%d", &R, &G, &B);
    printf("#");
    char d1, d2;
    toBase13(d1, d2, R);
    printf("%c%c", d1, d2);
    toBase13(d1, d2, G);
    printf("%c%c", d1, d2);
    toBase13(d1, d2, B);
    printf("%c%c", d1, d2);
    return 0;
}
