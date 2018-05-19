#include <cstdio>  
#include <cstring>  
  
char del[1000], str[1001][1001], ans[1001][1001];  
      
int main()  
{  
    int index = 0;    
    gets (del);  
    int len1 = strlen (del);  
      
    while (gets (str[index++]))                         //读入数据；   
     
    for(int i = 0; i < len1; i++){                   //全部转化为小写字母；   
        if(del[i] >= 'A' && del[i] <= 'Z') {    
            del[i] = del[i] - 'A' + 'a';    
        }    
    }    
  
    for(int i = 0; i < index; i++) {    
            int len2 = strlen (str[i]);  
            for (int j = 0; j < len2; j++) {  
                    ans[i][j] = str[i][j];          //用另一数组存储原数据，然后将其转化为小写字母；   
                    if (str[i][j] >= 'A' && str[i][j] <= 'Z') {  
                        str[i][j] = str[i][j] - 'A' + 'a';  
                }  
            }  
              
            for (int j = 0, k = 0; j < len2; ) {       
                if (str[i][j + k] == del[k]) {          //判断是否与短字符第一个字符相同；   
                    k++;                                  
                    if (k == len1)  {                   //若完全相同则跳过；   
                        j = j + k;  
                        k = 0;  
                    }  
                }  
                else {  
                    if (str[i][j] != ' ')       printf ("%c", ans[i][j]);   //输出原字符；   
                    j++;  
                    k = 0;  
                }  
            }  
        printf ("\n");  
    }  
  
    return 0;  
}        