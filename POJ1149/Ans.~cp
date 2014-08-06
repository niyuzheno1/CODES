#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 1000100;
int m,n;
struct e
{
 int c,v,ne;
};
int c[1010];
int pre[1010];
int map[110][110];
int st[110];
e lk[inf];
int tot;
int s[110];
int d[110];
void add(int x,int y,int z)
{
     lk[tot].c = z;
     lk[tot].v = y;
     lk[tot].ne = st[x];
     st[x] = tot;
     tot++;
     lk[tot].c = 0;
     lk[tot].v = x;
     lk[tot].ne = st[y];
     st[y] = tot;
     tot++;
}
int mf(int u,int f)
{
    if(u == n+1) return f;
    int sum = 0;
    for(int i = st[u];i!=-1;i = lk[i].ne)
    {
            int v = lk[i].v;
            if(lk[i].c && d[u]==d[v]+1)
            {
             int t = mf(v,min(f-sum,lk[i].c));
             lk[i].c -= t;lk[i^1].c += t;
             sum+=t;
             if(sum == f)
              return f;
            }
    }
    if(d[0] >= n+2)
     return sum;
    s[d[u]]--;
    if(s[d[u]] == 0)
     d[0] = n+2;
    s[++d[u]]++;
    return sum;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=m;i++)
     scanf("%d",&c[i]);
    for(int i = 1;i<=n;i++)
    {
     int k,x;scanf("%d",&k);
     while(k > 0)
     {
      scanf("%d",&x);
      if(pre[x])
       map[pre[x]][i] = inf;
      else
       pre[x] = i,map[0][i] += c[x];
      k--;
     }
     scanf("%d",&k);map[i][n+1] = k;
    }
    for(int i = 0;i<=n+1;i++)
     for(int j = 0;j<=n+1;j++)
      if(map[i][j])
       add(i,j,map[i][j]);
    int ans = 0;
    s[0] = n+2;
    while(d[0] <= n+1)
      ans += mf(0,2*inf);
    printf("%d\n",ans);
    return EXIT_SUCCESS;
}
