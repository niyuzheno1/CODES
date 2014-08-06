#include "mode.h"
#include "data.h"
#define du debug
#define MN 400010
typedef long long LL;
typedef pair<LL,LL> pLL;
typedef vector<pLL> vp;
pLL operator - (pLL a,pLL b) {return MP(a.X-b.X,a.Y-b.Y);}
pLL operator * (pLL a,pLL b) 
 {
             return MP(a.X*b.Y-a.Y*b.X,a.X*b.X+a.Y*b.Y);
 }
LL det(pLL A,pLL B,pLL C) 
{
           LL res = ((B-A)*(C-A)).X;
           return res;
}
vp test,test1;
void dpri1()
{
     int n = 10;
     for(int i = 1;i<=n;++i)
     {
      int sign = (rand()%2)?1:-1;
      int num = rand()%10;
      int sign1 = (rand()%2)?1:-1;
      int num1 = rand()%10;
      test.pb(MP(sign*num,sign1*num1));
     }
     sort(test.begin(),test.end());
     int u = unique(test.begin(),test.end())-test.begin();
     for(int i = 0;i<u;++i)
     {
      pLL now = test[i];
      while(test1.size() > 1 && det(test1[test1.size()-2],now,test1[test1.size()-1])<0)
       test1.pop_back();
      test1.pb(now);
      }
     ff(du,"list point(s):\n");
     for(int i = 0;i<test.size();++i)
      ff(du,"(%I64d,%I64d)",test[i].X,test[i].Y);
     ff(du,"\nconvex hull point(s):\n");
     for(int i = 0;i<test1.size();++i)
      ff(du,"(%I64d,%I64d)",test1[i].X,test1[i].Y);
     int _l = 0,_r = test1.size()-1;
     pLL now = MP(-4,1);
     while(_l<_r)
     {
     M;
     if(mid == 0 || mid == test1.size()-1) break;
     if((now*(test1[mid+1]-test1[mid])).X == 0 && (now*(test1[mid]-test1[mid-1])).X == 0) break;
     if((now*(test1[mid+1]-test1[mid])).X > 0 && (now*(test1[mid]-test1[mid-1])).X < 0)
     {_l = _r = mid;break;}
     if((now*(test1[mid+1]-test1[mid])).X < 0) _l = mid+1;
	 else _r = mid-1;
     }
     ff(du,"\navailable point(s):\n");
     for(int i = min(_l,_r);i<=max(_l,_r);++i)
      ff(du,"(%I64d,%I64d)",test1[i].X,test1[i].Y);
}

int main()
{
    srand(time(0));
    setIO("sample");
    dpri1();
    closeIO();
    return 0;
}
