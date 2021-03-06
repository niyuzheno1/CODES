#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#define LL long long
using namespace std;
const int maxn = 30001,inc = 3,bit=7;
int n,m,now,pre,code[20],bin[20],res[20];
char gp[20][20],fx,fy;
struct node
{
 int head[maxn],next[maxn],size;
 LL sum[maxn],sta[maxn];
 void clear()
 {
  memset(head,-1,sizeof(head));
  size = 0;
 }
 void push(LL st,const LL v)
 {
  LL hash = st%maxn;
  for(int i = head[hash];i>=0;i=next[i])
  {
   if(sta[i] == st)
   {
    sum[i] += v;
    return;
   }
   
  }sta[size]=st;sum[size] = v;
   next[size]=head[hash],head[hash] =size++;
 }
}dp[2];
LL encode(int m)
{
 LL st = 0;
 int cnt = 1;
 memset(bin,-1,sizeof(bin));
 bin[0] = 0;
 for(int i = m;i>=0;i--)
 {
  if(bin[code[i]] == -1)
   bin[code[i]] = cnt++;
  code[i] = bin[code[i]];
  st<<=inc;
  st |= code[i];
 }
 return st;
}
void decode(LL st,int m)
{
 for(int i = 0;i<=m;i++)
 {
  code[i] = st&bit;
  st>>=inc;
 }
}
void DP(int x,int y,int k)
{
 decode(dp[pre].sta[k],m);
 int l = code[y-1];
 int up = code[y];
 code[y-1] = code[y] = 0;
 memcpy(res,code,sizeof(code));
 LL v = dp[pre].sum[k];
 if(!l && !up)
 {
  if(gp[x][y] == '*')
   dp[now].push(encode(m),v);
  else if(x < n && y<m && gp[x+1][y] == '.' && gp[x][y+1] == '.')
  {
   code[y] = code[y-1] = bit;
   dp[now].push(encode(m),v);
  }
 }
 else if(!l || !up)
 {
  int e = l+up;
  if(x < n && gp[x+1][y] == '.')
  {
   code[y-1] = e;
   dp[now].push(encode(m),v);
   memcpy(code,res,sizeof(res));
  }
  if(y < m && gp[x][y+1] == '.')
  {
   code[y] = e;
   dp[now].push(encode(m),v);
  }
 }
 else if(l != up)
 {
  for(int i = 0;i<=m;i++)
   if(code[i] == up)
    code[i]=l;
  dp[now].push(encode(m),v);
 }
 else if(x == fx && y == fy)
  dp[now].push(encode(m),v);
}
LL solve()
{ 
 dp[0].clear();
 dp[0].push(0,1);
 now = 0,pre = 1;
 for(int i = 1;i<=n;i++)
 {
  pre = now;now^=1,dp[now].clear();
  for(int k = 0;k<dp[pre].size;k++)
   dp[now].push(dp[pre].sta[k]<<inc,dp[pre].sum[k]);
  for(int j = 1;j<=m;j++)
  {
   pre = now,now^=1,dp[now].clear();
   for(int k = 0;k<dp[pre].size;k++)
    DP(i,j,k);
  }
 }
 for(int i = 0;i<dp[now].size;i++)
  if(dp[now].sta[i] == 0)
   return dp[now].sum[i];
 
 return 0;
}
int main(int argc, char *argv[])
{
    //freopen("ural1519.in","r",stdin);
    //freopen("ural1519.out","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
     for(int i = 1;i<=n;i++)
      scanf("%s",&gp[i][1]);
     fx = fy = 0;
     for(int i = n;i>0 &&!fx;i--)
      for(int j=m;j>0&&!fx;j--)
       if(gp[i][j] == '.')
        fx = i,fy = j;
      if(fx == 0)
       puts("0");
      else
       printf("%I64d",solve());
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
