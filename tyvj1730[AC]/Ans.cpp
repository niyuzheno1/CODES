#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define L ch[0]
#define R ch[1]
using namespace std;
const int MAXN = 1000100,INF = 0x7f7f7f7f;
struct node
{
 int size,key;
 int ch[2];
};
node p[MAXN];
int tot,m,po;
void rotate(int & x,int y)
{
 int k = p[x].ch[!y];
 p[x].ch[!y] = p[k].ch[y];
 p[k].ch[y] = x;
 p[k].size = p[x].size;
 p[x].size = p[p[x].L].size+p[p[x].R].size+1;
 x = k;
}
void maintain(int & x,int y)
{
 if(!y)
 {
  if(p[p[p[x].L].L].size > p[p[x].R].size)
   rotate(x,1);
  else if(p[p[p[x].L].R].size > p[p[x].R].size)
    rotate(p[x].L,0),rotate(x,1);
  else
   return;
 }
 else
 {
  if(p[p[p[x].R].R].size > p[p[x].L].size)
   rotate(x,0);
  else if(p[p[p[x].R].L].size > p[p[x].L].size)
   rotate(p[x].R,1),rotate(x,0);
  else
   return;
 }
 maintain(p[x].L,0);
 maintain(p[x].R,1);
 maintain(x,0);
 maintain(x,1);
}
void insert(int &x,int y)
{
  if(x == 0)
  {
   x = ++tot;
   p[x].key = y;
   p[x].size = 1;
   return;
  }
  else 
  {
   p[x].size++;
   if(p[x].key > y)
    insert(p[x].L,y);
   else
    insert(p[x].R,y);
   maintain(x,!(p[x].key>y));
  }
}
int del(int & x,int y)
{
 p[x].size--;
 if((p[x].key==y) || (y < p[x].key && !p[x].L)||(y >= p[x].key && !p[x].R))
 {
   int ret = p[x].key;
   if(!p[x].L || !p[x].R)
    x = p[x].L+p[x].R;
   else
    p[x].key = del(p[x].L,p[x].key+1);
   return ret;
 }
 if(p[x].key > y)
  del(p[x].L,y);
 else
  del(p[x].R,y);
}
int rank1(int  x,int y)
{
 if(!x) return 0;
 if(y == p[x].key)
   po = 1;
 if(p[x].key >= y) return rank1(p[x].L,y);
 else return rank1(p[x].R,y)+p[p[x].L].size+1;
}
int select(int x,int y)
{
 int temp = p[p[x].L].size+1;
 if(temp == y)
  return p[x].key;
 else if(temp > y)
  return select(p[x].L,y);
 else
  return select(p[x].R,y-temp);
}
int pred(int x,int y)
{
 if(!x)
  return INF;
 if(p[x].key >= y)
  return pred(p[x].L,y);
 else
 {
  int tmp = pred(p[x].R,y);
  if(tmp == INF)
   return p[x].key;
  else
   return tmp;
 }
}
int succ(int x,int y)
{
 if(!x)
  return INF;
 if(p[x].key <= y)
  return succ(p[x].R,y);
 else
 {
  int tmp = succ(p[x].L,y);
  if(tmp == INF)
   return p[x].key;
  else
   return tmp;
 }
}
struct seg
{
 int root;
};
seg tr[MAXN];
int aa[MAXN];
int le,rig,n;

int ask1(int x,int ll,int rr,int num)
{
 if(ll>=le && rig>=rr)
 {
  return rank1(tr[x].root,num);
 }
 int mid = (ll+rr)/2;
 int now = 0;
 if(le <= mid)
  now = now+ask1(x*2,ll,mid,num);
 if(rig >= mid+1)
  now = now+ask1(x*2+1,mid+1,rr,num);
 return now;
}
void change(int x,int ll,int rr,int num)
{
 if(ll == rr)
 {
  p[tr[x].root].key = num;
  aa[le] = num;
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
  if(now == num || now == INF)
   return -1;
  return now;
 }
 now = -1;int mid = (l+r)/2;
 if(le <= mid)
  now =max(now,pre(x*2,l,mid,num));
 if(rig >= mid+1)
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
  if(now == num || now == INF)
   return INF;
  return now;
 }
 now = INF;int mid = (l+r)/2;
 if(le <=mid)
  now = min(now,suc(x*2,l,mid,num));
 if(rig >= mid+1)
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
 int mid = (ll+rr)/2;
 build(x*2,ll,mid);
 build(x*2+1,mid+1,rr);
}
int main(int argc, char *argv[])
{
    /*freopen("tyvj1730.in","r",stdin);
    freopen("tyvj1730.out","w",stdout);*/
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&aa[i]);
    build(1,1,n);
    for(int i = 1;i<=m;i++)
    {
     int x,num;
     scanf("%d",&x);
     if(x == 1)
     {
      scanf("%d%d%d",&le,&rig,&num);
      printf("%d\n",ask1(1,1,n,num)+1);
     }
     if(x == 2)
     {
      scanf("%d%d%d",&le,&rig,&num);
      printf("%d\n",get(le,rig,num));
     }
     if(x == 3)
     {
      scanf("%d%d",&le,&num);
      rig = le;
      change(1,1,n,num);
     }
     if(x == 4)
     {
      scanf("%d%d%d",&le,&rig,&num);
      printf("%d\n",pre(1,1,n,num));
     }
     if(x == 5)
     {
      scanf("%d%d%d",&le,&rig,&num);
      printf("%d\n",suc(1,1,n,num));
     }
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
