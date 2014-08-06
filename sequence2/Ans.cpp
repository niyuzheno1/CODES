#include <cstdlib>
#include <iostream>

using namespace std;
int s[100010];
int b[100010];
int d[100010];
int n;
bool cmp(int x,int y)
{
     if(s[x] < s[y])
      return true;
     else
      return false;
}
void dfs(int x)
{
     if(d[x])
      return;
     d[x] = 1;
     dfs(b[x]);
}
int main(int argc, char *argv[])
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    scanf("%d",&n);
    int c = 0;
    for(int i = 1;i<=n;i++)
    {
     scanf("%d",&c);
     s[i] = s[i-1]+c;
     b[i] = i;
    }
    sort(b+1,b+1+n,cmp);
    int cnt = 0;
    for(int i = 1;i<=n;i++)
     if(d[i] == 0)
     {
      cnt++;
      dfs(i);
     }
    printf("%d\n",n-cnt);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
