#include "mode.h"
const int MN = 200010;
int mex[MN],a[MN],next[MN];
map<int,int> mp;
int n , m;
void pre(){
 for(int i = 1;i<=n;mp[a[i]]=i,++i)
  if(mp.count(a[i]))
   next[mp[a[i]]] = i-1;
  else
   next[mp[a[i]]] = n;
 mp.clear();     
 int minn = 0;
 if(a[1] == 0)++minn;
 mex[1] = minn,mp[a[1]] = 1;
 for(int i =2;i<=n;++i) {
  mp[a[i]] = 1;
  while(mp[minn])++minn;
  mex[i] = minn;
 }
}
void change(int x){
 int val = a[x];
 mex[x] = 0;
 int end = next[x];
 if(end == 0)end = n;
 for(int i = end;i>x;--i)
  if(mex[i] > val)
   mex[i] = val;
  else
   break;
}
struct qes{
 int ind,l,r;
 bool operator < (const qes & a)const{
  return l < a.l|| (l == a.l && r<a.r);
 }
};
qes q[MN];
int anss[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    for(int i = 1;i<=n;++i)a[i] =gi;
    pre();
    for(int i = 1;i<=m;++i)
     q[i].ind = i,q[i].l = gi,q[i].r = gi;
    sort(q+1,q+1+m);
    int last = 1;
    for(int i = 1;i<=m;++i)
    {
     if(q[i].l == last)
      anss[q[i].ind] = mex[q[i].r];
     else
     {
      for(int j = last;j<q[i].l;++j)
       change(j);
      anss[q[i].ind] = mex[q[i].r];
     }
     last = q[i].l;
    }
    for(int i = 1;i<=m;++i)
     printf("%d\n",anss[i]);
    closeIO();
    return EXIT_SUCCESS;
}
