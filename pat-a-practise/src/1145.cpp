#include <cstdio>
#include <vector>
using namespace std;
int msize, n, m;
bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d %d %d", &msize, &n, &m);
  while (!isPrime(msize)) msize++;
  vector<int> hashTable(msize, 0);
  vector<int> inskey(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &inskey[i]);
    int flag = 0;
    for (int j = 0; j < msize; j++) {
      int pos = (inskey[i] + j * j) % msize;
      if (hashTable[pos] == 0) {
        hashTable[pos] = inskey[i];
        flag = 1;
        break;
      }
    }
    if (!flag) printf("%d cannot be inserted.\n", inskey[i]);
  }
  int query;
  int t = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &query);
    for (int j = 0; j <= msize; j++) {
      t++;
      int pos = (query + j * j) % msize;
      if (hashTable[pos] == query || hashTable[pos] == 0) {
        break;
      }
    }
  }
  printf("%.1f", t * 1.0 / m);
  return 0;
}