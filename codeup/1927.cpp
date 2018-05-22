#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    char str[200];
    memset(str, 0, sizeof(str));
    // 注意字符串中可能有空格
    while (gets(str)) {
        int n = strlen(str);
        sort(str, str + n);
        puts(str);
    }
    return 0;
}