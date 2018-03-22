#include <stdio.h>
#include <memory.h>

int main() {
    char n[100];                   // 如果用char* n的话gcc就会报段错误，原因就是char* 指向的是常量区的只读段，g++同样有这个错误，clang则不会
    char* f;
    int sum = 0;
    char* pinyin[10] = {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu"
    };
    scanf("%s", n);
    f = n;
    while (*f != '\0') {
        sum += (*f - '0');
        f += 1;
    }
    int indexs[20];
    memset(indexs, 0, sizeof indexs);
    int i = 0;
    while (sum != 0) {
        indexs[i] = sum % 10;
        sum /= 10;
        i += 1;
    }
    i -= 1;
    for (; i != 0; i--) {
        printf("%s ", pinyin[indexs[i]]);
    }
    printf("%s\n", pinyin[indexs[i]]);
    return 0;
}