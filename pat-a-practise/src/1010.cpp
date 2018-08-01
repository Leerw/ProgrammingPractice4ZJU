#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int map[128];
void init(){                                    //初始化，将字符影射成数字
    for(char c = '0'; c <= '9'; c++)
        map[c] = c - '0';
    for(char c = 'a'; c <= 'z'; c++)
        map[c] = c - 'a' + 10;
}
long long toten(char a[], long long radix){     //化为十进制
    long long ans=0;
    int len=strlen(a);
    for(int i=0;i<len;i++)
        ans=ans*radix+map[a[i]];                //溢出
    if(ans<0) return -1;
    return ans;
}
int find_largest_didit(char s[]){              //求最大的数位
    int max=-1,len=strlen(s);
    for(int i=0;i<len;i++){
        if(map[s[i]]>max)
            max=map[s[i]];
    }
    return max+1;                             //数位最大为max，进制位为max+1作为下界
}
int main(){
    init();
    char s1[15],s2[15];int tag,radix;
    cin>>s1>>s2>>tag>>radix;
    if(tag==2)
        swap(s1,s2);
    long long m=toten(s1,radix),n;
    long long left=find_largest_didit(s2),mid;
    long long right=max(left,m)+1;            //进制位上界
    while(left<=right){
        mid=(left+right)/2;
        n=toten(s2,mid);
        if(n==m){
            cout<<mid;
            return 0;
        }
        else if(n==-1||n>m) right=mid-1;     //s2的mid进制溢出或者大于s1的十进制
        else left=mid+1;
    }
    cout<<"Impossible";
    return 0;
}