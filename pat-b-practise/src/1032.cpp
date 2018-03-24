#include <cstdio>

#define MAXSCHOOLD 100000

int main() {
    int schoold[MAXSCHOOLD] = {0};
    int N = 0;
    int maxScore = 0;
    int sId = 0;
    int sScore = 0;
    int maxSID = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &sId, &sScore);
        schoold[sId] += sScore;
        if (schoold[sId] > maxScore) {
            maxScore = schoold[sId];
            maxSID = sId;
        }
    }
    printf("%d %d", maxSID, maxScore);
    return 0;
}