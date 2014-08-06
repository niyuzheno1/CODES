#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define zero(p) memset(p,0,sizeof(p));
#define zero1(m) m.clear();
#define pb push_back
#define itor iterator
#define mset multiset
#define rep(i,n) for(int i = 0;i<(n);i++)
#define mpr(x,y) make_pair(x,y);
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
bool vis[10010];
int r[10010],d[10010],w[10010];
int nw[10010];
int n;
vector<p> tim;
bool ok(int x,int n)
{
 mset<p> mm;
 mset<p>::iterator l;
 memset(vis,0,sizeof(vis));
 memcpy(nw,w,sizeof(w));
 int last = 0;
 rep(i,tim.size()-1)
 {
  int nn = tim[i+1].X - tim[i].X;
  int id = tim[i].Y;
  nn = nn*x;
  if(vis[id]){
   l = find(mm.begin(),mm.end(),p(d[id],id));
   if(l != mm.end())
   mm.erase(l);
  }
  else
  {
   mm.insert(p(d[id],id));
   vis[id] = true;
  }
  while(true)
  {
   if(nn <= 0)
    break;
   if(mm.empty())
    break;
   l = mm.begin();
   id = (*l).Y;
   if(nw[id] >= nn){
    nw[id] -= nn; nn =0;
    if(nw[id] == 0)
     mm.erase(l);
   }
   else
   {
    
    nn -= nw[id];nw[id] =0;
    mm.erase(l);
   }
  }
 }
 rep(i,n)
  if(nw[i] != 0)
   return false;
 return true;
}
int T;
int main(int argc, char *argv[])
{
scanf("%d",&T);
while(T--){
zero(vis)
zero(r)
zero(d)
zero(w)
zero(nw)
zero1(tim)
    scanf("%d",&n);
    rep(i,n){
     scanf("%d%d%d",&r[i],&d[i],&w[i]);
     tim.pb(p(r[i],i));
     tim.pb(p(d[i],i));
    }
    sort(tim.begin(),tim.end());
    int l = 0,r = 10000000;
    while(l<r)
    {
     int mid = (l+r)/2;
     if(ok(mid,n))
      r = mid;
     else
      l = mid+1;
     
    }
    printf("%d\n",(l+r)/2);
}
    
    return EXIT_SUCCESS;
}

