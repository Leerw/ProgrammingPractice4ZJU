#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node
{
    char name[25];
    int month,day,hour,minute;
    bool isOn;
}record;

int hourCost[25]; //[0..23]
record rec[1005]; //读入的通话记录
vector<int> output; //满足筛选条件的记录对的下标

bool cmp(const record &a, const record &b) //对读入的所有记录排序
{
    int tmp = strcmp(a.name, b.name);
    if (tmp == 0) //名字相同则按时间排序
    {
        if (a.month != b.month)
            return a.month < b.month;
        if (a.day != b.day)
            return a.day < b.day;
        if (a.hour != b.hour)
            return a.hour < b.hour;
        return a.minute < b.minute;
    }
    return tmp < 0; //名字不同则按名字升序
}

void testSort(int n) //输出排序后的结果
{
    for (int i = 0; i<n; ++i)
    {
        printf("%s %d:%d:%d:%d ",
              rec[i].name, rec[i].month, rec[i].day, rec[i].hour, rec[i].minute);
        if(rec[i].isOn) printf("on-line\n");
        else printf("off-line\n");
    }
}


void calc_cost(const record &s, const record &e, int &last, int &money)
{
    record tmp;
    tmp.day = s.day;
    tmp.hour = s.hour;
    tmp.minute = s.minute;
    while (tmp.day < e.day || tmp.hour < e.hour || tmp.minute < e.minute) //模拟时间流动，从start直到end
    {
        money += hourCost[tmp.hour];
        tmp.minute++; //分钟流动
        last++; //耗时+1
        if (tmp.minute > 59)
        {
            tmp.minute = 0;
            tmp.hour++;
            if (tmp.hour > 23)
            {
                tmp.hour = 0;
                tmp.day++;
            }
        }
    }
}


int main()
{
    for (int i = 0; i < 24; ++i)
        cin >> hourCost[i];
    int n;
    cin >> n;
    char s[10];
    for (int i = 0; i<n; ++i)
    {
        scanf("%s%2d:%2d:%2d:%2d %s",
              rec[i].name, &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute, s);
        if (strcmp("on-line", s) == 0)
            rec[i].isOn = true;
        else rec[i].isOn = false;
    }
    sort(rec, rec+n, cmp); //名字-时间升序
    //testSort(n);
    bool hasOn = false; //之前是否出现过on-line记录
    char name[25];
    int i = 0;
    while(i < n) //只处理下面三种情况
    {
        if (rec[i].isOn == true && hasOn == false) //当前的第一个on
        {
            hasOn = true;
            output.push_back(i);
            strcpy(name, rec[i].name);
        }
        else if(rec[i].isOn == true && hasOn == true) //再次出现on，抛弃之前的on
        {
            output.pop_back();
            output.push_back(i);
            strcpy(name, rec[i].name);
        }
        else if (rec[i].isOn == false && hasOn == true && strcmp(name, rec[i].name) == 0) //成功匹配
        {
            output.push_back(i);
            hasOn = false;
        }
        //其余情况都过滤掉
        ++i;
    }

    for (int i = output.size()-1; i>=0; --i) //去掉尾随的无效开始记录，测试点2.3.4
    {
        if (rec[output[i]].isOn == true)
            output.pop_back();
        else break;
    }

    int m = rec[0].month;
    //按格式输出，并计算每一对记录的价格
    record pre, now;
    strcpy(pre.name, "\0");
    int tot_cost = 0;
    for (int i = 0; i < output.size(); ++i)
    {
        now = rec[output[i]];
        if (strcmp(pre.name, now.name) != 0)
        {
            if (i != 0) printf("Total amount: $%.2f\n", tot_cost*1.0/100); //结束上一人的累加
            tot_cost = 0;
            printf("%s ", now.name);
            printf("%02d\n", m);
        }
        printf("%02d:%02d:%02d ", now.day, now.hour, now.minute);
        if (now.isOn == false)
        {
            int last = 0, money = 0;
            calc_cost(pre, now, last, money); //本条通话记录的价格
            printf("%d $%.2f\n", last, money*1.0/100); //持续时间
            tot_cost += money;
        }
        pre = now;
    }
    printf("Total amount: $%.2f\n", tot_cost*1.0/100); //最后一个人的总价
    return 0;
}
