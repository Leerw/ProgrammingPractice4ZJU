#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct stu {
    int id;
    char name[100];
    int score;
} students[100001];

bool cmp1(stu s1, stu s2) {
    return s1.id < s2.id;
}

bool cmp2(stu s1, stu s2) {
    if (strcmp(s1.name, s2.name) == 0) {
        return s1.id < s2.id;
    } else {
        return strcmp(s1.name, s2.name) < 0;
    }
}

bool cmp3(stu s1, stu s2) {
    if (s1.score == s2.score) {
        return s1.id < s2.id;
    } else {
        return s1.score < s2.score;
    }
}

int main() {
    int n, c;
    int count = 1;
    while (scanf("%d %d", &n, &c) != EOF) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            stu s;
            scanf("%d %s %d", &s.id, s.name, &s.score);
            students[i] = s;
        }
        switch (c) {
            case 1:
                sort(students, students + n, cmp1);
                break;
            case 2:
                sort(students, students + n, cmp2);
                break;
            case 3:
                sort(students, students + n, cmp3);
                break;
            default:
                break;
        }

        printf("Case %d:\n", count);
        for (int i = 0; i < n; ++i) {
            printf("%06d %s %d\n", students[i].id, students[i].name, students[i].score);
        }
        count++;
    }
    return 0;
}