#include <cstdlib>
#include <iostream>

using namespace std;
const int t[] = {0,548,866,892,64,1303,97,1278,1278,960,934};
const int o[] = {1,1,-1,-1,1,1,-1,1,-1,1,1};
int sum = 0,d = 0,n = 1,cnt = 0;
int a[100];
int main(int argc, char *argv[])
{
freopen("seven.in","r",stdin);
freopen("seven.out","w",stdout);
int X;
d = 1;
n = 0;
cnt = 0;
scanf("%d",&X);
d = o[X/100000000];
n = t[X/100000000];
a[9] = X/100000000;
if(a[9] == 7)
 cnt++;
X %=100000000;
    
    while(X >= 1)
    {
     n = n+d;
     X--;
     a[1]++;
     int j = 1;
     while(a[j] >= 10)
     {
      a[j] = 0;
      a[j+1]++;
      j++;
     }
     if(a[j] == 8)
      cnt--;
     if(a[j] == 7)
      cnt++;
     sum++;
     
     if(cnt > 0 || (sum == 7))
      d = -d;
     if(sum == 7)
      sum =0;
     
     n %= 1337;
     while(n <= 0)
      n += 1337;
     
    }
    printf("%d\n",n);
fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
