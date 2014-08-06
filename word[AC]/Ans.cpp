#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 451+10,inf = 27;
int t,n;
int f[(1<<inf)-1];
char str[maxn];
int a[maxn][inf];
int main(int argc, char *argv[])
{
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    scanf("%d",&t);
    while(t > 0)
    {
     memset(f,0,sizeof(f));
     
     scanf("%d",&n);
     scanf("%s",&str[1]);
     int len = strlen(&str[1]);
     for(int i = 0;i<n;i++)
      a[len+1][i] = len+1;
     for(int i = len;i>=0;i--)
     {
      memcpy(a[i],a[i+1],sizeof(a[i]));
      if(i == 0)
       break;
      a[i][str[i]-'a'] = i;
     }
     int j;
     bool ans = true;
     for(int i = 0;i<(1<<n);i++)
     {
      j = f[i];
      if(j == len+1)
      {
       ans = false;
       break;
      }
      for(int ch = 0;ch<n;ch++)
      {
       if((i>>ch)&1)
        continue;
       f[i|(1<<ch)] = max(f[i|(1<<ch)],a[j][ch]);
      }
     }
     printf("%s\n",(ans==true)?"YES":"NO");
     t--;
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
