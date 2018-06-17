#include <stdio.h>

int fibo[1010] = {-1};

int F(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (fibo[n] != -1) {
        return fibo[n];
    } else {
        return fibo[n] = F(n - 1) + F(n - 2);
    }
}

int main() {
	//code
	int T;
	scanf("%d", &T);
	while (T--) {
	    int n;
	    scanf("%d", &n);
	    printf("%d\n", F(n));
	}
	return 0;
}