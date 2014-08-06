#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define dprint(a,b) fprintf(debug,a,b);
using namespace std;
const int maxn = 1024,maxlog = 25;
int n,m,k,d,tu;
FILE * debug;
struct node
{
       int ll,rr;
       int l,r;
       int sum;
       /*int a[maxn];
       int b[maxn];*/
       void show()
       {
        dprint("ll:%d\n",ll);dprint("rr:%d\n",rr);
        dprint("l:%d\n",l)dprint("r:%d\n",r);
        dprint("sum:%d\n",sum);
        /*dprint("elements of a array:\n",0);
        for(int i = 1;i<=n;i++)
         if(a[i] != 0)
          dprint("%d ",i);*/
        dprint("\n",0);
       }
};
node tr[maxn*4];
int ra[maxlog];
int root[maxn],num;
int tot,a[maxn],b[maxn];
struct aaa
{
  int x,y;
  bool operator <(aaa a) const
  {
   return x<a.x;
  }
};
aaa c[maxn];
void init()
{
     k = 1;d=1;
     while(k <= n)
      k<<=1,d++;
     for(int i = 1;i<=n;i++){
      tr[k+i].ll = i;
      tr[k+i].rr = i;
     }
     tot = 2*k-1;
     for(int i = k-1;i>=1;i--){
      int l = 2*i,r = 2*i+1;
      int ll = 0,rr = 0;
      if(tr[l].ll != 0)
       ll = tr[l].ll,tr[i].l=l;
      else if(tr[r].ll != 0)
       ll = tr[r].ll,tr[i].l=0;
      if(tr[r].rr != 0)
       rr = tr[r].rr,tr[i].r=r;
      else if(tr[l].rr != 0)
       rr = tr[l].rr,tr[i].r=0;
      tr[i].ll = ll;
      tr[i].rr = rr;
     }
}
void print()
{
     for(int i = 1;i<=k+n;i++){
      dprint("Interval tree %d:\n",i);
      tr[i].show();
     }
}

void print2(int x)
{
     for(int i = x;i>x-d;i--){
      dprint("Interval tree %d:\n",i);
      tr[i].show();
     }
}

void cpy(int * a,int * b)
{
     for(int i = 1;i<=n;i++)
      a[i] = b[i];
}

int ins(int x){
 tot++;
 tr[tot].l = tr[x].l;tr[tot].r = tr[x].r;
 tr[tot].ll = tr[x].ll;tr[tot].rr = tr[x].rr;
 tr[tot].sum = tr[x].sum;
 return tot;
}

void trace(int u,int x)
{
  int o = 1;
  while(u != 0)
  {
   ra[o] = u;o++;
   if(tr[tr[u].l].rr >= x)
    u = tr[u].l;
   else
    u = tr[u].r;
  }
}

void insert(int l)
{
  trace(root[num],l);
  int last = 0;
  for(int i = d;i>=1;i--)
  {
   int u = ra[i];
   int now = ins(u);
   if(last != 0)
   {
    if(tr[u].l == 0)
     tr[now].r = last;
    else if(tr[last].rr <= tr[tr[u].l].rr)
     tr[now].l = last;
    else
     tr[now].r = last;
   }
   tr[now].sum++;
   /*for(int i = 1;i<=n;i++)
    tr[now].b[i] = tr[now].b[i-1]+tr[now].a[i];*/
   last = now;
  }
  num++;
  root[num] = last;
 //print2(root[num]);
}

int q1(int x,int z)
{
    while(true)
    {
     int next = 0,nextz = 0;;
     if(tr[x].l != 0 && tr[tr[x].l].sum >= z)
      next = tr[x].l,nextz = z;
     if(tr[x].l != 0 && tr[tr[x].l].sum < z)
      next = tr[x].r,nextz = z-tr[tr[x].l].sum;
     if(tr[x].l == 0)
      next = tr[x].r,nextz = z;
     if(tr[x].r == 0)
      next = tr[x].l,nextz = z;
     if(tr[x].l == 0 && tr[x].r == 0)
      break;
     x = next;
     z = nextz;
    }
    if(tr[x].ll != tr[x].rr || z!=1)
     return 0;
    return tr[x].ll;
}

int query(int x,int y,int z)
{
  
  return q1(root[y],z);
}
int main(int argc, char *argv[])
{
    freopen("tree.in","r",stdin);
    debug = fopen("tree.err","w");
    freopen("tree.out","w",stdout);
    scanf("%d%d",&n,&m);
    init();
    root[0]++;
    //print();
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]),c[i].x = a[i],c[i].y = i;
    sort(c+1,c+1+n);
    a[0] = -1;
    for(int i = 1;i<=n;i++){
     if(c[i].x != c[i-1].x)
      tu++,a[tu] = c[i].x;
     b[c[i].y] = tu;
    }
    for(int i = 1;i<=n;i++)
     insert(b[i]);
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",a[query(1,x,y)]);
    }
    fclose(debug);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
