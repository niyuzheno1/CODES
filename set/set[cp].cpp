#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int a,b,p;
int f[100010];
vector<int> t;
int n[100010];
bool m[100010];
int g(int x)
{
    if(x == f[x])
     return x;
    return f[x] = g(f[x]);
}
int u(int x,int y)
{
    f[g(x)] = g(y);
}
int main(int argc, char *argv[])
{
    freopen("set.in","r",stdin);
    freopen("set.ans","w",stdout);
    scanf("%d%d%d",&a,&b,&p);
    n[1] = 1;
    for(int i = 2;i<=b;i++)
     if(n[i] == 0){
      for(int j = 2;j<=b/i;j++)
       n[i*j] = 1;
      if(i >= p)
       t.push_back(i);
     }
    for(int i = a;i<=b;i++)
     f[i] = i;
    for(int i = a;i<=b;i++)
      for(int j = a;j<=b;j++)
       for(int k = 0;k<t.size();k++)
        if(i%t[k] == 0 && j % t[k] == 0)
         u(i,j);
    int ans = 0;
    for(int i = a;i<=b;i++)
     if(m[f[i]] == 0)
      m[f[i]] = 1,ans++;
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
