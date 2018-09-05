#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Institution {
    int testees;
    double scores;
    string name;
    Institution(int testees, double scores, string name) : testees(testees), scores(scores), name(name) {}
};
map<string, int> exist;
vector<Institution> vins;
int main() {
    int n;
    scanf("%d", &n);
    string id, insname;
    double score;
    int i = 0;
    while(n--) {
        cin >> id >> score >> insname;
        if (id[0] == 'B') {
            score = score / 1.5;
        } else if (id[0] == 'T') {
            score = score * 1.5;
        }
        std::transform(insname.begin(), insname.end(), insname.begin(), ::tolower);
        auto found = exist.find(insname);
        if (found != exist.end()) {
            vins[found->second].testees += 1;
            vins[found->second].scores += score;
        } else {
            exist[insname] = i++;
            vins.push_back(Institution(1, score, insname));
        }
    }
    sort(vins.begin(), vins.end(), [](const Institution a, const Institution b) {
        if (a.scores != b.scores) return a.scores > b.scores;
        else if (a.testees != b.testees) return a.testees < b.testees;
        else return a.name < b.name;
    });
    int rank = 1, prerank = rank;
    printf("%d\n", vins.size());
    if (vins.size() == 0) return 0;
    int prescore = (int)vins[0].scores;
    for (i = 0; i < vins.size(); i++) {
        if ((int)vins[i].scores == prescore) {
            printf("%d ", prerank);
            rank++;
        } else {
            prerank = rank;
            printf("%d ", rank++);
        }
        prescore = (int)vins[i].scores;
        cout << vins[i].name;
        printf(" %d %d\n", (int)vins[i].scores, vins[i].testees);
    }
    return 0;
}