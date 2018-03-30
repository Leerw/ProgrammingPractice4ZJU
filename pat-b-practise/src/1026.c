#include <stdio.h>

#define CLK_TCK 100

int main() {
    int C1 = 0, C2 = 0;
    scanf("%d%d", &C1, &C2);
    int seconds = (C2 - C1) % CLK_TCK >= 50 ? (C2 - C1) / CLK_TCK + 1 : (C2 - C1) / CLK_TCK;
    int hh = seconds / 3600;
    int mm = seconds % 3600 / 60;
    int ss = seconds - hh * 3600 - mm * 60;
    printf("%d:%d:%d", hh, mm, ss);
    return 0;
}