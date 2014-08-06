#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define L ch[0]
#define R ch[1]
#define F ch[2]
using namespace std;
typedef char ss[11];
const int MAXN = 251000;

struct hanode
{
 int n,w;
 ss str;
};
ss s;
struct node
{
 int ch[3],size,w;
 ss name;
 node()
 {
  L = R = F = 0;
  memset(name,0,sizeof(name));
  w = 0;
  size = 0;
 }
 node(int _w)
  :w(_w),size(1)
 {
  ch[0] = ch[1] = ch[2] = 0;
  memcpy(name,s,sizeof(s));
 }
};
int tot,n;
node t[MAXN];
void updata(int x)
{
 if(x == 0)return;
 t[x].size = 1;
 if(t[x].L != 0)t[x].size += t[t[x].L].size;
 if(t[x].R != 0)t[x].size += t[t[x].R].size;
}
int rotate(int x)
{
 int y = t[x].F;
 int z = t[y].F;
 int d = (t[y].R == x);
 int c = (t[z].R == y);
 t[y].ch[d] = t[x].ch[!d];
 t[t[x].ch[!d]].F = y;
 t[x].ch[!d] = y;
 t[y].F = x;
 t[z].ch[c] = x;
 t[x].F = z;
 updata(y);updata(x);updata(z);
}
struct hash
{
 int st[MAXN],size;
 hanode lk[MAXN];
 int calc()
 {
  int ret = 0;
  for(int i = 0;i<strlen(s);i++)
   ret *= 10,ret %= MAXN,ret += (s[i]-'0');
  return ret;
 }
 void clear()
 {
  size = 0;
 }
 void add(int x)
 {
  int y = calc();
  for(int i = st[y];i;i=lk[i].n)
   if(strcmp(lk[i].str,s) == 0)
   {
    lk[i].w = x;
    return;
   }
  size++;memcpy(lk[size].str,s,sizeof(s));lk[size].n = st[y];lk[size].w = x;st[y] = size;
 }
 int find()
 {
  int y = calc();
  for(int i = st[y];i;i=lk[i].n)
   if(strcmp(lk[i].str,s) == 0)
    return lk[i].w;
  return 0;
 }
};
hash h;
int root;
void ins(int & x,int w)
{
 if(x == 0)
 {
  tot++;
  t[tot] = node(w);
  x = tot;
  h.add(tot);
  return;
 }
 int i = w<=t[x].w;
 ins(t[x].ch[i],w);
 t[t[x].ch[i]].F = x;
 updata(x);
 int y = t[x].ch[i];
 if(rand()%t[x].size < 1){
  rotate(y);
  x = y;
 }
 if(t[x].F == 0)
  root = x;
}
void del(int & x)
{
 int bef;
 while(1)
 {
  if(t[x].L)
   {
    bef = t[x].L;
    rotate(t[x].L);
    if(t[bef].F == 0)
     root = bef;
   }
  else if(t[x].R){
   bef = t[x].R;
   rotate(t[x].R);
   if(t[bef].F == 0)
     root = bef;
  }
  else
   break;
 }
 int p = t[x].F;
 while(p)
 {
  t[p].size--;
  p = t[p].F;
 }
 if(t[x].F !=0){
  int y = t[x].F;
  int d = t[y].R == x;
  t[y].ch[d] = 0;
 }
 if(x == root)
  root = 0;
}
int findkth(int x,int y)
{
 int ls = t[t[x].L].size;
 if(y <= ls)
  findkth(t[x].L,y);
 else if(y == ls+1)
  memcpy(s,t[x].name,sizeof(s));
 else
  findkth(t[x].R,y-ls-1);
}
int count(int x)
{
 int ans = 1;
 ans += t[t[x].L].size;
 while(x)
 {
  int y = t[x].F;
  if(y == 0) return ans;
  if(t[y].R == x)
   ans += 1+t[t[y].L].size;
  x = t[x].F;
 }
 return ans;
}
int main(int argc, char *argv[])
{
    //freopen("rank.in","r",stdin);freopen("rank.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int w;char c=0;
     while(c != '+' && c != '?')
      scanf("%c",&c);
     switch(c)
     {
      case '+':
           {
            scanf("%s %d\n",s,&w);
            int u = h.find();
            if(u == 0)
             ins(root,w);
            else
             del(u),ins(root,w);
            break;
           }
      case '?':
           {
            scanf("%s\n",s);
            if(!isupper(s[0]))
            {
             w = strtol(s,0,10);
             int tot = min(t[root].size,w+9);
             for(int j = w;j<=tot;j++)
             {
              findkth(root,j);
              printf("%s",s);
              if( j < tot)
               printf(" ");
              else
               puts("");
             }
            }else
             printf("%d\n",count(h.find()));
           }
     }
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
