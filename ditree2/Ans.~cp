#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define dprint(a,b) fprintf(debug,a,b);
using namespace std;
int lowbit(int x)
{
    return x&(-x);
}
FILE * debug;
const int maxh = 10000010,maxn = 10000010;
struct qtype
{
   int a,b,c,d;
};
struct node
{
  int ll,rr;
  int l,r;
  int cnt;
  void show()
  {
   dprint("ll:%d\n",ll);
   dprint("rr:%d\n",rr);
   dprint("l:%d\n",l);
   dprint("r:%d\n",r);
   dprint("cnt:%d\n",cnt);
  }
};
int k,n,m,d;
qtype qu[maxh];
node heap[maxh];
int root[maxn],a[maxn],r[maxn],len,b[maxh+maxn],g[maxn];
map<int,int> f;//f:num->pos
int sym[maxn];
int tot,totq,N;
void initmode()
{
     k = 1;d=1;
     while(k <= n)
      k<<=1,d++;
     for(int i = 1;i<=n;i++){
      heap[i+k].ll = i,heap[i+k].rr = i;
      heap[i+k].l = 0;heap[i+k].r = 0;
      heap[i+k].cnt = 0;
     }
     for(int i = k-1;i>=1;i--){
      int l = 2*i,r = 2*i+1;
      if(heap[l].ll == 0)
       heap[i].ll = heap[r].ll,heap[i].l = 0;
      else
       heap[i].ll = heap[l].ll,heap[i].l = l;
      if(heap[r].rr == 0)
       heap[i].rr = heap[l].rr,heap[i].r = 0;
      else
       heap[i].rr = heap[r].rr,heap[i].r = r;
     }
     tot = k+n;
}
void print()
{
   for(int i = 1;i<=k+n;i++)
   {
    dprint("Interval tree:%d\n",i);
    heap[i].show();
   }
}
void print2(int x)
{
   dprint("root of Interval jungle:%d\n",x);
   for(int i = x;i>=x-d+1;i--)
   {
    dprint("Interval tree:%d\n",i);
    heap[i].show();
   }
}
void trace(int x,int y)
{
     for(int i = 1;i<=d;i++)
     {
      r[i] = x;
      if(i == d)
       break;
      int l = heap[x].l,r=heap[x].r;
      if(l != 0 && heap[l].rr >= y)
       x = l;
      else
       x = r;
     }
}
int separate(int x,int y,int z)
{
    trace(x,y);
    for(int i = d;i>=1;i--)
    {
     tot++;
     memcpy(&heap[tot],&heap[r[i]],sizeof(node));
     heap[tot].cnt+=z;
     if(i != d)
     {
     int ll = heap[r[i]].l;
     int rr = heap[r[i]].r;
     if(ll != 0 && heap[ll].rr >= y)
      heap[tot].l = tot-1;
     else
      heap[tot].r = tot-1;
     }
    }
    return tot;
}
void insert(int x,int y,int z)
{
     while(x<=N)
     {
      root[x] = separate(root[x],y,z);
      //print2(root[x]);
      x+=lowbit(x);
     }
}
int prefixsum()
{
    int ans = 0;
    for(int i = 1;i<=len;i++){
     int l = heap[r[i]].l;
     ans+= sym[i]*heap[l].cnt;
    }
    return ans;
}
void goleft()
{
     for(int i =1;i<=len;i++)
      r[i]=heap[r[i]].l;
}
void goright()
{
     for(int i =1;i<=len;i++)
      r[i]=heap[r[i]].r;
}
int query(int x,int y,int z)
{
     len = 0;x--;
     while(x > 0)
     {
      len++;
      r[len] = root[x];
      sym[len] = -1;/*coefficient*/
      x-=lowbit(x);
     }
     while(y > 0)
     {
      len++;
      r[len] = root[y];
      sym[len] = 1;/*coefficient*/
      y-=lowbit(y);
     }
     for(int i = 1;i<=d-1;i++){
      int now = prefixsum();
      if(z > now)
       z-=now,goright();
      else
       goleft();
     }
     return heap[r[1]].ll;
}


int main(int argc, char *argv[])
{
    freopen("tree.in","r",stdin);
    debug = fopen("tree.err","w");
    freopen("tree.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
     root[i] = 1,scanf("%d",&a[i]);b[i]=a[i];
     totq++;
     qu[totq].a = 1;// 1 <=> insert,2<=>change,3<=>query
     qu[totq].b = i;
     qu[totq].c = a[i];
    }
    int u = n;
    for(int i = 1;i<=m;i++){
      char c[5];
      scanf("%s",c);
      if(c[0] == 'C')
      {
       int x,y;
       scanf("%d%d",&x,&y);
       totq++;
       qu[totq].a = 2;
       qu[totq].b = x;
       qu[totq].c = y;
       u++;
       b[u] = y;
      }
      else
      {
       int x,y,z;
       scanf("%d%d%d",&x,&y,&z);
       totq++;
       qu[totq].a = 3;
       qu[totq].b = x;
       qu[totq].c = y;
       qu[totq].d = z;
      }
    }
    sort(b+1,b+1+u);
    int x = 0;
    for(int i = 1;i<=u;i++)
     if(b[i] != b[i-1])
     {
      x++;
      f[b[i]] = x;
      g[x] = b[i];
     }
    N = n;
    n = x;
    for(int i = 1;i<=totq;i++)
     if(qu[i].a != 3)
      qu[i].c = f[qu[i].c];
    for(int i = 1;i<=N;i++)
     a[i] = f[a[i]];
    tot = 0;
    initmode();//print();
    for(int i = 1;i<=totq;i++)
    {
     if(qu[i].a == 1)
      insert(qu[i].b,qu[i].c,1);
     if(qu[i].a == 2)
     {
      insert(qu[i].b,a[qu[i].b],-1);
      a[qu[i].b] = qu[i].c;
      insert(qu[i].b,a[qu[i].b],1);
     }
     if(qu[i].a == 3)
      printf("%d\n",g[query(qu[i].b,qu[i].c,qu[i].d)]);
    }
    fclose(debug);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
