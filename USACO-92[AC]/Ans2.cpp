#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int u[9][9];
int b[34];
int c[64][64];
void dec(int x,u & y)
{
 int n = 4,now = 0;
 for(int i = 0;i<n;i++)
  y[i][i] = 0;
 for(int i = 0;i<n;i++)
  for(int j = i+1;j<n;j++){
   if((x & (1<<(now))))
    y[i][j] = y[j][i] = 1;
   else
    y[i][j] = y[j][i] = 0;
   now++;  
  }
}
void cod(int & x,u y)
{
 x = 0;
 int n = 4,now = 0;
 for(int i = 0;i<n;i++)
  for(int j = i+1;j<n;j++){
    if(y[i][j])
    x |= (1<<now);
   now++;
  }
}
void floyd(u & x,int n)
{
 for(int k = 0;k<n;k++)
  for(int i = 0;i<n;i++)
   for(int j = 0;j<n;j++)
    if(x[i][k] && x[k][j])
     x[i][j] = 1;
}
void f4(u & x)
{
     floyd(x,4);
}
void f8(u & x)
{
     floyd(x,8);
}
int ba(int x)
{
     u a;
     int ret = 0;
     memset(a,0,sizeof(a));
     if(x & (1<<0))
      a[0][1] = a[1][0] = 1;
     if(x & (1<<1))
      a[2][3] = a[3][2] = 1;
     if(x & (1<<2))
      a[0][2] = a[2][0] = 1;
     if(x & (1<<3))
      a[1][3] = a[3][1] = 1;
     f4(a);
     cod(ret,a);
     return ret;
}
void show(u x,int n)
{
 for(int i = 0;i<n;i++){
  for(int j = 0;j<n;j++)
   printf("%d ",x[i][j]);
  printf("\n");
 }
}
void show8(u y)
{
  show(y,8);
}
void show4(u y)
{
  show(y,4);
}
int com(int x,int y)
{
 u a,b,c;
 int ret = 0;
 memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
 dec(x,a);dec(y,b);
 for(int i = 0;i<4;i++)
  for(int j = 0;j<4;j++){
   c[i][j] = a[i][j];
   c[i+4][j+4] = b[i][j];
  }
 c[1][4] = c[4][1] = 1;
 c[3][6] = c[6][3] = 1;
 f8(c);
 for(int i = 0;i<4;i++)
  for(int j = 0;j<4;j++){
   int ni = i,nj = j;
   if(ni % 2 == 1) ni += 4;
   if(nj % 2 == 1) nj += 4;
   a[i][j] = c[ni][nj]; 
  }
 //show8(c);
 //show4(a);
 cod(ret,a);
 return ret;
}
void init()
{
     for(int i = 0;i<16;i++)
      b[i] = ba(i);
     /*for(int i = 0;i<16;i++)
      printf("%d\n",b[i]);*/
     for(int i = 0;i<64;i++)
      for(int j = 0;j<64;j++)
       c[i][j] = com(i,j);
     /*for(int i = 0;i<64;i++){
      for(int j = 0;j<64;j++)
       printf("%d ",c[i][j]);
      printf("\n");
     }*/
}
int o[50000*4];
int n;
struct seg
{
 struct note
 {
  int l,r;
  int s;
  int t;
 };
 note t[50000*4];
 int m;
 void build(int x)
 {
  m = 1;
  while(m <= x)
   m <<= 1;
  for(int i = m+1;i<=m+x-1;i++)
  {
   t[i].l = i-m;
   t[i].r = i-m-1;
   t[i].s = 0;
   t[i].t = b[0];
  }
  for(int i = m;i>=1;i--)
  {
   int l = 2*i;
   int r = 2*i+1;
   if(t[l].l == 0)
    t[i].l = t[r].l,t[i].r = t[r].r;
   if(t[r].r == 0)
    t[i].l = t[l].l,t[i].r = t[l].r;
   if(t[l].l != 0 && t[r].r != 0)
    t[i].l = t[l].l,t[i].r = t[r].r;
   t[i].t = c[t[l].t][t[r].t];
  }
 }
 void change(int x,int r1,int c1,int r2,int c2,bool open)
 {
  if(x == m+2)
   x = m+2;
  int id = 0;
  if(r1 == r2)
   id = r1;
  else if(c1 == t[x].l)
   id = 2;
  else
   id = 3;
  if(open == 0){
   if(t[x].s & (1<<id))
    t[x].s ^= (1<<id);
  }else
   t[x].s |= (1<<id);
  t[x].t = b[t[x].s];
 }
 void updata(int x)
 {
  int l = x*2,r = x*2+1;
  if(t[l].l == 0)
   t[x].t = t[r].t;
  if(t[r].l == 0)
   t[x].t = t[l].t;
  if(t[l].l != 0 && t[r].l != 0)
   t[x].t = c[t[l].t][t[r].t];
 }
 void up(int x)
 {
  int y = 0,z = (x>>1);
  while(z > 0)
   z>>=1,y++;
  for(int i = 1;i<=y;i++)
   updata(x>>i);
 }
 void modify(int r1,int c1,int r2,int c2,bool open)
 {
  if(r1 == r2)
   change(m+c1,r1,c1,r2,c2,open),up(m+c1);
  else{
   change(m+c1,r1,c1,r2,c2,open),up(m+c1);
   if(c1-1 != 0)
   change(m+c1-1,r1,c1,r2,c2,open),up(m+c1-1);
  }
 }
 void sum(int & x,int y,int & z,bool left)
 {
  if(z == 1){
   if(left == 1)
   x = c[x][y];
   else
   x = c[y][x];
  }
  else
  {
   x = y;
   z = 1;
  }
 }
 int find(int c1,int c2)
 {
  int l = m+c1-1,r = m+c2;
  int ll = l,rr = r;
  int la = 0,lb = 0;
  int ra = 0,rb = 0;
  while(true)
  {
   if((l^r) == 1)
    break;
   if((l & 1)== 0)
   {
    sum(la,t[l+1].t,lb,1);
    l++;
   }
   if((r & 1) == 1)
   {
    sum(ra,t[r-1].t,rb,0);
    r--;
   }
   l>>=1,r>>=1;
  }
  if(lb == 1 && rb == 1)
   return c[la][ra];
  else if(lb == 1)
   return la;
  else if(rb == 1)
   return ra;
  else
  {
   u a;
   memset(a,0,sizeof(a));
   a[0][1] = a[1][0] = 1;
   a[3][2] = a[2][3] = 1;
   if(o[c1])
   {
    a[0][2] = a[2][0] = 1;
    a[3][1] = a[1][3] = 1;
   }
   f4(a);
   int ret = 0;
   cod(ret,a);
   return ret;
  }
 }
};
seg t;
char sta[51];
u pa;
int main(int argc, char *argv[])
{
    //freopen("traffic.in","r",stdin);
    //freopen("traffic.out","w",stdout);
    init();
    scanf("%d",&n);
    t.build(n);
    while(true)
    {
      int r1,c1,r2,c2;
      scanf("%s%d%d%d%d",&sta,&r1,&c1,&r2,&c2);
      r1--;r2--;
      if(sta[0] == 'E')
       break;
      if(c1 > c2)
       swap(c1,c2),swap(r1,r2);
      if(sta[0] == 'A')
      {
       int l=0,r =0;
       int g = t.find(1,c1);
       dec(g,pa);
       if(pa[1][3])
        l = 1;
        g = t.find(c2,n);
       dec(g,pa);
       if(pa[0][2])
        r = 1;
        g = t.find(c1,c2);
       dec(g,pa);
       if(l == 1)
        pa[0][2] = pa[2][0] = 1;
       if(r == 1)
        pa[1][3] = pa[3][1] = 1;
       f4(pa);
       l = 2*r1;r = 2*r2+1;
       printf("%c\n",(pa[l][r] == 1)?'Y':'N');
      }
      else
      {
       if(sta[0] == 'O'){
        if(c1 == c2)
         o[c1] = 1;
        t.modify(r1,c1,r2,c2,1);
       }
       else{
        if(c1 == c2)
         o[c1] = 0;
        t.modify(r1,c1,r2,c2,0);
       }
      }
      
    }
    //fclose(stdin);
    //fclose(stdout);
    return EXIT_SUCCESS;
}
