#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
    int n;
    scanf("%d", &n);
    char strs[n][100];
    int i = 0;
    for (i = n; i != 0; i--)
    {
        scanf("%s", strs[n - i]);
    }
    for (i = 0; i < n; i++)
    {
        int indexes[2] = {0, 0};
        int P_pos = -1, T_pos = 0;
        int leftA = 0, middleA = 0, rightA = 0;
        int flag = 0;
        for (int j = 0; j < strlen(strs[i]); j++)
        {
            if (strs[i][j] == 'P')
            {
                if (P_pos == -1)
                {
                    P_pos = j;
                }
                indexes[0] += 1;
            }
            else if (strs[i][j] == 'T')
            {
                if (T_pos == 0)
                {
                    T_pos = j;
                }
                indexes[1] += 1;
            }
            else if (strs[i][j] == 'A')
            {
                if (P_pos == -1)
                {
                    leftA += 1;
                }
                else if (T_pos != 0 && j > T_pos)
                {
                    rightA += 1;
                }
                else
                {
                    middleA += 1;
                }
            }
            else
            {
                printf("NO\n");
                flag = 1;
                break;
            }
        }
        if (indexes[0] == 1 && indexes[1] == 1 && leftA + middleA + rightA > 0 && leftA * middleA == rightA)
        {
            printf("YES\n");
        }
        else if (!flag)
        {
            printf("NO\n");
        }
    }
    return 0;
}