#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>

using namespace std;

int main() {
  map<int, double> ploy;
  int size, exp;
  double coeff;
  cin >> size;
  while (size--) {
    cin >> exp >> coeff;
    ploy[exp] = coeff;
  }
  cin >> size;
  while (size--) {
    cin >> exp >> coeff;
    ploy[exp] += coeff;
    if (ploy[exp] == 0) {
      ploy.erase(exp);
    }
  }
  cout << ploy.size();
  for (map<int, double>::reverse_iterator s = ploy.rbegin(); s != ploy.rend(); s++) {
    cout << fixed << setprecision(1);
    cout << " " << s->first << " " << s->second;
  }
  return 0;
}