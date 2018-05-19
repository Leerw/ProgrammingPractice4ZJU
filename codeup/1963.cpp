#include <cstdio>
#include <string.h>

int main() {
    char s[1000];
    while (gets(s)) {
        char c;
        scanf("%c", &c);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] != c) {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        getchar(); // gets会接受回车，所以需要先把回车给消掉
    }
    return 0;
}