#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define L ch[0]
#define R ch[1]
using namespace std;

const int INF = 1000000000,maxn = 2000005;
int N,T,tot;
struct node
{
 int size,key;
 int ch[2];
};
node p[maxn];
void rotate(int & t,int u)
{
 int k = p[t].ch[!u];
 p[t].ch[!u] = p[k].ch[u];
 p[k].ch[u] = t;
 p[k].size = p[t].size;
 p[t].size = p[p[t].L].size+p[p[t].R].size+1;
 t = k;
}
void maintain(int &t,bool flag)
{
     if(!flag)
     {
      if(p[p[p[t].L].L].size > p[p[t].R].size)
       rotate(t,1);
      else if(p[p[p[t].L].R].size > p[p[t].R].size)
       rotate(p[t].L,0),rotate(t,1);
      else
       return;
     }
     else
     {
      if(p[p[p[t].R].R].size > p[p[t].L].size)
       rotate(t,0);
      else if(p[p[p[t].R].L].size > p[p[t].L].size)
       rotate(p[t].R,1),rotate(t,0);
      else
       return;
     }
     maintain(p[t].L,0);
     maintain(p[t].R,1);
     maintain(t,0);
     maintain(t,1);
}
void insert(int & t,int v)
{
     if(!t)
     {
      t = ++tot;
      p[t].size = 1;
      p[t].L = p[t].R = 0;
      p[t].key = v;
     }
     else
     {
      p[t].size++;
      if(v < p[t].key)
       insert(p[t].L,v);
      else
       insert(p[t].R,v);
      maintain(t,v>=p[t].key);
     }
}
int Delete(int & t,int v)
{
 p[t].size--;
 if((p[t].key == v) || (v<p[t].key && !p[t].L)|| (v >= p[t].key && !p[t].R))
 {
  int ret = p[t].key;
  if(!p[t].L || !p[t].R)
   t = p[t].L+p[t].R;
  else
   p[t].key = Delete(p[t].L,p[t].key+1);
  return ret;
 }
 if(v < p[t].key)
  Delete(p[t].L,v);
 else
  Delete(p[t].R,v);
}
int Rank(int t,int v)
{
   if(!t) return 0;
   if(v <= p[t].key) return Rank(p[t].L,v);
   else return (p[p[t].L].size+1+Rank(p[t].R,v));
}
int Select(int t,int v)
{
 int temp = p[p[t].L].size+1;
 if(temp == v)
  return p[t].key;
 if(v <= temp)
  return Select(p[t].L,v);
 else
  return Select(p[t].R,v-temp);
}
int Pred(int t,int v)
{
    if(!t) return INF;
    if(v <= p[t].key)
     return Pred(p[t].L,v);
    else
    {
     int temp = Pred(p[t].R,v);
     if(temp == INF)return p[t].key;
     else return temp;
    }
}
int Succ(int t,int v)
{
 if(!t) return INF;
 if(v >= p[t].key)
  return Succ(p[t].R,v);
 else
 {
  int temp = Succ(p[t].L,v);
  if(temp == INF) return p[t].key;
  else
   return temp;
 }
}
int main(int argc, char *argv[])
{
    //freopen("tyvj1728.in","r",stdin);
    //freopen("tyvj1728.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--)
    {
     int op,x;
     scanf("%d%d",&op,&x);
     if(op == 1) insert(T,x);
     if(op == 2) Delete(T,x);
     if(op == 3) printf("%d\n",Rank(T,x)+1);
     if(op == 4) printf("%d\n",Select(T,x));
     if(op == 5) printf("%d\n",Pred(T,x));
     if(op == 6) printf("%d\n",Succ(T,x));
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
