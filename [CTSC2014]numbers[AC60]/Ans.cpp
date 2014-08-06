#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define sqr(x) ((x)*(x))
#define ff fprintf
#define X first
#define Y second
#define MP make_pair
using namespace std;
typedef pair<double,int> p;
typedef pair<int,double> arcp;
typedef pair<arcp,int> arcm;
const int MAXN = 60010,MAXM = 3010,delta = 6,NEAREST = 2;
FILE *r,*d;
int n,m;
vector<p> v;
int a[29][29];
int ans[MAXN];
vector<p> in;
vector<arcm> vm;
double t[10];
int h[10];
bool cmp(arcm x,arcm y)
{
 if(x.X.X != y.X.X)
  return x.X.X< y.X.X;
 if(x.X.Y != y.X.Y)
  return x.X.Y< y.X.Y;
 
  return x.Y < y.Y;
}
int nearest(double x,int y)
{

 vm.clear();
 for(int i = 0;i<=9;i++)
  t[i] = 10e10;
 memset(h,0,sizeof(h));
 int l = y,r = y;
 for(int i = 1;i<=NEAREST;i++)
 {
  if(l >= 0 && r<v.size())
  {
   if(abs(v[l].X-x) < abs(v[r].X-x)){
    int u = v[l].Y;
    double vv = v[l].X;
    t[u] = min(t[u],abs(vv-x)),h[u]++,l--;
   }
   else{
    int u = v[r].Y;
    double vv = v[r].X;
    t[u] = min(t[u],abs(vv-x)),h[u]++,r++;
   }
  }
  else if(l >= 0){
   int u = v[l].Y;
   double vv = v[l].X;
   t[u] = min(t[u],abs(vv-x)),h[u]++,l--;
  }
  else if(r < v.size()){
   int u = v[r].Y;
   double vv = v[r].X;
   t[u] = min(t[u],abs(vv-x)),h[u]++,r++;
  }
 }
 for(int i = 0;i<=9;i++)
  if(h[i] != 0)
   vm.push_back(MP(MP(h[i],t[i]),i));
 sort(vm.begin(),vm.end(),cmp);
 return vm[0].Y; 
}
int main(int argc, char *argv[])
{
    m = 2999;
    freopen("change.in","r",stdin);freopen("numbers1.out","w",stdout);
    r = fopen("table2.txt","r");d = fopen("table1.txt","r");
    for(int i = 1;i<=m;i++)
    {
     double x;int y;
     fscanf(d,"%lf",&x);
     fscanf(r,"%d",&y);
     v.push_back(p(x,y));
    }
    sort(v.begin(),v.end());
    n = 60000;
    for(int i = 1;i<=n;i++)
    {
      double average;
      scanf("%lf",&average);
     in.push_back(p(average,i));
    }
    sort(in.begin(),in.end());
    int pos = 0;
    for(int i = 0;i<in.size();i++)
    {
     double u = in[i].X;
     while(pos+1<v.size() && v[pos].X < u)
      pos++;
     ans[in[i].Y] = nearest(in[i].X,pos);
    }
    printf("%d\n",n);
    for(int i =1;i<=n;i++)
     printf("%d\n",ans[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
