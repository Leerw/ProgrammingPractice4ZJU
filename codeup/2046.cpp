#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int MaxN = 93, n = 8;
int i = 1, P[MaxN][n] = { 0 }, T[n + 1];
bool HashTable[MaxN] = { false };
void GenerateT(int t)
{
    if (t == n + 1)
    {
        for (int k = 0; k < n; ++k)
            P[i][k] = T[k + 1];
        ++i;
        return;
    }
    for (int k = 1; k <= n; ++k)
    {
        if (HashTable[k] == false)
        {
            bool flag = true;
            for (int j = 1; j < t; ++j)  //判断与之前排放的位置是否有冲突
            {
                if (abs(t - j) == abs(k - T[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                T[t] = k;
                HashTable[k] = true;
                GenerateT(t + 1);
                HashTable[k] = false;
            }
        }
    }
}

int main()
{
    int m, index;
    cin >> m;
    GenerateT(1);
    while (m--)
    {
        cin >> index;
        for (int i = 0; i < n; ++i)
            printf("%d", P[index][i]);
        printf("\n");
    }
    return 0;
}