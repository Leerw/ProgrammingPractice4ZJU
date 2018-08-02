#include <cstdio>
#include <string.h>

int main() {
    char str[80];
    scanf("%s", str); 
        int n = strlen(str);
        int side = (n + 2) / 3;
        int space = n - side * 2;
        for (int i = 0; i < side - 1; i++) {
            printf("%c", str[i]);
            for (int j = 0; j < space; j++) {
                printf(" ");
            }
            printf("%c\n", str[n - 1 - i]);
        }
        for (int i = side - 1; i <= n - side; i++) {
            printf("%c", str[i]);
        }
    
    return 0;    
}
