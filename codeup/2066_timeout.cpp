#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    vector<int> numbers, groups;
    set<int> sortedNumbers, sortedGroups;
    vector<pair<int, int> > num_group;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        int temp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            numbers.push_back(temp);
            sortedNumbers.insert(temp);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            groups.push_back(temp);
            sortedGroups.insert(temp);
            num_group.push_back(make_pair(numbers[i], temp));
        }
        for (set<int>::iterator sg = sortedGroups.begin(); sg != sortedGroups.end(); sg++) {
            printf("%d={", *sg);
            for (set<int>::iterator sn = sortedNumbers.begin(); sn != sortedNumbers.end(); sn++) {
                printf("%d=", *sn);
                int count = 0;
                for (vector<pair<int, int> >::iterator m = num_group.begin(); m != num_group.end(); m++) {
                    if (m->first == *sn && m->second == *sg) {
                        count += 1;
                    }
                }
                printf("%d,", count);
            }
            printf("\b}\n");
        }
    }
    return 0;
}