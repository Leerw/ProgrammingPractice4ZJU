#include <cstdio>
const int maxn = 11;
// P为当前排列。HashTable记录整数x是否已经存在与数组P中
int n, P[maxn], hashTable[maxn] = {false};
// 当前处理排列的第index号位
void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main() {
    n = 3;
    generateP(1);
    return 0;
}