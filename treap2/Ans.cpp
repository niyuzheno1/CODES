#include <cstdlib>
#include <iostream>
#define dprint(x,y) fprintf(debug,x,y)
using namespace std;
const int maxn = 100010;
FILE * debug;
typedef int sret[2];
struct node
{
 int l,r,k,v,s;
 node()
 {
 k = rand();
 }
 void print()
 {
  dprint("left:%d\n",l);
  dprint("right:%d\n",r);
  dprint("random:%d\n",k);
  dprint("value:%d\n",v);
  dprint("size:%d\n",s);
 }
};
node t[maxn];
int tot,n;
int root;
void updata(int x)
{
     t[x].s = t[t[x].l].s+t[t[x].r].s+1;
}
void spl(int x,int y,int & l,int & r)
{
     if(x == 0)
      return ;
     int u = ++tot;
     memcpy(&t[u],&t[x],sizeof(node));
     l = t[u].l;r = t[u].r;
     if(t[t[u].l].s>y)
     {
      int xx = 0,yy = 0;
      spl(t[u].l,y,xx,yy);
      t[u].l = yy;
      updata(u);
      l = xx,r = tot;
     }
     else{
      int xx = 0,yy = 0;
      spl(t[u].r,n-y-1,xx,yy);
      t[u].r = xx;
      updata(u);
      l = tot,r = yy;
     }
}
/*
  Note : Be sure Tx < Ty then use this function.
*/
int mer(int x,int y)
{
    if(x == 0)
    {
     tot++;
     memcpy(&t[tot],&t[y],sizeof(node));
     return tot;
    }
    if(y == 0)
    {
     tot++;
     memcpy(&t[tot],&t[x],sizeof(node));
     return tot;
    }
    if(t[x].k < t[y].k)
    {
     int u = ++tot;
     memcpy(&t[tot],&t[x],sizeof(node));
     t[u].r = mer(t[u].r,y);
     updata(u);
     return u;
    }
    else
    {
     int u = ++tot;
     memcpy(&t[tot],&t[y],sizeof(node));
     t[u].l = mer(x,t[u].l);
     updata(u);
     return u;
    }
}
int findkth(int x,int y)
{
    if(x == 0)
     return 0;
    if(y>t[x].v)
     return t[t[x].l].s+1+findkth(t[x].r,y);
    else
     return findkth(t[x].l,y);
}
int insert(int x,int y)
{
     if(x == 0)
     {
      tot++;
      t[tot].v = y;
      t[tot].s = 1;
      return tot;
     }
     int v = ++tot;
     t[v].v = y;
     t[v].s = 1;
     int u = findkth(x,y);
     int xx = 0,yy=0;
     spl(x,u,xx,yy);
     updata(xx);updata(yy);
     xx = mer(xx,v);
     updata(xx);
     xx = mer(xx,yy);
     updata(xx);
     return xx;
}
void print()
{
     for(int i = 1;i<=tot;i++){
      dprint("tree %d:\n",i);
      t[i].print();
      printf("\n");
     }
}
int main(int argc, char *argv[])
{
    debug = fopen("debug","w");
    freopen("treap.in","r",stdin);
    freopen("treap.out","w",stdout);
    srand(clock());
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     root = insert(root,i);
    print();
    fclose(stdin);
    fclose(stdout);
    fclose(debug);
    return EXIT_SUCCESS;
}
