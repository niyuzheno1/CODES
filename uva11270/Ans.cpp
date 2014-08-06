#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30001,maxm = 20;
int n,m,ans;
struct 
{
 int st[maxn],lk[maxn],sta[maxn],num[maxn],size;
 void clear()
 {
  memset(st,-1,sizeof(st));
  size = 0;
 }
 void push(int x,int y)
 {
  int u = x%maxn;
  for(int i = st[u];i>=0;i=lk[i]){
   if(sta[i] == x)
    num[i]+=y;
  }
  size++;sta[size] = x;num[size] = y;
 }
}dp[2];
int code[maxm],temp[maxm];
void decode(int k,int m)
{
 for(int i = m;i>=0;i--)
 {
  code[i] = k%2;
  k>>=1;
 }
}
int encode(int m)
{
 int ret = 0;
 for(int i = 0;i<=m;i++)
 {
  ret|=code[i];
  ret<<=1;
 }
 return ret;
}
int now,pre;
void DP(int x,int y,int k,int v)
{
 k>>=1;
 decode(k,m);
 memcpy(temp,code,sizeof(code));
 if(code[m] == 0)
 {
  code[m] = 1;
  code[0] = 1;
  int u = encode(m);
  dp[pre].push(u,v);
  memcpy(code,temp,sizeof(temp));
 }
 if(code[1] == 0 )
 {
  
  code[1] = 1;
  code[0] = 1;
  int u = encode(m);
  dp[pre].push(u,v);
  memcpy(code,temp,sizeof(temp));
 }
 if(code[1] != 0 && code[m] != 0)
 {
  int u = encode(m);
  dp[pre].push(u,v);
 }
}
void solve()
{
 dp[0].clear();dp[1].clear();
  now = 1,pre = 0;
  dp[1].push((1<<m+1)-1,1);
  for(int i = 1;i<=n;i++){
   for(int j = 1;j<=m;j++)
    for(int k = 1;k<=dp[now].size;k++)
    {
     int u = dp[now].sta[k];
     int v = dp[now].num[k];
     DP(i,j,u,v);
    }
   pre ^= 1;now ^= 1;dp[pre].clear();
  }
  for(int i = 1;i<=dp[now].size;i++)
  {
   bool flag = 1;
   int u = dp[now].sta[i];
   decode(i,m);
   for(int j = m;j>=0;j--)
    if(code[j] == 0)
     flag = 0;
   if(flag)
    ans+=dp[now].num[i];
  }
}

int main(int argc, char *argv[])
{
    freopen("uva11270.in","r",stdin);
    freopen("uva11270.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    if(n < m)
     swap(n,m);
    solve();
    printf("%d\n",ans);
    return EXIT_SUCCESS;
}
