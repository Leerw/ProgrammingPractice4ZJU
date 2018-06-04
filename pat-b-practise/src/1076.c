#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char str[20];
    gets(str);
    getchar();
    if (str[2] == 'T') {
      printf("%d", str[0] - 'A' + 1);
    } else if (str[6] == 'T') {
      printf("%d", str[4] - 'A' + 1);
    } else if (str[10] == 'T') {
      printf("%d", str[8] - 'A' + 1);
    } else if (str[14] == 'T') {
      printf("%d", str[12] - 'A' + 1);
    }
  }
  printf("\n");
  return 0;
}