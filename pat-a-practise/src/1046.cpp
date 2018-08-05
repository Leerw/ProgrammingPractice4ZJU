#include <cstdio>
#include <string.h>

int D[100010];
int distance1[100010];
int distance2[100010];

int main() {
  int N;
  scanf("%d", &N);
  memset(distance1, 0, sizeof distance1);
  memset(distance2, 0, sizeof distance2);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &D[i]);
    sum += D[i];
    if (i == 0) {
        distance1[i] = 0;
    } else {
        distance1[i] = distance1[i - 1] + D[i - 1];
    }
  }
  for (int i = 0; i < N; i++) {
      distance2[i] = sum - distance1[i];
  }
  int M;
  scanf("%d", &M);
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    a -= 1;
    b -= 1;
    if (a == b) {
        printf("0\n");
    } else {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int d1 = distance1[b] - distance1[a];
        int d2 = distance1[a] + distance2[b];
        printf("%d\n", d1 < d2 ? d1 : d2);
    }
  }
  return 0;
}