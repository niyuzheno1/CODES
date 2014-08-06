#include "mode.h"
#include "data.h"
#define MN 400010
typedef long long LL;
typedef pair<LL,LL> pLL;
typedef vector<pLL> vp;
pLL operator - (pLL a,pLL b) {return MP(a.X-b.X,a.Y-b.Y);}
//satisfy right hand to det
pLL operator * (pLL a,pLL b) 
 {
  return MP(a.X*b.Y-a.Y*b.X,a.X*b.X+a.Y*b.Y);
 }
LL det(pLL A,pLL B,pLL C) 
{
           return ((B-A)*(C-A)).X;
}

pLL a[MN],c[MN];
vp b[MN];
void refresh(int p)
{
 int x = lb(p);
 vp & d = b[p];
 int tot = 0;
 for(int i = p-x+1;i<=p;++i)
  c[++tot] = a[i];
 sort(c+1,c+1+tot);
 for(int i = 1;i<=tot;++i)
 {
  pLL & u = c[i];
  while(d.size() >= 2 && det(d[d.size()-2],u,d[d.size()-1])<0)
   d.pop_back();
 d.pb(u);
 }
}
pLL ask;
LL find(int l,int r)
{
 LL ans = -INF;
 if(l > r) return ans;
 if(r >= l)
 {
  if(r-lb(r)+1 < l) ans = (a[r]*ask).Y,ans=max(ans,find(l,r-1));
  else
  {
  vp & d = b[r];
  int _l = 0,_r = d.size();
  pLL now = MP(-ask.Y,ask.X);
  while(_l < _r)
  {
   M;
   if(mid+1<d.size()&&(now*(d[mid+1]-d[mid])).X < 0 ) _r = mid-1;
   if(mid+1<d.size()&&(now*(d[mid+1]-d[mid])).X > 0 ) _l = mid+1;
   if(mid+1<d.size()&&(now*(d[mid+1]-d[mid])).X == 0){
    for(int i = mid;i>=0;--i){
     ans =max(ans,(d[i]*ask).Y);
     if(i == 0 || (now*(d[i]-d[i-1])).X != 0) 
      break;
    }
    for(int i = mid;i<d.size();++i){
     ans =max(ans,(d[i]*ask).Y);
     if(i == d.size()-1 || (now*d[i]-d[i-1]).X != 0) break;
    }
   break;
   }
   if(mid+1 >= d.size()){
    for(int i = _l;i<=_r;++i)
     if(i < d.size())
     ans = max(ans,(d[i]*ask).Y);
    break;
   }
  }
  ans = max(ans,find(l,r-lb(r)));
  }
 }
 return ans;
}
int n,tot;
char str[31];
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%s",&n,&str);
    for(int i = 1;i<=n;++i)
    {
     scanf("%s",&str);
     if(str[0] == 'A')
     {
      int x,y;
      scanf("%d%d",&x,&y);
      a[++tot] = MP(x,y);
      refresh(tot);
     }else{
      int x,y,z,w;
      scanf("%d%d%d%d",&x,&y,&z,&w);
      ask = MP(x,y);
      printf("%I64d\n",find(z,w));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
