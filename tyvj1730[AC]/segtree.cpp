#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define L ch[0]
#define R ch[0]
using namespace std;
const int MAXN = 100010;
int le,rig,n;
struct tree
{
 int key,size;
 int ch[2];
};
tree p[MAXN];
struct seg
{
 int root;
};
seg tr[MAXN];
int aa[MAXN];
int tot;
bool po;
int rank(int x,int y)
{
 return 0;
}
void insert(int x,int y)
{
}
void del(int x,int y)
{
}
int ask1(int x,int ll,int rr,int num)
{
 if(ll>=le && rig>=rr)
 {
  return rank(tr[x].root,num);
 }
 int mid = (ll+rr)/2;
 int now = 0;
 if(le <= mid)
  now = now+ask1(x<<1,ll,mid,num);
 if(rig >= mid+1)
  now = now+ask1(x<<1+1,mid+1,rr,num);
 return now;
}
void change(int x,int ll,int rr,int num)
{
 if(ll == rr)
 {
  p[tr[x].root].key = num;
  return;
 }
 del(tr[x].root,aa[le]);
 insert(tr[x].root,num);
 int mid = (ll+rr)/2;
 if(le <= mid)
  change(x*2,ll,mid,num);
 if(rig >= mid+1)
  change(x*2+1,mid+1,rr,num);
}
int get(int left,int right,int num)
{

 int x = tr[1].root;po = false;
 int ans = 0;
 int now = ask1(1,1,n,p[x].key)+1;
 while(x != 0)
 {
  if(now <= num)
  {
   if(po) ans = p[x].key;
   if(now == num && po)
    break;
   if(x != p[x].R)
   {
    po = false;now = ask1(1,1,n,p[p[x].R].key)+1;
   }
   x = p[x].R;
  }
  else{
   if(x != p[x].L)
   {
    po = false;now = ask1(1,1,n,p[p[x].L].key)+1;
   }
   x = p[x].L;
  }
 }
 return ans;
}
int pre(int x,int l,int r,int num)
{
 int now;
 if(le <= l && rig >= r)
 {
  now = pred(tr[x].root,num);
  if(now == num)
   return -1;
  return now;
 }
 now = -1;int mid = (l+r)/2;
 if(le <= mid)
  now =max(now,pre(x*2,l,mid,num));
 if(right >= mid+1)
  now = max(now,pre(x*2+1,mid+1,r,num));
 if(now == num)
  now = -1;
 return now;
}
int suc(int x,int l,int r,int num)
{
 int now;
 if(le <= l && rig >= r)
 {
  now = succ(tr[x].root,num);
  if(now == num)
   return INF;
  return now;
 }
 now = INF;mid = (l+r)/2;
 if(left <=mid)
  now = min(now,suc(x*2,l,mid,num));
 if(right >= mid+1)
  now = min(now,suc(x*2+1,mid+1,r,num));
 return now;
}
void build(int x,int ll,int rr)
{
 if(ll == rr)
 {
  tot++;
  tr[x].root = tot;
  p[tot].key = aa[ll];
  p[tot].size = 1; 
  return;
 }
 for(int i = ll;i<=rr;i++)
  insert(tr[x].root,aa[i]);
 mid = (ll+rr)/2;
 build(x*2,ll,mid);
 build(x*2+1,mid+1,rr);
}
int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
