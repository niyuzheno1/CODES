#include "mode.h"
const double eps = 10e-5;
int dblcmp(double x){
 if(abs(x) < eps) return 0;
 if(x > 0) return 1;
 else return -1;
}
int n;
const int MN = 10010;
typedef double ld;
typedef pair<ld,ld> pdd;
pdd a[MN];
int stk[MN],top,sou[MN];
vector<int> ans;
bool cmp1(pdd x,pdd y)
{
     if(dblcmp(x.X-y.X) == 0) return dblcmp(x.Y-y.Y) > 0;
     return  dblcmp(x.X-y.X) < 0;
}
bool cmp2(int x,int y)
{
     return cmp1(a[x],a[y]);
}

double getv(int li,ld x)
{
 return a[li].X*x+a[li].Y;
}
pdd inser(int li1,int li2)
{
  double dk = a[li1].X-a[li2].X;
  double db = a[li2].Y-a[li1].Y;
  double x = db/dk; 
  return MP(x,getv(li1,x));
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i) a[i].Y = gi,sou[i] = i;
    for(int i = 1;i<=n;++i) a[i].X = gi;
    sort(sou+1,sou+1+n,cmp2);
    sort(a+1,a+n+1,cmp1);
    stk[++top] = 1;
    for(int i = 2;i<=n;++i)
    {
      if(dblcmp(a[stk[top]].X-a[i].X) == 0) continue;
      while(top)
      {
       pdd pu = inser(stk[top],i);
       if(pu.X<0) --top;
       else if(top >= 2 && pu.Y<getv(stk[top-1],pu.X)) --top;
       else break;
      }
      stk[++top] = i;
    }
    for(int i = 1;i<=top;++i)
    {
     int x = stk[i];
     for(int j = x;j<=n;++j)
      if(dblcmp(a[j].X - a[x].X) != 0 || dblcmp(a[j].Y - a[x].Y) != 0)
       break;
      else
       ans.pb(sou[j]);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i = 0;i<ans.size()-1;++i)
     printf("%d ",ans[i]);
    printf("%d\n",ans[ans.size()-1]);
    closeIO();
    return EXIT_SUCCESS;
}
