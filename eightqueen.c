#include <stdio.h>

char mask[8] = {1};

int judge()
{

}

int main()
{
    int total = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            mask[i] <<= j;
            
        }
    }
}