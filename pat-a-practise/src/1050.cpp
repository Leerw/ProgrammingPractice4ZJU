#include <iostream>
#include <string>
using namespace std;

int array[200];

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  fill(array, array + 200, 0);
  for (int i = 0; i < s2.length(); i++) {
    array[s2[i]] = -1;
  }
  for (int i = 0; i < s1.length(); i++) {
    if (array[s1[i]] != -1) {
      cout << s1[i];
    }
  }
  return 0;
}