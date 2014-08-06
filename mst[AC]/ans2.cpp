#include "mode.h"
#define MM 10000001
#define MN 100000
#define MH 10007
#define ML 10000000
typedef long long LL;
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
const LL MAXINT64 =~0ULL>>1;
typedef pair<int,pii> piii;
int prime[MM];
int t,l,x[MN],y[MN];
vector<piii> hsh[MH];
LL val[MN];
struct Node
{
       int id;
       long long dist;
       Node(){}
       Node(int _id,long long _dist):id(_id),dist(_dist) {}
       bool operator <(const Node & _n)const{
        return dist + x[id]+y[id] > _n.dist + x[_n.id]+y[_n.id];
       }
};
priority_queue<Node> q;
int gcd(int a,int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
int getid(int a,int b)
{
    int tmp = (((LL)a<<32)+b)%MH;
    for(int i = 0;i<hsh[tmp].size();++i)
     if(hsh[tmp][i].Y.X==a && hsh[tmp][i].Y.Y == b)
      return hsh[tmp][i].X;
    hsh[tmp].pb(MP(l,MP(a,b)));
    x[l] = a,y[l] = b;
    val[l] = MAXINT64;
    return l++;
}
void upd(int a,int b,long long d)
{
     if(!a || !b) return;
     int id = getid(a,b);
     d += gcd(a,b);
     if(d < val[id])
      val[id] = d,q.push(Node(id,d));
}
int main()
{
    setIO();
    for(int i = 1;i<=ML;++i) prime[i] = 1;
    for(int i = 2;i<=ML;++i)
     if(prime[i])
      for(int j = i<<1;j<=ML;j+=i)
       prime[j] = 0;
    t = gi;
    while(t--)
    {
     scanf("%d%d",&x[0],&y[0]);
     if(x[0]<y[0]) swap(x[0],y[0]);
     for(int i = 0;i<10007;++i) hsh[i].clear();
     long long ans = MAXINT64;
     l = 0;
     getid(x[0],y[0]);
     val[0] = gcd(x[0],y[0]);
     q.push(Node(0,val[0]));
     while(!q.empty())
     {
      Node t = q.top();q.pop();
      int id = t.id;
      if(t.dist != val[id]) continue;
      if(prime[max(x[id],y[id])]) ans = min(ans,t.dist+x[id]+y[id]-2);
      else if(t.dist + x[id]+y[id]-2 < ans)
       for(int i = 1;i<=4;++i)
        upd(x[id]+dx[i],y[id]+dy[i],t.dist);
     }
     printf("%lld\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
