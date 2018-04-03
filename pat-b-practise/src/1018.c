#include <stdio.h>

char Elements[3] = {'B', 'C', 'J'};

int returnIndex(char c) {
    for (int i = 0; i != 3; i++) {
        if (c == Elements[i]) {
            return i;
        }
    }
}

int main() {
    char J, Y;
    int N = 0;
    scanf("%d", &N);
    int Jia[3] = {0};                                  // 顺序为 胜 负 平
    int JiaCount[3] = {0};                             // 顺序为 B C J
    int Yi[3] = {0};
    int YiCount[3] = {0};
    int JiaIndex = 0;
    int YiIndex = 0; 
    for (int i = 0; i != N; i++) {
        getchar();
        scanf("%c %c", &J, &Y);
        if (J == Y) {
            Jia[1] += 1;
            Yi[1] += 1;
            continue;
        }

        JiaIndex = returnIndex(J);
        YiIndex = returnIndex(Y);

        if ((JiaIndex + 1) % 3 == YiIndex) {
            Jia[0] += 1;
            Yi[2] += 1;
            JiaCount[JiaIndex] += 1;
        } else {
            Yi[0] += 1;
            Jia[2] += 1;
            YiCount[YiIndex] += 1;
        }
    }
    printf("%d %d %d\n", Jia[0], Jia[1], Jia[2]);
    printf("%d %d %d\n", Yi[0], Yi[1], Yi[2]);
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++) {
        if (JiaCount[i] > JiaCount[id1]) {
            id1 = i;
        }
        if (YiCount[i] > YiCount[id2]) {
            id2 = i;
        }
    }
    printf("%c %c", Elements[id1], Elements[id2]);
    return 0;
}