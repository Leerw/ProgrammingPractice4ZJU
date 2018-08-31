#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, grade;
char gender;
char tempname[12];
char tempID[12];

int gradeF = -1, gradeM = 0x3fffffff;
char nameF[12], nameM[12];
char IDF[12], IDM[12];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %c %s %d", tempname, &gender, tempID, &grade);
    if (gender == 'F') {
      if (grade > gradeF) {
        gradeF = grade;
        strcpy(nameF, tempname);
        strcpy(IDF, tempID);
      }
    } else if (gender == 'M') {
      if (grade < gradeM) {
        gradeM = grade;
        strcpy(nameM, tempname);
        strcpy(IDM, tempID);
      }
    }
  }
  if (gradeF == -1) {
    printf("Absent\n");
  } else {
    printf("%s %s\n", nameF, IDF);
  }
  if (gradeM == 0x3fffffff) {
    printf("Absent\n");
  } else {
    printf("%s %s\n", nameM, IDM);
  }
  if (gradeF == -1 || gradeM == 0x3fffffff) {
    printf("NA");
  } else {
    printf("%d", (int)abs((double)gradeF - (double)gradeM));
  }
  return 0;
}