#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int z;
char str[101];
char a;
char m1[101],m2[101];
int n1[101],n2[101];
int get(int x,int y)
{
    if(x == 0)
     return 0;
    if(y == 1)
     return pow(double(10),double(x-1))+get(x-1,1)+get(x-1,0)*9;
    else
     return get(x-1,0)*9+get(x-1,1);
    
}
int ff(int y)
{
    int ans = 0;
    for(int i = 1;i<=y;i++)
    {
     int t = y-i+1;
     if(str[i] >= a)
      ans += get(t,1)+get(t,0)*(str[i]-'0'-1);
     else
      ans += get(t,0)*(str[i]-'0');
    }
    return ans;
}
int f(int x[],int y)
{
    for(a='0';a<='9';a++)
     x[a-'0'] = ff(y);
}
int main(int argc, char *argv[])
{
    scanf("%s%s",m1,m2);
    
    strcpy(&str[1],m1);
    f(n1,strlen(m1));
    strcpy(&str[1],m2);
    f(n2,strlen(m2));
    for(int i = 0;i<=9;i++) 
     printf("%d ",n2[i]-n1[i]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
