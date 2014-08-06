#include "mode.h"
#include "data.h"
const int MN = 41001000,MH = 200010,ML = 21,MK = 5010000;
int o1[MN],o2[MN],sum,tot,sm[MN],len,h[MH],an[MH][ML];
int point[MH],c[MH],son[MH],deep[MH],tim,f[MH],n,l,m;
struct
{
 int x,n;
} e[MK];
#define LEF(_t) o1[_t]
#define RIG(_t) o2[_t]
#define S(_t) sm[_t]
inline void swap(int & a,int & b)
{int c = a;a = b;b = c;}

int build(TREE)
{
 if((~_t) == 0) _t = ++tot;
 LEF(_t) = -1;RIG(_t) = -1;
 S(_t) = 0;
 if(_l != _r)
 {M;LEF(_t) = build(LEFT);RIG(_t) = build(RIGHT);}
 return _t;
}

int change(TREE,int x,int z){
  int q =0;
  if(_l == _r && _l == x)
  {
   ++tot; q = tot;
   LEF(q) = LEF(_t);RIG(q) = RIG(_t);S(q) = S(_t)+z;
   return q;
  }
  else{
   M;++tot;
   q = tot;
   LEF(q) = LEF(_t);RIG(q) = RIG(_t);S(q) = S(_t);
   _t = q;
   if(x <= mid) LEF(q) = change(LEFT,x,z); else  RIG(q) = change(RIGHT,x,z);
   S(q) = S(LEF(q))+S(RIG(q));return q;
  }
}

void query(TREE,int x,int y)
{
     if(x <= _l && _r <= y)
      sum += S(_t);
     else
     {
      M;
      if(x <= mid) query(LEFT,x,y);
      if(y > mid) query(RIGHT,x,y);
     }
}

void dfs(int dep)
{
     int tmp,k,x;
     ++len;h[len] = dep;
     tmp = 1;k = 0;
     while(tmp < len){
      an[dep][k] = h[len-tmp];
      tmp *= 2;++k;
     }
     ++tim,point[dep] = tim;
     x = dep,son[dep] = 1;
     while(e[x].n != 0){
      x = e[x].n;
      if(f[e[x].x])
      {
       f[e[x].x] = 0;
       deep[e[x].x] = deep[dep]+1;
       dfs(e[x].x);
       son[dep] += son[e[x].x];
      }
     }
     --len;
}

void ins(int kth,int key,int delta){
 int x = kth;
 for(;x<=n;x+=lb(x))
  c[x] = change(c[x],1,n,key,delta);
}

int getsum(int dep,int tx,int ty)
{
    int x = dep;sum = 0;
    for(;x;x -= lb(x))
     query(c[x],1,n,tx,ty);
    return sum;
}

int lca(int x,int y)
{
    int tmp;
    while(deep[x]<deep[an[y][0]])
    {
     tmp = 0;
     while(deep[x]<deep[an[y][tmp]])++tmp;
     if(tmp > 0) --tmp;
     y = an[y][tmp];
    }
    return y;
}

void add(int x,int y)
{
     ++l;
     e[l].x = y;e[l].n = e[x].n;e[x].n = l;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;l = n;
    for(int i = 1;i<=n-1;++i)
    {
     int x = gi,y = gi;
     add(x,y);
     add(y,x);
    }
    CLEAR(f,1);CLEAR(son,0);CLEAR(deep,0);
    f[1] = false,tim = 0,deep[1] = 1;
    dfs(1);
    tot = 0;
    int tmp = build(0,1,n);
    for(int i = 1;i<=n;++i) c[i] = tmp;
    m = gi;
    for(int i = 1;i<=m;++i)
     {
      int x = gi,y = gi;
      ins(point[x],point[y],1);
      ins(point[y],point[x],1);
     }
    int count = gi;
    while(count--)
    {
      int opt = gi,x= gi,y=gi;
      if(opt == 1)
      {
      ins(point[x],point[y],1);
      ins(point[y],point[x],1); 
      }
      if(opt == 2)
      {
      ins(point[x],point[y],-1);
      ins(point[y],point[x],-1);
      }
      if(opt == 3)
      {
       if(point[x]>point[y]) swap(x,y);
       if(point[x]+son[x]-1>=point[y]) //case 1:y belongs to x
       {
        tmp = lca(x,y);
        int x1,x2,y1,y2;
        x1 = point[tmp]-1;x2 = point[tmp]+son[tmp];
        y1 = point[y];y2 = y1 + son[y]-1;
        printf("%d\n",getsum(y2,1,x1)-getsum(y1-1,1,x1)+getsum(y2,x2,n)-getsum(y1-1,x2,n));
       }
       else{//case 2:y not belongs to x
        int x1,x2,y1,y2;
        x1 = point[x];x2 = x1 + son[x]-1;
        y1 = point[y];y2 = y1 + son[y]-1;
        printf("%d\n",getsum(y2,x1,x2)-getsum(y1-1,x1,x2));
       }
      }            
    }
    closeIO();
    return EXIT_SUCCESS;
}
