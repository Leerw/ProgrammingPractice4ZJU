#include <cstdio>
#include <map>
#include <set>
using namespace std;

int n, k, ci, ni, i, j, h;
char tempname[5];
map<int, set<int> > records;

int myhash(char* name)
{
    return (name[0] - 'A') * 26 * 26 * 10 +
           (name[1] - 'A') * 26 * 10 +
           (name[2] - 'A') * 10 +
           (name[3] - '0');
}

int main() {
    scanf("%d %d", &n, &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &ci, &ni);
        for (j = 0; j < ni; j++) {
            scanf("%s", tempname);
            h = myhash(tempname);
            records[h].insert(ci);
        }
    }
    for (i = 0; i < n; i++) {
        scanf("%s", tempname);
        printf("%s", tempname);
        h = myhash(tempname);
        printf(" %d", records[h].size());
        for (auto it = records[h].begin(); it != records[h].end(); ++it) {
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}