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
    vector<int> vsN, vsG;
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
        for (set<int>::iterator it = sortedNumbers.begin(); it != sortedNumbers.end(); it++) {
            vsN.push_back(*it);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            groups.push_back(temp);
            sortedGroups.insert(temp);
            num_group.push_back(make_pair(numbers[i], temp));
        }

        for (set<int>::iterator it = sortedGroups.begin(); it != sortedGroups.end(); it++) {
            vsG.push_back(*it);
        }

        for (int i = 0; i < vsG.size(); i++) {
            printf("%d={", vsG[i]);
            for (int j = 0; j < vsN.size(); j++) {
                printf("%d=", vsN[j]);
                int count = 0;
                for (int k = 0; k < num_group.size(); k++) {
                    if (num_group[k].first == vsN[j] && num_group[k].second == vsG[i]) {
                        count += 1;
                    }
                }
                if (j != vsN.size() - 1) {
                    printf("%d,", count);
                }
            }
            printf("}\n");
        }
        numbers.clear();
        groups.clear();
        sortedNumbers.clear();
        sortedGroups.clear();
        vsN.clear();
        vsG.clear();
        num_group.clear();
    }
    return 0;
}