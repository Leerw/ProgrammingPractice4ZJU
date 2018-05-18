#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int index(char c)
{
	for (int i = 0; i < sizeof(nums); i++)
	{
		if (nums[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int a, b;
	long long n = 0;
	string sn;
	while (cin >> a >> sn >> b)
	{
		int product = 1;
		for (int i = sn.size() - 1; i >= 0; i--)
		{
			n += product * index(sn[i]);
			product *= a;
		}
		int z[40], num = 0;
		do
		{
			z[num++] = n % b;
			n = n / b;
		} while (n != 0);
		for (int i = num - 1; i >= 0; i--)
		{
			printf("%c", nums[z[i]]);
		}
		printf("\n");
	}
	return 0;
}