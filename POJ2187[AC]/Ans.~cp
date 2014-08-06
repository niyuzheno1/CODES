#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define ff fprintf
using namespace std;
const int maxn = 50100;
const double eps = 10e-3;
double cmp(double x)
{
 if(fabs(x) < eps)
  return 0;
 else if(x > 0)
  return 1;
 else
  return -1;
}
struct p
{
double x,y;
 p()
 {
  x = y = 0;
 }
 p(double xx,double yy)
 {
   x=xx;y=yy;
 }
 p operator -(p u)
 {
  return p(x-u.x,y-u.y);
 }
 bool operator <(p u) const
 {
  if(x == u.x)
   return cmp(y-u.y)>0;
  return cmp(x-u.x)<0;
 }
 bool comp(p u)
 {
  if(x == u.x)
   return cmp(y-u.y)<0;
  return cmp(x-u.x)<0; 
 }
 double abs()
 {
  return x*x+y*y;
 }
 double lv()
 {
  return x/y;
 }
};
int n;
FILE * d;
double det(p x,p y)
{
       double uu = (x.x*y.y-x.y*y.x);
       return uu;
}
p mp[maxn];
p h[maxn*2];
int tot = 0;

int main(int argc, char *argv[])
{
    freopen("poj2187.in","r",stdin);
    freopen("poj2187.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf",&mp[i].x,&mp[i].y);
    sort(mp+1,mp+1+n);
    stack<p> m;
    m.push(mp[1]);
    for(int i = 2;i<=n;i++)
    {
      while(m.size() >= 2)
      {
       p x = m.top();m.pop();
       p y = m.top();m.pop();
       if(cmp(det(x-y,mp[i]-y)) < 0)
        m.push(y);
       else{
        m.push(y),m.push(x);
        break;
       }
      }
      m.push(mp[i]);
    }
    int u = m.size();
    for(int i = n-1;i>=1;i--)
    {
     while(m.size() >= u+2)
     {
      p x = m.top();m.pop();
      p y = m.top();m.pop();
      if(cmp(det(x-y,mp[i]-y)) < 0)
       m.push(y);
      else{
       m.push(y),m.push(x);
       break;
      }
     }
     m.push(mp[i]);
    }
    
    while(!m.empty())
    {
     h[tot] = m.top();m.pop();
     tot++;
    }
    tot--;
    if(tot <= 2)
    {
     printf("%lf",(h[0]-h[1]).abs());
     return 0;
    }
    int j = 0;
    double ans = 0;
    int i = 0;j = 0;
    for(int k = 0;k<tot;k++){
     if(!(h[i]<(h[k])))
      i = k;
     if(h[j]<(h[k]))
      j = k;
    }
    ff(d,"%d %d\n",i,j);
    
    int si = i,sj = j;
    while(i != sj || j != si){
     ans = max(ans,(h[i]-h[j]).abs());
     if(cmp(det((h[i+1]-h[i]),(h[j+1]-h[j]))) > 0)
      i = (i+1)%tot;
     else
      j = (j+1)%tot;
    }
    printf("%.0f\n",ans);
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
