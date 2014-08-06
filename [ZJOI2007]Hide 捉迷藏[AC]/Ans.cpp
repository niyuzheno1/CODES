#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define gi getint()
#define LP ch[0]
#define LM ch[1]
#define RP ch[2]
#define RM ch[3]
#define tree t
#define lch l
#define rch r
#define right_plus ch[2]
#define left_minus ch[1]
#define right_minus ch[3]
#define left_plus ch[0]
using namespace std;
const int MAXN = 200100,MAXM = 200100*2,HEAD = -1,TAIL = -2,inf = 1000000;
int getint()
{
 char c = 0;int ret = 0;
 while(!isdigit(c))c = getchar();
 while(isdigit(c)){ret *= 10;ret += (c-'0');c = getchar();}
 return ret;
}
char getC()
{
 char c = 0;
 while(!((c<='z'&&c>='a')||(c<='Z'&&c>='A')))c = getchar();
 return c;
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
struct edge
{
 int n,v;
};
struct segtr
{
 int left,right,dist;
 int ch[4];
};
segtr t[MAXN*6];
edge lk[MAXM];
int st[MAXN];
int color[MAXN],tot,cnt,a[MAXN*3+1],b[MAXN];
void add1(int x,int y)
{
 tot++;lk[tot].n = st[x];lk[tot].v = y;st[x] = tot;
}
void add(int x,int y)
{
 add1(x,y);add1(y,x);
}
void dfs(int x,int y)
{
 cnt++;
 a[cnt] = HEAD;
 cnt++;
 a[cnt] = x;
 b[x] = cnt;
 for(int i = st[x];i;i=lk[i].n)
  if(lk[i].v != y)
   dfs(lk[i].v,x);
 cnt++;
 a[cnt] = TAIL;
}
void upson(int x,int y)
{
 t[x].left = (a[y]==HEAD);
 t[x].right = (a[y]==TAIL);
 t[x].dist = -inf;
 t[x].LP = t[x].LM = t[x].RP = t[x].RM = (a[y]>=0&&color[a[y]]==0)?0:-inf;
}
void update(int x)
{
 int l = x*2,r=2*x+1;
 t[x].left = t[r].left+max(t[l].left-t[r].right,0);
 t[x].right = t[l].right+max(t[r].right-t[l].left,0);
 t[x].dist = max(max(t[l].dist,t[r].dist),max(t[l].RM+t[r].LP,t[l].RP+t[r].LM));
 t[x].LM = max(t[l].LM,t[r].LM-t[l].right+t[l].left);
 t[x].LP = max(max(t[r].LP+t[l].right-t[l].left,t[r].LM+t[l].right+t[l].left),t[l].LP);
 t[x].RM = max(t[r].RM,t[l].RM+t[r].right-t[r].left);
 t[x].RP = max(max(t[l].RP-t[r].right+t[r].left,t[l].RM+t[r].right+t[r].left),t[r].RP);
}
void build(int x,int l,int r)
{
 if(l == r)
  upson(x,l);
 else
 {
  int mid = (l+r)/2;
  build(x*2,l,mid);
  build(x*2+1,mid+1,r);
  update(x);
 }
}
void modify(int x,int l,int r,int t)
{
 if(l==r)
  upson(x,l);
 else
 {
  int mid = (l+r)/2;
  if(t<=mid)
   modify(x*2,l,mid,t);
  else
   modify(x*2+1,mid+1,r,t);
  update(x);
 }
}
int main(int argc, char *argv[])
{
    setIO("Hide");
    int n = gi;
    for(int i = 1;i<=n-1;i++)
    {
     int x=gi,y=gi;
     add(x,y);
    }
    int bl = n;
    dfs(1,-1);
    build(1,1,cnt);
    int m = gi;
    for(int i = 1;i<=m;i++)
    {
     char ope = getC();
     if(ope == 'G')
     {
      if(bl == 0)
       puts("-1");
      else if(bl == 1)
       puts("1");
      else
       printf("%d\n",t[1].dist);
     }
     else
     {
      int x = gi;
      color[x]^=1;
      if(color[x])
       bl--;
      else
       bl++;
      modify(1,1,cnt,b[x]);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}

