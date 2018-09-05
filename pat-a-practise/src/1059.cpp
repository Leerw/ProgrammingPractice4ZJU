#include <cstdio>
#include <vector>
using namespace std;
vector<int> prime(500000, 1);
int main() {
  for (int i = 2; i * i < 500000; i++) {
    for (int j = 2; j * i < 500000; j++) {
      prime[i * j] = 0;
    }
  }
  long int a;
  scanf("%ld", &a);
  printf("%ld=", a);
  if (a == 1) printf("1");
  bool state = false;
  for (int i = 2; a >= 2; i++) {
    int cnt = 0, flag = 0;
    while (prime[i] == 1 && a % i == 0) {
      cnt++;
      a /= i;
      flag = 1;
    }
    if (flag == 1) {
      if (state == true) printf("*");
      printf("%d", i);
      state = true;
    }
    if (cnt > 1) {
      printf("^%d", cnt);
    }
  }
  return 0;
}