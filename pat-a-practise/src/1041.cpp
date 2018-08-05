#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int numbers[N];
  int hash[10010];
  memset(hash, 0, sizeof hash);
  int i;
  for (i = 0; i < N; i++) {
    cin >> numbers[i];
    hash[numbers[i]]++;
  }
  for (i = 0; i < N; i++) {
    if (hash[numbers[i]] == 1) {
      cout << numbers[i];
      break;
    }
  }
  if (i == N) {
    cout << "None";
  }
  return 0;
}
