#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  string str1, str2, str3, str4;
  cin >> str1 >> str2 >> str3 >> str4;
  int i;
  set<char> s;
  vector<char> vec1, vec2;
  char first = '0', second = '0';
  for (i = 0; i < str1.size() && i < str2.size(); i++) {
    if (str1[i] == str2[i]) {
      if (isupper(str1[i]) && str1[i] <= 'G' && first == '0') {
        first = str1[i];
      } else if (first != '0' && second == '0' &&
                 ((isupper(str1[i]) && str1[i] <= 'N') || isdigit(str1[i]))) {
        second = str1[i];
        break;
      }
    }
  }
  for (i = 0; i < str3.size() && i < str4.size(); i++) {
    if (isalpha(str3[i]) && str3[i] == str4[i]) break;
  }
  int m = i;
  char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int h = isalpha(second) ? (second - 'A' + 10) : (second - '0');
  printf("%s %02d:%02d\n", week[first - 'A'], h, m);
  return 0;
}