#include <cstdio>
int count(int n) {
    int cnt = 0;
    int iFactor = 1;
    int iLowerNum = 0;
    int iCurrNum = 0;
    int iHigherNum = 0;
    while (n / iFactor != 0) {
        iLowerNum = n - (n / iFactor) * iFactor;
        iCurrNum = (n / iFactor) % 10;
        iHigherNum = n / (iFactor * 10);
        switch (iCurrNum) {
            case 0:
                cnt += iHigherNum * iFactor;
                break;
            case 1:
                cnt += iHigherNum * iFactor + iLowerNum + 1;
                break;
            default:
                cnt += (iHigherNum + 1) * iFactor;
                break;
        }
        iFactor *= 10;
    }
    return cnt;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", count(n));
    return 0;
}