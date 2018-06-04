#include <stdio.h>
#include <string.h>
int main()
{
    char A[1001];
    int B, Q = 0, R = 0, flag = 0;
    scanf("%s %d", &A, &B);
    for (int i = 0; i < strlen(A); i++)
    {
        R = R * 10 + (A[i] - '0');
        Q = R / B;
        R %= B;
        if (Q > 0) // 判断第一次的商是否为0
            flag = 1;
        if (flag)
            printf("%d", Q);
    }
    if (flag == 0)
      printf("0");
    printf(" %d", R);
    return 0;
}