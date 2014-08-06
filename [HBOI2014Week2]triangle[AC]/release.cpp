#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}


#define MN 10

#define eps 1e-3

const double m = 2.0;

typedef pair<double,double> pdd;
typedef pair<pdd,double> pddd;
pdd a[MN],b[MN];
pddd c[MN];
double ea[MN],eb[MN];
int fa[MN],fb[MN],tmp[MN],T;

int cmp(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}

pdd operator - (pdd u,pdd v)
{
    return MP(u.X-v.X,u.Y-v.Y);
}

double det(pdd u,pdd v)
{
       return u.X*v.Y-u.Y*v.X;
}

double dot(pdd u,pdd v){
 return u.X*v.X+u.Y*v.Y;
}

double abs(pdd x,pdd y)
{
       return sqr(x.X-y.X)+sqr(x.Y-y.Y);
}

double getangle(pdd u,pdd v)
{
       return dot(u,v)*(1.0/(sqrt(abs(MP(0,0),u))*sqrt(abs(MP(0,0),v))));
}

bool cmp1(int x,int y)
{
     return cmp(ea[x]-ea[y])<0;
}

bool cmp2(int x,int y)
{
     return cmp(eb[x]-eb[y])<0;
}

pddd getline(pdd u,pdd v,pdd f,pdd g,double l)
{
     return MP(MP(m*v.X-m*u.X-m*l*g.X+m*l*f.X,m*v.Y-m*u.Y-m*l*g.Y+m*l*f.Y),sqr(u.X)-sqr(v.X)+sqr(u.Y)-sqr(v.Y)-l*(sqr(f.X)-sqr(g.X)+sqr(f.Y)-sqr(g.Y)));
}

int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&T);
    while(T--){
    for(int i = 1;i<=3;++i) scanf("%lf%lf",&a[i].X,&a[i].Y),fa[i] = fb[i] = i;
    for(int i = 1;i<=3;++i) fa[i+3] = fb[i+3] = i;
    for(int i = 1;i<=3;++i) scanf("%lf%lf",&b[i].X,&b[i].Y);
    int st = 0;
    double a1 = getangle(a[fa[2]]-a[fa[1]],a[fa[3]]-a[fa[1]]);
    for(int i = 1;i<=3;++i)
    {
     double a2 = getangle(b[fb[i+1]]-b[fb[i]],b[fb[i+2]]-b[fb[i]]);
     if(cmp(a1-a2) == 0)
     {
      double a3 = getangle(a[fa[3]]-a[fa[2]],a[fa[1]]-a[fa[2]]);
      double a4 = getangle(b[fb[i+2]]-b[fb[i+1]],b[fb[i+3]]-b[fb[i+1]]);
      if(cmp(a3-a4) == 0)
       st = i;
     }
    }
    if(st)
    for(int i = 1;i<=3;++i){
     tmp[i] = fb[st];++st;
     if(st == 4) st = 1;
    }
    if(!st){
    reverse(fb+1,fb+7);
    for(int i = 1;i<=3;++i)
    {
      double a2 = getangle(b[fb[i+1]]-b[fb[i]],b[fb[i+2]]-b[fb[i]]);
       if(cmp(a1-a2) == 0)
       {
       double a3 = getangle(a[fa[3]]-a[fa[2]],a[fa[1]]-a[fa[2]]);
      double a4 = getangle(b[fb[i+2]]-b[fb[i+1]],b[fb[i+3]]-b[fb[i+1]]);
       if(cmp(a3-a4) == 0)
        st = i;
      }
     }
     for(int i = 1;i<=3;++i){
      tmp[i] = fb[st];++st;
     }
    }
    memcpy(fb,tmp,sizeof(tmp));
    double k = abs(det(a[2]-a[1],a[3]-a[1])*(1.0/det(b[2]-b[1],b[3]-b[1])));
   // sort(fa+1,fa+4,cmp1);sort(fb+1,fb+4,cmp2);
    for(int i = 1;i<=2;++i)
     c[i] = getline(a[fa[i]],a[fa[i+1]],b[fb[i]],b[fb[i+1]],k);
    double K = det(c[1].X,c[2].X);
    double xX = det(MP(-c[1].Y,c[1].X.Y),MP(-c[2].Y,c[2].X.Y));
    double xY = det(MP(c[1].X.X,-c[1].Y),MP(c[2].X.X,-c[2].Y));
    double xx = xX*(1.0/K),yy = xY*(1.0/K);
    printf("%.6f %.6f\n",xx,yy);
    }
    closeIO();
    return EXIT_SUCCESS;
}
