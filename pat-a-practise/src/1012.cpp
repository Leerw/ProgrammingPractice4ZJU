#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct student {
    int id;
    int CGrade;
    int MGrade;
    int EGrade;
    int AGrade;
    int CRank, MRank, ERank, ARank;
    student(int id, int c, int m, int e, int a) : id(id), CGrade(c), MGrade(m), EGrade(e), AGrade(a) {}
};

vector<student> students;
map<int, int> id_index;

void printBestRank(student s) {
    int bestrank = s.ARank;
    char rank = 'A';
    if (s.CRank < bestrank) { bestrank = s.CRank; rank = 'C'; }
    if (s.MRank < bestrank) { bestrank = s.MRank; rank = 'M'; }
    if (s.ERank < bestrank) { bestrank = s.ERank; rank = 'E'; }
    printf("%d %c\n", bestrank, rank);
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int id, C, M, E, A;
    for (int i = 0; i < n; i++) {
        cin >> id >> C >> M >> E;
        A = C + M + E;
        students.push_back(student(id, C, M, E, A));
    }

    // sort by C grade
    std::sort(students.begin(), students.end(), [](student a, student b) {
        return a.CGrade > b.CGrade;
    });
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i].CGrade == students[i-1].CGrade) {
            students[i].CRank = students[i-1].CRank;
        } else {
            students[i].CRank = i + 1;
        }
    }

    // sort by M grade
    std::sort(students.begin(), students.end(), [](student a, student b) {
        return a.MGrade > b.MGrade;
    });
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i].MGrade == students[i-1].MGrade) {
            students[i].MRank = students[i-1].MRank;
        } else {
            students[i].MRank = i + 1;
        }
    }

    // sort by E grade
    std::sort(students.begin(), students.end(), [](student a, student b) {
        return a.EGrade > b.EGrade;
    });
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i].EGrade == students[i-1].EGrade) {
            students[i].ERank = students[i-1].ERank;
        } else {
            students[i].ERank = i + 1;
        }
    }

    // sort by A grade
    std::sort(students.begin(), students.end(), [](student a, student b) {
        return a.AGrade > b.AGrade;
    });
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i].AGrade == students[i-1].AGrade) {
            students[i].ARank = students[i-1].ARank;
        } else {
            students[i].ARank = i + 1;
        }
        id_index.insert(make_pair(students[i].id, i));
    }

    int qid;
    for (int i = 0; i < m; i++) {
        cin >> qid;
        auto found = id_index.find(qid);
        if (found != id_index.end()) {
            printBestRank(students[found->second]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}