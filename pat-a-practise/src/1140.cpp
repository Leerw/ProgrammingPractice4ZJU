#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100010;
int n, noindex = 0;
int hashtable[maxn] = {0};
int main() {
  int temp, step = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    hashtable[temp] = i;
  }
  while (true) {
    while (hashtable[0] != 0) {
      swap(hashtable[0], hashtable[hashtable[0]]);
      step++;
    }
    while (noindex == hashtable[noindex] && noindex < n) {
      noindex++;
    }
    if (noindex == n) break;
    swap(hashtable[noindex], hashtable[0]);
    step++;
  }
  printf("%d", step);
  return 0;
}