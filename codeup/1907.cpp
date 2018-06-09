#include <cstdio>
int s[20] = {0};
int S(int index) {
    if (index == 1 || index == 0) {
        return 1;
    }
    if (s[index - 1] == 0) {
        s[index - 1] = S(index - 1);
    }
    if (s[index - 2] == 0) {
        s[index - 2] = S(index - 2);
    }
    s[index] = s[index - 1] + s[index - 2]; 
    return s[index];
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", S(n));
    }
    return 0;
}