#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, k, grade;
char id[15];

struct Student {
    char id[15];
    int grade;
    int loc;
    int local_rank;
    int global_rank;

    Student() {}

    Student(char *srcid, int grade, int loc) : grade(grade), loc(loc) { strcpy(id, srcid); }
};

struct cmp {
    bool operator()(const Student &s1, const Student &s2) {
        return s1.grade < s2.grade;
    }
};

priority_queue<Student, vector<Student>, cmp> students;
vector<Student> global_students;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%s %d", id, &grade);
            students.push(Student(id, grade, i + 1));
        }
        int local_rank = 1;
        Student prev;
        if (!students.empty()) {
            prev = students.top();
            students.pop();
            prev.local_rank = local_rank++;
            global_students.push_back(prev);
        }
        while (!students.empty()) {
            Student student = students.top();
            if (student.grade == prev.grade) {
                student.local_rank = prev.local_rank;
            } else {
                student.local_rank = local_rank;
            }
            local_rank++;
            prev = student;
            students.pop();
            global_students.push_back(student);
        }
    }
    sort(global_students.begin(), global_students.end(), [](Student a, Student b) {
        if (a.grade == b.grade) {
            return strcmp(a.id, b.id) < 0;
        } else {
            return a.grade > b.grade;
        }
    });
    int index = 1;
    Student prev;
    if (!global_students.empty()) {
        global_students[0].global_rank = index++;
        prev = global_students[0];
    }
    for (int i = 1; i < global_students.size(); i++) {
        if (global_students[i].grade == prev.grade) {
            global_students[i].global_rank = prev.global_rank;
        } else {
            global_students[i].global_rank = index;
        }
        index++;
        prev = global_students[i];
    }
    printf("%d\n", (int) global_students.size());
    if (!global_students.empty()) {
        for (auto student : global_students) {
            printf("%s %d %d %d\n", student.id, student.global_rank, student.loc, student.local_rank);
        }
    }
    return 0;
}
