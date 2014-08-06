#include <cstdlib>
#include <iostream>
#include <complex>
#include <vector>
#include <map>
#define X first
#define Y second
using namespace std;
const int maxn = 300010;
typedef complex<double> ci;
typedef pair<int,int> ii;
double det(ci a,ci b)
{
    return imag(a*conj(b));
}
ci p[maxn];
double f[2][maxn];
bool t[maxn];
int n,d;
double re(ii a)
{
 return det(p[a.Y],p[a.X])/(imag(p[a.X])-imag(p[a.Y]));
}
void up(ii & a,int b)
{
  if(re(a) < re(ii(a.X,b)))
   a.Y = b;
}
int main(int argc, char *argv[])
{
    scanf("%d%d",&n,&d);
    for(int i = 1;i<=n;i++){
    double x=0,y=0;
    scanf("%d%lf%lf",&t[i],&x,&y);
    p[i] = ci(x,y);
    }
    n++;
    p[n] = ci(d,0);
    n++;
    for(int k = 0;k<2;k++){
     vector<ii> v;
     for(int i = 0;i<n-1;i++)
     {
     for(;v.size()&&imag(p[v.back().X])<imag(p[i]);v.pop_back());
      if(v.size())
       for(up(v.back(),i);v.size()>1;v.pop_back())
       {
        up(v[v.size()-2],i);
        if(re(v[v.size()-2]) < re(v.back()))
          break;
       }
      if(t[i])
       v.push_back(ii(i,i+1)),f[k][i] = real(p[i]);
      else
      {
       f[k][i]=real(p[i+1]);
       if(v.size())
        f[k][i] = min(re(v.back()),real(p[i+1]));
      }
     }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
