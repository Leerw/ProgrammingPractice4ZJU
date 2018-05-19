#include <cstdio>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        char A[100], B[100];
        scanf("%s%s", A, B);
        int flag = (strlen(A) > strlen(B) ? 1 : (strlen(A) == strlen(B) ? 0 : -1));
        switch (flag) {
            case 1:
                printf("%s is longer than %s\n", A, B);
                break;
            case 0:
                printf("%s is equal long to %s\n", A, B);
                break;
            case -1:
                printf("%s is shorter than %s\n", A, B);
                break;
            default:
                break;
        }
    }
    return 0;
}