#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
struct Student {
    int ID;
    int grade;
    char name[10];
}tempstudent;

vector<Student> students;

int main() {
    scanf("%d %d", &n, &c);
    students.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &tempstudent.ID, tempstudent.name, &tempstudent.grade);
        students[i] = tempstudent;
    }
    switch (c) {
        case 1: {
            sort(students.begin(), students.end(), [](const Student a, const Student b) {
                return a.ID < b.ID;
            });
            break;
        }
        case 2: {
            sort(students.begin(), students.end(), [](const Student a, const Student b) {
                if (strcmp(a.name, b.name) == 0) {
                    return a.ID < b.ID;
                } else {
                    return strcmp(a.name, b.name) < 0;
                }
            });
            break;
        }
        case 3: {
            sort(students.begin(), students.end(), [](const Student a, const Student b) {
                if (a.grade == b.grade) {
                    return a.ID < b.ID;
                } else {
                    return a.grade < b.grade;
                }
            });
            break;
        }
    }
    for (int i = 0; i < students.size(); i++) {
        printf("%06d %s %d\n", students[i].ID, students[i].name, students[i].grade);
    }
    return 0;
}