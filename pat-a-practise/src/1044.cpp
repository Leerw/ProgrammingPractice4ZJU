#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100100;
const int INF = 0x3fffffff;
int n, m;
int acusum[maxn];
vector<pair<int, int> > pairs;
vector<pair<int, int> > bak;

int main() {
    fill(acusum, acusum + maxn, 0);
    scanf("%d %d", &n, &m);
    int temp, min = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        acusum[i] = acusum[i - 1] + temp;
    }
    int i = 1, j = 1;
    while (i <= j && i <= n && j <= n) {
        while (acusum[j] - acusum[i - 1] < m && j <= n) {
            j++;
        }
        if (acusum[j] - acusum[i - 1] == m) {
            pairs.push_back(make_pair(i, j));
        } else {
            if ((int)abs((double)acusum[j] - (double)acusum[i - 1]) < min) {
                min = (int)abs((double)acusum[j] - (double)acusum[i - 1]);
                bak.clear();
                bak.push_back(make_pair(i, j));
            } else if ((int)abs((double)acusum[j] - (double)acusum[i - 1]) == min) {
                bak.push_back(make_pair(i, j));
            }
        }
        i++;
        if (j < i) {
            j = i;
        }
    }
    if (pairs.size() != 0) {
        for (int i = 0; i < pairs.size(); i++) {
            printf("%d-%d\n", pairs[i].first, pairs[i].second);
        }
    } else {
        for (int i = 0; i < bak.size(); i++) {
            printf("%d-%d\n", bak[i].first, bak[i].second);
        }
    }
    return 0;
}