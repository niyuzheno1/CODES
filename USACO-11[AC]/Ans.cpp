#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
map<int,int> p[6];
int a[20010];
int n;
bool cmp(int x,int y)
{
    int ret = 0;
    for(int i = 1;i<=5;i++)
     ret += (p[i][x] < p[i][y]);
    if(ret >= 3)
     return 1;
    else
     return 0;
}
int main(int argc, char *argv[])
{
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=5;i++)
     for(int j = 1;j<=n;j++)
     {
      int x;
      scanf("%d",&x);
      if(i == 1)
       a[j] = x;
      p[i][x] = j;
     }
    
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n;i++)
     printf("%d\n",a[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
