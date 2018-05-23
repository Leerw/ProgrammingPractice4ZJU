#include <cstdio>
#include <cstring>

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) == 2) {
        int books[M + 1];
        int favorite[N];
        memset(books, 0, sizeof(books));
        for (int i = 0; i < N; i++) {
            scanf("%d", &favorite[i]);
            books[favorite[i]] += 1;
        }
        for (int i = 0; i < N; i++) {
            if (books[favorite[i]] == 1) {
                printf("BeiJu\n");
            } else {
                printf("%d\n", books[favorite[i]] - 1);
            }
        }        
    }
    return 0;
}