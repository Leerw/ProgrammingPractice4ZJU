#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    vector<int> numbers;
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
            sortedGroups.insert(temp);
            num_group.push_back(make_pair(numbers[i], temp));
        }
        for (set<int>::iterator sg = sortedGroups.begin(); sg != sortedGroups.end(); sg++) {
            printf("%d={", *sg);
            int c = 0;
            for (set<int>::iterator sn = sortedNumbers.begin(); sn != sortedNumbers.end(); sn++, c++) {
                printf("%d=", *sn);
                int count = 0;
                for (int i = 0; i < num_group.size(); i++) {
                    if (num_group[i].first == *sn && num_group[i].second == *sg) {
                        count += 1;
                    }
                }
                if (c != sortedNumbers.size() - 1) {
                    printf("%d,", count);
                } else {
                    printf("%d", count);
                }
            }
            // 之前做的也没有错，只是输出的格式出现了问题，本来想用\b把最后一个逗号消去，但是OJ一直报错，\b存疑？
            printf("}\n");
        }
        numbers.clear();
        sortedNumbers.clear();
        sortedGroups.clear();
        num_group.clear();
    }
    return 0;
}