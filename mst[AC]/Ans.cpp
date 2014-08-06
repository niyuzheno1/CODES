#include "mode.h"
#define MH 100007
#define MS 10000101
#define MN 10000001
typedef long long LL;
#include "hash.h"
int syst,T;
hash mp;
int p[MN],prime[MN],tot,ans;
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
typedef pair<int,pii> piii;
void init()
{
 for(int i = 2;i<=MN-1;++i)
 {
  if(!prime[i]) ++tot,p[tot] = i;
  for(int j = 1;j<=tot;++j)
  {
   if(LL(LL(i) * LL(p[j])) >= LL(MN)) break;
   prime[i * p[j]] = 1;
   if(i % p[j] == 0) break;
  }
 }
}
int gcd(int x,int y){if(y == 0) return x;return gcd(y,x%y);}
bool REC(int x,int y)
{
     return x>0&&y>0&&x<MN&&y<MN;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    T = gi;
    init();
    while(T--){
     ++syst;
     mp.init(syst);
     int x = gi , y = gi;
     if(x == 1 && y == 1){
      puts("1");continue;
     }
     mp.push(pii(x,y),1);
     priority_queue<piii,vector<piii>,greater<piii> > q;
     ans = INF;
     q.push(MP(gcd(x,y)+x+y-2,MP(x,y)));
     while(!q.empty())
     {
      piii uX = q.top();q.pop();
      if(!prime[max(uX.Y.X,uX.Y.Y)])
         ans = uX.X;
      if(uX.X >= ans) break;
      pii u = uX.Y;
      for(int i = 1;i<=4;++i)
       if(REC(u.X+dx[i],u.Y+dy[i]) && mp.find(MP(u.X+dx[i],u.Y+dy[i])) == -1)
       {
        int ret = uX.X+gcd(u.X+dx[i],u.Y+dy[i])-u.X-u.Y+2;
        mp.push(MP(u.X+dx[i],u.Y+dy[i]),ret);
        q.push(MP(ret+u.X+dx[i]+u.Y+dy[i]-2,MP(u.X+dx[i],u.Y+dy[i])));
       }
     }
     printf("%d\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
